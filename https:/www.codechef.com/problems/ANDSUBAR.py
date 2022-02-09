t=int(input())
for i in range(t):
    n = int(input())
    if n == 1:
        print(n)
    else:
        i = 0
        while 2**i <= n:
            i = i + 1
        a = n - 2**(i-1) + 1
        b = 2**(i-1) - 2**(i-2)
        print(max(a,b))
        
