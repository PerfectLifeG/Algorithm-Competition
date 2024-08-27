#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e9;
const int mod=998244353;
mt19937 rd;

void solve(){
    int n=250000,q=250000;
    cin>>n>>q;
    vector<int>a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        a[i]=rd()%N+1;
        // cin>>a[i];
        sum+=a[i];
    }
    vector<PII>b(n);
    for(int i=0;i<n;i++){
        b[i].first=rd()%N+1;
        // cin>>b[i].first;
        b[i].second=i;
    }

    int j=0;
    ll val=0;
    // for(;j*j<=n&&j<q;j++){
    //     int k;
    //     k=rd()%n;
    //     // cin>>k;
    //     for(int i=0;i<n;i++){
    //         if(a[i]<b[(i+k)%n].first){
    //             sum+=b[(i+k)%n].first-a[i];
    //             a[i]=b[(i+k)%n].first;
    //         }
    //     }
    //     val+=sum;
    //     // cout<<sum<<endl;
    // }

    sort(all(b));
    reverse(all(b));
    for(;j<q;j++){
        int k;
        k=rd()%n;
        // cin>>k;
        // int limit=min(n,n/max(1,j-20)*100+100);
        // if(limit<n){cout<<j<<' '<<limit<<endl;}
        for(int i=0;i<n&&i<=120*n/max(1,i);i++){
            int pos=(b[i].second-k+n)%n;
            if(b[i].first>a[pos]){
                sum+=b[i].first-a[pos];
                a[pos]=b[i].first;
            }
        }
        val+=sum;
        // cout<<sum<<endl;
    }
    cout<<val<<endl;


}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("out.txt","w",stdout);
    int _=2;
    cin>>_;
    while(_--)solve();
    return 0;
}