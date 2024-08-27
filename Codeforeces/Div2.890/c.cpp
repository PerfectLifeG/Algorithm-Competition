#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int n,k;
vector<int>a(N);
// vector<PII>b(N);
int mid;
// int dfs(int t,int v){
//     if(a[t]>=mid){
//         return 1;
//     }
//     if(a[t+1]<mid||)if(dfs(t+1))return 1;
//     return 0;
// }
int check(vector<PII>& b){
    // vector<int>book(n);
    // for(int i=0;i<n;i++){
    //     if(!book[i]){
    //         book[i]=1;
    //         if(dfs(i,0))return 1;
    //     }
    // }
    // return 0;
    // cout<<mid<<endl;
    // for(int i=0;i<n;i++){
    //     if(a[i]==mx){
    //         id.push_back(i);
    //     }
    // }
    for(int j=b.size()-1;j>=0;j--){
        int t=0;int lst=mid;
        for(int i=b[j].second;i<n;i++){
            // cout<<i<<' '<<t<<endl;
            t+=lst-a[i];
            lst--;
            if(i+1<n&&a[i+1]>=lst&&t<=k){
                return 1;
            }
            if(t>k)break;
        }
    }
    return 0;
}
void solve()
{
    cin>>n>>k;
    vector<PII>b;
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        b.push_back({a[i],i});
    }
    sort(b.begin(),b.end());
    // for(auto i:b)cout<<i.first<<' '<<i.second<<endl;
    int l=mx,r=mx+k+1;
    while(l+1!=r){
        mid=l+r>>1;
        if(check(b))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}