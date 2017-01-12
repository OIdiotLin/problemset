#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("djsa.in");
	ofstream fout("djsa.out");
	int n[100][100]={0},a,b,c,city,road,temp[100]={0},school;
	int i,k,leng[100][100],j,max=9000000;
	fin>>city>>road;
	for(k=0;k<city;k++){
	for(i=0;i<city;i++){
		leng[k][i]=max;
	}
	}
	for(i=1;i<=road;i++){
		fin>>a>>b>>c;
		n[a][b]=c;
		n[b][a]=c;
		leng[a][b]=c;
		leng[b][a]=c;
	}
	 
	for(k=0;k<city;k++){
		for(i=0;i<city;i++){
			for(j=0;j<city;j++){
				if(leng[i][k]+leng[k][j]<leng[i][j]){
					leng[i][j]=leng[i][k]+leng[k][j];
				}
			}
		}
	}
	for(k=0;k<city;k++) leng[k][k]=0;
	for(i=0;i<city;i++){
		temp[i]=leng[0][i];
		for(j=1;j<city;j++){
			temp[i]=(leng[j][i]>temp[i])?leng[j][i]:temp[i];
		}
	}
	school=0;
	for(i=1;i<city;i++) if(temp[i]<temp[school]) school=i;
	fout<<school<<endl;
	fin.close();
	fout.close();
	return 0;
}
