from subprocess import call
T=input('Check Times : ')
for i in xrange(T):
	call ('3238_make')
	call ('3238_c')
	call ('3238')
	if call (['fc','3238.ans','3238.out']):
		print str(i+1) + ' Wrong Answer'
		break
	print str(i+1) + ' Accepted'