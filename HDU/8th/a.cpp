#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int check(int n){
    int t=sqrt(n);
    if(t*t==n){
        return 1;
    }return 0;
}
void solve()
{
    int a,b;cin>>a>>b;
    int t=abs(b-a);
    if((int)sqrt(t)*(int)sqrt(t)==t){
        cout<<1<<endl;
    }
    else if(t&1||(t>8&&t%2==0&&t%4==0)){
        cout<<2<<endl;
    }else {
        for(int i=1;i<=t/i;i++){
            if(check(t-i*i)){
                cout<<2<<endl;
                return;
            }
        }
        cout<<3<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}