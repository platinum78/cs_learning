import numpy as np

input_io = open("input.txt", "w")

tc_num = int(input("Enter number of test cases: "))

tc_dimensions = []
for idx in range(tc_num):
    tc_dimensions.append([int(x) for x in input("Enter test case #%d: " % (idx + 1)).split()])

input_io.write("%d \n" % tc_num)
for row, col in tc_dimensions:
    arr = np.int32(np.random.random([row, col]) * 1000 % 26)
    char_map = [[chr(arr[r, c] + ord('A')) for c in range(col)] for r in range(row)]

    input_io.write("%d %d \n" % (row, col))
    for r in char_map:
        for c in r:
            input_io.write("%c" % c)
        input_io.write("\n")

