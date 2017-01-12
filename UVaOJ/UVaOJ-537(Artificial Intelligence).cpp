/*
	Name: Artificial Intelligence?
	Copyright: UVaOJ-537
	Author: LHD
	Date: 20/11/13 19:48
	Description:物理老师提问，根据 P=IU 这个公式计算并回答。
				提问会告诉你公式中的任意两个元素的值，求出第三个元素的值。
				因此，提问语句中含有两个 DataField，DataField的格式如下：
				DataField ::= Concept '=' RealNumber [Prefix] Unit
				Concept   ::= 'P' | 'U' | 'I'
				Prefix    ::= 'm' | 'k' | 'M'
				Unit      ::= 'W' | 'V' | 'A'
				其中，Prefix可为 m (milli) 、k (kilo) 或 M (Mega) 。
				并且题目的输入保证如下三点：
					“=”在提问语句里，只出现在DataField中。
					DataField中不出现多余空格。
					题目保证三个元素中有且只有给出两个元素的值。
	Analysis: 找到提问语句中的“=”，以“=”为基准，因为所有的物理量都是伴随“=”定义的。处理输入数据以后就可以直接代入公式计算。
			  要注意输出格式，切记！ 
*/
#include<stdio.h>
#include<math.h>
char question[1000];
int main()
{
    freopen("537.in","r",stdin);
	int CaseNumber,count=0;
    scanf("%d",&CaseNumber);
    getchar();
    while(CaseNumber--)
    {
		fgets(question,sizeof(question),stdin);
        printf("Problem #%d\n",++count);
        int i,j,w=0;
        double Number,U=0,I=0,P=0;
        for(i=0;question[i]!='\0';i++)
        {
            Number=0;
            if(question[i]=='=')
            {
                int symbol=0;
                for(j=i+1;question[j]!='V'&&question[j]!='A'&&question[j]!='W';j++)
                {
                    if(question[j]=='M')
						Number*=1000000;					//单位转换 
                    else if(question[j]=='k')
						Number*=1000;
                    else if(question[j]=='m')
						Number*=0.001;
                    else if(question[j]=='.')
						symbol=j;
                    else
                    {
                        if(symbol==0)
                            Number=Number*10+question[j]-'0';
                        else
                            Number+=(question[j]-'0')*(pow(10,(symbol-j)));
                    }
                }
                if(question[j]=='V') U=Number;
                else if(question[j]=='A') I=Number;
                else P=Number;
                if(w==0)
                {
                    w=1;
                    i=j;
                }
                else break;
            }
        }
        if(U==0)
            printf("U=%.2lfV\n\n",P/I);
        else if(P==0)
            printf("P=%.2lfW\n\n",I*U);
        else if(I==0)
            printf("I=%.2lfA\n\n",P/U);
    }
    return 0;
}
