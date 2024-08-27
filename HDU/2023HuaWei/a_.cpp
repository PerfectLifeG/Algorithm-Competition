#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
double read2()
{
    double s=0,w=1;
    char ch=getchar();
    if(ch=='-')
    {
        w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    if(ch=='.')
    {
        ch=getchar();
        double f=0;
        int i=0;//计数器，计算小数位数
        while(ch>='0'&&ch<='9')
        {
            f=f*10+ch-'0';
            i++;
            ch=getchar();
        }
        for(int j=0;j<i;j++)
        {
            f/=10;
        }
        s+=f;
    }
    return w*s;
}
int read()
{
    int s=0,w=1;
    char ch=getchar();
    if(ch=='-')//判断是否为负数
    {
        w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=s*10+ch-'0';//进位并且加上个位
        ch=getchar();
    }
    return w*s;
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<array<double,6>>v(n);
    for(int i=0;i<n;i++){
        double a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        v[i]={a,b,c,d,e,f};
    }
    for(int i=0;i<m;i++){
        double a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        int idx=0,mn=1e9;
        for(int j=0;j<n;j++){
            if(v[j][0]>=a&&v[j][1]>=b&&v[j][2]>=c&&v[j][3]>=d&&v[j][4]>=e&&v[j][5]<=mn){
                mn=v[j][5];
                idx=j+1;
            }
        }
        cout<<idx<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}