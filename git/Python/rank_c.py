

num = int(input()) #ループ回数
sum = 0 # 合計

for i in range(num):
    inputNum = input()
    array = inputNum.split()

    if array[0] == array[1]:
        sum += int(array[0]) * int(array[1])
    else:
        sum += int(array[0]) + int(array[1])

print(sum)