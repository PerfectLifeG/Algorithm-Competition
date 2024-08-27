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
const double eps=1e-8;
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
double cross(Vector A, Vector B){return A.x * B.y - B.x * A.y;}
double dot(Vector A, Vector B){return A.x * B.x + A.y * B.y;}
int sgn(double x){
    if(fabs(x) < eps)
        return 0;
    if(x < 0)
        return -1;
    return 1;
}
int relation(Point A, Point B, Point C)
{
    int c = sgn(cross((B - A), (C - A)));
    if(c < 0) return 1;
    else if(c > 0) return -1;
    return 0;
}
void solve(){
    int n,m,x1,y1,x2,y2;
    int flag=0;
    while(cin>>n,n){
        if(flag)cout<<endl;
        else flag=1;
        cin>>m>>x1>>y1>>x2>>y2;
        vector<Point>a(n+1);
        for(int i=0;i<n;i++){
            int x,y;cin>>x>>y;
            a[i]={x,y};
        }
        a[n]={x2,x2};
        vector<int>ans(n+1);
        for(int i=0;i<m;i++){
            int x,y;cin>>x>>y;
            int l=-1,r=n+1;
            while(l+1!=r){
                int mid=l+r>>1;
                if(relation({a[mid].x,y1},{a[mid].y,y2},{x,y})>=0){
                    r=mid;
                }else l=mid;
            }
            ans[r]++;
        }
        for(int i=0;i<=n;i++){
            cout<<i<<": "<<ans[i]<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}