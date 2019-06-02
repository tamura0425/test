CREATE TABLE sessions (
  session_id    VARCHAR(200),
  created_at    TIMESTAMP    DEFAULT CURRENT_TIMESTAMP,
PRIMARY KEY (session_id));
