#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define PII pair<int,int>
vector<PII>v;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int a,b;cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int cnt=1;
    int idx=1;int temp=v[0].first;
    while(idx<t){
        if(v[idx].second>temp){
            cnt++;
            temp=v[idx].first;
        }
        idx++;
    }
    cout<<cnt;
    return 0;
}