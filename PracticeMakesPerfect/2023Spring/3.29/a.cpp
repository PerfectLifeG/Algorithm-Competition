#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int get(int x){
    int mx=0,mn=0x3f3f3f3f;
    while(x){
        mx=max(mx,x%10);
        mn=min(mn,x%10);
        x/=10;
    }
    return mx-mn;
}
void solve(){
    int l,r;
    cin>>l>>r;
    int book[10]={};
    for(int i=l;i<=r;i++){
        if(get(i)==9){
            cout<<i<<endl;
            return;
        }
        book[get(i)]=i;
    }
    for(int i=8;i>=0;i--){
        if(book[i]){cout<<book[i]<<endl;return;}
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}