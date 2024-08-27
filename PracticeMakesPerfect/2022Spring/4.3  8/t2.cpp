#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int f=0;int t;
    char a[1000];int s=0;
    while (scanf("%s",a)!=EOF)
    {
        if(f==3)s--;
        int i=0;int flag=0;f=0;
        while (a[i]!='\0')
        {
            
            if(a[i]>='0'&&a[i]<='9') {f=1;break;}
            if(a[i]=='!'||a[i]==','||a[i]=='.')if(a[i+1]=='\0'&&f==0){s++;f=3;}
            if(a[i]=='-'){flag++;t=i;}
            
            i++;
        }
        if(f==0)s++;
        if(flag==1&&f==0)
            {if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')
            s++;f=2;}
    }
    cout<<s;
}