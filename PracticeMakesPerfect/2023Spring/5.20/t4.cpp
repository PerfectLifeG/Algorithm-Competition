#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    set<int>v1[13];
    set<int>v2[13];
    // unordered_map<int,int>mp[13];
    for(int i=1;i<=12;i++){
        int id;cin>>id;
        int n;cin>>n;
        for(int j=0;j<n;j++){
            int a;cin>>a;
            v1[id].insert(a);
        }
        cin>>n;
        for(int j=0;j<n;j++){
            int a;cin>>a;
            v2[id].insert(a);
        }
    }
    // return 0;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(v1[a].find(b)!=v1[a].end()||v1[b].find(a)!=v1[b].end()){
            yes;
        }else if(v2[a].find(b)!=v2[a].end()||v2[b].find(a)!=v2[b].end()){
            no;
        }else{
            cout<<"NA"<<endl;
        }
    }
    return 0;
}