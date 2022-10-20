
#-*- coding: utf-8-*-
import sys 
from flask import *
from flask import Flask
from flask import request



#インストールしたモジュールが読み込めないので
sys.path.append('/usr/local/lib64/python3.6/site-packages/')
sys.path.append('/usr/local/lib/python3.6/site-packages/')

from flask import Flask, request, redirect, url_for, render_template, g

app = Flask(__name__)

@app.route('/')
def index():
    return 'Hello, World!55555'
    
if __name__ == "__main__":
    app.run()
