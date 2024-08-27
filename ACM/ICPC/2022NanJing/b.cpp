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
const double eps = 1e-6;
int sign(double x){
    if(fabs(x) < eps) return 0;
    if(x > 0) return 1;
    return -1;
}
struct point{
    double x , y;
    point(){}
    point(double a , double b) : x(a) , y(b){}
}; 
double det(const point &a , const point &b){
    return a.x * b.y - a.y * b.x;
}
double toleft(point p , point a, point b) {
    point A = point(b.x - a.x , b.y - a.y);
    point B = point(p.x - a.x , p.y - a.y);
    return det(A , B);
}
int n;
point p[N];
inline nex(int x){ return (x + 1) % n; }
inline pre(int x){ return (x - 1 + n) % n; }
void solve(){
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        double x , y;cin >> x >> y;
        p[i] = point{x , y};
    }
    point xx , yy;
    int res = 0;
    for(int i = 0 ; i < n ; i ++){
        if(p[i].y == p[nex(i)].y) continue;
        bool tagp = 0 , tagn = 0;
        for(int j = pre(i) ; j != i ; j = pre(j)){
            if(p[j].y == p[i].y) continue;
            if(p[j].y >  p[i].y) {
                xx = p[j];
                tagp = 1;
                break;
            }
            if(p[j].y <  p[i].y) break;
        }
        
        for(int j = nex(i) ; j != i ; j = nex(j)){
            if(p[j].y == p[i].y) continue;
            if(p[j].y >  p[i].y) {
                yy = p[j];
                tagn = 1;
                break;
            }
            if(p[j].y <  p[i].y) break;
        }
        
        if(!tagp || !tagn) continue;
        
        if(p[i].y == p[pre(i)].y){
            if(p[i].x > p[pre(i)].x) res += 1;
        }else{
            if(sign(toleft(p[pre(i)] , p[i] , p[nex(i)])) == 1) res += 1;
        }
        
    }
    cout << res << "\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}