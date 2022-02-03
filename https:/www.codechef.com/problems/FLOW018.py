t=int(input())
while(t!=0):
    n=int(input())
    f=1
    while(n!=0):
        f=f*n
        n-=1
    print(f)
    t-=1

