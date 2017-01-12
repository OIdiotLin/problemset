#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1000000000;
int n,m;
int ans=INF;
/*
在除掉一�?�意义下的圆柱�?���
体积=R^2*H
侧面�?2RH
底面�?R^2
*/
/*
从下到上第x层是从上到下第m+1-x�
l至少是m+1-x,h至少是m+1-x
*/
int minv[99]={0},mins[99]={0};
void DFS(int x,int lr,int lh,int s,int v){
//当前计算第x层，上一层参数是lr,lh，当前面�?��s
cout<<v<<" "<<s<<" "<<lr<<" "<<lh<<" "<<x<<endl;
	if(v>n||(x<=m&&v==n)||s<0||v<0){
		return;
	}
	if(x==m+1){
		if(v==n&&s<ans){
			ans=s;
		}
		return;
	}
	int i,j,nows=0,nowv=0,leftv=n-v-minv[x+1];//i对r,j对h
	if(v+minv[x]>n||s+mins[x]>ans||2*(n-v)/lr+s>=ans) return;
	for(i=lr-1;i>=m+1-x&&i>0;i--){
		if(x==m){
			if((leftv%(i*i)==0)){
				j=leftv/(i*i);
				if(j>=lh) continue;
				nows=s+2*i*j;
				if(x==1) nows+=i*i;
				nowv=v+i*i*j;
				DFS(x+1,i,j,nows,nowv);
			}
			continue;
		}
		for(j=min(leftv/(i*i),lh-1);j>=m+1-x&&j>0;j--){
			nows=s+2*i*j;
			if(x==1) nows+=i*i;
			nowv=v+i*i*j;
			DFS(x+1,i,j,nows,nowv);
		}
	}
}

int main(){
	//freopen("cake.in","r",stdin);
	//freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;i++){
		minv[m+1-i]=minv[m+1-i+1]+i*i*i;
		mins[m+1-i]=mins[m+1-i+1]+2*i*i;
	}mins[1]+=m*m;
	for(int i=1;i<=m;i++)
	{
		cout<<minv[i]<<"\t"<<mins[i]<<endl;
	}
	
	DFS(1,n,n,0,0);
	if(ans==INF) printf("0\n");
	else printf("%d\n",ans);
	return 0;
}
