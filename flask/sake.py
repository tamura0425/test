# 必要なライブラリのインポート
from flask import *
from flask import Flask
# render_templateを使用するために記載
from flask import Flask, render_template #追加
from flask import Blueprint

sake_module = Blueprint("sake", __name__)


#HTMLとの連結サンプル
@sake_module.route('/sake/sake.html')
def sake3():
  return render_template('/sake/sake.html')