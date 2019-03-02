input_file = open("input.txt", "w")
test_cnt = 255

input_file.write(str(test_cnt))
input_file.write("\n")

for x in range(test_cnt):
    input_file.write(str(x ** 1) + "\n")

input_file.close()