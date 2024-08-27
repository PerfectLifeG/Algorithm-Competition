#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int a,b;cin>>a>>b;
    if(b*3>a){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<b;i++){
        cout<<"you";
    }
    for(int i=0;i<a-b*3;i++){
        cout<<'y';
    }
    cout<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}