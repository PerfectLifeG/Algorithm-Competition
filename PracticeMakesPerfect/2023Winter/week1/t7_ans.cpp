#include<bits/stdc++.h>
using namespace std;
const int N=100;
unordered_map<char,int>mp;
priority_queue<int,vector<int>,greater<int>>p;
int res;
int flag;
int cal_len(){
    int len=0;
    while(p.size()>1){
        int a=p.top();p.pop();
        int b=p.top();p.pop();
        len+=a+b;
        p.push(a+b);
    }
    return len;
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char c;int a;
        cin>>c>>a;
        mp[c]=a;
        p.push(a);
    }
    res=cal_len();
    int m;cin>>m;string s[n+1];
    while(m--){
        int sum=0;
        flag=1;
        for(int i=0;i<n;i++){
            char c;
            cin>>c>>s[i];
            sum+=mp[c]*s[i].size();
        }
        if(sum!=res)flag=0;
        else{
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    int len=min(s[i].size(),s[j].size());
                    int flag2=0;
                    for(int k=0;k<len;k++){
                        if(s[i][k]!=s[j][k]){
                            flag2=1;break;
                        }
                    }
                    if(!flag2){flag=0;break;}
                }
            }
        }
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}