import cs50

while(True):
    height = cs50.get_int("Integer between 0 and 23: ")
    if height >= 0 and height <= 23:
        break

t = height
i = 1
for x in range(0, height):
    # print spaces for left
    t = t - 1
    print(' ' * t, end="")

    # print # for left portion
    print('#' * i, end="")

    # print double gap
    print('  ', end="")

    # print # for right portion
    print('#' * i)

    # change # for next row
    i = i + 1
