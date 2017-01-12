/*
	Name: Artificial Intelligence?
	Copyright: UVaOJ-537
	Author: LHD
	Date: 20/11/13 19:48
	Description:������ʦ���ʣ����� P=IU �����ʽ���㲢�ش�
				���ʻ�����㹫ʽ�е���������Ԫ�ص�ֵ�����������Ԫ�ص�ֵ��
				��ˣ���������к������� DataField��DataField�ĸ�ʽ���£�
				DataField ::= Concept '=' RealNumber [Prefix] Unit
				Concept   ::= 'P' | 'U' | 'I'
				Prefix    ::= 'm' | 'k' | 'M'
				Unit      ::= 'W' | 'V' | 'A'
				���У�Prefix��Ϊ m (milli) ��k (kilo) �� M (Mega) ��
				������Ŀ�����뱣֤�������㣺
					��=������������ֻ������DataField�С�
					DataField�в����ֶ���ո�
					��Ŀ��֤����Ԫ��������ֻ�и�������Ԫ�ص�ֵ��
	Analysis: �ҵ���������еġ�=�����ԡ�=��Ϊ��׼����Ϊ���е����������ǰ��桰=������ġ��������������Ժ�Ϳ���ֱ�Ӵ��빫ʽ���㡣
			  Ҫע�������ʽ���мǣ� 
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
						Number*=1000000;					//��λת�� 
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
