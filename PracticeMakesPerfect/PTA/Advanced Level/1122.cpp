#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,q;cin>>n>>q;
    map<pair<int,int>,int>mp;
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        mp[{a,b}]=1;
        mp[{b,a}]=1;
    }
    int k;cin>>k;
    while(k--){
        int m;cin>>m;
        int st;cin>>st;
        int lst=st;
        vector<int>book(n+1);
        book[st]=1;
        int flag=1;
        if(m!=n+1)flag=0;
        for(int i=1;i<m-1;i++){
            int a;cin>>a;
            if(!flag)continue;
            if(book[a]){flag=0;continue;}
            if(!mp.count({lst,a})){flag=0;continue;}
            book[a]=1;
            lst=a;
        }
        int ed;cin>>ed;
        if(!mp.count({lst,ed})){flag=0;}
        if(ed!=st)flag=0;
        if(flag)yes;
        else no;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}