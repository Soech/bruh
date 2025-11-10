def find_smallest_k(N):
    K = 1
    while 3 ** K <= N:
        K += 1
    return K

N = int(input("Введите число N: "))
K = find_smallest_k(N)
print(K)
