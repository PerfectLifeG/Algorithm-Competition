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
    double cross(Vector a, Vector b){return a.x * b.y - b.x * a.y;}
    double dot(Vector a, Vector b){return a.x * b.x + a.y * b.y;}
    double length(Vector a){return sqrt(dot(a, a));}
    int sign(double x)  // 符号函数 
    {
        if (fabs(x) < eps) return 0;
        if (x < 0) return -1;
        return 1;
    }
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

    //点到线段距离
    double Distance_point_to_segment(Point p, Point a, Point b)
    {
        if(a == b) return length(p - a);//如果重合那么就是两个点之间的距离，直接转成向量求距离即可
        Vector v1 = b - a, v2 = p - a, v3 = p - b;
        if(dot(v1, v2)<0)return length(v2);// A点左边
        if(dot(v1, v3)>0)return length(v3);// B点右边
        return fabs(cross(v1, v2)/length(v1));// 点到直线
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
void solve(){
    int n;cin>>n;
    vector<Point>v(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v[i]={x,y};
    }
    if(n<5){
        cout<<"NO\n";
        return;
    }
    vector<int>vv;
    int f=1;
    for(int i=0;i<4;i++){
        vv.push_back(i);
        for(int j=i;j<4;j++){
            if(!f)break;
            for(int k=4;k<n;k++){
                if(relation(v[k],v[i],v[j])!=0){
                    vv.push_back(k);
                    f=0;
                }
            }
        }
    }
    for(auto i:vv){
        vector<Point>ans;
        for(int j=0;j<n;j++){
            // cout<<i<<' '<<j<<endl;
            if(i==j)continue;
            int flag=1;
            for(int k=0;k<ans.size();k++){
                // cout<<v[j].x<<' '<<v[j].y<<' '<<v[i].x<<' '<<v[i].y<<' '<<ans[k].x<<' '<<ans[k].y<<endl;
                if(on_segment(v[j],v[i],ans[k])||on_segment(ans[k],v[i],v[j])){
                    flag=0;break;
                }
            }
            if(flag){
                // cout<<j<<endl;
                // cout<<v[j].x<<'.'<<v[j].y<<endl;
                ans.push_back(v[j]);
            }
            if(ans.size()==4){
                cout<<"YES\n";
                cout<<(int)v[i].x<<' '<<(int)v[i].y<<endl;
                for(auto k:ans){
                    cout<<(int)k.x<<' '<<(int)k.y<<endl;
                }
                return;
            }
        }
    }
    cout<<"NO\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}