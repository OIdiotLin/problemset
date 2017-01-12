import os
N=input("N=")
for i in range(1,N) :
  print(i)
  os.system("1207_makedata")
  os.system("1207_c")
  os.system("1207")
  os.system("fc pasture.out pasture.ans || pause")
