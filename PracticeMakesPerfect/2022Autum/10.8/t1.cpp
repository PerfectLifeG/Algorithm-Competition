#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<string,int>mp;
    for (int i = 0; i < n; i++)
    {
        string a;cin>>a;
        mp[a]=1;
    }
    for (int i = 0; i < m; i++)
    {
        string s;cin>>s;
        int flag=0;
        for(auto it:mp){
            if(s.find(it.first)!=-1)
            {
                flag=1;
                break;}
        }
        if(flag){
            printf("bieexina\n");
        }else printf("enenen\n");
    }
    return 0;
}