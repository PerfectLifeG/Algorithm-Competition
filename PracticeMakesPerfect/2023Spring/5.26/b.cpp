#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int exgcd(int a,int b,int &x,int &y){
    if(b==0)return x=1,y=0,a;
    int ret=exgcd(b,a%b,y,x);//经过这步返回的是x2,y2，然后求x1,y1
    y-=a/b*x;
    return ret;
}
void solve(){
    int n;cin>>n;
    cout<<n*2<<' '<<n*3<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}