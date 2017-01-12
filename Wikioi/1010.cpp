#include <stdio.h>
int n,m,x,y;
int F[20][20];
void input()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			F[i][j]=1;
	F[x][y]=0;
	F[x+2][y+1]=0;
	F[x+1][y+2]=0;
}
void limit()
{
	if(x>=1)
		F[x-1][y+2]=0;
	if(x>=2)
		F[x-2][y+1]=0;
	if(x>=2&&y>=1)
		F[x-2][y-1]=0;
	if(x>=1&&y>=2)
		F[x-1][y-2]=0;
	if(y>=2)
		F[x+1][y-2]=0;
	if(y>=1)
		F[x+2][y-1]=0;
}
void work()
{
	for(int i=0;i<=n;i++)
    {
		for(int j=0;j<=m;j++)
        {
			if(!F[i][j])
				continue;
			if(i==0 && j==0)
				continue;
			else if(i==0)
				F[i][j]=F[i][j-1];
			else if(j==0)
				F[i][j]=F[i-1][j];
			else 
				F[i][j]=F[i-1][j]+F[i][j-1];
        }
    }
}
int main()
{
	input();
	limit();
	work();
	printf("%d\n",F[n][m]);
	return 0;
}
