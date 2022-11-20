num4_set = {num for num in range(1,2021)if num%4==0}
num100_set = {num for num in range(1,2021) if num%100==0}
num400_set = {num for num in range(1,2021) if num%400==0}
result = len(num4_set ^ num100_set ^ num400_set)
print(result)



