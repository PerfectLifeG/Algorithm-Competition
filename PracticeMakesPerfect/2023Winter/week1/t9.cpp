#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int op[N];
int book[N];
int main(){
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>op[i];
    }
    while(k--){
        memset(book,0,sizeof(book));
        int tail=0;int head=0;
        int flag=1;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(book[a]==0){
                while(op[tail]!=a){book[op[tail]]=1;tail++;}
                book[op[tail]]=1;
                if(tail==head)head++;//终于找到bug了！
            }else{
                if(op[head]==a){
                    head++;
                }else while(op[tail]!=a&&tail>=head){
                    tail--;
                    if(tail<head){flag=0;break;}
                }
            }
        }
        if(flag)puts("yes");
        else puts("no");
    }
    return 0;
}