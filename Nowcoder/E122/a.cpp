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
    int T;cin>>T;
    int n;cin>>n;
    while(T--){
        int t1=0,t2=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a==0)t1++;
            if(a==1)t2++;
        }
        cout<<abs(t1-t2)<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}