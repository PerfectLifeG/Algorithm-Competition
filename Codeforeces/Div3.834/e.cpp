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
    int n,h;cin>>n>>h;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    int v[3][3]={3,2,2,2,2,3,2,3,2};
    int ans=0;
    int t=h;
    for(int i=0;i<3;i++){
        int cnt=3;
        int at=0;
        h=t;
        while(cnt>=0){
            while(at<n&&h>a[at]){h+=a[at]/2;at++;}
            cnt--;
            if(cnt<0)break;
            h*=v[i][cnt];
        }
        ans=max(ans,at);
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