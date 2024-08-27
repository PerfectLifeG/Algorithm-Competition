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
const int INF=0x3f3f3f3f;
void solve(){
    int m,n,k;cin>>m>>n>>k;
    while(k--){
        stack<int>st;
        queue<int>q;
        int idx=1;
        int flag=1;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(!flag)continue;
            q.push(a);
            if(!st.size())st.push(idx++);
            while(st.size()<m&&st.top()!=a)st.push(idx++);
            if(st.size()>m){flag=0;continue;}
            while(st.size()&&q.size()&&st.top()==q.front()){
                st.pop();
                q.pop();
            }
        }
        if(flag&&!st.size())yes;
        else no;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}