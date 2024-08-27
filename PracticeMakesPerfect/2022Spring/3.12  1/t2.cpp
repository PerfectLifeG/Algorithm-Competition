#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int n,s;int flag=0;
    cin>>n>>s;
    int car[n];
    int car2[n];
    for (int i = 0; i < n; i++)
    {
        car[i]=s;
        car2[i]=s;
    }
    
    map<int,string>mp;
    map<string,int>mpp;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin>>a;
        mp.insert(make_pair(i,a));
        mpp.insert(make_pair(a,i));
    }
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        string a,b;int c;
        int t;
        cin>>a>>b>>c;
        t=mpp[b]-mpp[a];
        int num=car2[mpp[a]];
        int it=mpp[a];
        flag=0;
        for (int j = 0; j < t; it++,j++)
        {   
            car[it]-=c;
            if(num>car2[it])num=car2[it];
            
            if(car[it]<0 )  flag=1;
            
            if(j==t-1){

            if(flag){cout<<num<<" "<<"NO"<<endl;
            }
            else cout<<num<<" "<<"YES"<<endl;
            
            for (int ll = 0; ll < t&&flag==0; it--,ll++)
            {
                car2[it]=car[it];
            }
            
            for (int ll = 0; ll < t&&flag==1; it--,ll++)
            {
                car[it]=car2[it];
            }


            }

            
        }
        
    }

    return 0;
}