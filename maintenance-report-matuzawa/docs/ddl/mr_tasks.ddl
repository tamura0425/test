CREATE TABLE mr_tasks (
  id                        SERIAL,
  project_id                INTEGER,         -- mr_projectsのidと結合
  date_of                   DATE,            -- 作業実施日 2019/04/01
  task_name                 VARCHAR(20),     -- 実施名称
  task_no                   INTEGER,         -- 案件No
  target_system             VARCHAR(20),     -- 対象(システム)
  work_detail               VARCHAR(50),     -- 作業内容
  working_time              NUMERIC(4,1),    -- 作業時間
  task_remarks              VARCHAR(50),     -- 作業備考
  delete_at                 TIMESTAMP,
  created_by                INTEGER,
  created_at                TIMESTAMP,
  updated_by                INTEGER,
  updated_at                TIMESTAMP,
PRIMARY KEY (id));
