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
struct node
{
    int data;
    node* next;
};
int main()
{
    int n;cin>>n;int num=n;
    node* nd=new node;nd->next=NULL;
    node* ndd=nd;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        if(i==0){ndd->data=a;continue;}
        node* temp=new node;
        temp->next=NULL;
        temp->data=a;
        ndd->next=temp;
        ndd=ndd->next;
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==0&&b>num){int c;cin>>c;}
        if(a==0&&b<=num){
            ndd=nd;
            int c;
            cin>>c;
            int cnt=0;
            if(b==0){
                num++;
                node* temp=new node;
                temp->data=c;
                temp->next=nd;
                nd=temp;
                continue;
            }
            while(ndd){
                cnt++;
                if(cnt==b){
                    num++;
                    node* temp=new node;
                    temp->data=c;
                    temp->next=ndd->next;
                    ndd->next=temp;
                    break;
                }
                ndd=ndd->next;
            }
        }    
        else if(a==1&&b!=0&&b<=num){
            ndd=nd;int cnt=1;
            if(b==1){
                num--;
                nd=nd->next;
                continue;
            }
            while(ndd){
                cnt++;
                if(cnt==b){
                    num--;
                    ndd->next=ndd->next->next;
                    break;
                }
                ndd=ndd->next;
            }
        }
    }
    while (nd)
    {
        cout<<nd->data<<" ";
        nd=nd->next;
    }
    return 0;
}