#!/bin/env python
# -*- coding: utf-8 -*-
import datetime

#タスク登録画面初期値
def initTask():
  taitem=[]
  taitem.append("0") #mr_taskid
  for i in range(7):
    taitem.append("")   #date_of, task_name, task_no, target_system, work_detail, working_time, task_remarks
  return taitem

#タスク更新画面初期値
def getTask(option, pg_con, self):
  taitem=[]
  for i in range(8):
    taitem.append("")
  
  try:
    #PostgreSQLのカーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM mr_tasks WHERE id=%s AND delete_at is null;',(self.get_argument("id"),))

    row = cur.fetchone()
    if row:
        item[0] = row[0] #id
        item[1] = row[1] #date_of
        item[2] = row[2] #task_name
        item[3] = row[3] #task_no
        item[4] = row[4] #target_system
        item[5] = row[5] #work_detail
        item[6] = row[6] #working_time
        item[7] = row[7] #task_remarks
    return taitem

  except Exception as e:
    print(e)
    return taitem

  finally:
    #PostgreSQLのカーソルクローズ
    cur.close()

#タスクリストの取得
def getTaskList(options, pg_con, self):

  taitems = []
  try:
    #PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM mr_tasks WHERE delet_at is null ORDER BY date_of;')
    taitems = cur.fetchall()
    return taitems

  except Exception as e:
      print(e)
      return taitems

  finally:
    #PostgreSQL カーソルクローズ
    cur.close()


#タスク登録（validator）
def validatorTask(options, pg_con, self):

  #フォーム入力値取得
   taskid        = self.get_argument('taskid')
   date_of       = self.get_argument('date_of')
   task_name     = self.get_argument('task_name')
   task_no       = self.get_argument('task_no')
   target_system = self.get_argument('target_system')
   work_detail   = self.get_argument('work_detail')
   working_time  = self.get_argument('working_time')
   task_remarks  = self.get_argument('task_remarks')

   taitem = []
   taitem.append(taskid) #taskid
   taitem.append(date_of)       #日付
   taitem.append(task_name)     #作業名
   taitem.append(task_no)       #作業番号
   taitem.append(target_system) #作業対象
   taitem.append(work_detail)   #作業詳細
   taitem.append(working_time)  #作業時間
   taitem.append(task_remarks)  #備考
   taitem.append("")            #エラーメッセージ

   



#タスク新規登録
def registTask(options, pg_con, self):

    # ここでフォーム入力値を取得
    taskid        = self.get_argument('taskid')
    date_of       = self.get_argument('date_of')
    task_name     = self.get_argument('task_name')
    task_no       = self.get_argument('task_no')
    target_system = self.get_argument('target_system')
    work_detail   = self.get_argument('work_detail')
    working_time  = self.get_argument('working_time')
    task_remarks  = self.get_argument('task_remarks')

    # タスクテーブルへデータを挿入
    cur = pg_con.cursor()

    sql = """
    INSERT INTO mr_tasks (
     task_no
    ,date_of
    ,task_name
    ,target_system
    ,work_detail
    ,working_time
    ,task_remarks
    ) VALUES (%s, %s, %s, %s, %s, %s, %s)
    """
    try:
     cur.execute(sql, (task_no, date_of, task_name, target_system, work_detail, working_time, task_remarks))
     pg_con.commit()

    except Exception as e:
      pg_con.rollback
      print(e)

    finally:
    # PostgreSQL カーソルクローズ
      cur.close()

#タスク新規更新
def updateTask(options, pg_con, self):

  try:
    # ここでフォーム入力値を取得
    taskid        = self.get_argument('taskid')
    date_of       = self.get_argument('date_of')
    task_name     = self.get_argument('task_name')
    task_no       = self.get_argument('task_no')
    target_system = self.get_argument('target_system')
    work_detail   = self.get_argument('work_detail')
    working_time  = self.get_argument('working_time')
    task_remarks  = self.get_argument('task_remarks')
    deleteFlag    = self.get_argument('deleteFlag', False)
    if deleteFlag:
      delete_at = datetine.datetime.now()
    else:
      delet_at = None

    # タスクテーブルへデータを挿入
    cur = pg_con.cursor()

    sql = """
    UPDATE mr_tasks SET
    date_of=%s,
    task_name=%s,
    task_no=%s,
    target_system=%s,
    work_detail=%s,
    working_time=%s,
    task_remarks=%s,
    delete_at=%s,
    WHERE id=%s
     
    """

    cur.execute(sql, (date_of, task_name, task_no, target_system, work_detail, working_time, task_remarks, delete_at, taskid))
    pg_con.commit()
    return True

  except Exception as e:
    print(e)
    pg_con.rollback()
    return False

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()
