t=int(input())
for _ in range(t):
    n,x,y=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=[]
    for i in range(n):
        o=b[i]-a[i]
        c.append(o)
    if set(c).issubset({x,y}):
        print("YES")
    else:
        print('NO')

