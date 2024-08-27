#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
// const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vector<PII>v1(m1+1);
    vector<PII>v2(m2+1);
    for(int i=1;i<=m1;i++){
        int a,b;cin>>a>>b;
        v1[i]={b,a};
        v1[i].first+=v1[i-1].first;
    }
    for(int i=1;i<=m2;i++){
        int a,b;cin>>a>>b;
        v2[i]={b,a};        
        v2[i].first+=v2[i-1].first;
    }
    if(n==1){
        if(v1[1].second!=v2[1].second){
            cout<<1<<endl;
        }else cout<<0<<endl;
        return;
    }
    int j=1;
    int pos=1;
    int ans=0;
    for(int i=1;i<=m1&&j<=m2;){
        // cout<<i<<' '<<j<<' '<<pos<<' '<<ans<<endl;
        if(v1[i].second==v2[j].second){
            if(v1[i].first>v2[j].first){
                pos=v2[j].first+1;
                j++;
                if(v2[j].second!=v1[i].second){
                    ans++;
                }
            }else if(v1[i].first<v2[j].first){
                pos=v1[i].first+1;
                i++;
                if(v2[j].second!=v1[i].second){
                    ans++;
                }
            }else{
                pos=v1[i].first+1;
                if(v2[j+1].second==v1[i+1].second){
                    ans++;
                }
                i++;j++;
            }
        }else{
            if(v1[i].first>v2[j].first){
                ans+=v2[j].first-pos;
                pos=v2[j].first+1;
                j++;
                if(v2[j].second==v1[i].second){
                    ans++;
                }
            }else if(v1[i].first<v2[j].first){
                ans+=v1[i].first-pos;
                pos=v1[i].first+1;
                i++;
                if(v2[j].second==v1[i].second){
                    ans++;
                }
            }else{
                ans+=v1[i].first-pos;
                pos=v1[i].first+1;
                i++,j++;
                if(v1[i].second==v2[j-1].second&&v2[j].second==v1[i-1].second){
                    ans++;
                }
            }
        }
        while(i<=m1&&pos>v1[i].first)i++;
        while(j<=m2&&pos>v2[j].first)j++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}