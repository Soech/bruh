def CircleS(R):
    pi = 3.14
    return pi*R**2
    

R1 = int(input("Радиус первого: "))
R2 = int(input("Радиус второго: "))
R3 = int(input("Радиус третьего: "))

S1 = CircleS(R1)
S2 = CircleS(R2)
S3 = CircleS(R3)

print(f"Площадь первого круга: {S1}")
print(f"Площадь второго круга: {S2}")
print(f"Площадь третьего круга: {S3}")