#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int m;cin>>m;
    vector<PII>v;
    vector<int>id(m+1);
    int c[2]={0};
    for(int i=0;i<m;i++){
        string s;cin>>s;
        int a;cin>>a;
        v.push_back({a,i});
        if(s=="-")id[i]=0,c[0]++;
        else id[i]=1,c[1]++;
    }
    sort(all(v),[&](PII a,PII b){
        if(a.x==b.x){
            return id[a.y]<id[b.y];
        }
        return a.x<b.x;
    });
    // cout<<c[0]<<' '<<c[1]<<endl;
    // for(auto [i,j]:v)cout<<i<<' '<<j<<endl;
    //     cout<<endl;
    double ans=0;
    double l=1.0;
    double pre=1.0;
    int n[2]={0};
    for(int i=0;i<v.size();i++){
        if(id[v[i].y]==0){
            ans+=1.0*(l-1.0*(c[0]-n[0])/c[0])*1.0*pre;
            // cout<<i<<' '<<ans<<' '<<l<<' '<<1.0*(c[0]-n[0])/c[0]<<' '<<pre<<' '<<n[0]<<' '<<n[1]<<endl;
            l=1.0*(c[0]-n[0])/c[0];
            n[0]++;
            while(i+1<v.size()&&v[i+1].x==v[i].x){
                n[id[v[i+1].y]]++;
                i++;
            }
            pre=1.0*(c[1]-n[1])/c[1];
        }else{
            n[1]++;
            // pre=1.0*(c[1]-n[1])/c[1];
        }
        if(n[0]==c[0]){
            ans+=1.0*(l-1.0*(c[0]-n[0])/c[0])*1.0*pre;
            // cout<<i<<' '<<ans<<' '<<l<<' '<<1.0*(c[0]-n[0])/c[0]<<' '<<pre<<' '<<n[0]<<' '<<n[1]<<endl;
            break;
        }
    }
    printf("%.12lf",ans);
    // cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}