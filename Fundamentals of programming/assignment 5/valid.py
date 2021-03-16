def validateDay(day):
        try:
            day = int(day)
            if day >= 1 and day <= 30:
                return True
            else:
                return False
        except Exception as ex:
            return ex # print ex in ui

def validateAmount(amount):
    try:
        amount = int(amount)
        if amount > 0:
            return True
        else:
            return False

    except Exception as ex:
        return ex # print ex in ui
