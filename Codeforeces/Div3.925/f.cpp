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
void solve(){
    int n,k;cin>>n>>k;
    int ru[n+1]={};
    vector<int>v[n+1];
    for(int i=0;i<k;i++){
        int a;cin>>a;
        int lst=-1;
        for(int j=0;j<n-1;j++){
            int b;cin>>b;
            if(lst!=-1){
                v[lst].push_back(b);
                ru[b]++;
            }
            lst=b;
        }
    }
    int cnt=0;
    function<void()> topsort=[&](){
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(ru[i]==0){q.push(i);cnt++;}
        }
        while(q.size()){
            auto t=q.front();
            q.pop();
            for(auto j:v[t]){
                if(--ru[j]==0){
                    q.push(j);
                    cnt++;
                }
            }
        }
    };
    topsort();
    if(cnt!=n)no;
    else yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}