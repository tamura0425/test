#!/bin/env python
# -*- coding: utf-8 -*-
import os
import datetime
import atexit
import psycopg2
import psycopg2.pool
import tornado.ioloop
import tornado.web
import tornado.options
from tornado.options import define, options, parse_config_file

# ビジネスロジック
import logic.authsession as au
import logic.users as us

# コンフィグの読み込み
define("debug", type=bool)
define("system_name", type=str)
define("port", type=int)
define("db_host", type=str)
define("db_schema", type=str)
define("db_user", type=str)
define("salt", type=str)
define("session_timeout_min", type=int)
parse_config_file('default.conf')

# PostgreSQL接続
pg_pool = psycopg2.pool.SimpleConnectionPool(minconn=3,
                                             maxconn=6,
                                             host=options.db_host,
                                             dbname=options.db_schema,
                                             user=options.db_user)
# PostgreSQLコネクションプール取得
pg_con = pg_pool.getconn()

# システムプロセス終了時の処理
def processExit():
  print("process exit.")
  pg_pool.putconn(pg_con)

# システムプロセス終了ファンクションの登録
atexit.register(processExit)

# ログイン画面
class MainHandler(tornado.web.RequestHandler):
  # ログイン初期表示処理
  def get(self):
    self.render("index.html", system_name=options.system_name, msg="")

  # ログインボタン押下処理
  def post(self):

    # ログイン認証
    result = au.authCheck(options, pg_con, self)
    if result:
      # ログイン成功のため保守報告書画面に遷移
      self.render("home.html")
    else:
      # ログイン失敗
      self.render("index.html", system_name=options.system_name, msg="ログインIDまたはパスワードが違います。")

# 保守報告書画面
class HomeHandler(tornado.web.RequestHandler):
  def get(self):
    # セッションチェック
    result = au.sessionCheck(options, pg_con, self)
    if result:
      self.render("home.html")
    else:
      self.render("index.html", system_name=options.system_name, msg="再ログインが必要です。")

# タスク登録画面
class TaskHandler(tornado.web.RequestHandler):
  def get(self):
    # セッションチェック
    result = au.sessionCheck(options, pg_con, self)
    if result:
      self.render("task.html")
    else:
      self.render("index.html", system_name=options.system_name, msg="再ログインが必要です。")

# プロジェクト管理画面
class ProjectHandler(tornado.web.RequestHandler):
  def get(self):
    # セッションチェック
    result = au.sessionCheck(options, pg_con, self)
    if result:
      self.render("project_list.html")
    else:
      self.render("index.html", system_name=options.system_name, msg="再ログインが必要です。")

# ユーザー管理画面
class UserListHandler(tornado.web.RequestHandler):
  def get(self):
    # セッションチェック
    result = au.sessionCheck(options, pg_con, self)
    if result:
      # ユーザーリスト取得
      items = us.getUserList(options, pg_con, self)
      self.render("user_list.html", items=items)
    else:
      self.render("index.html", system_name=options.system_name, msg="再ログインが必要です。")

# ユーザー設定画面
class UserHandler(tornado.web.RequestHandler):
  def get(self):
    # セッションチェック
    result = au.sessionCheck(options, pg_con, self)
    if result:
      if self.get_argument("id") == "0":
        item = us.initUser()
        self.render("user.html", item=item)
      else:
        item = us.getUser(options, pg_con, self)
        self.render("user.html", item=item)
    else:
      self.render("index.html", system_name=options.system_name, msg="再ログインが必要です。")

  def post(self):
    # バリデーション
    item = us.validatorUser(options, pg_con, self)
    if item[4]:
      # 入力値エラー
      self.render("user.html", item=item)
      return

    if self.get_argument("userid") == "0":
      result = us.registUser(options, pg_con, self)
    else:
      result = us.updateUser(options, pg_con, self)

    if result:
      # ユーザーリスト取得
      items = us.getUserList(options, pg_con, self)
      self.render("user_list.html", items=items)
    else:
      self.render("index.html", system_name=options.system_name, msg="サーバーでエラーが発生しました。")

BASE_DIR = os.path.dirname(__file__)

# Tornado setting.
settings = {
    "debug": options.debug,
    "cookie_secret": "748f8b6da408d71743dd175aa501847251f5c4c5",
    "xsrf_cookies": True,
    "template_path": os.path.join(BASE_DIR, "templates"),
    "static_path": os.path.join(BASE_DIR, "static"),
}
# ルーティングの登録とクライアントリソースのパス設定
application = tornado.web.Application([
  (r"/", MainHandler),
  (r"/home", HomeHandler),
  (r"/task", TaskHandler),
  (r"/project_list", ProjectHandler),
  (r"/user_list", UserListHandler),
  (r"/user", UserHandler),
  ], **settings
)

# サーバー起動処理
if __name__ == "__main__":
  application.listen(options.port)
  print("Server running... port =", options.port)
  tornado.ioloop.IOLoop.instance().start()

