import random

size = 200
with open("input.txt", "w") as fp:
    fp.write(str(size) + "\n")
    for x in range(size):
        numbers = [(y + 1 + size * x) for y in range(size)]
        if x % 2 == 1:
            numbers = list(reversed(numbers))
        fp.write(" ".join([str(x) for x in numbers]) + "\n")