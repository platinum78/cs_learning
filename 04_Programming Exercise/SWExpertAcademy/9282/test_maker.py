import random

fp = open("input.txt", "w")

fp.write("1 \n")
fp.write("32 32 \n")
for x in range(32):
    for y in range(32):
        fp.write(str(1))
        fp.write(" ")
    fp.write("\n")

fp.close()