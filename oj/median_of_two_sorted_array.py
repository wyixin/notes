#!/user/bin/env python

#return as float
def findMedianSortedArrays(A, B):
    temp = []
    i, j = 0, 0
    while i<len(A) and j<len(B):
        if A[i] < B[j]:
            temp.append(A[i])
            i+=1
        elif A[i] == B[j]:
            temp.append(A[i])
            temp.append(B[j])
            i+=1
            j+=1
        else:
            temp.append(B[j])
            j+=1

    while i<len(A):
        temp.append(A[i])
        i+=1
    while j<len(B):
        temp.append(B[j])
        j+=1

    if len(temp)%2 == 0:
        return (temp[len(temp)/2] + temp[len(temp)/2 - 1]) / 2.0
    return temp[len(temp)/2]
    
A = (1, 2, 3, 4, 5)
B = (101, 111, 1112)

print findMedianSortedArrays(A, B)    
