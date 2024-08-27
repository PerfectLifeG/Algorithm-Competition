#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()-1
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
    int n,mm,k;cin>>n>>mm>>k;
    __int128 m=mm;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    __int128 sum=0;
    priority_queue<int,vector<int>,greater<int>>q;
    int ans=min(n,k);
    for(int i=0;i<n&&i<k;i++){
        q.push(a[i]);
    }
    for(int i=k;i<n;i++){
        q.push(a[i]);
        sum+=q.top();
        q.pop();
        if(m>sum){
            ans=i+1;
        }else break;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}