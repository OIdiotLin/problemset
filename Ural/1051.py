N,M=(int(i) for i in raw_input().split())
if N==1 or M==1:
	print (N+M)>>1
elif N*M%3==0:
	print 2
else:
	print 1