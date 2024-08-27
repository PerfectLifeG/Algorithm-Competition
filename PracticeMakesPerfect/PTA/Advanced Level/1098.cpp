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
    vector<int>v(n);
    vector<int>final(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>final[i];
    }
    for(int i=2;i<n;i++){
        sort(v.begin(),v.begin()+i);
        if(v==final){
            sort(v.begin(),v.begin()+i+1);
            cout<<"Insertion Sort\n";
            cout<<v[0];
            for(int i=1;i<v.size();i++){
                cout<<' '<<v[i];
            }
            return;
        }
    }
    auto adjust_down=[&](int l,int r){
        int t=l;
        int j=t*2+1;
        while(j<=r){
            if(j+1<=r&&final[j]<final[j+1])j++;
            if(final[t]>=final[j])return;
            swap(final[t],final[j]);
            t=j;
            j=2*t+1;
        }
    };
    int i=1;
    while(i<n&&final[0]>final[i])i++;i--;
    swap(final[0],final[i]);
    adjust_down(0,i-1);
    cout<<"Heap Sort\n";
    cout<<final[0];
    for(int i=1;i<final.size();i++){
        cout<<' '<<final[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}