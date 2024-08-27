#include<bits/stdc++.h>
using namespace std;
const int N=25010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    int n,m,a,b,c,d;string dir;
    cin>>n>>m>>a>>b>>c>>d>>dir;
    map<pair<pair<int,int>,string>,int>mp;
    int bound=0;
    while(!(a==c&&b==d)){
        if(dir=="DR"){
            if(a==n&&b==m){
                dir="UL";
                bound++;
            }else if(a==n){
                dir="UR";
                bound++;
            }else if(b==m){
                dir="DL";
                bound++;
            }else {
                a++,b++;
            }
        }else if(dir=="DL"){
            if(a==n&&b==1){
                dir="UR";
                bound++;
            }else if(b==1){
                dir="DR";
                bound++;
            }else if(a==n){
                dir="UL";
                bound++;
            }else {
                a++,b--;
            }
        }else if(dir=="UR"){
            if(a==1&&b==m){
                dir="DL";
                bound++;
            }else if(b==m){
                dir="UL";
                bound++;
            }else if(a==1){
                dir="DR";
                bound++;
            }else {
                a--,b++;
            }
        }else if(dir=="UL"){
            if(a==1&&b==1){
                dir="DR";
                bound++;
            }
            else if(1==a){
                dir="DL";
                bound++;
            }else if(1==b){
                dir="UR";
                bound++;
            }else {
                a--,b--;
            }
        }
        if(mp.count({{a,b},dir})){
            cout<<-1<<endl;
            return;
        }
        mp[{{a,b},dir}]++;
    }
    cout<<bound<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}