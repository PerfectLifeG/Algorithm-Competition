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
int n;
PII q[N];int idx;//存点
int stk[N], top;//凸包
bool used[N];
PII operator-(PII a, PII b)
{
    return{ a.x - b.x,a.y - b.y };
}
int operator*(PII a, PII b)
{
    return a.x * b.y - a.y * b.x;
}
int area(PII a, PII b,PII c)
{
    return (b - a) * (c - a);
}
int get_dist(PII a, PII b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}
void get_convex()//建立凸包
{
    sort(q, q + n);
    for (int i = 0; i < n; i++)
    {
        while (top >= 2 && area(q[stk[top - 2]], q[stk[top - 1]], q[i]) >= 0)
        {
            if (area(q[stk[top - 2]], q[stk[top - 1]], q[i]) > 0)//q[i])>=0顺时针
                used[stk[--top]] = false;
            else top--;//如果在直线上的话不用取消标记
        }
        stk[top++] = i;
        used[i] = true;
    }
    used[0] = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (used[i]) continue;
        while (top >= 2 && area(q[stk[top - 2]], q[stk[top - 1]], q[i]) >= 0)
            top--;
        stk[top++] = i;
    }
    top--;
}
void solve()
{
    string s;cin>>s;
    s=','+s;

    //  s=','+s;
    // int cnt=0;
    // for(int i=0;i<s.size();i++){
    //     if(s[i]==','){
    //         int j=i+1;
    //         int val=0;
    //         int v=1;
    //         if(s[j]=='-'){v=-1;j++;}
    //         while(s[j]>='0'&&s[j]<='9'){
    //             val=val*10+s[j]-'0';
    //             j++;
    //         }
    //         if(cnt&1){
    //             q[cnt/2].y=val*v;
    //         }else{
    //             q[cnt/2].x=val*v;
    //         }
    //         cnt++;
    //     }
    // }
    // n=cnt/2;

    int cnt=0;
    for(int i=0;i<s.size();i++){
        int a=0,b=0;
        while(i<s.size()&&s[i]==',')i++;
        while(i<s.size()&&s[i]<='9'&&s[i]>='0'){a=a*10+(s[i]-'0');i++;}
        while(i<s.size()&&s[i]==',')i++;
        while(i<s.size()&&s[i]<='9'&&s[i]>='0'){b=b*10+(s[i]-'0');i++;}
        q[idx++]={a,b};
        cnt++;
    }
    n=cnt;

    get_convex();
    if(n>top){
        puts("ERROR");
    }else{

        // vector<int>a(n+5);
        // for(int i=0;i<n;i++) a[stk[i]]=i;
        // int ji=-1;
        // int minn=1e18;
        // for(int i=0;i<n;i++){
        //     if(q[i].x*q[i].x+q[i].y*q[i].y<minn){
        //         minn=q[i].x*q[i].x+q[i].y*q[i].y;
        //         ji=i;
        //     }
        // }
        // int be=a[ji];
        // for(int i=0;i<n;i++){
        //     if(i) cout<<',';
        //     int j=be%n;
        //     cout<<q[stk[j]].x<<','<<q[stk[j]].y;
        //     be++;
        // }


        idx=0;int mn=1e18;
        for(int i=0;i<top;i++){
            if(mn>q[stk[i]].x*q[stk[i]].x+q[stk[i]].y*q[stk[i]].y){
                idx=i;
                mn=q[stk[i]].x*q[stk[i]].x+q[stk[i]].y*q[stk[i]].y;
            }
        }
        cout<<q[stk[idx]].x<<','<<q[stk[idx]].y;
        for(int i=idx+1;i<top;i++){
            cout<<','<<q[stk[i]].x<<','<<q[stk[i]].y;
        }
        for(int j=0;j<idx;j++){
            cout<<','<<q[stk[j]].x<<','<<q[stk[j]].y;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}