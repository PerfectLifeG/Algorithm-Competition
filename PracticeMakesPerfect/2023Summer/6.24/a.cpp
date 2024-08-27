#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int b[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0;
    for(;i<n&&j<m;){
        if(a[i]<b[j]){
            b[j]-=a[i];
            i++;
        }
        else if(a[i]>b[j]){
            a[i]-=b[j];
            j++;
        }else {
            i++;j++;
        }
    }
    if(i==n&&j==m){
        cout<<"Draw"<<endl;
    }else if(j==m){
        cout<<"Tsondu"<<endl;
    }else cout<<"Tenzing"<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}