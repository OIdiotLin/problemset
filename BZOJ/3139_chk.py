from subprocess import call
n=input('Check Times : ')
for i in xrange(n):
	call ('3139_make')
	call ('3139')
	call ('3139_c')
	if call (['fc','3139.ans','3139.out']):
		print str(i+1)+' WA'
		break
	print str(i+1)+' AC'