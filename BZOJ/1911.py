N=input()

Q=range(0,10000000)
s=range(0,10000000)
f=range(0,10000000)
data=range(0,10000000)

def g(x,y):
	return (float)((f[y]+A*s[y]*s[y]-B*s[y])-(f[x]+A*s[x]*s[x]-B*s[x]))/(s[y]-s[x])

A,B,C=(long(i) for i in raw_input().split())
