t=int(input())
for i in range(t):
    N,X=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    j=1
    s=0
    f=0
    for i in a:
        s+=i
        if s>=X:
            f=1
            break
        j+=1
    if f:
        print(j)
    else:
        print("-1")




