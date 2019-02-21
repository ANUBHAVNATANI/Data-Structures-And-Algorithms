def insertion_sort(arr):
    for i in range(1,len(arr)):
        c = arr[i]
        j = i-1
        while(j>=0 and arr[j]>c):
            arr[j+1] = arr[j]
            j = j-1
        arr[j+1] = c
                

a = [4,5,7,1,2,3,6,88,4,11,22,4,5]
insertion_sort(a)
print(a)