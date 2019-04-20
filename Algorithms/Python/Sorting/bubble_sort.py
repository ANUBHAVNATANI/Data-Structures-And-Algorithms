def swap(a,b):
    temp = a
    a = b
    b = temp
    return a,b

a = [4,5,7,1,2,3,6,88,4,11,22,4,5]
for j in range(len(a)-1,-1,-1):
    for i in range(0,j):
        if(a[i]>a[i+1]):
            a[i],a[i+1] = swap(a[i],a[i+1])


print(a)