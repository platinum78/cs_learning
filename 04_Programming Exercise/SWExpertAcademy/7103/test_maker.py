input_file = open("input.txt", "w")
test_cnt = 255

input_file.write(str(test_cnt))
input_file.write("\n")

for x in range(test_cnt):
    input_file.write(str(32767 - 100 * x) + "\n")

input_file.close()