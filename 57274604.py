def chef(n):
    m=int(n[:2]+n[3:5])
    if 'PM' in n and m<1200:
        m=m+1200
    if 'AM' in n and m>=1200:
        m=m-1200
    return m

for x in range(int(input())):
    n=chef(input())
    add=""
    for i in range(int(input())):
        r=(input())
        l=chef(r[:8])
        f=chef(r[9:])
        if l<=n<=f:
            add+='1'
        else:
            add+='0'
    print(add)

