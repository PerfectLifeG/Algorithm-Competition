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
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

namespace Geometry {
    const double pi = acos(-1);
    const double eps = 1e-8;
    struct Point{
        double x, y;
        Point(double x = 0, double y = 0):x(x), y(y){ }
    };
    typedef Point Vector;
    Vector operator + (Vector a, Vector b){return Vector(a.x + b.x, a.y + b.y);}
    Vector operator - (Point a, Point b){return Vector(a.x - b.x, a.y - b.y);}
    Vector operator * (Vector a, double p){return Vector(a.x * p, a.y * p);}
    Vector operator / (Vector a, double p){return Vector(a.x / p, a.y / p);}
    bool operator < (const Point& a, const Point& b) {return a.x < b.x || (a.x == b.x && a.y < b.y);}
    bool operator == (const Point& a, const Point& b){return fabs(a.x - b.x)<=eps && fabs(a.y - b.y)<=eps;}
    struct Line{
        Point x;Vector y;
        Line(Point X,Point Y){x=X,y=Y-X;}
    };
    
    double cross(Vector a, Vector b){return a.x * b.y - b.x * a.y;}//向量a->b逆时针夹角小于180面积为正
    double dot(Vector a, Vector b){return a.x * b.x + a.y * b.y;}
    double len(Vector a){return dot(a, a);}//用sqrtl开根号
    double dist(Point a,Point b){return len(a-b);}//用sqrtl开根号
    int sign(double x) {return fabs(x)<eps?0:x<0?-1:1;}
    bool ToLeftTest(Point p,Point a, Point b){
        return cross(b - a, p - b) > 0;
    }
    
    //点在线段上
    bool on_segment(Point p, Point a, Point b)
    {
        return cross(p - a, p - b) == 0 && dot(p - a, p - b) <= 0;
    }
    //点与直线关系
    int relation(Point p, Point a, Point b)
    {
        // 1 left -1 right 0 in
        int c = cross((b - a), (p - a));
        if(c < 0) return 1;
        else if(c > 0) return -1;
        return 0;
    }
    
    //线段与直线是否相交：线段两点在直线异侧
    //两线段是否相交
    bool segment_intersection(Point a1, Point a2, Point b1, Point b2)
    {
        double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
        double c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
        return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
    }
    //两直线交点
    Point get_line_intersection(Point p, Vector v, Point q, Vector w)
    {
        // 使用前提，直线必须有交点
        // cross(v, w) == 0则两直线平行或者重合
        Vector u = p - q;
        double t = cross(w, u) / cross(v, w);
        return p + v * t;
    }
    //点到直线投影
    Point projection(Point p, Point a, Point b)
    {
        Vector v = b - a;
        return a + v * (dot(v, p - a) / dot(v, v));
    }
    //点A逆时针沿点B旋转θ弧度
    Point rotate(Point a, Point b, double theta)
    {
        Point p = a - b;
        Point q;
        q.x=p.x*cos(theta)-p.y*sin(theta);
        q.y=p.x*sin(theta)+p.y*cos(theta);
        return q+b;
    }

    //点到线段距离
    double Distance_point_to_segment(Point p, Point a, Point b)
    {
        if(a == b) return len(p - a);//如果重合那么就是两个点之间的距离，直接转成向量求距离即可
        Vector v1 = b - a, v2 = p - a, v3 = p - b;
        if(dot(v1, v2)<0)return len(v2);// A点左边
        if(dot(v1, v3)>0)return len(v3);// B点右边
        return fabs(cross(v1, v2)/len(v1));// 点到直线
    }
    //点到直线距离
    double DistanceToLine(Point P,Line l){
        Vector v1=l.y, v2=P-l.x;
        return fabs(cross(v1,v2))/len(v1);
    }
    
    //多边形面积
    double polygon_area(Point p[], int n)
    {
        double s = 0;
        for (int i = 1; i + 1 < n; i ++ )
            s += cross(p[i] - p[0], p[i + 1] - p[i]);
        return s / 2;
    }
}
using namespace Geometry;


// struct Point{
//     double x, y;
//     Point(double x = 0, double y = 0):x(x), y(y){ }
// };
// typedef Point Vector;
// Vector operator * (Vector a, double p){return Vector(a.x * p, a.y * p);}
// Vector operator - (Point a, Point b){return Vector(a.x - b.x, a.y - b.y);}
// struct Line{
//     Point x;Vector y;
//     Line(Point X,Point Y){x=X,y=Y-X;}
// };
// double cross(Vector a, Vector b){return a.x * b.y - b.x * a.y;}
// double dot(Vector a, Vector b){return a.x * b.x + a.y * b.y;}
// double len(Vector a){return dot(a, a);}
// double dist(Point a,Point b){return len(a-b);}
// int sign(double x) {return fabs(x)<eps?0:x<0?-1:1;}
// double DistanceToLine(Point P,Line l){
//     Vector v1=l.y, v2=P-l.x;
//     return fabs(cross(v1,v2))/len(v1);
// }

Point P[N];
int id[N],idx;
void Andrew(int n){//n>2 构建逆时针凸包
    sort(P,P+n,[&](Point x,Point y){
        return (x.x==y.x)?(x.y<y.y):(x.x<y.x);
    });

    idx=0;
    for(int i=0;i<n;i++){//构建下凸包
        while(idx>1&&sign(cross(P[i]-P[id[idx-2]],P[id[idx-1]]-P[id[idx-2]]))>=0)idx--;
        id[idx++]=i;//先将前两个点加入凸包
    }

    int k=idx;
    for(int i=n-2;i>=0;i--){//构建上凸包，最后一个点已经被加入到上凸包
        while(idx>k&&sign(cross(P[i]-P[id[idx-2]],P[id[idx-1]]-P[id[idx-2]]))>=0)idx--;
        id[idx++]=i;//先加一个点
    }
    idx--;//起点在正着扫描和倒着扫描都能加入凸包
}

double RotateCalipers()//返回直径的平方
{
    if (idx <= 2) return dist(P[0], P[idx - 1]);
    double res = 0;
    for (int i = 0, j = 0; i < idx; i++)
    {
        Line line(P[id[i]],P[id[(i+1)%idx]]);
        while(DistanceToLine(P[id[j]], line) <= DistanceToLine(P[id[(j+1)%idx]], line)){
            j=(j+1)%idx;
        }
        res = max(res, max(dist(P[id[i]], P[id[j]]), dist(P[id[(i+1)%idx]], P[id[j]])));
    }
    return res;
}

void solve(){
    int n;cin>>n;
    double ans=0;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        P[i].x=x;P[i].y=y;
    }
    for(int i=0;i<n;i++){
        ans+=sqrtl(dist(P[i],P[(i+1)%n]));
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        P[i].x=x;P[i].y=y;
    }
    Andrew(m);
    int res=RotateCalipers();
    ans+=2*sqrtl(res)*acos(-1);
    cout<<fixed<<setprecision(15)<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    
    cin>>_;
    while(_--)solve();
    return 0;
}