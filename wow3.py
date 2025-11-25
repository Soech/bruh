import random
lst = [random.randint(-10, 10)for _ in range(4)]
print("Сгенерированный список:", lst)
max_element = lst[0]
for num in lst[1:]:
    if num > max_element:
     max_element = num
print("Максимальный элемент:", max_element)

nezero = [x for x in lst if x != 0]
zero = [x for x in lst if x == 0]
translst = nezero + zero
print(translst)