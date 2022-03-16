# 必要なライブラリのインポート
from flask import *
from flask import Flask
# render_templateを使用するために記載
from flask import Flask, render_template #追加
from flask import Blueprint

Brandy_module = Blueprint("Brandy", __name__)

@Brandy_module.route("/Brandy")
def Brandy1():
    #変数定義
    return "Brandy"

@Brandy_module.route("/Brandy/1")
def Brandy2():
       #変数定義
     return render_template('/Brandy/Brandy.html')