for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split()]
    m = 2*n
    s = list(set(arr))
    cmp = []
    if len(s)!=n:
        print(-1)
        continue
    arr.sort()
    mid = (n//2) -1 if n%2==0 else n//2
    s.sort()
    for i in range(mid):
        cmp.append(s[i])
        cmp.append(s[i])
    cmp.append(s[mid])
    cmp.append(s[mid])
    cmp.append(s[mid])
    for i in range(mid+1,n-1):
        cmp.append(s[i])
        cmp.append(s[i])
    cmp.append(s[n-1])
    
    flag =False
    for i in range(m):
        if cmp[i]!=arr[i]:
            flag = True
            break
    if flag==False:
        print(*s)
        
    else:
        print(-1)
        
        
        
        
            


    
    