#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
struct Point{
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y){ }
};
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x + B.x, A.y + B.y);}
Vector operator - (Point A, Point B){return Vector(A.x - B.x, A.y - B.y);}
Vector operator * (Vector A, double p){return Vector(A.x * p, A.y * p);}
Vector operator / (Vector A, double p){return Vector(A.x / p, A.y / p);}
bool operator < (const Point& a, const Point& b) {return a.x < b.x || (a.x == b.x && a.y < b.y);}
bool operator == (const Point& a, const Point& b){return !(a.x - b.x) && !(a.y - b.y);}
double cross(Vector A, Vector B){return A.x * B.y - B.x * A.y;}
double dot(Vector A, Vector B){return A.x * B.x + A.y * B.y;}
double length(Vector A){return sqrt(dot(A, A));}
bool ToLeftTest(Point p,Point a, Point b){
    return cross(b - a, p - b) > 0;
}
double Distance_point_to_segment(Point P, Point A, Point B)
{
    if(A == B) return length(P - A);// （如果重合那么就是两个点之间的距离，直接转成向量求距离即可）
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if(dot(v1, v2)<0)return length(v2);// A点左边
    if(dot(v1, v3)>0)return length(v3);// B点右边
    return fabs(cross(v1, v2)/length(v1));// 垂线的距离
}
void solve(){
    int n,q;cin>>n>>q;
    vector<Point>a(n);
    for(int i=0;i<n;i++){
        double x,y;cin>>x>>y;
        a[i]={x,y};
    }
    vector<double>r(n);
    while(q--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        double r=(1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))/8;
        double x=1.0*(x1+x2)/2,y=1.0*(y1+y2)/2;
        // cout<<r<<' '<<x<<' '<<y<<endl;
        int flag=1;
        for(int i=0;i<n;i++){
            if(!ToLeftTest({x,y},a[i],a[(i+1)%n])){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("%.10lf\n",r);
            continue;
        }
        double ans=1e18;
        for(int i=0;i<n;i++){
            ans=min(ans,Distance_point_to_segment({x,y},a[i],a[(i+1)%n]));
        }
        printf("%.10lf\n",r+ans*ans);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}