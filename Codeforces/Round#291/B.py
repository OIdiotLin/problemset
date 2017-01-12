N,x,y=map(int,raw_input().split())
S=set()
for i in range(N):
	a,b=map(int,raw_input().split())
	S.add(float(b-y)/(a-x) if a!=x else float('inf'))
print len(S)