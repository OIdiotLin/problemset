N,M=map(int,raw_input().split())

def gcd(x,y):
    return x if y==0 else gcd(y,x%y)

boy=[0]*N
girl=[0]*M
lim=N*M/gcd(N,M)

#print 'gcd(%d,%d)=%d'%(N,M,lim)

for i in map(int,raw_input().split())[1:]:
    boy[i]=1
for i in map(int,raw_input().split())[1:]:
    girl[i]=1
for i in xrange(1000000):
    boy[i%N]=girl[i%M]=max(boy[i%N],girl[i%M])
print 'Yes' if min(boy+girl)==1 else 'No'
