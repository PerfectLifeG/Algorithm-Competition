#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    unordered_map<char,char>mp;
    mp['6']='9';
    mp['9']='6';
    mp['8']='8';
    mp['1']='1';
    mp['0']='0';
    for(int i=0;i<n;i++){
        string a;cin>>a;
        string ans="";
        int flag=1;
        for(auto i:a){
            if(!mp.count(i)){    
                flag=0;
                break;
            }
            ans+=mp[i];
        }
        if(flag){
            cout<<ans<<endl;
        }else cout<<"bu ke neng"<<endl;
    }
    return 0;
}