def extGCD(a, b):
	if b == 0:	return (1, 0, a)
	(x, y, r) = extGCD(b, a%b)
	tmp = x
	x = y
	y = tmp - (a/b)*y
	return (x, y, r)