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
int main()
{
    int n;
    cin>>n;
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        int a,b,c;
        cin>>a;
        if(a){cin>>b;q.push(b);}
        else {
            if(q.empty())
        cout<<"invalid"<<endl;
        else{c=q.front();q.pop();cout<<c<<endl;}
        }
    }
    
    return 0;
}