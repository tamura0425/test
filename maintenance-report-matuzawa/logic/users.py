#!/bin/env python
# -*- coding: utf-8 -*-
import datetime
import hashlib

#
# ユーザー登録画面初期値
#
def initUser():
  item=[]
  item.append("0")    # userid
  for i in range(4):
    item.append("")   # employee_number, name, loginid, msg
  return item

#
# ユーザー更新画面初期値
#
def getUser(options, pg_con, self):
  item=[]
  for i in range(5):
    item.append("")

  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM users WHERE id=%s AND delete_at is null;', (self.get_argument("id"), ))
    row = cur.fetchone()
    if row:
      item[0] = row[0]  # id
      item[1] = row[1]  # employee_number
      item[2] = row[2]  # name
      item[3] = row[3]  # loginid
    return item

  except Exception as e:
    print(e)
    return item

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

#
# ユーザーリスト取得
#
def getUserList(options, pg_con, self):

  items = []
  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM users WHERE delete_at is null ORDER BY employee_number;')
    items = cur.fetchall()
    return items

  except Exception as e:
    print(e)
    return items

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

#
# ユーザー登録 Validator
#
def validatorUser(options, pg_con, self):

  # フォーム入力値の取得
  userid = self.get_argument('userid')
  employeeNumber = self.get_argument('inputEmployeeNumber')
  name = self.get_argument('inputName')
  loginid = self.get_argument('inputLoginid')
  password1 = self.get_argument('inputPassword')
  password2 = self.get_argument('inputPasswordConfirm')

  item = []
  item.append(userid)          # userid（新規は固定で0）
  item.append(employeeNumber)  # 社員番号
  item.append(name)            # 氏名
  item.append(loginid)         # ログインID
  item.append("")              # エラーメッセージ

  # パスワード入力チェック
  if userid == "0":
    # 新規登録の場合
    if not password1 or not password2:
      item[4] = "パスワードとパスワード（確認）を入力してください。"
      return item

  # パスワード差異チェック
  if password1 != password2:
    item[4] = "確認で入力したパスワードと違いがあります。"
    return item

  # ログインID 重複チェック
  result = duplicationCheck(options, pg_con, self)
  if result:
    item[4] = "既に利用されているログインIDです。"

  return item

#
# ユーザー新規登録処理
#
def registUser(options, pg_con, self):

  # フォーム入力値の取得
  userid = self.get_argument('userid')
  employeeNumber = self.get_argument('inputEmployeeNumber')
  name = self.get_argument('inputName')
  loginid = self.get_argument('inputLoginid')
  password1 = self.get_argument('inputPassword')
  password2 = self.get_argument('inputPasswordConfirm')

  # sha512 hash.
  password_hash = options.salt + password1
  hashed = hashlib.sha512(password_hash.encode('utf-8')).hexdigest()

  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    sql = """
    INSERT INTO users (employee_number, name, login_id, password)
    VALUES (%s, %s, %s, %s)
    """
    cur.execute(sql, (employeeNumber, name, loginid, hashed))
    pg_con.commit()
    return True

  except Exception as e:
    print(e)
    pg_con.rollback()
    return False

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

#
# ユーザー新規更新処理
#
def updateUser(options, pg_con, self):

  # フォーム入力値の取得
  userid = self.get_argument('userid')
  employeeNumber = self.get_argument('inputEmployeeNumber')
  name = self.get_argument('inputName')
  loginid = self.get_argument('inputLoginid')
  password1 = self.get_argument('inputPassword')
  password2 = self.get_argument('inputPasswordConfirm')
  deleteFlag = self.get_argument('deleteFlag', False)
  if deleteFlag:
    delete_at = datetime.datetime.now()
  else:
    delete_at = None

  # パスワードが入力されている場合は更新するためhash化する
  if len(password1) > 0:
    # sha512 hash.
    password_hash = options.salt + password1
    hashed = hashlib.sha512(password_hash.encode('utf-8')).hexdigest()

  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    if len(password1) > 0:
      sql = """
      UPDATE users SET employee_number=%s, name=%s, login_id=%s, password=%s, delete_at=%s WHERE id=%s
      """
      cur.execute(sql, (employeeNumber, name, loginid, hashed, delete_at, userid))
    else:
      sql = """
      UPDATE users SET employee_number=%s, name=%s, login_id=%s, delete_at=%s WHERE id=%s
      """
      cur.execute(sql, (employeeNumber, name, loginid, delete_at, userid))

    pg_con.commit()
    return True

  except Exception as e:
    print(e)
    pg_con.rollback()
    return False

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

#
# ログインID 重複チェック
#
def duplicationCheck(options, pg_con, self):

  # フォーム入力値の取得
  userid = self.get_argument('userid')
  loginid = self.get_argument('inputLoginid')

  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()

    if userid == "0":
      # 新規登録の場合
      cur.execute('SELECT * FROM users WHERE login_id=%s AND delete_at is null;', (loginid, ))
    else:
      # 更新の場合
      cur.execute('SELECT * FROM users WHERE id!=%s AND login_id=%s AND delete_at is null;', (userid, loginid))

    row = cur.fetchone()
    if row:
      return True
    else:
      return False

  except Exception as e:
    print(e)
    return True

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()

