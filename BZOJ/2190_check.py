import os
N=input("N=")
for i in range(1,N) :
  print(i)
  os.system("2190_makedata")
  os.system("2190_c")
  os.system("2190")
  os.system("fc 2190.ans 2190.out  || pause")
