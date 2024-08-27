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
void solve(){
    int n,x,k;cin>>n>>x>>k;
    int sum=n*x;
    int left=0;
    vector<int>ans;
    do{
        // if(left){
            int t=max(k-left,0ll);
            if(sum<k){
                break;
            }
            int p=ceil(1.0*t/x);
            ans.push_back(p);
            sum-=k;
            left+=p*x-k;
            // cout<<sum<<' '<<left<<' '<<p<<' '<<endl;
        // }else{
        //     int t=max(k-left,0ll);
        //     if(sum<t){
        //         break;
        //     }
        //     int p=ceil(1.0*t/x);
        //     ans.push_back(p);
        //     sum-=p*x;
        //     left+=p*x-k;
        // }
    }while(1);
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}