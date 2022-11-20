
# 【sub_class.py】
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