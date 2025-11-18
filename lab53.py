import math
for n in range(100, 0, -1):
    a = 3
    p = math.log(n) / math.log(a)
    if (p - int(p) == 0):
        n = True
    else:
        n = False
print(n)