t=int(input())
for _ in range(t):
    n=int(input())
    count=0
    while n>0:
        r= n%10
        n= n//10
        if r==4:
            count+=1
    print(count)
