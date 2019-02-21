def partition(arr,low,high):
    i = low-1
    p = arr[high]
    for j in range(low,high):
        if(arr[j]<=p):
            i = i+1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return i+1


def quick_sort(arr,l,h):
    if(l<h):
        pi = partition(arr,l,h)
        quick_sort(arr,l,pi-1)
        quick_sort(arr,pi+1,h)




a = [4,5,7,1,2,3,6,88,4,11,22,4,5]

quick_sort(a,0,len(a)-1)

print(a)