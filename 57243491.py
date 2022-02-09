t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    Fmax=Smax=count=0
    for i in range(n):
        if(a[i]==1):
            if(count!=0):
                if(count>Fmax):
                    Smax=Fmax
                    Fmax=count
                elif(count>Smax):
                    Smax=count
                count=0
        else :
            count=count+1
    if(Fmax%2!=0 and Smax<(Fmax+1)//2):
        print("Yes")
    else : 
        print("No")