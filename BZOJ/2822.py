f=[]
f.append(1)
f.append(1)
for i in range(2,501):
    f.append(f[i-1]*(4*i-2)/(i+1))
n=input()
print f[n]
