#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    int n;cin>>n;
    int f1=1e9,f2=1e9,f3=1e9;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(b==01)f1=min(f1,a);
        if(b==10)f2=min(f2,a);
        if(b==11)f3=min(f3,a);
    }
    if(f1+f2>=1e9&&f3>=1e9){
        cout<<-1<<endl;
        return;
    }
    cout<<min(f1+f2,f3)<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}