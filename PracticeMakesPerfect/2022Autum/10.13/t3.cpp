#include<bits/stdc++.h>
using namespace std;
char book[8][8];
int cnt[8][8];
int main(){
    int n;cin>>n;
    for (int k = 0; k < n; k++)
    {
        map<int,int>mp;
        int flag=0;
        memset(cnt,0,sizeof(cnt));
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                char c;cin>>c;
                if(flag==1)continue;
                if(c=='R'){mp[i]++;
                if(i==0)cnt[i][j]=1;
                else cnt[i][j]+=cnt[i-1][j]-81;}
                book[i][j]=c;
                if(i==7&&cnt[i][j]==8){
                    flag=1;
                }
            }
            if(mp[i]==8)flag=1;
        }
        if(flag)cout<<'R'<<endl;
        else cout<<'B'<<endl;
    }
    return 0;
}