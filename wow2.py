
text = input("Введите текст: ")
sogl = 'аеёиоуыэюяАЕЁИОУЫЭЮЯ'
words = text.split()

count = 0
for word in words:
    if word and word[0] in sogl:
        count += 1
print("Количество слов, начинающихся с гласной:", count)