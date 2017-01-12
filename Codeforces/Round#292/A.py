x,y,s=map(abs,map(int,raw_input().split()))
if x+y<=s and ((x+y)&1)==(s&1):
    print 'YES'
else:
    print 'NO'
