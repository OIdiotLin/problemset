N,M=(int(i) for i in raw_input().split())
A=[]
Ans=0
for i in range(N):
	A.append(input())
	
def check(x):
	s=0
	tmp=1
	for k in A:
		if s+k<=x:
			s=s+k
		else:
			s=k
			tmp=tmp+1
			if tmp>M or k>x:
				return False
	return True

l=1
r=1000000000
while l<=r:
	mid=(l+r)>>1
	if check(mid):
		Ans=mid
		r=mid-1
	else:
		l=mid+1
print Ans
