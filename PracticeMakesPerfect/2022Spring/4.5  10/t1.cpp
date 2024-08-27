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
#include<cstring>
using namespace std;
struct word
{
    char *p;
    int k;
};

int main()
{   
    int n;cin>>n;getchar();
    word w[11];
    for (int i = 0; i < n; i++)
    {   
        w[i].k=0;
        char *a=(char*)malloc(1000*sizeof(char));int j=0;
        while ((a[j]=getchar())!='\n')
        {
            if(a[j]==' ')w[i].k++;
            j++;
        }
        w[i].k++;
        w[i].p=a;
    }
    char mu[50];int pp=0;
    while ((mu[pp]=getchar())!='\n')pp++;
    mu[pp]='\0';
    for (int i = 0; i < n; i++)
    {
        if(strstr(w[i].p,mu))
        {   
            mu[pp]='.';mu[pp+1]='\0';
            char *p=strstr(w[i].p,mu);
            if(strcmp(p,mu)==0);
            {
                int j=0;int ji=0;
                while(ji<w[i].k-pp){
                    if(w[i].p[j]==' ')ji++;
                    if(ji==w[i].k-pp)w[i].p[j]='.';
                    printf("%c",w[i].p[j]);
                    j++;
                }
                printf("\n");
            }
        }else cout<<"No delete!"<<endl;
    }
    
    return 0;
}