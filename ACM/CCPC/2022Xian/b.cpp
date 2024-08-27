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
    vector<int>a(n);
    vector<int>book(n);
    int f=1;
    int ff=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0)ff=a[i];
        else if(a[i]!=ff)f=0;
    }
    int ans=0;
    if(f&&ff!=0){
        for(int i=0;i<n;i++){
            a[i]=((a[i]-i)%n+n)%n;
            // cout<<a[i]<<endl;
        }
        ans++;
    }
    int t=-1;
    for(int i=1;i<n;i++){
        if(t==-1){
            t=((a[i]-a[i-1])%n+n)%n;
            continue;
        }
        if(((a[i]-a[i-1])%n+n)%n!=t){
            cout<<-1<<endl;
            return;
        }
    }
    if(a[0]==0){
        cout<<t+ans<<endl;
    }else cout<<t+1+ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}