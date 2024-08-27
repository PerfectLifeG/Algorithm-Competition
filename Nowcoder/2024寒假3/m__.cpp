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
int check(int t){
    int cnt=0;
    while(t){
        cnt++;
        t/=10;
    }
    return cnt;
}
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    multiset<int>st[20];
    for(int i=0;i<n;i++){
        int a;cin>>a;v[i]=a;
        st[log10(v[i])+1].insert(v[i]%36);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int p=log10(v[i])+1;
        st[p].erase(st[p].find(v[i]%36));
        int f=10;
        for(int j=1;j<19;j++){
            int t=v[i]*f;
            ans+=st[j].count(((36-v[i]%36*f%36)+36)%36);
            f*=10;
        }
        st[p].insert(v[i]%36);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}