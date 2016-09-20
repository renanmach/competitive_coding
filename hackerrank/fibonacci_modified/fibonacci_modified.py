# https://www.hackerrank.com/challenges/fibonacci-modified/
# Fibonacci Modified

import sys

def func(t1,t2,n):
    for i in range(3,n+1):
        t = t1 + t2**2
        t1 = t2
        t2 = t
    return t


line = input()
line = line.split(" ")

t1 = int(line[0])
t2 = int(line[1])
n = int(line[2])

print(func(t1,t2,n))
