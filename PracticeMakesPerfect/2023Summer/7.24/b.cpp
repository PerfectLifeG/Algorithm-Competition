#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int ferbo(int n){
    return (sqrt(5)/5)*(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n));
}
int exgcd(int a,int b,int &x,int &y){
    if(b==0)return x=1,y=0,a;
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
//用矩阵快速幂求斐波那契数列
struct Matrix { //定义矩阵结构体 
    int a[2][2];
}; 
Matrix muliMatrix(Matrix x, Matrix y) { //求两个矩阵相乘
    Matrix result; //结果矩阵result 
    memset(result.a, 0, sizeof(result.a)); //将结果矩阵的元素全部初始化为0
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++){
                result.a[i][j] += x.a[i][k] * y.a[k][j]; //矩阵的乘法 
            }
        }
    } 
    return result; 
} 
int matrixPow(int n) { //快速幂求斐波那契数列
    Matrix res, c;
    memset(res.a, 0, sizeof(res.a));  
    for(int i = 0; i < 2; i++) {
        res.a[i][i] = 1; //将res初始化为单位矩阵，因为任何矩阵和单位矩阵相乘都是它本身 
    } 
    c.a[0][0] = 1; //构造斐波那契矩阵 
    c.a[0][1] = 1;
    c.a[1][0] = 1;
    c.a[1][1] = 0;
    
    while(n) {
        if(n&1 != 0){ //这里和求x^n的快速幂类似 
            res = muliMatrix(res, c);
        }
        c = muliMatrix(c, c);
        n >>= 1; // 等价于把n右移一位并把结果赋给n即n=>>1 
    } 
    return res.a[0][1]; //由于斐波那契第n项Fn对应结果举证中res.a[0][1]的值
}
void solve()
{
    int n,k;cin>>n>>k;
    //1 1 2 3 5 
    //1 2 3 4 5 
    //3 4 5 6 7 8
    if(k>28){
        cout<<0<<endl;;
        return;
    }
    int a=matrixPow(k-2),b=matrixPow(k-1),c=n;
    int x,y;
    // cout<<a<<' '<<b<<endl;
    int d=exgcd(a,b,x,y);
    if(c%d!=0){
        cout<<0<<endl;
        return;
    }else{
        int b1=b/d;
        int x1=x*c/d;
        x1=(x1%b1+b1)%b1;
        int y1=(c-a*x1)/b;
        if(y1<x1){
            cout<<0<<endl;
            return;
        }
        int t=y1-x1;
        cout<<t/(a+b)+1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cout<<matrixPow(100)<<endl;
    cin>>_;
    while(_--)solve();
    return 0;
}