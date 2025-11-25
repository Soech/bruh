
text = input("Введите текст: ")
glas = 'аеёиоуыэюяАЕЁИОУЫЭЮЯ'
words = text.split()

count = 0
for word in words:
    if word and word[0] in glas:
        count += 1
print(count)