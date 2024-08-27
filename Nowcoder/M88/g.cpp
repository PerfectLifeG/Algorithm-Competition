#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define PI acos(-1)
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-12;
void solve(){
    double x1,y1,x2,y2,a;cin>>x1>>y1>>x2>>y2>>a;
    if(y1>y2){
        swap(x1,x2);
        swap(y1,y2);
    }
    if(x1==x2){
        // cout<<a<<' '<<tan(a*1.0/180*3.14)<<endl;
        cout<<x1+1.0*(y2-y1)/tan(a*PI/180)<<' '<<y1<<endl;
        return;
    }
    if(a==90){
        cout<<x2<<' '<<y1<<endl;
        return;
    }
    double t=a;
    if(a>90)t=180-a;
    double h=y2-y1;
    double l=0,r=abs(x2-x1);
    while(l+eps<=r){
        double mid=(l+r)/2;
        if(h>=mid*tan(t*PI/180))l=mid;
        else r=mid;
    }
    if(x1>x2){
        if(a>90){
            cout<<x2+l<<' '<<y1<<endl;
        }else cout<<x2-l<<' '<<y1<<endl;
    }else{
        if(a>90){
            cout<<x2-l<<' '<<y1<<endl;
        }else cout<<x2+l<<' '<<y1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    cout<<fixed<<setprecision(12);
    while(_--)solve();
    return 0;
}