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
const int INF=0x3f3f3f3f;
vector<int> divs[N];
void solve(){
    int n;cin>>n;vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(auto i:divs[n]){
        int d=0;
        for(int j=0;j<i;j++){
            if(d==1)break;
            for(int k=1;k<n/i;k++){
                if(d==1)break;
                // if(!d)d=abs(a[j+k*i]-a[j+(k-1)*i]);
                d=__gcd(abs(a[j+k*i]-a[j+(k-1)*i]),d);
            }
        }
        if(d!=1)ans++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
        }
    }
    for(int i=1;i<N;i++){
        divs[i].push_back(1);
    }
    while(_--)solve();
    return 0;
}