#!/bin/env python
# -*- coding: utf-8 -*-

#
# プロジェクト取得
#
def getProjects(options, pg_con, self):

  pritem = []
  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT * FROM mr_projects WHERE delete_at is null ORDER BY id;')
    #cur.execute('SELECT *  FROM users;')
    pritem = cur.fetchall()
    return pritem

  except Exception as e:
    print(e)
    return pritem

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()



#
# タスク内容取得
#
def getPrtask(options, pg_con, self):

  prtask = []
  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    #cur.execute('SELECT * FROM mr_tasks WHERE delete_at is null ORDER BY id;')
    cur.execute('SELECT * FROM mr_tasks WHERE project_id=1 ORDER BY id;')
    prtask = cur.fetchall()
    return prtask

  except Exception as e:
    print(e)
    return prtask

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()



#
# 毎月の契約時間取得
#
def getPrmtime(options, pg_con, self):

  mtime = []
  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT month_contract_time FROM mr_projects WHERE id=1 ORDER BY id;')
    mtime = cur.fetchone()
    return mtime

  except Exception as e:
    print(e)
    return mtime

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()



#
# 契約時間取得
#
#def getPrmxtime(options, pg_con, self):

#  mxtime = []
#  try:
#    # PostgreSQL カーソル取得
#    cur = pg_con.cursor()
#    cur.execute('SELECT month_contract_time FROM mr_projects WHERE id=1 ORDER BY id;')
#    mxtime = cur.fetchone()
#    return mxtime

#  except Exception as e:
#    print(e)
#    return mxtime

#  finally:
    # PostgreSQL カーソルクローズ
#    cur.close()



#
# 作業時間取得
#
def getPrtime(options, pg_con, self):

  wtime = []
  try:
    # PostgreSQL カーソル取得
    cur = pg_con.cursor()
    cur.execute('SELECT sum(working_time) as working_time FROM mr_tasks WHERE project_id=1 GROUP BY ROLLUP(project_id) ORDER BY project_id;')
    #cur.execute('SELECT * FROM mr_tasks WHERE project_id=1 ORDER BY id;')
    wtime = cur.fetchone()
    return wtime

  except Exception as e:
    print(e)
    return wtime

  finally:
    # PostgreSQL カーソルクローズ
    cur.close()
