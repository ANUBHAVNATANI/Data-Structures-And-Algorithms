def count_sort(arr,k):
    count = [0]*k
    b = [0]*len(arr)
    for j in range(0,len(arr)):
        count[arr[j]]=count[arr[j]]+1
    for i in range(0,k):
        if(i>0):
            count[i] = count[i]+count[i-1]
        else:
            count[i] = count[i]
    for j in range(len(a)-1,-1,-1):
        b[count[arr[j]]-1] = arr[j]
        count[arr[j]]=count[arr[j]]-1
    return b