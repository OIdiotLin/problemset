/*
http://acm.pku.edu.cn/JudgeOnline/problem?id=1179
?? + ??DP
????????,?????????????????DP,????
????????,????????min?max?????
(1)????
max[i][j] = max(max[i][j], max[i][k] + max[k+1][j]), i <= k < j
min[i][j] = min(min[i][j], min[i][k] + min[k+1][j]), i <= k < j
(2)????
max[i][j] = max(max[i][j], min[i][k] * min[k + 1][j], min[i][k] * max[k + 1][j],
max[i][k] * min[k + 1][j], max[i][k] * max[k + 1][j]), i <= k < j
min[i][j] = min(min[i][j], min[i][k] * min[k + 1][j], min[i][k] * max[k + 1][j],
max[i][k] * min[k + 1][j], max[i][k] * max[k + 1][j]), i <= k < j
????DP?????????????0,???????????
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxlen 51
#define maxnum 999999999
#define minnum -999999999
int operand[maxlen];//???
char operat[maxlen];//???
//resmax[i][j]i?j??????
int resmax[maxlen][maxlen];
//resmin[i][j]i?j??????
int resmin[maxlen][maxlen];
int ansmax;//????????
bool dedge[maxlen];//?????????
int n,i,j,k,steplen,deledge;
int tempmax,tempmin;
//???
void ini()
{
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if(i == j) 
				resmax[i][j] = resmin[i][j] = operand[i];
			else{
				resmax[i][j] = minnum;
				resmin[i][j] = maxnum;
			}
}
int main(){
	freopen("1.txt","r",stdin);
	cin>>n;
	for (i=0;i<n;i++)
		cin>>operat[i]>>operand[i];
	ansmax=minnum;
	//??????????
	for (deledge=0;deledge<n;deledge++)
	{
		ini();
		//????????
		for (steplen=2;steplen<=n;steplen++)
		{
			//???????????
			for (i=deledge;i<=n+deledge-steplen;i++)
			{
				//????????????
				j=i+steplen-1;
				//????K
				for (k=i;k<j;k++)
				{
					int kleftmax=resmax[i%n][k%n];
					int kleftmin=resmin[i%n][k%n];
					int krightmax=resmax[(k+1)%n][j%n];
					int krightmin=resmin[(k+1)%n][j%n];
					//?????????????????
					if(operat[(k+1)%n]=='t'){
						tempmax=kleftmax+krightmax;
						tempmin=kleftmin+krightmin;
					}
					else{
						tempmax=max(max(kleftmax*krightmax,kleftmin*krightmin),
							max(kleftmin*krightmax,kleftmax*krightmin));
						tempmin=min(min(kleftmax*krightmax,kleftmin*krightmin),
							min(kleftmin*krightmax,kleftmax*krightmin));
					}
					resmax[i%n][j%n]=max(resmax[i%n][j%n],tempmax);
					resmin[i%n][j%n]=min(resmin[i%n][j%n],tempmin);
				}
			}
		}
		//????????????,?????????
		if(resmax[deledge][(deledge+n-1)%n]>ansmax)
		{
			memset(dedge,0,sizeof(dedge));
			ansmax=resmax[deledge][(deledge-1+n)%n];
			dedge[deledge]=1;
		}else if(resmax[deledge][(deledge-1+n)%n]==ansmax)
			dedge[deledge]=1;
	}
	//????
	cout<<ansmax<<endl;
	for (i=0;i<n;i++)
		if(dedge[i]) cout<<i+1<<" ";
}

