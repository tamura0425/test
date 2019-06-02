CREATE TABLE mr_projects (
  id                        SERIAL,
  project_name              VARCHAR(100),   -- 案件名
  client_name               VARCHAR(100),   -- 顧客名
  contracted_start_month    DATE,           -- 契約開始月 2019/04/01
  contract_months           SMALLINT,       -- 契約期間 12(ヵ月)
  month_contract_time       SMALLINT,       -- 月契約時間 20(h)
  delete_at                 TIMESTAMP,
  created_by                INTEGER,
  created_at                TIMESTAMP,
  updated_by                INTEGER,
  updated_at                TIMESTAMP,
PRIMARY KEY (id));
