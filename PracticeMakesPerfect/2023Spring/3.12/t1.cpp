#include<bits/stdc++.h>
using namespace std;
const int N=210;
#define sc(n) scanf("%d",&n)
int n=200;
int d[N][N];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
typedef pair<pair<int,int>,int> PII;
#define x first
#define y second
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int a,b;cin>>a>>b;
        a=abs(a);b=abs(b);
        cout<<a+b+max(0,abs(a-b)-1)<<endl;
    }
    return 0;
}