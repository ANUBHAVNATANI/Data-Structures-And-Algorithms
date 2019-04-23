# program for premtive priority


n_p = 5
brust_time = [7, 3, 2, 10, 8]
priority = [2, 3, 4, 1, 5]
arr_time = [0, 2, 5, 6, 7]
turn_around_time = [0, 0, 0, 0, 0]
waiting_time = [0, 0, 0, 0, 0]
c = [7, 3, 2, 10, 8]
time_stamp = 0
curr = 6
ij = -1


def ifless(a, curr, t):
    s = []
    i = 0
    # print("time"+str(t))
    while(i < len(a)):
        # print(c)
        if(a[i] <= curr and arr_time[i] <= t):
            if(c[i] <= 0):
                for i in range(0, len(a)):
                    ini = 0
                    if(a[i] <= curr and arr_time[i] <= t and c[i] > 0):
                        s.append(a[i])
                        ini = ini+1
                if(ini == 0):
                    curr = curr+1
                    i = -1
            else:
                s.append(a[i])
        i = i+1

    if(len(s) >= 1):
        return a.index(min(s))
    else:
        return -1


def checkWait(time_stamp, i):
    if(arr_time[i] < time_stamp and c[i] > 0):
        return True
    return False


while(sum(c) > 0):
    ii = ifless(priority, curr, time_stamp)
    # print(ii)
    curr = priority[ii]
    c[ii] = c[ii]-1
    time_stamp = time_stamp+1
    for i in range(0, n_p):
        if(i != ii):
            if(checkWait(time_stamp, i)):
                waiting_time[i] = waiting_time[i]+1
for i in range(0, n_p):
    turn_around_time[i] = brust_time[i]+waiting_time[i]

print(waiting_time)
print(turn_around_time)
