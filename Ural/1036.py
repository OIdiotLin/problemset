f=[[0]*1001,[0]*1001]
N,M=(int(i) for i in raw_input().split())
def work():
    global N,M,f
    if(M&1):
        print str(0)
        return
    f[0][0]=1
    M=M>>1
    for i in range(1,N+1):
        for j in range(0,M+1):
            f[i&1][j]=0;
            for k in range(0,10):
                if j>=k:
                    f[i&1][j]=f[i&1][j]+f[(i-1)&1][j-k];
    print f[N&1][M]*f[N&1][M]

work()
