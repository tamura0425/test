#!/bin/env python
# -*- coding: utf-8 -*-
import datetime
import hashlib

#
# ログイン認証
#
def authCheck(options, pg_con, self):

  # フォーム入力値の取得
  username = self.get_argument('username')
  password = self.get_argument('password')

  # sha512 hash.
  password_hash = options.salt + password
  hashed = hashlib.sha512(password_hash.encode('utf-8')).hexdigest()

  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM users WHERE login_id=%s AND delete_at is null;', (username,))
    row = cur.fetchone()
    if row:
      # パスワードをhash値で比較しチェック
      if hashed == row[4]:
        # セッションキーを生成
        now = datetime.datetime.now()
        sid = password_hash + str(now)
        sid_hashed = hashlib.sha512(sid.encode('utf-8')).hexdigest()

        # セッション情報を登録
        cur.execute('INSERT INTO sessions (session_id) VALUES (%s)', (sid_hashed,))
        pg_con.commit()

        # ブラウザのCookieにセッションキーを保存
        self.set_secure_cookie("sid", sid_hashed, expires_days=1)

        # ログイン成功
        return True
      else:
        # ログイン失敗
        print("login failer.")
        return False
    else:
      # ログイン失敗
      print("login failer.")
      return False

  except Exception as e:
    print(e)
    pg_con.rollback()
    return False

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

#
# セッションチェック
#
def sessionCheck(options, pg_con, self):

  # ブラウザのセッションキーを取得
  sid = self.get_secure_cookie("sid")

  # セッションの有効期限を取得
  now = datetime.datetime.now()
  session_time = now - datetime.timedelta(minutes=options.session_timeout_min)

  # 有効なセッション情報がデータベースに存在するかチェック
  try:
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM sessions WHERE session_id=%s AND created_at >= %s;', (sid.decode('utf-8'), session_time))
    row = cur.fetchone()

    if row:
      # セッションタイムを延長
      sessionExtension(options, pg_con, sid)
      # 有効なセッション
      return True
    else:
      # 無効なセッション
      return False

  except Exception as e:
    print(e)
    return False

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

#
# セッションタイムアウトの有効期限を延長
#
def sessionExtension(options, pg_con, sid):
  try:
    cur = pg_con.cursor()
    cur.execute('UPDATE sessions SET created_at = now() WHERE session_id=%s;', (sid.decode('utf-8'),))
    pg_con.commit()

  except Exception as e:
    print(e)
    pg_con.rollback()

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()
