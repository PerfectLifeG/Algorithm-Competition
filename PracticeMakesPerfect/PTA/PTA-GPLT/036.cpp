#include<bits/stdc++.h>
using namespace std;
int value[205][205];
int Min=1000000000;
int cnt,ind;
int main()
{
    int n,m;cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        value[a][b]=c;
        value[b][a]=c;
    }
    int k;cin>>k;
    for (int i = 1; i <= k; i++)
    {
        int a;cin>>a;
        int start;cin>>start;
        int s=0;int flag=0;
        map<int,int>mp;
        if(value[0][start]){
            mp[start]=1;
            s+=value[0][start];
            flag++;
        }
        for (int i = 0; i < a-1; i++)
        {
            int b;cin>>b;
            if(value[start][b]){
                mp[b]=1;
                s+=value[start][b];
                start=b;
            }
        }
        if(value[start][0]){
            s+=value[start][0];
            flag++;
        }
        if(flag==2&&a==n&&mp.size()==n){
            if(Min>s){
                Min=s;
                ind=i;
            }
            cnt++;
        }
    }
    cout<<cnt<<endl;
    cout<<ind<<" "<<Min;
    return 0;
}