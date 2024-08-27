#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
int book[N];//差值
int book2[N];//坐标
int book3[N];//第二
int n,m;
void solve()
{
    cin>>n>>m;
    for(int i=0;i<=m;i++){book[i]=0;book2[i]=0;book3[i]=0;}
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        if(!book2[a[i]]){
            book[a[i]]=i-1;
            book2[a[i]]=i;
        }else{
            if(i-book2[a[i]]-1>=book[a[i]]){
                book3[a[i]]=book[a[i]];
                book[a[i]]=i-book2[a[i]]-1;
            }else{
                book3[a[i]]=max(book3[a[i]],i-book2[a[i]]-1);
            }
            book2[a[i]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(n-book2[i]>=book[i]){
            book3[i]=book[i];
            book[i]=n-book2[i];
        }else{
            book3[i]=max(book3[i],n-book2[i]);
        }
    }
    for(int i=1;i<=m;i++){
        if(!book2[i])continue;
        ans=min(ans,max(book[i]/2,book3[i]));
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}