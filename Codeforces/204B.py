N = int(raw_input())
lim = (N+1)/2
ans = lim + 929
cntFore = {}
cntBack = {}
color = set()

for i in range(N):
	f,b = map(int,raw_input().split())
	color.add(f), color.add(b)
	cntFore[f] = cntFore.get(f,0) + 1
	if f==b: continue
	cntBack[b] = cntBack.get(b,0) + 1
for c in color:
	upwardsAmount = cntFore.get(c,0) + cntBack.get(c,0)
	if upwardsAmount >= lim:
		ans = min(ans, lim - cntFore.get(c,0))
if ans < 0:
	ans = 0
if ans > lim:
	ans = -1
print ans