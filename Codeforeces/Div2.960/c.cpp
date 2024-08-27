#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    vector<int>c(n+1);
    vector<int>book(n+1);
    int mx=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        book[a[i]]++;
        if(book[a[i]]==2){
            mx=max(mx,a[i]);
        }
        b[i]=mx;
        // cout<<b[i]<<' ';
    }
    // cout<<endl;
    book.assign(n+1,0);
    mx=0;
    for(int i=1;i<=n;i++){
        book[b[i]]++;
        if(book[b[i]]==2){
            mx=max(mx,b[i]);
        }
        c[i]=mx;
        sum+=b[i];
        // cout<<c[i]<<' ';
    }
    // cout<<endl;
    // for(int i=1;i<=n;){
    //     int j=i+1;
    //     while(j<=n&&b[i]==b[j])j++;
    //     int l=j-i;
    //     // cout<<l<<' '<<b[i]<<endl;
    //     sum+=(l*b[i]+b[i])*l/2;
    //     i=j;
    // }
    for(int i=1;i<=n;){
        int j=i+1;
        while(j<=n&&c[i]==c[j])j++;
        int l=j-i;
        // cout<<l<<' '<<c[i]<<endl;
        sum+=(l*c[i]+c[i])*l/2+(n+1-j)*c[i]*l;
        i=j;
    }
    cout<<sum<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}