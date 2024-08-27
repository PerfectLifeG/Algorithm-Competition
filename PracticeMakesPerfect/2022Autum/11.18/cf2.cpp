#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
set<int>st;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=55;i++){
    mp[i]=i*(i+1)/2;
    st.insert(i*(i+1)/2);}
    for (int i = 0; i < n; i++)
    {
        int m,s;
        int flag=1;
        set<int>a;
        scanf("%d%d",&m,&s);
        int sum=0;
        int mx=0;
        while(m--){
            int b;scanf("%d",&b);
            mx=max(mx,b);
            a.insert(b);
            if(b==0||a.count(b))flag=0;
            sum+=b;
        }
        if(st.count(sum+s)){
            if(mp[mx]<=sum+s)flag=1;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}