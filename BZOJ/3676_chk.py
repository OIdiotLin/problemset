from subprocess import call

n=input('times:')
for i in xrange(n):
	call ('3676_make')
	call ('3676')
	call ('3676_c')
	if call (['fc','3676.ans','3676.out']):
		print str(i+1) + ' WA'
		break
	print str(i+1) + ' AC'