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
    int a,b;cin>>a>>b;
    if(a%2==0||b&1){
        no;
        return;
    }
    if(a*2<b||b*2<(a-1)){
        no;
        return;
    }
    yes;
    a--;a/=2;b/=2;
    queue<int>q;q.push(1);
    unordered_map<int,int>mp;mp[1]=1;
    int idx=2;
    do{
        auto t=q.front();
        q.pop();
        if(mp[t]==1){
            if(b){
                cout<<idx<<' '<<idx+1<<endl;
                q.push(idx);mp[idx]=2;
                q.push(idx+1);mp[idx+1]=2;
                idx+=2;
                b--;
            }
            else cout<<-1<<' '<<-1<<endl;
        }
        if(mp[t]==2){
            if(a){
                cout<<idx<<' '<<idx+1<<endl;
                q.push(idx);mp[idx]=1;
                q.push(idx+1);mp[idx+1]=1;
                idx+=2;
                a--;
            }
            else cout<<-1<<' '<<-1<<endl;
        }
    }while(q.size());
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}