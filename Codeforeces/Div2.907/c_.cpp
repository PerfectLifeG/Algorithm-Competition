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
int a[N];
int n;
int check(int mid){
    
}
void solve(){
    cin>>n;
    int l=0,r=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        r+=a[i];
        if(a[i]==1)l++;
    }
    while(l+1!=r){
        int mid=l+r>>1;
        if(check()){
            r=mid;
        }else l=mid;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}