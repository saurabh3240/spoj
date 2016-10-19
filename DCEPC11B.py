def modp(n,p,m):
    test=1;
    x = n;
    while(p>0):
        if(p&1>0):
            test = ((test%m)*(n%m))%m;
        n = ((n%m)*(n%m))%m;
        p>>=1
    return test

t = int(input())
for x in range(t):
    n,p = map(int,raw_input().split())
    if(p<=n):
        print 0;
    else:
        ans = p-1;
        i = p-1;
        while(i>n):
            ans*=modp(i,p-2,p);
            ans%=p;
            i-=1
        print ans;
