#include<bits/stdc++.h>
using namespace std;
const int N=505;const int INF=0x3f3f3f3f;
int edge[N][N];
char sex[N];
int main()
{
    int n;cin>>n;
    memset(edge,0x3f,sizeof(edge));

    for (int i = 1; i <= n; i++)
    {
        char c[2];int m;scanf("%s%d",c,&m);
        sex[i]=c[0];
        while(m--){
            int a,b;
            scanf("%d:%d",&a,&b);
            edge[i][a]=b;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
            }
        }
    }
    for(auto it:string("FM"))
    {
        int mn=INF;bool is_first=true;
        for (int i = 1; i <= n; i++)
        {
            int t=0;
            if(sex[i]==it){
                for (int j = 1; j <= n; j++)
                {
                    if(sex[j]!=it)
                        t=max(t,edge[j][i]);
                }
                mn=min(mn,t);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int t=0;
            if(sex[i]==it){
                for (int j = 1; j <= n; j++)
                {
                    if(sex[j]!=it)
                        t=max(t,edge[j][i]);
                }
                if(t == mn){
                    if(is_first){cout<<i;is_first=false;}
                    else cout<<' '<<i;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}