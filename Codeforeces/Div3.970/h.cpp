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
    int n,q;cin>>n>>q;
    vector<int>a(n+1);
    vector<int>ans(n+1);
    vector<int>pre(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
    }
    for(int i=1;i<=n;i++){
        int l=-1,r=i;
        while(l+1!=r){
            int mid=l+r>>1;
            int sum=0;
            for(int j=0;j<=n;j+=i){
                int x=pre[min(n,j+mid)];
                if(j)x-=pre[j-1];
                sum+=x;
            }
            if(sum>=(n+2)/2)r=mid;
            else l=mid;
        }
        ans[i]=r;
    }


    while(q--){
        int x;cin>>x;
        cout<<ans[x]<<' ';
    }cout<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}