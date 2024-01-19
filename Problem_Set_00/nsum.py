data = input()
lines = data.split('\n')
str_n = lines[0].replace(" ", "")
n = int(str_n)
integers = lines[1].split(" ")
total = 0

for x in range(n):
    total += int(integers[x])

print(total)
