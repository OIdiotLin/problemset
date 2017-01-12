from math import sin
pi=3.1415926535
v,a,k=(float(i) for i in raw_input().split())
ans=v*v*sin(a*pi/90.0)/10*k/(k-1)
print '%.2f' % ans