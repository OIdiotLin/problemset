#include<stdio.h>
#include<string.h>

void fun(char* str)
{
    char uknum;
    for(int i=0; i<(int)strlen(str); i++)
        if(str[i]>='a' &&str[i]<='z')
		{
            uknum=str[i];
            break;
        }
    int equalpos=0;
    for(int i=0; i<(int)strlen(str); i++)
        if(str[i]=='=') equalpos=i;
    int co=0;
    for(int i=0; i<(int)strlen(str); i++)
	{
        int tmpco=0;
        if(str[i]>='a' &&str[i]<='z')
		{
            if(i<equalpos)
			{
                if(i==0 || str[i-1]=='+')tmpco=1;
                else
				{
                    if(str[i-1] == '-')tmpco=-1;
                    else
					{
                        char* tmp=str+i-1;
                        while(*tmp!='+' && *tmp!='-' && tmp > str)tmp--;
                        if(*tmp == '-')
						{
                            tmp++;
                            while(tmp < str+i)
							{
                                tmpco=tmpco*10+*tmp-48;
                                tmp++;
                            }
                            tmpco=0-tmpco;
                        }
						else
						{
                            if(*tmp == '+')
							{
                                tmp++;
                                while(tmp < str+i)
								{
                                    tmpco=tmpco*10+*tmp-48;
                                    tmp++;
                                }
                            }
							else
							{
                                while(tmp < str+i)
								{
                                    tmpco=tmpco*10+*tmp-48;
                                    tmp++;
                                }
                            }
                        }
                    }
                }
            }
            else
			{
                if(str[i-1]=='+' || str[i-1]=='=')tmpco=-1;
                else
				{
                    if(str[i-1] == '-')tmpco=1;
                    else
					{
                        char* tmp=str+i-1;
                        while(*tmp!='+' && *tmp!='-' && *tmp!='=')
							tmp--;
                        if(*tmp == '-')
						{
                            tmp++;
                            while(tmp < str+i)
							{
                                tmpco=tmpco*10+*tmp-48;
                                tmp++;
                            }
                        }else{
                            if(*tmp == '+')
							{
                                tmp++;
                                while(tmp < str+i)
								{
                                    tmpco=tmpco*10+*tmp-48;
                                    tmp++;
                                }
                                tmpco=0-tmpco;
                            }
							else
							{
                                tmp++;
                                while(tmp < str+i)
								{
                                    tmpco=tmpco*10+*tmp-48;
                                    tmp++;
                                }
                                tmpco=0-tmpco;
                            }
                        }
                    }
                }
            }
        }
        co+=tmpco;
    }
    int coint=0;
    for(int i=0; i<(int)strlen(str); i++)
	{
        int tmpcoint=0;
        if(str[i]>='0' && str[i]<='9')
		{
            if(i<equalpos)
			{
                char* tmpint=str+i;
                while(*tmpint>='0'&&*tmpint<='9')
				{
                    tmpcoint=tmpcoint*10+*tmpint-48;
                    tmpint++;
                }
                if(*tmpint==uknum)
				{
                    i=tmpint-str;
                    continue;
                }
                else
				{
                    if(i==0 || str[i-1]=='+')
					{
						coint-=tmpcoint;
						i=tmpint-str;
					}
                    else
					{
                        coint+=tmpcoint;
                        i=tmpint-str;
                    }
                }
            }
            else
			{
                char* tmpint=str+i;
                while(*tmpint>='0'&&*tmpint<='9')
				{
                    tmpcoint=tmpcoint*10+*tmpint-48;
                    tmpint++;
                }
                if(*tmpint==uknum)
				{
                    i=tmpint-str;
                    continue;
                }
                else{
                    if(str[i-1]=='=' ||str[i-1]=='+')
					{
						coint+=tmpcoint;
						i=tmpint-str;
					}
                    else
					{
                        coint-=tmpcoint;
                        i=tmpint-str;
                    }
                }
            }
        }
    }
    //cout<<uknum<<"="<<fixed<<setprecision(3)<<double(coint)/double(co)<<endl;
	printf("%c=%.3lf",uknum,coint/co);
}
int main()
{
	char str[1000];
    gets(str);
    fun(str);
    return 0;
}
