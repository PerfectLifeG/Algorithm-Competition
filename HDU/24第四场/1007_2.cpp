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
    int n,q;cin>>n>>q;
    vector<int>a(n);
    vector<int>b(n);
    // ll sum=0;
    for(int i=0;i<n;i++){
        a[i]=rd()%N+1;
        // cin>>a[i];
        // sum+=a[i];
    }
    vector<PII>v;
    for(int i=0;i<n;i++){
        b[i]=rd()%N+1;
        // cin>>b[i];
        v.push_back({b[i],i});
    }

    // if((ll)n*n*q<=5e7){
    //     for(int j=0;j<q;j++){
    //         int sum=0;
    //         int k;
    //         cin>>k;
    //         // k=rd()%n;
    //         for(int i=0;i<n;i++){
    //             a[i]=max(a[i],b[(i+k)%n]);
    //             sum+=a[i];
    //         }
    //         cout<<sum<<endl;
    //     }
    //     return;
    // }


    ll val=0;
    int j=1;
    for(;j*j<=n&&j<=q;j++){
        int k;
        k=rd()%n;
        ll sum=0;
        // cin>>k;
        for(int i=0;i<n;i++){
            a[i]=max(a[i],b[(i+k)%n]);
            sum+=a[i];
            // if(b[(i+k)%n]>a[i]){
            //     sum+=b[(i+k)%n]-a[i];
            //     a[i]=b[(i+k)%n];
            // }
        }
        val+=sum;
        // cout<<sum<<endl;
    }

    sort(all(v));
    reverse(all(v));
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

    for(;j<=q;j++){
        int k;
        // cin>>k;
        k=rd()%n;
        for(int p=0;p<=n*120/j&&p<=n;p++){
            // int id=myrand()%n;
            // if(a[id]<b[(id+k)%n]){
            //     sum-=a[id];
            //     a[id]=b[(id+k)%n];
            //     sum+=a[id];
            // }
            // if(a[(id-k+n)%n]<b[id]){
            //     sum-=a[(id-k+n)%n];
            //     a[(id-k+n)%n]=b[id];
            //     sum+=a[(id-k+n)%n];
            // }
            if(v[p].first>a[(v[p].second-k+n)%n]){
                sum-=a[(v[p].second-k+n)%n];
                a[(v[p].second-k+n)%n]=v[p].first;
                sum+=a[(v[p].second-k+n)%n];
            }
        }
        val+=sum;
        // cout<<sum<<endl;
    }
    cout<<val<<endl;


}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}