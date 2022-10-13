from datetime import date

def calc(birth_date):
    now_date = date.today()
    bth_date_list = [int(x) for x in birth_date.split("/")]
    year = bth_date_list[0]
    month = bth_date_list[1]
    day = bth_date_list[2]

    birth_date = date(year, month, day)
    diff_day = (now_date - birth_date).days
    return diff_day

if __name__ == "__main__":
    print(calc("1998/9/25"))