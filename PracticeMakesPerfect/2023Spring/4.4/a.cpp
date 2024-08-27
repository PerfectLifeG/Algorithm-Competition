#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    string a,c;
    int n;char b;
    cin>>n>>c>>a;
    b=c[0];
    int flag=n;
    for(int i=0;i<n;i++){
        if(a[i]<b){
            flag=i;
            break;
        }
        if(a[i]==b&&(a[i+1]<b||i==n-1)){
            flag=i;
            break;
        }
    }
    for(int i=0;i<a.size();i++){
        if(i==flag){cout<<b;}
        cout<<a[i];
    }
    if(flag==n)cout<<b;
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}