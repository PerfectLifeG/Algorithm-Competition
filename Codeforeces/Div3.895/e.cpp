#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>s0(n+1);
    vector<int>s1(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    string s;cin>>s;s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            s0[i]+=s0[i-1]^a[i];
            s1[i]=s1[i-1];
        }else{
            s1[i]+=s1[i-1]^a[i];
            s0[i]=s0[i-1];
        }
    }
    int q;cin>>q;
    int a0=s0[n];
    int a1=s1[n];
    while(q--){
        int op;cin>>op;
        if(op==1){
            int l,r;cin>>l>>r;
            a0^=(s0[r]^s0[l-1])^(s1[r]^s1[l-1]);
            a1^=(s0[r]^s0[l-1])^(s1[r]^s1[l-1]);
        }else{
            int x;cin>>x;
            if(x==0){
                cout<<a0<<' ';
            }else cout<<a1<<' '; 
        }
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}