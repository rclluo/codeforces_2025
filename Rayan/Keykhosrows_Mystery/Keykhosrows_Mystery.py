from math import lcm
for _ in range(int(input())):
    a,b=[int(x) for x in input().split()]
    print(lcm(a,b))