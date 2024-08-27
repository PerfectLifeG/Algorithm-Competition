#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    string ss;
    cin>>ss;
    string sss=ss;
    int j=2;int num=999; int len=sss.size();
    for (int i = 0; i < len/2; )
    {
       
        string a(ss,0,j);
        if(sss.find(a,len/2)==-1){i++;ss.erase(0,1);continue;}
        while (sss.find(a,len/2-1)!=-1)
        {
            j++;
            string b(ss,0,j);
            a=b;
        }
        int size=a.size();
        if(num>size-1)num=size-1;
        ss.erase(0,size-1);
        i+=size-1;
    }
    cout<<num;
    return 0;
}