arr = [5, 3, 2, 6, 1]

for i in range (0,4):
    for i in range (0,len(arr)-1):
        if (arr [i] > arr[i+1]):
            var = arr[i]
            arr[i]=arr[i+1]
            arr [i+1]=var

print(arr)