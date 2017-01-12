N=input()

def check(x):
    x=str(x)
    a=0
    b=0
    for i in range(0,3):
        a+=int(x[i])
        b+=int(x[3+i])
    return a==b

flag=False
for i in range(-1,2):
    if check(N+i):
        flag=True
if flag:print 'Yes'
else:   print 'No'
