def linear_search(li, target):
    for i in range(len(li)):
        if target == li[i]:
            return i
    return -1

li = [99,66,55,22,33,45,68,22,84,66,77,999,333,44,787,456,654]
target = 787
print(linear_search(li, target))