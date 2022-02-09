t=int(input())
for i in range(t):
    n=int(input())
    if n*(n+1)*(n+1)%4==0:
        print(((n*(n+1)*(n+1))//4)%998244353)
    else:
        x=n*(n+1)*(n+1)
        x=x//2
        print((x*499122177)%998244353)
        
