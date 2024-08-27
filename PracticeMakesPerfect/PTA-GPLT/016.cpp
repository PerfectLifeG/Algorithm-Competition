#include<bits/stdc++.h>
using namespace std;
struct node
{
    vector<int>v;//也可以是mom和dad
    int sex;
}e[100001];
int book[100001];
int flag;
void dfs(int start,int cnt){
    if(cnt>=4){return ;}
    int len=e[start].v.size();
    
    for (int i = 0; i < len; i++)
    {
        int s=e[start].v[i];
        if(book[s]==0){
            book[s]=1;
            dfs(s,cnt+1);
        }
        else {
            flag=1;//当在五代内遇到一个标记的，就说明近亲通婚
            return ;
        }
    }
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;char b;int c,d;
        cin>>a;getchar();
        b=getchar();
        cin>>c>>d;
        if(b=='F')e[a].sex=0;
        else e[a].sex=1;
        if(c!=-1)
        {e[a].v.push_back(c);
         e[c].sex=1;}
        if(d!=-1)
        {e[a].v.push_back(d);
         e[d].sex=0;}
    }
    int k;cin>>k;
    for (int i = 0; i < k; i++)
    {
        int a,b;cin>>a>>b;
        if(e[a].sex+e[b].sex==1){
            memset(book,0,sizeof(book));
            flag=0;
            dfs(a,0);
            dfs(b,0);
            if(flag==1)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }else cout<<"Never Mind"<<endl;
    }
    return 0;
}