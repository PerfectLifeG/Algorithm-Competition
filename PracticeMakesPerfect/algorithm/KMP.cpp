#include<bits/stdc++.h>
using namespace std;
char s[1000001],p[1000001];
int f[1000002],nxt[1000002];
void kmp(){
    int n=strlen(s+1);
    int m=strlen(p+1);
    nxt[0]=0;nxt[1]=0;
    int j=1;
    for (int i = 2; i <= m; i++)
    {
        while(j>1&&p[i]!=p[j])j=nxt[j-1]+1;
        if(p[i]==p[j])nxt[i]=j;// i、j同步了
        else nxt[i]=j-1;
    }

    j=1;
    for (int i = 1; i <= n; i++)
    {
        while (j>1&&s[i]!=p[j])j=nxt[j-1]+1;
        if(s[i]==p[j])f[i]=j;
        else f[i]=j-1;
    }
    
}
int main()
{
    scanf("%s\n%s",s+1,p+1);
    return 0;
}