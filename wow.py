s = input("Введите строку: ")
first_space = s.find(' ')
if first_space == -1:
    result = s
else:
    second_space = s.find(' ', first_space + 1)
    if second_space == -1:
        result = ''
    else:
        result = s[first_space + 1:second_space]
print(result)