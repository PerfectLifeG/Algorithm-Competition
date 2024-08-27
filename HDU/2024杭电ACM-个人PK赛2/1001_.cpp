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
    // int n,k;cin>>n>>k;
    int n=6,k=2,len=3;
    vector<int>v(n);
    int cnt=0;
    for(int i=0;i<n;i++)v[i]=i+1;
    do{
        int mn=INF;
        for(int i=0;i<n;i++){
            if(v[i]==n){
                int p=1;
                while(p<len){
                    if(i-p>=0)mn=min(mn,v[i-p]);
                    if(i+p<n)mn=min(mn,v[i+p]);
                    p++;
                }
                if(v[i]-mn==len-1+k){
                    // cout<<v[i]<<' '<<mn<<endl;
                    // if(i-1>=0&&v[i-1]==3){
                        for(int i=0;i<n;i++)cout<<v[i];cout<<endl;
                        cnt++;
                    // }
                }
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    //2:144 192 240
    //3:432 192
    //4:576
    cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}