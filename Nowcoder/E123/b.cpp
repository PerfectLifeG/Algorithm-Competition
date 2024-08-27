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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int mx1=0,mx2=0;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]>mx1){
            mx2=max(mx1,mx2);
            mx1=a[i];
        }else mx2=max(mx2,a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]>sum-a[i]){
            cout<<1<<' ';
        }else{
            int left=sum-a[i];
            int t;
            if(a[i]==mx1)t=mx2;
            else t=mx1;
            if(t>left-t){
                t-=left-t;
                if(a[i]>t)cout<<1<<' ';
                else cout<<0<<' ';
            }else{
                if(left%2==0)cout<<1<<' ';
                else if(a[i]==1)cout<<0<<' ';
                else cout<<1<<' ';
            }
        }
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}