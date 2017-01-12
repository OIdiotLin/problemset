#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
struct source
{
       char country[20];
       int tot;
       bool visited;
}sheet[2010];
 
int comp(void const *p,void const *q)
{
       return strcmp((*(source *)p).country,(*(source *)q).country);
}

int main()
{
	int N,i,j;
	char temp[90];
    cin>>N;
    getchar();
    for(i=0;i<N;i++)
    {
        gets(temp);
        int len=strlen(temp);
        	for(j=0;j<len;j++)
                if(temp[j]==' ')
					break;
        strncpy(sheet[i].country,temp,j); 
        sheet[i].tot=1;
		sheet[i].visited=false;   //��־Ϊδ��ȡ
    }
    for(i=0;i<N;i++)
    {
		if(!sheet[i].visited)
            for(j=i+1;j<N;j++)
            {
                if(!sheet[j].visited)	//���û�ж�ȡ 
                    if(!strcmp(sheet[i].country,sheet[j].country))
                    {
                        sheet[i].tot++; 
                        sheet[j].visited=true;  //���Ϊ�Ѷ�ȡ
                    }
            }
    }
    qsort(sheet,N,sizeof(sheet[0]),comp);
    for(i=0;i<N;i++)
		if(!sheet[i].visited)
			cout<<sheet[i].country<<" "<<sheet[i].tot<<endl;
	return 0;
}
