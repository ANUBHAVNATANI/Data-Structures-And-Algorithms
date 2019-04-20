def merge(arr,l,mid,r):
    L = arr[:mid]
    R = arr[mid:]
    i = j = k = 0
    while(i<len(L) and j<len(R)):
        if(L[i]<=R[j]):
            arr[k] = L[i]
            i = i+1
        else:
            arr[k] = R[j]
            j=j+1
        k = k+1  
    while(i<len(L)):
        arr[k] = L[i]
        i = i+1
        k = k+1
    while(j<len(R)):
        arr[k] = R[j]
        j = j+1
        k = k+1

def merge_sort(arr,l,r):
    if(l<r):
        mid=(l+r)//2
        merge_sort(arr,l,mid)
        merge_sort(arr,mid+1,r)
        merge(arr,l,mid,r)

a = [4,5,7,1,2,3,6,88,4,11,22,4,5]

merge_sort(a,0,len(a)-1)

print(a)