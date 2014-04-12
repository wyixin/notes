#!/usr/bin/env python

def two_sum(num, target):
    hash_array = {}
    for k, v in enumerate(num):
        if not v in hash_array:
            hash_array[v] = k
        else:
            klist = []
            ek = hash_array[v]
            if type(ek) is list:
                klist += ek
            else :
                klist.append(ek)
            klist.append(k)
            hash_array[v] = klist
    for i in hash_array:
        sub = target - i
        if sub in hash_array:
            sub_v = hash_array[sub]
            i_v = hash_array[i]
            if type(sub_v) is list:
                if sub == i:
                    return (sub_v[0] + 1, sub_v[1] + 1)
                sub_v = sub_v[0]
            if type(i_v) is list:
                i_v = i_v[0]
            if i_v > sub_v:
                return (sub_v + 1, i_v + 1)
            else:
                return (i_v + 1, sub_v + 1)

num = (2,1,9,4,4,56,90,3)
target = 8
print two_sum(num, target)        
