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
int book[N];
void solve(){
    int n;cin>>n;
    set<int>st;
    int p=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        st.insert(a);
        book[a]++;
    }
    int ans=0;
    int lst=0;
    for(auto i:st){
        p=max(p,book[i]);
        for(int j=2;j<=200000;j++){
            int cnt=0;
            int t=i;
            while(book[t]){
                cnt++;
                t=t*j;
                if(t>2e5)break;
            }
            // if(cnt<=lst)break;
            ans=max(ans,cnt);
        }
        lst=ans;
    }
    cout<<max(p,ans)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}