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
__int128 read(){
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
// void scan(__int128 &x)//输入
// {
//     x = 0;
//     int f = 1;
//     char ch;
//     if((ch = getchar()) == '-') f = -f;
//     else x = x*10 + ch-'0';
//     while((ch = getchar()) >= '0' && ch <= '9')
//         x = x*10 + ch-'0';
//     x *= f;
// }
// void _print(__int128 x)
// {
//     if(x > 9) _print(x/10);
//     putchar(x%10 + '0');
// }
// void print(__int128 x)//输出
// {
//     if(x < 0)
//     {
//         x = -x;
//         putchar('-');
//     }
//     _print(x);
// }
void solve(){
    int a1,b1,n1;cin>>a1>>b1>>n1;
    __int128 a,b,n;a=a1;b=b1;n=n1;
    // a=read();b=read();n=read();
    // scan(a);scan(b);scan(n);
    __int128 ans=a*a+b*b;
    for(int i=0;i<=b;i++){
        __int128 y=(i*n*a+b-1)/b;
        y=(y+a-1)/a*a;
        __int128 x=y*b/a;
        x%=n;y%=n;
        if(__int128(x*x+y*y))
        ans=min(ans,__int128(x*x+y*y));
    }
    for(int i=0;i<=a;i++){
        __int128 x=(i*n*b+a-1)/a;
        x=(x+b-1)/b*b;
        __int128 y=x*a/b;
        x%=n;y%=n;
        if(__int128(x*x+y*y))
        ans=min(ans,__int128(x*x+y*y));
    }
    // print(ans);
    cout<<(int)ans<<endl;
    // putchar('\n');
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // __int128 _=1;
    // _=read();
    int _=1;cin>>_;
    // scan(_);
    while(_--)solve();
    return 0;
}