#!/bin/env python
# -*- coding: utf-8 -*-]
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
# import logic.authsession as au
# import logic.users as us
'''
同じ階層のロジックフォルダー(logic)の中にある
authsession・ｐｙファイル
users.ｐｙファイル
使用（インポート）するために記載

as au == authsessionの省略系
as us == logic.users 
'''

# コンフィグの読み込み
"""
コマンドラインからのoptionを追加できる便利なメソッド。
define (定数名 , 値 [, 文字の区別フラグ] )
"""
define("debug", type=bool)
define("system_name", type=str)
define("port", type=int)
define("db_host", type=str)
define("db_schema", type=str)
define("db_user", type=str)
define("salt", type=str)
define("session_timeout_min", type=int)
#parse_config_file('default.conf')


#接続
'''
connect()には以下の接続情報を含めることができます。
パラメータ	意味
minconn: 最小接続数
maxconn: 最大接続数
host	接続先のアドレス(PostgreSQLが稼動しているサーバのホスト名)、
      省略時はUnixドメインソケットでの通信を行う。
      デフォルトの値が"localhost

dbname	接続先のDB名
user	接続に使用するDBユーザ名、省略時はOSユーザ名が使用される
password	接続に使用するDBユーザのパスワード
port	接続先のポート番号、省略時は5432が使用される
また、options後ろのdb_host、db_schema、db_userは上のdefineで
定義されているのものを使用している。
'''
connector = psycopg2.connect(
                              host='localhost',     #
                              database='postgres',  #
                              user='postgres',      #
                              password='hirotada',  #データベース接続のpass
                          )


#データ所得
cursor = connector.cursor()
cursor.execute('select name from staff;')
pg_con = cursor.fetchone()

#result = cursor.fetchone()
#pg_con
cursor.close()
#result = cursor.fetchall()
  
print(pg_con)

print(type(pg_con))

#<class 'tuple'>
# なのでresult[0]
add = pg_con[0]
print(add)

ans = "tamura"
print(ans in pg_con)


# ログイン画面
class MainHandler(tornado.web.RequestHandler):
  # ログイン初期表示処理
  def get(self):
    self.render("index.html", system_name=options.system_name, msg="")
    print("ログイン初期表示")
  # ログインボタン押下処理
  def post(self):
    #5/8の予定　入力フォームからデータを受取,画面を遷移する。
    # フォーム入力値の取得
    username = self.get_argument('username')
    password = self.get_argument('password')
    #5／8日完成
    # ログイン認証   
    if add == username:
      # ログイン成功のため保守報告書画面に遷移
      self.render("home.html")
      print("ログイン成功")
    else:
      # ログイン失敗
      self.render("index.html", system_name=options.system_name, msg="ログインIDまたはパスワードが違います。")


# 保守報告書画面
class HomeHandler(tornado.web.RequestHandler):
  def get(self):
    self.render("home.html")
    print("保守報告書画面")
    

#5／9日
#画面遷移
# ユーザー管理画面
class UserListHandler(tornado.web.RequestHandler):
  def get(self):
    self.render("user_list.html")
    print("ユーザー管理画面")

# ユーザー設定画面
class UserHandler(tornado.web.RequestHandler):
  def get(self):
    self.render("user.html")
    print("ユーザー設定画面")



#5／9日
# タスク登録画面
class TaskHandler(tornado.web.RequestHandler):
  def get(self):
    self.render("task.html")
    print("タスク登録画面")

class ProjectHandler(tornado.web.RequestHandler):
  def get(self):
    self.render("project_list.html")
    print("プロジェクト管理")


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
  (r"/", MainHandler),               #ログイン画面に行くとMainHandlerが処理される
  (r"/home", HomeHandler),           #保守報告書画面に行くとHomeHandlerが処理される
  (r"/task", TaskHandler),           #タスク登録画面に行くとTaskHandlerが処理される
  (r"/project_list", ProjectHandler),#プロジェクト管理画面に行くとProjectHandlerが処理される
  (r"/user_list", UserListHandler),  #ユーザー管理画面に行くとUserListHandlerが処理される
  (r"/user", UserHandler),           #ユーザー設定画面に行くとUserHandlerが処理される
  ], **settings
)

# サーバー起動処理
if __name__ == '__main__':
    application.listen(8888)
    tornado.ioloop.IOLoop.current().start()

'''
render()
renderメソッドはテンプレートファイルと指定した引数をテンプレートエンジンに渡し、
その結果生成された文字列をレスポンスとして送信するメソッドです。
get_argument()
get_argumentメソッドは、クライアントから渡されたパラメータを受け取るためのメソッド

'''
