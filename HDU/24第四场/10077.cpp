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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    mt19937 myrand(time(0));
    int n,q;cin>>n>>q;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<PII>v;
    for(int i=0;i<n;i++){
        cin>>b[i];
        v.push_back({b[i],i});
    }


    if((ll)n*n*q<=1e7){
        for(int j=0;j<q;j++){
            int sum=0;
            int k;cin>>k;
            for(int i=0;i<n;i++){
                a[i]=max(a[i],b[(i+k)%n]);
                sum+=a[i];
            }
            cout<<sum<<endl;
        }
        return;
    }

    int j=1;
    for(;j*j<=n&&j<=q;j++){
        int k;cin>>k;
        ll sum=0;
        for(int i=0;i<n;i++){
            a[i]=max(a[i],b[(i+k)%n]);
            sum+=a[i];
        }
        cout<<sum<<endl;
    }

    sort(all(v));
    reverse(all(v));
    ll sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    for(;j<=q;j++){
        int k;cin>>k;
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

        cout<<sum<<endl;
    }


}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}