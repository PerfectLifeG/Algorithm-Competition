#include<stdio.h>
int main()
{
    char a[1000]={};int b[10]={},c;
    scanf("%s",&a);
    for (int i=0; a[i]!='\0';i++)
    {
        c=a[i]-'0';
        b[c]++;
    }

    for (int i = 0; i < 10; i++)
    {
        if(b[i]!=0)
            switch (i)
        {
        case 0:printf("0:%d\n",b[i]);break;
        case 1:printf("1:%d\n",b[i]);break;
        case 2:printf("2:%d\n",b[i]);break;
        case 3:printf("3:%d\n",b[i]);break;
        case 4:printf("4:%d\n",b[i]);break;
        case 5:printf("5:%d\n",b[i]);break;
        case 6:printf("6:%d\n",b[i]);break;
        case 7:printf("7:%d\n",b[i]);break;
        case 8:printf("8:%d\n",b[i]);break;  
        case 9:printf("9:%d\n",b[i]);break;  
        }
    }
    if(a==0)printf("0:1");
    
    return 0;
}