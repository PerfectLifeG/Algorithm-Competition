#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {   
        int mx=0;
        int a;cin>>a;getchar();
        char c[a];
        int ans[a][2]={0};
        c[0]=getchar();
        if(c[0]=='0')ans[0][0]=1;
        else if(c[0]=='1')ans[0][1]=1;
        else {
            ans[0][1]=1;ans[0][0]=1;
        }
        for (int j = 1; j < a; j++)
        {   
            c[j]=getchar();
            if(c[j]=='2'){
                if(c[j-1]=='2'){
                    ans[j][1]=ans[j-1][1]+1;
                    ans[j][0]=ans[j-1][0]+1;
                }
                else if(c[j-1]=='0'){ans[j][0]=ans[j-1][0]+1;ans[j][1]=1;}
                else if(c[j-1]=='1'){ans[j][1]=ans[j-1][1]+1;ans[j][0]=1;}
            }else{
                ans[j][c[j]-'0']=ans[j-1][c[j]-'0']+1;
            }
            mx=max(mx,ans[j][0]);
            mx=max(mx,ans[j][1]);
        }
        cout<<mx<<endl;
    }
    return 0;
}