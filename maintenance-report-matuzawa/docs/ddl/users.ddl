CREATE TABLE users (
  id                 SERIAL,                                     -- キー重複が起きないように自動採番
  employee_number    VARCHAR(10),                                -- 社員番号
  name               VARCHAR(50),                                -- 社員氏名
  login_id           VARCHAR(20),                                -- ログインID
  password           VARCHAR(200),                               -- パスワード(hash値) 平文で保存しない
  delete_at          TIMESTAMP,                                  -- 削除した日(日付があれば削除したとみなす)(全テーブル共通)
  created_by         INTEGER,                                    -- 登録者(全テーブル共通)
  created_at         TIMESTAMP    DEFAULT CURRENT_TIMESTAMP,     -- 登録日(全テーブル共通)
  updated_by         INTEGER,                                    -- 更新者(全テーブル共通)
  updated_at         TIMESTAMP    DEFAULT CURRENT_TIMESTAMP,     -- 更新日(全テーブル共通)
PRIMARY KEY (id));
