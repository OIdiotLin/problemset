import os
N=input("N=")
for i in range(1,N) :
  print(i)
  os.system("1816_makedata")
  os.system("1816_c")
  os.system("1816")
  os.system("fc 1816.ans 1816.out  || pause")
