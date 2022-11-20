class Car:
    def __init__(self, color = "white"):
self.color = color
self.mileage = 0
def drive(self, km):
self.mileage += km
msg1 = f"{km}kmドライブしました。"
msg2 = f"総移動距離は{self.mileage}kmです。"
print(msg1+msg2)
【実行プログラム】

from car_class import Car
car1 = Car()
car2 = Car()


car1.drive(21)
car2.drive(15)
car1.drive(3)