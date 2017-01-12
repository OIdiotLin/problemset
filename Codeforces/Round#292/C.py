N=input()
a=raw_input()
s=''
con=('','','2','3','322','5','53','7','7222','7332')

for i in range(0,N):
    s=s+con[int(a[i])]
tmp=list(s)
tmp.sort()
tmp.reverse()
s=''.join(tmp)
print s
