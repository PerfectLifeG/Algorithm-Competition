#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
double dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void solve(){
    double px,py,ax,ay,bx,by;
    cin>>px>>py>>ax>>ay>>bx>>by;
    double pa=dis(ax,ay,px,py);
    double pb=dis(bx,by,px,py);
    double a=sqrt(ax*ax+ay*ay);
    double b=sqrt(bx*bx+by*by);
    double ans=sqrt(1.0*((ax-bx)*(ax-bx)+(ay-by)*(ay-by))/4);
    printf("%.12lf\n",min({
        max({min(pa,pb),min(a,b),ans}),
        max(pa,a),
        max(pb,b),
    }));
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}