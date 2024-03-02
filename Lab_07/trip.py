n = int(input())
while n != 0:
    arr = list(map(int,input().split()))
    arr.sort()
    groups = []
    curridx = 0
    curr = 0
    for x in arr:
        if x != curr:
            curridx = 0
            curr = x
        else:
            curridx += 1
        if curridx >= len(groups):
            groups.append([])
        groups[curridx].append(curr)
    print(len(groups))
    for group in groups:
        for val in group:
            print(val,end=" ")
        print()
    print()
    n = int(input())