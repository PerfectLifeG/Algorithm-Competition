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
const int INF=0x3f3f3f3f;
void solve(){
    int x1,x2;
    int y1,y2;
    int a,b,c,d;
    cin>>x1>>x2;
    cin>>y1>>y2;
    cin>>a>>b>>c>>d;
    if(x1>y1||x2>y2){
        swap(x1,y1);
        swap(x2,y2);
    }
    if(x1>a||x2>b){
        swap(x1,a);
        swap(x2,b);
    }
    if(x1>c||x2>d){
        swap(x1,c);
        swap(x2,d);
    }
    if(a<y1||b<y2){
        swap(a,y1);
        swap(b,y2);
    }
    if(a<c||b<d){
        swap(a,c);
        swap(b,d);
    }
    cout<<abs(x1-a)*abs(x2-b)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}