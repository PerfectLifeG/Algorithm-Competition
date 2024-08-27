#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int scan()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
    return x*f;
}
unordered_map<int,int>mp;
// int dfs(int n,int cnt){
//     // cout<<n<<endl;
//     if(mp.count(n)&&mp[n]<=cnt){
//         return 0;
//     }
//     mp[n]=cnt;
//     if(n==1)return 1;
//     int flag=0;
//     if(!(n%3)){if(dfs(n/3,cnt+1))return 1;flag=1;}
//     if(!(n%2)){if(dfs(n/2,cnt+1))return 1;flag=1;}
//     // if(!flag){
//     dfs(n-1,cnt+1);
//     // }
//     return 0;
// }
// int cnt=0;
unordered_map<int,int>mp2;
int bfs(int n){
    queue<PII>q;
    q.push({n,0});
    mp.clear();
    while(q.size()){
        auto t=q.front();
        q.pop();
        // cout<<t.x<<' '<<t.y<<endl;
        if(t.x==1){
            return t.y;
        }
        // if(t.x%2==0){
        //     if(t.x%3==0&&(!mp.count(t.x/3)||mp[t.x/3]>t.y+1)){q.push({t.x/3,t.y+1});mp[t.x/3]=t.y+1;mp2[t.x/3]=t.x;}
        //     else if(t.x%2==0&&(!mp.count(t.x/2)||mp[t.x/2]>t.y+1)){q.push({t.x/2,t.y+1});mp[t.x/2]=t.y+1;mp2[t.x/2]=t.x;}
        //     if(!mp.count(t.x-1)||mp[t.x-1]>t.y+1){q.push({t.x-1,t.y+1});mp[t.x-1]=t.y+1;mp2[t.x-1]=t.x;}
        //     continue;
        // }
        if(!mp.count(t.x-1)||mp[t.x-1]>t.y+1){q.push({t.x-1,t.y+1});mp[t.x-1]=t.y+1;mp2[t.x-1]=t.x;}
        if(t.x%2==0&&(!mp.count(t.x/2)||mp[t.x/2]>t.y+1)){q.push({t.x/2,t.y+1});mp[t.x/2]=t.y+1;mp2[t.x/2]=t.x;}
        if(t.x%3==0&&(!mp.count(t.x/3)||mp[t.x/3]>t.y+1)){q.push({t.x/3,t.y+1});mp[t.x/3]=t.y+1;mp2[t.x/3]=t.x;}
    }
}   
void solve()
{
    int n;cin>>n;
    cout<<endl;
    cout<<bfs(n)<<endl;
    cout<<mp.size()<<endl;
    int t=1;
    while(t<n){
        cout<<t<<endl;
        t=mp2[t];
    }
    cout<<n<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}