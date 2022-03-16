# 必要なライブラリのインポート
from flask import *
from flask import Flask
# render_templateを使用するために記載
from flask import Flask, render_template #追加
from flask import Blueprint

wine_module = Blueprint("wine", __name__)

@wine_module.route("/wine")
def wine1():
    #変数定義
    return "wine"

@wine_module.route("/wine/1")
def wine2():
       #変数定義
     return render_template('/wine/wine.html')
