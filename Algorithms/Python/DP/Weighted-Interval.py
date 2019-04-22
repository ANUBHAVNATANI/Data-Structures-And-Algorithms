def computePi(val_st_F, ft_ar, st_ar):
    Pi = [0]*len(ft_ar)
    c = sorted(ft_ar)
    for i in range(0, len(val_st_F)):
        for j in range(0, i):
            if(c[j] <= st_ar[i]):
                d = val_st_F[j]
                if(d > Pi[i]):
                    Pi[i] = j
    #Pi[0] = val_st_F[0]
    return Pi


job_arr = [[3, 10, 20], [1, 2, 50], [6, 19, 100], [2, 100, 200]]

M = [0]*len(job_arr)

st_ar = []
ft_ar = []
val_ar = []
for i in range(0, len(job_arr)):
    st_ar.append(job_arr[i][0])
    ft_ar.append(job_arr[i][1])
    val_ar.append(job_arr[i][2])
j = [i for i in range(0, len(job_arr))]
# sort jobs according to finish time
j_st_F = [x for _, x in sorted(zip(ft_ar, j))]
val_st_F = [x for _, x in sorted(zip(ft_ar, val_ar))]
st_st = [x for _, x in sorted(zip(ft_ar, st_ar))]
A = [0]*len(job_arr)

l = computePi(val_st_F, ft_ar, st_st)


def wig(n):

    if(M[n] != 0):
        return M[n]
    else:
        M[n] = max(val_st_F[n]+wig(l[n]), wig(n-1))
    return M


a = wig(3)
print(a)
