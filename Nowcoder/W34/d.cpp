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
    vector<int>v;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(a[i])v.push_back(a[i]);
    }
    int ans=0;
    for(int i=1;i<v.size();i++){
        ans+=abs(v[i]-v[i-1]);
    }
    if(ans>1){cout<<-1<<endl;return;}
    if(!v.size()){
        if(n>1){
            cout<<1<<' ';
            for(int i=1;i<n;i++){
                cout<<2<<' ';
            }
            cout<<endl;
        }else cout<<-1<<endl;
        return;
    }


    for(int i=0;i<n;){
        if(a[i]){
            int j=i-1;
            while(j>=0&&a[j]==0){a[j]=a[i];j--;}
            j=i+1;
            while(j<n&&a[j]==0){a[j]=a[i];j++;}
            i=j;
        }else i++;
    }
    ans=0;
    for(int i=1;i<n;i++){
        ans+=abs(a[i]-a[i-1]);
    }
    if(ans==0){
        if(b[0]==0){
            a[0]++;
        }else if(b[n-1]==0){
            a[n-1]++;
        }else {cout<<-1<<endl;return;}
    }
    if(ans>1){cout<<-1<<endl;return;}
    else {for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;}
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}