#include<bits/stdc++.h>
using namespace std;
int book[505];
int city[505][505];
int n,m;
void dfs(int s){
    for (int i = 0; i < n; i++)
    {
        if(book[i]==0&&city[s][i]==1){
            book[i]=1;
            dfs(i);
        }    
    }
}
int calcu(){
    int cnt=0;
    memset(book,0,sizeof(book));
    for (int i = 0; i < n; i++)
    {
        if(book[i]==0){
            book[i]=1;
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int cnt=0;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;cin>>a>>b;
        city[a][b]=1;
        city[b][a]=1;
    }
    cnt=calcu();
    int k;cin>>k;
    for (int i = 0; i < k; i++)
    {
        int a;cin>>a;
        for (int j = 0; j < n; j++)
        {
            if(city[a][j]==1)
            {city[a][j]=0;
            city[j][a]=0;}
        }
        int cal=calcu();
        if(cal>cnt+1){
            cout<<"Red Alert: City "<<a<<" is lost!"<<endl;
        }else cout<<"City "<<a<<" is lost."<<endl;
        cnt=cal;
        if(i==n-1) cout<<"Game Over."<<endl;
    }
    return 0;
}