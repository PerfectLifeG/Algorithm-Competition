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
    int ans=0;
    for(int i=1;i<=n;i++){cin>>a[i];if(a[i])ans++;if(a[i]==1)a[i]=2;if(a[i]==3)a[i]=4;}
    for(int i=1;i<=n;){
        int j=i+1;
        if(a[i]==2){
            while(j<=n&&a[j]==4)j++;
            if(j<=n&&a[j]==2&&(j-i-1)%2==0){
                ans--;
                j++;
            }
        }
        i=j;
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}