#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int book[N];
int a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        book[a]++;
        s.insert(a);
    }
    auto i=s.begin();
    int ans=0;
    for(;i!=s.end();i++){
        for(auto j=s.begin();j!=s.end();j++){
            if((*i^*j)==(*i+*j)){
                ans+=book[*i]*book[*j];
            }
        }
    }
    cout<<ans;
    return 0;
}