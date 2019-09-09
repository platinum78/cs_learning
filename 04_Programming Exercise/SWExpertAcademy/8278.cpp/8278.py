s0 = 0
s1 = 1
num = 4
found = False
cache = [0, 1]

i = 2
while True:
    s = (s0 ** 3 % num + s1 ** 3 % num) % num
    cache.append(s)
    # print(cache)
    s0 = s1
    s1 = s

    if cache[-2] == 0 and cache[-1] == 1:
        break

    i += 1

print(cache, i)