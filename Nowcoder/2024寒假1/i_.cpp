#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int sum=0;
    // srand(time(nullptr));
    // mt19937 rng;
    for(int i=0;i<100000;i++){
        int a,b,r;
        a=rand()%199-99;
        b=rand()%199-99;
        do{
            r=rand()%100+1;
        }while( a-r<-100 || a+r>100 || b-r<-100 || b+r>100);
        sum+=abs(a)+abs(b);
    }
    cout<<sum<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}