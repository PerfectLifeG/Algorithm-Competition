#include<iostream>
#include<string>
using namespace std;
const int N=20;
int r[N],l[N],e[N];
int head,tail,idx;
void init(){
    head=1;
    tail=2;
    r[head]=tail;l[tail]=head;
    idx=tail+1;
}
void add_l(int k,int x){
    e[idx]=x;
    l[idx]=l[k];r[idx]=k;
    r[l[k]]=idx;l[k]=idx;
    idx++;
}
void add_r(int k,int x){
    e[idx]=x;
    r[idx]=r[k];l[idx]=k;
    l[r[k]]=idx;r[k]=idx;
    idx++;                  //这个不能忘啊！！！
}
void del(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}
int main(){
    int m;cin>>m;
    init();
    while(m--){
        string c;
        cin>>c;
        int k,x;
        if(c=="R"){
            cin>>x;
            add_r(l[tail],x);
        }else if(c=="D"){
            cin>>k;
            del(k+2);
        }else if(c=="L"){
            cin>>x;
            add_r(head,x);
        }else if(c=="IL"){
            cin>>k>>x;
            add_l(k+2,x);
        }else{
            cin>>k>>x;
            add_r(k+2,x);
        }
    }
    head=r[head];
    while(head!=tail){
        cout<<e[head]<<' ';
        head=r[head];
    }
    return 0;
}