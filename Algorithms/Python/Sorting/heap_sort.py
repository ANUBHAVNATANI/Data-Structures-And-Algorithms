def max_hepify(arr,i,heap_size):
    try:
        l = 2*i+1
        r = 2*i+2
        largest = i
        if(l<heap_size and arr[l]>arr[i]):
            largest = l
        if(l<heap_size and arr[r]>arr[largest]):
            largest = r
        if(largest != i):
            a[largest],a[i] = a[i],a[largest]
            max_hepify(arr,largest,heap_size)
    except:
        print("Root node given")
#max hepify takes O(logn)
def build_max_heap(arr):
    heap_size = len(arr)-1
    for i in range(heap_size//2,-1,-1):
        max_hepify(arr,i,heap_size)
#max heap takes O(n)
def heap_sort(arr):
    build_max_heap(arr)
    heap_size=len(arr)-1
    for i in range(heap_size,1,-1):
        a[i],a[0]=a[0],a[i]
        heap_size = heap_size-1
        max_hepify(arr,0,heap_size)
#at total heap sort take O(nlogn)


a = [16,4,10,14,7,9,3,2,8,1]
heap_sort(a)
print(a)
