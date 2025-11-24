
lst = [1, 0, 3, 0, 5, 2, 0, 6, 0, 4]

max_element = max(lst)
print("Максимальный элемент:", max_element)

nezero = [x for x in lst if x != 0]
zero = [x for x in lst if x == 0]
transformed_lst = nezero + zero
print("Преобразованный список:", transformed_lst)