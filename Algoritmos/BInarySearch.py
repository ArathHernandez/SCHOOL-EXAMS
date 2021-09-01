def binary_search(arr, left, right, n):
 
    if right >= left:
 
        mid = (right + left) // 2
 
        if arr[mid] == n:
            return mid
 
        elif arr[mid] > n:
            return binary_search(arr, left, mid - 1, n)
 
        else:
            return binary_search(arr, mid + 1, right, n)
 
    else:
        return -1
arr = [ 1, 2, 3, 4, 5 ]
n = 4
 
result = binary_search(arr, 0, len(arr)-1, n)
 
if result != -1:
    print("Index:", str(result))
else:
    print("Not present")
