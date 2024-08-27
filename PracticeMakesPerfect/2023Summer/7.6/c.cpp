#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int n,m;
int i,j,k;
int t[N][2],tot=0;
int minn,maxx;
int ans[2];
int a[N];
void insert(int x)
{
    int res=30;
    int rt=0;
    while(res!=-1){
        int id=(x&(1<<res))?1:0;
        if(!t[rt][id]) t[rt][id]=++tot;
        rt=t[rt][id];
        res--;
    }
}
void find(int x)
{
    int res=30;
    int rt[2]={0,0};
    ans[0]=ans[1]=0;
    while(res!=-1){
        int id=(x&(1<<res))?1:0;
        if(t[rt[0]][id]) rt[0]=t[rt[0]][id];
        else{
            rt[0]=t[rt[0]][id^1];
            ans[0]^=(1<<res);
        }
        if(t[rt[1]][id^1]){
            rt[1]=t[rt[1]][id^1];
            ans[1]^=(1<<res);
        }
        else rt[1]=t[rt[1]][id];
        res--;
    }
}
void solve()
{
    int num=0;
    cin>>n;
    minn=1e9,maxx=0;
    insert(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
        find(a[i]);
        minn=min(minn,ans[0]);
        maxx=max(maxx,ans[1]);
        insert(a[i]);
    }
    cout<<maxx<<endl;
    for(int i=0;i<=tot;i++) t[i][0]=t[i][1]=0;
    tot=0;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}