#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;int flag=0;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin>>a;
        int len=a.size();
        for (int i = 0; i <len-1 ; i++)
        {
            if(a[i]>='a'&&a[i]<='z')if(!(a[i+1]==a[i]+'Z'-'z'||a[i+1]==a[i]-1)){cout<<"N"<<endl;flag=1;break;}
            if(a[i]>='A'&&a[i]<='Z')if(!(a[i+1]==a[i]+'z'-'Z'||a[i+1]==a[i]+1)){cout<<"N"<<endl;flag=1;break;}
        }    
        if(flag){flag=0;continue;}
        cout<<"Y"<<endl;
        
    }
    
    
    
    return 0;
}