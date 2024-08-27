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
    int n,m;cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v[i]=a;
    }
    queue<int>q1;
    queue<int>q2;
    vector<int>ans(n);
    for(int i=0;i<n;i++){int a;cin>>a;q2.push(a);ans[i]=1;}
    while(q2.size()!=1){
        while(q2.size()){q1.push(q2.front());q2.pop();}
        int rank=q1.size()/m+(bool)(q1.size()%m);
        while(q1.size()){
            int lst=-1;
            for(int i=0;q1.size()&&i<m;i++){
                auto t=q1.front();
                // cout<<t<<' ';
                if(lst==-1){ans[t]=rank+1;lst=t;}
                else if(v[t]>v[lst]){ans[lst]=rank+1;lst=t;}
                else if(v[t]<v[lst]){ans[t]=rank+1;}
                q1.pop();
            }
            ans[lst]=rank;
            q2.push(lst);
        }
    }
    int first=1;
    for(int i=0;i<n;i++){
        if(first){cout<<ans[i];first=0;}
        else cout<<' '<<ans[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}