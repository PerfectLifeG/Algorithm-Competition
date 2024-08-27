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
    int n,x;cin>>n>>x;
    set<int>st;
    int ans=1;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(x%a==0){
            set<int>tmp;
            for(auto j:st){
                if(a*j==x){
                    ans++;
                    st.clear();
                    tmp.clear();
                    break;
                }
                if(x%(a*j)==0)tmp.insert(a*j);
            }
            tmp.insert(a);
            st.merge(tmp);
        }
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