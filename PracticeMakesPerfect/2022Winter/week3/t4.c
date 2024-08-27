#include<stdio.h>     //第一行
int main()
{
    char a[1000]={'6','6','6','6'};
    static int i=3,zg,yg,zx,yx,zz,yz,zd,yd;
    while (a[i-3]!='\n'||a[i-2]!='.'||a[i-1]!='\n')       
    {
        a[i]=getchar();
        if (a[i-1]=='/'&&a[i]=='*')  zg++;
        if (a[i]=='(')  zx++;
        if (a[i]=='[')  zz++;
        if (a[i]=='{')  zd++;
        if (a[i-1]=='*'&&a[i]=='/')  yg++;
        if (a[i]==')')  yx++;
        if (a[i]==']')  yz++;
        if (a[i]=='}')  yd++;
        i++;
    }
    if(zg<yg)     printf("NO\n/*-?");
    else if(zg<yg)printf("NO\n/*-?");
    else if(zx<yx)printf("NO\n(-?");
    else if(zz<yz)printf("NO\n[-?");
    else if(zd<yd)printf("NO\n{-?");
    else if(zg>yg)printf("NO\n?-*/");
    else if(zx>yx)printf("NO\n?-)");
    else if(zz>yz)printf("NO\n?-]");
    else if(zd>yd)printf("NO\n?-}");
    else printf("YES");
    return 0;
