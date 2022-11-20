super_class.pyを継承したsub_class.pyがあるとする。ここで、その下のプログラムを実行した場合の出力結果として正しいものを1つ選べ。なお、それぞれのファイルと実行プログラムは同じフォルダ内にあるとする。

【super_class.py】
class A:
    def __init__(self, name=""土屋""):
        self.name = name
    def hello(self):
        print(f""{self.name}さん、こんにちは"")

【sub_class.py】
from super_class import A
class B(A):
    def bye(self):
        print(f""{self.name}さん、さようなら"")
    def hello(self, night=False):
        if night:
            print(f""{self.name}さん、こんばんは"")
        else:
            super().hello()

# 【実行プログラム】
from sub_class import B

obj = B()
obj.hello(night=True)