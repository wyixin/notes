#!/usr/bin/env python

def two_sum(num, target):
    hash_map = {}
    for k, v in enumerate(num):
        k += 1
        if target - v in hash_map:
            return (hash_map[target - v], k)
        if v not in hash_map:
            hash_map[v] = k
        
num = (-10,2,9,10,4,4,56,90,3)
target = 0
print two_sum(num, target)        
