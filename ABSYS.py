t = int(input())
while(t>0):
    s = raw_input()
    if(len(s)==0):
        continue
    a,b,c,d,e =s.split()
    if(a.find('m')>=0):
        print str(int(e)-int(c))+" + "+c + " = "+ e
    elif(c.find('m')>=0):
        print a+" + "+str(int(e)-int(a)) + " = "+ e
    else:
        print a+" + "+c + " = "+ str(int(a)+int(c))
    t-=1
    
