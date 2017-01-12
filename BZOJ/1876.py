def gcd(x,y):
	return gcd(y,x%y) if y!=0 else x
x=input()
y=input()
print gcd(x,y)