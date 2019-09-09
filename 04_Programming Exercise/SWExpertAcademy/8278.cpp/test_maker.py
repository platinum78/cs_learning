m = 300

with open("input.txt", "w") as fp:
    fp.write("%d \n" % m)
    for x in range(m):
        fp.write("%d %d\n" % (x ** 4, x + 1))