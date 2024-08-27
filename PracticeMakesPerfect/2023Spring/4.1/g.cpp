#include<bits/stdc++.h>
using namespace std;
const int N=10;
#define all(x) x.begin(),x.end()
int n,k,ans;
vector<string>group[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    unordered_map<string,int>t;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            string a;cin>>a;
            t[a]=50;
            group[i].emplace_back(a);
        }
        sort(all(group[i]));
    }
    vector<int>seq(n);
    for(int i=0;i<n;i++)seq[i]=i;
    do{
        unordered_map<string,int>v=t;
        int sum=0;
        for(int i=0;i<k;i++){
            int ret=0;
            for(int j=0;j<group[seq[i]].size();j++){
                auto s=group[seq[i]][j];
                if(v[s]==0)continue;
                if(ret+v[s]>114){
                    v[s]=ret+v[s]-114;
                    ret=114;
                    break;
                }else {ret+=v[s];v[s]=0;}
            }
            sum+=ret;
        }
        ans=max(ans,sum);
    }while(next_permutation(all(seq)));
    cout<<ans;
    return 0;
}