#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define lowbit(x) (x&(-x))
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=2e5+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int tr1[N],tr2[N];
void add1(int t,int val){
    for(int i=t;i<N;i+=lowbit(i)){
        tr1[i]+=val;
    }
}
int query1(int t){
    int res=0;
    for(int i=t;i;i-=lowbit(i)){
        res+=tr1[i];
    }
    return res;
}
void add2(int t,int val){
    for(int i=t;i<N;i+=lowbit(i)){
        tr2[i]+=val;
    }
}
int query2(int t){
    int res=0;
    for(int i=t;i;i-=lowbit(i)){
        res+=tr2[i];
    }
    return res;
}
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    unordered_map<int,int>mp;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        add1(a[i],1);
        cnt1+=query1(N-1)-query1(a[i]);
        mp[a[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        add2(b[i],1);
        cnt2+=query2(N-1)-query2(b[i]);
    }
    for(int i=0;i<n;i++){
        add1(a[i],-1);
        add2(b[i],-1);
    }
    for(int i=0;i<n;i++)if(!mp.count(b[i])){no;return;}
    if((cnt1%2==0&&cnt2%2==0)||((cnt1&1)&&(cnt2&1)))yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}