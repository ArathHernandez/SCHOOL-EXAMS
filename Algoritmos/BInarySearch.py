def binary_search(lista, obj):
    left = 0
    right = len(lista)
    while right > left:
        mid = (left + right)
        mid = lista[mid]
        if mid == obj:
            return mid
        if obj < mid:
            right = mid
        if obj > mid:
            left = mid + 1

    return "Value not in list"


# test cases
print(binary_search([1, 2, 3, 4, 5], 1))
print(binary_search([1, 2, 3, 4, 5], 2))
print(binary_search([1, 2, 3, 4, 5], 0))
print(binary_search([1, 2, 3, 4, 5], 3))
print(binary_search([1, 2, 3, 4, 5], 5))
