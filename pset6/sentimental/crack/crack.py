import cs50 as c
import crypt, sys

if len(sys.argv) == 2:
    thash = sys.argv[1]
    salt = thash[0:2]
    dic = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for five in dic:
        for four in dic:
            for three in dic:
                for two in dic:
                    for one in dic[1:]:
                        pw = f"{one}{two}{three}{four}{five}".strip()

                        if crypt.crypt(pw, salt) == thash:
                            print(pw)
                            sys.exit(0)
else:
    print("Enter 1 desired hash")
    sys.exit(1)