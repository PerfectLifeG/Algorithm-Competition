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
    deque<int>q;
    int n;cin>>n;
    int t=2;
    int id=1;
    while(t<=n){
        q.push_back(id++);
        if(t*2>n){
            t=n-t;
            break;
        }
        t<<=1;
    }
    for(int i=60;i>=0;i--){
        if((t>>i)&1){
            q.push_front(id-i-1);
        }
    }
    cout<<q.size()<<endl;
    while(q.size()){cout<<q.front()<<' ';q.pop_front();}
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}