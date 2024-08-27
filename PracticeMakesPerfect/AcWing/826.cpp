#include<iostream>
using namespace std;
const int N=100010;

int head,e[N],ne[N],idx;

void init(){
    head=-1;
    idx=1;
}

void insert_head(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void add_k(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

void del(int k){
    ne[k]=ne[ne[k]];
}

int main(){
    int n;cin>>n;
    init();
    for(int i=0;i<n;i++){
        char c;cin>>c;
        int k,x;
        if(c=='H'){
            cin>>x;
            insert_head(x);
        }else if(c=='D'){
            cin>>k;
            if(k==0)head=ne[head];
            else del(k);
        }else{
            cin>>k>>x;
            add_k(k,x);
        }
    }
    while(head!=-1){
        cout<<e[head]<<' ';
        head=ne[head];
    }
    return 0;
}