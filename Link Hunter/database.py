from sqlalchemy import create_engine
db = "mysql+pymysql://USERNAME:PASSWORD@HOST/DATABASE?charset=utf8mb4"
engine = create_engine(
    db,
    connect_args={
    "ssl": {
        "ssl_ca": "/etc/ssl/cert.pem"
        }
  }
)