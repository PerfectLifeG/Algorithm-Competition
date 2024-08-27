#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int a;cin>>a;
    int m=40;
    vector<int>v(40);
    while(m--){
        if(!(a&1)){cout<<-1<<endl;return;}
        if(a==1){
            cout<<40-m-1<<endl;
            for(int i=m+1;i<=39;i++){
                cout<<v[i]<<' ';
            }
            cout<<endl;
            return;
        }
        if(((a+1)/2)&1){
            a=(a+1)/2;
            v[m]=1;
        }else{
            a=(a-1)/2;
            v[m]=2;
        }
    }
    cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}