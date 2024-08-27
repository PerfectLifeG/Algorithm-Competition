#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int n,k;
pair<int,int> a[N];
int book[N];
// int cmp(pair<int,int> a1,pair<int,int>b1){
//     if(a1.second==b1.second)return a1.first<b1.first;
//     return a1.second>b1.second;
// }
int cmp2(pair<int,int> a1,pair<int,int>b1){
    return (a1.first-a1.second)<(b1.first-b1.second);
}
vector<pair<int,int>>v;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){cin>>a[i].first;cin>>a[i].second;
    }
    sort(a,a+n,cmp2);
    int ans=0;
    int i;
    for(i=0;i<n&&k;i++){   
        ans+=a[i].second;k--;
        // else v.push_back({a[i]});
    }
    // sort(v.begin(),v.end(),cmp2);
    // int i;
    // for(i=0;i<v.size()&&k;i++){
    //     ans+=v[i].second;
    //     k--;
    // }
    // for(;i<v.size();i++)ans+=v[i].first;
    for(;i<n;i++)ans+=a[i].first;
    cout<<ans;
    return 0;
}