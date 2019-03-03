import cs50 as c

cred_number = c.get_float('Number: ')
cc = cred_number
sum_last = 0
sum_second_last = 0
z = 0

while cc > 0:
    last_digit = cc % 10
    sum_last += last_digit

    cc = cc // 10
    z += 1

    if cc == 0:
        break

    second_last = 2 * (cc % 10)
    if second_last > 9:
        sum_second_last += 1 + second_last % 10
    else:
        sum_second_last += second_last

    cc = cc // 10
    z += 1

    if cc == 0:
        break

big_sum = sum_last + sum_second_last
first_digit = cred_number // 10**(z - 1)
two_digits = cred_number // 10**(z-2)

if big_sum % 10 == 0:
    if ((two_digits == 34) or (two_digits == 37)) and (z == 15):
        print("AMEX")
    elif ((two_digits == 51) or (two_digits == 52) or (two_digits == 53) or (two_digits == 54) or (two_digits == 55)) and (z == 16):
        print("MASTERCARD")
    elif (first_digit == 4) and (z == 13 or z == 16):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")


