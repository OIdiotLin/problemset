/*
	Name: Automatic Editing
	Copyright: UVaOJ-10115
	Author: LHD
	Date: 20/11/13 15:27
	Description:���һ���Զ��༭������
				�ù���Ҫ��һЩ��������滻������
				����ÿ������Ҫ��ͣ�����ַ������ҵ��ؼ��ʽ����滻��
				ֱ���ؼ��ʲ��ٳ������ַ�����Ϊֹ��
				Ҫ��������й�����滻��������������ַ�����
				��Ҫ��������string����:
				strlen():��ȡ���� 
				strcmp():�Ƚ��ַ��������ж��滻ʱ������ 
				strcpy()&memcpy():����
				strcat():�ַ������� 
				strstr():�ַ�������  
				������Ƕ�ά�ַ��������ã���Ҫ�����ϰ������֮�� 
*/
#include<stdio.h>
#include<string.h>
char keyWords[50][100],input[50][100],replaced[300],temp[1000];
int main()
{
	freopen("autoedit.in","r",stdin);
	//freopen("autoedit.out","w",stdout); 
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        getchar();
        int i;
        for(i=0;i<n;i++)
        {
            gets(keyWords[i]);
            gets(input[i]);
        }
        gets(replaced);
        for(i=0;i<n;i++)
        {
            char *p,*q;
            while(p=strstr(replaced,keyWords[i]),p!=NULL)	//�ַ������ң��ҵ��ؼ��ִ���ʱ�򷵻�ָ��p 
            {
                q=p+strlen(keyWords[i]);
                strcpy(temp,input[i]);
                strcat(temp,q);								//�ַ������Ӻ����� 
                strcpy(p,temp);
            }
        }
        puts(replaced);
    }
    return 0;
}
