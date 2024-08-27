#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define lowbit(x) (x&-x)
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1000010;
const int mod=998244353;
const int INF=1e9;

int tr[N];
set<int>st={-INF,INF};
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a!=0)st.insert(i);
        tr[i]=a;
    }
    for(int i=0;i<m;i++){
        int op;cin>>op;
        if(op==1){
            int a,b;cin>>a>>b;
            if(tr[a])tr[a]-=b;
            if(tr[a]<=0){
                tr[a]=0;
                st.erase(a);
            }
        }else{
            int a;cin>>a;
            int ans=*st.lower_bound(a);
            if(ans==1e9)cout<<n<<endl;
            else cout<<ans<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}