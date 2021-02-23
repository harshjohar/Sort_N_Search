macbook = {
    'name': 'Macbook',
    'company': 'Apple',
    'price': 150000
}

hp_pavillion = {
    'name': 'hp_pavillion',
    'company': 'Hp',
    'price': 100000
}

yoga = {
    'name': 'Yoga', 
    'company': 'Lenovo', 
    'price': 70000
}

li = [macbook, hp_pavillion, yoga]
print(li)

arr = [2, 3, 4, 5, 6, 1, 7]
print('Unsorted: ', arr)
arr.sort()
print('Sorted(asc): ', arr)

arr = [2, 3, 4, 5, 6, 1, 7]
arr.sort(reverse=True)
print('Sorted(desc): ', arr)

# if you don't want to sort the same list but to create a new one
arr2 = [-1, 4, 7, 3, 4, 5]
result = sorted(arr2)
print('original: ', arr2)
print('a new list: ', result)