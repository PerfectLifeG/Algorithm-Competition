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
void solve(){
    int n;cin>>n;
    vector<double>a(n);
    vector<double>b(n);
    int f=0;
    double s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        // b[i]=a[i];
    }
    // for(int i=0;i<n-1;i++){
    //     a[i+1]+=1.0*a[i]/2;
    //     a[i]=1.0*a[i]/2;
    // }
    // a[0]+=1.0*a[n-1]/2;
    // a[n-1]=1.0*a[n-1]/2;
    // for(int i=0;i<n;i++){
    //     if(a[i]!=b[i]){
    //         f=1;
    //         break;
    //     }
    // }
    // if(!f){
    //     for(int i=0;i<n;i++){
    //         printf("%.6lf ",a[i]);
    //     }
    //      return;   
    // }
    s=1.0*s/(n+1);
    printf("%.6lf ",s*2);
    for(int i=0;i<n-1;i++){
        printf("%.6lf ",s);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}