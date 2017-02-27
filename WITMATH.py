z = []
for x in range(100000):
    z.append(1);
z[0] = 0;
z[1] = 0;
prime=[]
 
 
i = 2
while(i<100000):
    if(z[i]==1):
        prime.append(i)
        j = i+i
        while(j<100000):
            z[j]=0;
            j = j+i;
    i+=1;
t = int(input()) 
for x in range(t):
    n = int(input())
    a = 1
    b = 1
    i = 0;
    while(a<=n):
        b = a
        #print b
        a = a*prime[i]
        i+=1;
    print b
