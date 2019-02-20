def swap(a,b):
    temp = a
    a = b
    b = temp
    return a,b

a = [4,5,7,1,2,3,6,88,4,11,22,4,5]

arr_len = len(a)
for j in range(0,arr_len):
    for k in range(j,arr_len):
        if(a[j]>a[k]):
            a[j],a[k] = swap(a[j],a[k])

print(a)