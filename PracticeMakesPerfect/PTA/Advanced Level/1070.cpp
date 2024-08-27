#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<double,double> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;double m;cin>>n>>m;
    vector<PII>v(n);
    for(int i=0;i<n;i++){
        double a;cin>>a;
        v[i].x=a;
    }
    for(int i=0;i<n;i++){
        double a;cin>>a;
        v[i].y=a;
    }
    sort(all(v),[&](PII a,PII b){
        if(1.0*a.y/a.x==1.0*b.y/b.x)return a.x>b.x;
        return 1.0*a.y/a.x>1.0*b.y/b.x;
    });
    double ans=0;
    for(int i=0;i<n;i++){
        if(v[i].x<m){
            ans+=v[i].y;
            m-=v[i].x;
        }else{
            ans+=(1.0*m/v[i].x)*v[i].y;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}