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
const int N=1e9;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n=2e5,q=2e5;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        a[i]=rand()%N+1;
        // cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i]=rand()%N+1;
        // cin>>b[i];
    }


    if(n*n*q<=5e7){
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
        int k=rand()%n;
        int sum=0;
        for(int i=0;i<n;i++){
            a[i]=max(a[i],b[(i+k)%n]);
            sum+=a[i];
        }
        cout<<sum<<endl;
    }

    int mx=0;
    for(int i=0;i<n;i++)mx=max(mx,b[i]);
    vector<int>v1;
    for(int i=0;i<n;i++){
        if(a[i]<mx){
            v1.push_back(i);
        }
    }
    cout<<v1.size()<<endl;


    // int sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    for(;j<=q;j++){
        int k;cin>>k;
        vector<int>v2;
        for(auto &id:v1){
            if(a[id]<b[(id+k)%n]){
                sum-=a[id];
                a[id]=b[(id+k)%n];
                sum+=a[id];
            }
            if(a[id]!=mx){
                v2.push_back(id);
            }
        }
        v1=v2;
        cout<<sum<<endl;
    }


}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}