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
    if(n==1){
        cout<<"1"<<endl;
        cout<<"1"<<endl;
    }
    if(n==2){
        cout<<"2"<<endl;
        cout<<"1 2"<<endl;
    }
    if(n==3){
        cout<<"2"<<endl;
        cout<<"1 2 2"<<endl;
    }
    if(n==4){
        cout<<"3"<<endl;
        cout<<"1 2 2 3"<<endl;
    }
    if(n==5){
        cout<<"3"<<endl;
        cout<<"1 2 2 3 3"<<endl;
    }
    if(n>=6){
        int idx=0;
        cout<<4<<endl;
        for(int i=0;i<n;i++){
            cout<<(idx%4)+1<<' ';
            idx++;
        }cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}