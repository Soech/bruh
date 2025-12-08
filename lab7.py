import random
rows = int(input('Введите ряд: '))
cols = int(input('Введите столбец: '))
res = [[random.randint(0, 10) for _ in range(cols)] for _ in range(rows)]
count = 0
for col in range(cols):
    nenol = False
    for row in range(rows):
        if res[row][col] == 0:
            nenol = True
            break
    
    if not nenol:
        count += 1

print(f"Столбцы без нулевых элементов: {count}")
print('матрица: ')
for row in res:
    print(row)
