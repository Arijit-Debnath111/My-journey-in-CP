t=int(input())
while(t!=0):
    n=int(input())
    s=0
    x=n
    while(x>=10):
        x=x//10
    s=x+n%10
    print(s)
    t-=1
