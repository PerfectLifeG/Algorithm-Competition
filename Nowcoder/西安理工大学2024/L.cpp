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
    int n,m;cin>>n>>m;
    string s;cin>>s;
    deque<char>q;
    for(auto i:s)q.push_back(i);
    int flag=0;
    while(m--){
        int op;cin>>op;
        if(op==1){
            flag^=1;
        }else{
            int t;cin>>t;char c;cin>>c;
            // cout<<t<<' '<<c<<' '<<endl;
            if(t==1){
                if(flag){
                    q.push_back(c);
                }else q.push_front(c);
            }
            if(t==2){
                if(flag){
                    q.push_front(c);
                }else q.push_back(c);
            }
        }
    }
    while(q.size()){
        if(flag){cout<<q.back();q.pop_back();}
        if(!flag){cout<<q.front();q.pop_front();}
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}