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
const int INF=0x3f3f3f3f;
void solve(){
    int n,k;cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<k;i++)q.push(8*3600);
    vector<PII>v;
    for(int i=0;i<n;i++){
        int h,m,s,ti;
        scanf("%d:%d:%d %d",&h,&m,&s,&ti);
        int arr=h*3600+m*60+s;
        v.push_back({arr,ti});
    }
    sort(all(v));
    int ans=0;int cnt=0;
    for(auto [i,j]:v){
        if(i>17*3600)break;
        auto t=q.top();
        // if(t<=17*3600){
            q.pop();
            if(i>=t){
                q.push(i+j*60);
            }else{
                q.push(t+j*60);
                ans+=t-i;
            }
            cnt++;
        // }
    }
    printf("%.1lf",1.0*ans/(60*cnt));
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}