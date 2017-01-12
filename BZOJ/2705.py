N=input()
 
Ans=0
 
def Calc(x):
    ret=x
    i=2
    while i*i<=x:
        if x%i==0:
            ret=ret/i*(i-1)
            while x%i==0:
                x=x/i
        i=i+1
    if x!=1:
        ret=ret/x*(x-1)
    return ret
         
i=1
while(i*i<=N):
    if N%i==0:
        Ans=Ans+i*Calc(N/i);
        if i*i!=N:
            Ans=Ans+N/i*Calc(i)
    i=i+1
print Ans
