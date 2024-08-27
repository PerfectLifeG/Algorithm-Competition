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
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v));

    // vector<int>u;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         u.push_back(v[i]+v[j]);
    //     }
    // }
    // sort(all(u));
    // for(auto i:u)cout<<i<<' ';cout<<endl;


    // for(int i=0;i<n*(n-1)/2;i++){

    int k;cin>>k;
    //     int k=i;
    int l=v[0]+v[1]-1,r=v[n-1]+v[n-2]+1;
    while(l+1!=r){
        int mid=l+r>>1;
        int cnt=0;//严格小于mid的个数
        int j=n-1;
        for(int i=0;i<j;i++){
            while(j>i&&mid<=v[j]+v[i])j--;
            cnt+=j-i;
        }
        if(cnt>=k)r=mid;
        else l=mid;
    }
    cout<<l<<' ';

    // }
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}