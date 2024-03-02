cases = int(input())


dict = {'upper': 3, 'middle': 2, 'lower': 1}

for x in range(cases):
    val = []
    people = int(input())
    for y in range(people):
        person = input()
        words = person.split(": ")
        name = words[0]
        classes = words[1][:-6].split("-")
        for z in range(15 - len(classes)):
            classes.insert(0, "middle")
        nums = []
        for a in range(len(classes)):
            nums.append(dict[classes[a]])
        nums.reverse()
        val.append((name, nums))  
    val.sort(key=lambda x: x[0])
    val.sort(key=lambda x: x[1], reverse=True)
    for b in range(len(val)):
        print(val[b][0])
    print(30 * "=")
        