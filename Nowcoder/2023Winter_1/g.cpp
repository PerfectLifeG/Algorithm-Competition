#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=1e18;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    set<int>q={INF};
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        q.insert(i);
    }
    while(m--){
        int op;cin>>op;
        if(op==2)cout<<sum<<endl;
        else{
            int l,r,k;cin>>l>>r>>k;
            auto t=q.lower_bound(l);
            for(;*t!=INF&&*t<=r;){
                sum-=a[*t];
                int flag=1;
                for(int j=0;j<k;j++){
                    int b=round(10*sqrt(a[*t]));
                    if(a[*t]==b){
                        sum+=b;
                        t=q.erase(t);
                        flag=0;
                        break;
                    }
                    a[*t]=b;
                }
                if(flag){
                    sum+=a[*t];
                    t++;
                }
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}