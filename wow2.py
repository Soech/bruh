word = input('entir: ')
x = ("а", "О", "у", "Ы", "э", "и", "я", "ё", "ю", "е")
count = 0
for words in word:
 if word and word[0] in x:
    count += 1
print(count)