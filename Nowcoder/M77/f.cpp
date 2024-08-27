#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
unordered_map<int,int>mp;
int a,b;
int bfs(){
    queue<int>q;
    q.push(b);
    mp.clear();
    int ans=b-a;
    while(q.size()){
        auto t=q.front();
        q.pop();
        int c=sqrt(t);
        if(c>=a&&c*c<=t&&(!mp.count(c)||mp[c]>mp[t]+1+t-(c*c))){mp[c]=mp[t]+1+t-(c*c);q.push(c);}
        if(t/2>=a&&(!mp.count(t/2)||mp[t/2]>mp[t]+1+t%2)){mp[t/2]=mp[t]+1+t%2;q.push(t/2);} 
        ans=min(ans,mp[t]+t-a);
    }
    return ans;
}
void solve()
{
    cin>>a>>b;
    cout<<bfs()<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}