# 必要なライブラリのインポート
from flask import *
from flask import Flask
# render_templateを使用するために記載
from flask import Flask, render_template #追加
from flask import Blueprint

Bourbon_module = Blueprint("Bourbon", __name__)

@Bourbon_module.route("/Bourbon")
def Bourbon1():
    #変数定義
    return "Bourbon"


@Bourbon_module.route("/Bourbon/1")
def Bourbon():
       #変数定義
     return render_template('/Bourbon/Bourbon.html')