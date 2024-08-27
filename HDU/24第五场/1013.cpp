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
const int INF=0x3f3f3f3f3f3f3f3f;

mt19937 rd(time(0));
void solve(){
    int n;
    for(int n=1;n<=20;n++){
        double t=0;
        for(int k=0;k<100000;k++){
            int now=0;
            int ans=0;
            while(1){
                int x=rd()%n+1;
                ans++;
                if(x==n){
                    now+=x;
                    if(now==n){
                        t+=ans;
                        // cout<<n<<' '<<ans<<endl;
                        break;
                    }else if(now>n){
                        now=n-(now-n);
                    }
                    x=rd()%(n-1)+1;
                }
                if(now==n)break;
            }
        }
        cout<<n<<' '<<t/100000<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}