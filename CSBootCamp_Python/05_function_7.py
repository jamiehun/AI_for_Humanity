# lambda 함수
li = [i for i in range(1, 11)]

li.sort(key = lambda x : x % 2 == 0)
print(li) # True 면 1 False면 0
# [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]

# ------------------------------------
f = lambda x : x ** 2
print(f(2))

print(f(5))