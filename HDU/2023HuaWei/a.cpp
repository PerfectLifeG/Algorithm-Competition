#include<bits/stdc++.h>
using namespace std;
#define int long long
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
struct Node{
    int a,b;double c;int d,e,f,id;
    bool operator<(const Node &n)const{
        if(f==n.f)return id<n.id;
        return f<n.f;
    }
};
void solve()
{
    int n,m;n=read();m=read();
    Node v[n];
    for(int i=0;i<n;i++){
        int a,b;double c;int d,e,f;
        a=read();b=read();c=read2();d=read();e=read();f=read();
        v[i]={a,b,c,d,e,f,i+1};
    }   
    sort(v,v+n);
    for(int i=0;i<m;i++){
        int a,b;double c;int d,e;
        a=read();b=read();c=read2();d=read();e=read();
        int l=-1,r=n;
        while(l+1!=r){
            int mid=l+r>>1;
            if(v[mid].a>=a&&v[mid].b>=b&&v[mid].c>=c&&v[mid].d>=d&&v[mid].e>=e){
                r=mid;
            }
        }
        cout<<v[r].id<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    _=read();
    while(_--)solve();
    return 0;
}