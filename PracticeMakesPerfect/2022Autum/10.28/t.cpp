#include<bits/stdc++.h>
using namespace std;
int panduan(char a[][4],int i,int j){
    if(a[i][j]==a[i-1][j]&&a[i-1][j-1]==a[i][j-1]&&a[i-1][j-1]==a[i-1][j]){
        return 1;
    }
    return 0;
}
int main(){
    int t;cin>>t;
    for (int k = 0; k < t; k++)
    {
        char a[4][4]={0};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char c;cin>>c;
                a[i][j]=c;
            }
        }
        int flag=0;
        for (int i = 1; i <= 3; i++)
        {
            if(flag==1)break;
            for (int j = 1; j <= 3; j++)
            {
                if(flag==1)break;
                flag=panduan(a,i,j);
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}