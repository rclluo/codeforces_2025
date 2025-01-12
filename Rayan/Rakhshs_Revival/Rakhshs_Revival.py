for _ in range(int(input())):
    n,m,k=[int(x) for x in input().split()]
    rakhsh=input()
    size,ans,i=0,0,0
    while i<n:
        if rakhsh[i]=='1':
            size=0
            i+=1
        else:
            size+=1
            if size==m:
                ans+=1
                i+=k
                size=0
            else:
                i+=1
    print(ans)