#include <stdio.h>
int FF[5];
int i;
int judge(int inf[])
{
	int i=0;
	if(inf[i]<inf[i+1] && inf[i+1]<inf[i+2] && inf[i+2]<inf[i+3])
		return 1;			//Fish Rising
	else if(inf[i]==inf[i+1] && inf[i+1]==inf[i+2] && inf[i+2]==inf[i+3])
		return 2;			//Fish At Constant Depth
	else if(inf[i]>inf[i+1] && inf[i+1]>inf[i+2] && inf[i+2]>inf[i+3])
		return 3;			//Fish Diving
	return 0;
}
int main()
{
	for(i=0;i<4;i++)
		scanf("%d",&FF[i]);
	switch(judge(FF))
	{
		case 1:printf("Fish Rising");break;
		case 2:printf("Fish At Constant Depth");break;
		case 3:printf("Fish Diving");break;
		case 0:printf("No Fish");break;
	}
	return 0;
}
