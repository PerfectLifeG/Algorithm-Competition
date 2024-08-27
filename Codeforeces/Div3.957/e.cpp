#include<bits/stdc++.h>
using namespace std;
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
vector<PII>v[110];
void solve(){
    int n;cin>>n;
    cout<<v[n].size()<<endl;
    for(auto &[a,b]:v[n]){
        cout<<a<<' '<<b<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int n=1;n<=100;n++){
        string f=to_string(n);
        int t=f.size();
        for(int a=1;a<=10000;a++){
            for(int b=max(1,a*t-7);b<=a*t-1&&n*a-b>=1;b++){
                string s;int idx=0;
                while(s.size()<a*t-b){
                    s+=f[idx%t];
                    idx++;
                }
                if(to_string(n*a-b)==s){
                    v[n].push_back({a,b});
                }
            }
        }
    }
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}