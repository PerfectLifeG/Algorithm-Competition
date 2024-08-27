#include<bits/stdc++.h>
using namespace std;
//map+队列
int book[100000];
int main()
{
    map<int,int>mp1;
    map<int,int>mp2;
    map<int,int>temp;
    queue<int>q1;
    queue<int>q2;
    int start,n;
    cin>>start>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        temp[abs(b)]++;
        mp1[a]=c;
        mp2[a]=b;
    }
    for (int i = 0; i < n; i++)
    {
        if(temp[abs(mp2[start])]==1){
            q1.push(start);
        }
        else if(temp[abs(mp2[start])]>1){
            if(book[abs(mp2[start])]==0)
            {q1.push(start);
            book[abs(mp2[start])]=1;}
            else q2.push(start);
        }
        start=mp1[start];
        if(start==-1)break;
    }
    while (!q1.empty())
    {
        int t=q1.front();
        printf("%05d %d ",t,mp2[t]);
        q1.pop();
        if(!q1.empty())
            {t=q1.front();
            printf("%05d\n",t);}
        else cout<<-1<<endl;
    }
    while (!q2.empty())
    {
        int t=q2.front();
        printf("%05d %d ",t,mp2[t]);
        q2.pop();
        if(!q2.empty())
            {t=q2.front();
            printf("%05d\n",t);}
        else cout<<-1<<endl;
    }

    return 0;
}