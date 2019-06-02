CREATE TABLE mr_remarks (
  id                        SERIAL,
  project_id                INTEGER,        -- mr_projectsのidと結合
  target_month              DATE,           -- 対象月 2019/04/01
  remarks                   TEXT,           -- 備考内容
  delete_at                 TIMESTAMP,
  created_by                INTEGER,
  created_at                TIMESTAMP,
  updated_by                INTEGER,
  updated_at                TIMESTAMP,
PRIMARY KEY (id));
