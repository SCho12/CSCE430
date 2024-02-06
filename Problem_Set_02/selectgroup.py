dict_of_sets = {}


def group(members):
    name = members[0]
    if name not in dict_of_sets:
        dict_of_sets[name] = set(members[2:])


def union(commands) -> set:
    if commands[0] not in dict_of_sets:
        if commands[0] == "union":
            return union(commands[1:])
        elif commands[0] == "intersection":
            print("line 15")
            print("commands:", commands[1])
            return intersection(commands[1:])
        elif commands[0] == "difference":
            return difference(commands[1:])
    if commands[1] not in dict_of_sets:
        if commands[1] == "union":
            return dict_of_sets[commands[0]].union(union(commands[2:]))
        elif commands[1] == "intersection":
            return dict_of_sets[commands[0]].union(intersection(commands[2:]))
        elif commands[1] == "difference":
            return dict_of_sets[commands[0]].union(difference(commands[2:]))
    return dict_of_sets[commands[0]].union(dict_of_sets[commands[1]])


def intersection(commands) -> set:
    if commands[0] not in dict_of_sets:
        if commands[0] == "union":
            return union(commands[1:])
        elif commands[0] == "intersection":
            return intersection(commands[1:])
        elif commands[0] == "difference":
            return difference(commands[1:])
    elif commands[1] not in dict_of_sets:
        if commands[1] == "union":
            return dict_of_sets[commands[0]].intersection(union(commands[2:]))
        elif commands[1] == "intersection":
            return dict_of_sets[commands[0]].intersection(intersection(commands[2:]))
        elif commands[1] == "difference":
            return dict_of_sets[commands[0]].intersection(difference(commands[2:]))
    else:
        return dict_of_sets[commands[0]].intersection(dict_of_sets[commands[1]])


def difference(commands) -> set:
    if commands[0] not in dict_of_sets:
        if commands[0] == "union":
            return union(commands[1:])
        elif commands[0] == "intersection":
            return intersection(commands[1:])
        elif commands[0] == "difference":
            return difference(commands[1:])
    if commands[1] not in dict_of_sets:
        if commands[1] == "union":
            return dict_of_sets[commands[0]].difference(union(commands[2:]))
        elif commands[1] == "intersection":
            return dict_of_sets[commands[0]].difference(intersection(commands[2:]))
        elif commands[1] == "difference":
            return dict_of_sets[commands[0]].difference(difference(commands[2:]))
    return dict_of_sets[commands[0]].difference(dict_of_sets[commands[1]])


try:
    while True:
        line = input()
        words = line.split()
        if words[0] == "group":
            group(words[1:])
        elif words[0] == "union":
            out = union(words[1:])
            print(' '.join(sorted(out)))
        elif words[0] == "intersection":
            out = intersection(words[1:])
            print(' '.join(sorted(out)))
        elif words[0] == "difference":
            out = difference(words[1:])
            print(' '.join(sorted(out)))
except EOFError:
    pass
