N=input()
ans=0
x=0
y=0

for i in range(1,N+1):
    x=input()
    if i>1:
        ans+=max(y,x)
    y=x
print ans
