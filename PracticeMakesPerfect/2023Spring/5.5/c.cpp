#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    int a,b;cin>>a>>b;
    if(b==1||a==1){
        yes;
        return;
    }
    for(int i=2;i<=a/i;i++){
        if(a%i==0&&i<=b){
            no;
            return;
        }
    }
    if(a<=b)no;
    else yes;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}