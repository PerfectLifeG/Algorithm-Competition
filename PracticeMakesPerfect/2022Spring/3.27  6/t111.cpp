#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int p[3],q[3];int o=0,f=0;
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin>>a;
        while(a.size()>=4)
        {
            string b(a,0,4);
            if(b.find('k')!=-1&&a.size()>=4) {p[0]++;string c(a,4,a.size()-4);a=c;}
            else if(b.find('i')!=-1&&a.size()>=4) {p[1]++;string c(a,8,a.size()-8);a=c;}
            else if(b.find('a')!=-1&&a.size()>=4) {p[2]++;string c(a,5,a.size()-5);a=c;}
        
            string d(a,0,4);
            if(d.find('k')!=-1&&a.size()>=4) {q[0]++;string c(a,4,a.size()-4);a=c;}
            else if(d.find('i')!=-1&&a.size()>=4) {q[1]++;string c(a,8,a.size()-8);a=c;}
            else if(d.find('a')!=-1&&a.size()>=4) {q[2]++;string c(a,5,a.size()-5);a=c;}

                if(p[0]==q[0]&&p[1]==q[1]&&p[2]==q[2]) {o++;f++;}
                else if((p[0]==q[1]&&p[0]!=0)||(p[1]==q[2]&&p[1]!=0)||(p[2]==q[0]&&p[2]!=0)) o++;
                else f++;
            
            p[0]=p[1]=p[2]=0;
            q[0]=q[1]=q[2]=0;
        }
        if(o>f)cout<<"Win"<<endl;
        else if(o==f)cout<<"Tie"<<endl;
        else cout<<"Lose"<<endl;
        o=0;f=0;
    }
    
    return 0;
}