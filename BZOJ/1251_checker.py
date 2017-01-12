from subprocess import call
Lim=input('Check times: ')

for i in range(1,Lim+1):
	call('./1251_make.exe')
	call('./1251.exe')
	call('./1251_cc.exe')
	if call(['diff','1251.out','1251.ans']):
		print str(i)+ ' Wrong Answer'
		break
	else:
		print str(i)+ ' Accepted'