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
double mn;
double mid;
double px,py,ax,ay,bx,by;
double pa,pb,a,b;
bool check(){
    if(mid>=mn&&(mid>=a||mid>=b)&&(mid>=pa||mid>=pb)){
        return 1;
    }else if(mid>=a&&mid>=pa||mid>=b&&mid>=pb)return 1;
    return 0;
}
void search(double l,double r)
{
     double eps = 1e-8;
     while(r-l>eps)
     { 
        // cout<<l<<' '<<r<<endl;
     // printf("%.12lf ",l);
     // printf("%.12lf\n",r);
     if(r-l<eps)break;
      mid=(l+r)/2;//不能用位运算
      if(check()) r=mid;
      else l=mid;//无边界问题
     }
     // return r;
     printf("%.12lf\n",r);
}
double dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void solve(){
    cin>>px>>py>>ax>>ay>>bx>>by;
    pa=dis(ax,ay,px,py);
    pb=dis(bx,by,px,py);
    a=sqrt(ax*ax+ay*ay);
    b=sqrt((bx)*(bx)+(by)*(by));
    mn=sqrt(1.0*((ax-bx)*(ax-bx)+(ay-by)*(ay-by))/4);
    search(0,4000.0);
    // vector<double>v;
    // if(pa>aa)
    // v.push_back(pa);
    // if(pb>aa)
    // v.push_back(pb);
    // if(a>aa)
    // v.push_back(a);
    // if(b>aa)
    // v.push_back(b);
    // sort(all(v));
    // for(double ans:v){
    //     // printf("%.12lf\n",sqrt(ans));
    //     if((ans>=(ax)*(ax)+(ay)*(ay)||ans>=(bx)*(bx)+(by)*(by))&&(ans>=(ax-px)*(ax-px)+(ay-py)*(ay-py)||ans>=(px-bx)*(px-bx)+(py-by)*(py-by))){
            
    //         return;
    //     }
    // }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}