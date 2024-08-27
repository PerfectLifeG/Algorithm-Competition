#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    int a[n][3];
    int tot=0;
    for(int i=0;i<n;i++){cin>>a[i][0];tot+=a[i][0];}
    for(int i=0;i<n;i++)cin>>a[i][1];
    for(int i=0;i<n;i++)cin>>a[i][2];
    tot=(tot+2)/3;
    
    PII ans[3];
    vector<int>v(3);
    for(int i=0;i<3;i++)v[i]=i;
    do{
        int i=0;
        int sum=0;
        while(i<n&&sum<tot)sum+=a[i++][v[0]];
        if(sum>=tot){
            ans[v[0]]={1,i};ans[v[1]].x=i+1;sum=0;
        }else continue;
        while(i<n&&sum<tot)sum+=a[i++][v[1]];
        if(sum>=tot){
            ans[v[1]].y=i;ans[v[2]].x=i+1;sum=0;
        }else continue;
        while(i<n&&sum<tot)sum+=a[i++][v[2]];
        if(sum>=tot){
            ans[v[2]].y=n;
            for(int i=0;i<3;i++){
                cout<<ans[i].x<<' '<<ans[i].y<<' ';
            }cout<<endl;
            return;
        }
    }while(next_permutation(v.begin(),v.end()));

    cout<<-1<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}