#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
// #include"t1.h"
using namespace std;
const int N=200;
struct Grammar
{
	int pos;
	string left;
	set<string> search;
	vector<string> right;
	bool operator<(const Grammar& a)const
	{
		if(pos==a.pos){
			if(left==a.left){
				if(search==a.search){
					return right<a.right;
				}else return search<a.search;
			}else return left<a.left;
		}else return pos<a.pos;
	}
}G[N];//语法

struct LR_table
{
	unordered_map<string,int> gt;
	unordered_map<string,int> ac;
	unordered_map<string,int> gy;
}LR[N];

map<string,set<string>> First;//非终结符的First集合
unordered_map<string,int>Vn;//非终结符
set<Grammar> I[N];//项目集
map<set<Grammar>,int> vis;//是否有相同项目

void init(){
	G[1].left="CompUnit";
	G[1].right.push_back("Block"); 
	G[2].left="Block";
	G[2].right.push_back("{"); G[2].right.push_back("BlockItemList"); G[2].right.push_back("}"); 
	G[3].left="BlockItemList";
	G[3].right.push_back("BlockItemList"); G[3].right.push_back("BlockItem"); 
	G[4].left="BlockItemList";
	G[4].right.push_back("EPSILON"); 
	G[5].left="BlockItem";
	G[5].right.push_back("VarDecl"); 
	G[6].left="BlockItem";
	G[6].right.push_back("Stmt"); 
	G[7].left="VarDecl";
	G[7].right.push_back("int"); G[7].right.push_back("VarDeclList"); G[7].right.push_back(";"); 
	G[8].left="VarDeclList";
	G[8].right.push_back("VarDeclList"); G[8].right.push_back(","); G[8].right.push_back("VarDef"); 
	G[9].left="VarDeclList";
	G[9].right.push_back("VarDef"); 
	G[10].left="VarDef";
	G[10].right.push_back("Ident"); 
	G[11].left="VarDef";
	G[11].right.push_back("Ident"); G[11].right.push_back("="); G[11].right.push_back("Exp"); 
	G[12].left="Stmt";
	G[12].right.push_back("Ident"); G[12].right.push_back("="); G[12].right.push_back("Exp"); G[12].right.push_back(";"); 
	G[13].left="Stmt";
	G[13].right.push_back("Exp"); G[13].right.push_back(";"); 
	G[14].left="Stmt";
	G[14].right.push_back(";"); 
	G[15].left="Stmt";
	G[15].right.push_back("Block"); 
	G[16].left="Stmt";
	G[16].right.push_back("if"); G[16].right.push_back("("); G[16].right.push_back("Cond"); G[16].right.push_back(")"); G[16].right.push_back("Block"); 
	G[17].left="Stmt";
	G[17].right.push_back("if"); G[17].right.push_back("("); G[17].right.push_back("Cond"); G[17].right.push_back(")"); G[17].right.push_back("Block"); G[17].right.push_back("else"); G[17].right.push_back("Block"); 
	G[18].left="Stmt";
	G[18].right.push_back("while"); G[18].right.push_back("("); G[18].right.push_back("Cond"); G[18].right.push_back(")"); G[18].right.push_back("Stmt"); 
	G[19].left="Stmt";
	G[19].right.push_back("Ident"); G[19].right.push_back("="); G[19].right.push_back("getint"); G[19].right.push_back("("); G[19].right.push_back(")"); G[19].right.push_back(";"); 
	G[20].left="Stmt";
	G[20].right.push_back("printf"); G[20].right.push_back("("); G[20].right.push_back("FormatString"); G[20].right.push_back("ExpList"); G[20].right.push_back(")"); G[20].right.push_back(";"); 
	G[21].left="ExpList";
	G[21].right.push_back("ExpList"); G[21].right.push_back(","); G[21].right.push_back("Exp"); 
	G[22].left="ExpList";
	G[22].right.push_back("EPSILON"); 
	G[23].left="Exp";
	G[23].right.push_back("AddExp"); 
	G[24].left="Cond";
	G[24].right.push_back("LOrExp"); 
	G[25].left="PrimaryExp";
	G[25].right.push_back("("); G[25].right.push_back("Exp"); G[25].right.push_back(")"); 
	G[26].left="PrimaryExp";
	G[26].right.push_back("Ident"); 
	G[27].left="PrimaryExp";
	G[27].right.push_back("IntConst"); 
	G[28].left="UnaryExp";
	G[28].right.push_back("PrimaryExp"); 
	G[29].left="MulExp";
	G[29].right.push_back("UnaryExp"); 
	G[30].left="MulExp";
	G[30].right.push_back("MulExp"); G[30].right.push_back("*"); G[30].right.push_back("UnaryExp"); 
	G[31].left="MulExp";
	G[31].right.push_back("MulExp"); G[31].right.push_back("/"); G[31].right.push_back("UnaryExp"); 
	G[32].left="MulExp";
	G[32].right.push_back("MulExp"); G[32].right.push_back("%"); G[32].right.push_back("UnaryExp"); 
	G[33].left="AddExp";
	G[33].right.push_back("MulExp"); 
	G[34].left="AddExp";
	G[34].right.push_back("AddExp"); G[34].right.push_back("+"); G[34].right.push_back("MulExp"); 
	G[35].left="AddExp";
	G[35].right.push_back("AddExp"); G[35].right.push_back("-"); G[35].right.push_back("MulExp"); 
	G[36].left="RelExp";
	G[36].right.push_back("AddExp"); 
	G[37].left="RelExp";
	G[37].right.push_back("RelExp"); G[37].right.push_back("<"); G[37].right.push_back("AddExp"); 
	G[38].left="RelExp";
	G[38].right.push_back("RelExp"); G[38].right.push_back(">"); G[38].right.push_back("AddExp"); 
	G[39].left="RelExp";
	G[39].right.push_back("RelExp"); G[39].right.push_back("<="); G[39].right.push_back("AddExp"); 
	G[40].left="RelExp";
	G[40].right.push_back("RelExp"); G[40].right.push_back(">="); G[40].right.push_back("AddExp"); 
	G[41].left="EqExp";
	G[41].right.push_back("RelExp"); 
	G[42].left="EqExp";
	G[42].right.push_back("EqExp"); G[42].right.push_back("=="); G[42].right.push_back("RelExp"); 
	G[43].left="EqExp";
	G[43].right.push_back("EqExp"); G[43].right.push_back("!="); G[43].right.push_back("RelExp"); 
	G[44].left="LAndExp";
	G[44].right.push_back("EqExp"); 
	G[45].left="LAndExp";
	G[45].right.push_back("LAndExp"); G[45].right.push_back("&&"); G[45].right.push_back("EqExp"); 
	G[46].left="LOrExp";
	G[46].right.push_back("LAndExp"); 
	G[47].left="LOrExp";
	G[47].right.push_back("LOrExp"); G[47].right.push_back("||"); G[47].right.push_back("LAndExp"); 

	Vn["AddExp"]=1;
	Vn["Block"]=1;
	Vn["BlockItem"]=1;
	Vn["BlockItemList"]=1;
	Vn["CompUnit"]=1;
	Vn["Cond"]=1;
	Vn["EqExp"]=1;
	Vn["Exp"]=1;
	Vn["ExpList"]=1;
	Vn["LAndExp"]=1;
	Vn["LOrExp"]=1;
	Vn["MulExp"]=1;
	Vn["PrimaryExp"]=1;
	Vn["RelExp"]=1;
	Vn["Stmt"]=1;
	Vn["UnaryExp"]=1;
	Vn["VarDecl"]=1;
	Vn["VarDeclList"]=1;
	Vn["VarDef"]=1;
}
//求闭包
queue<int>production_queue;//项目集队列

int num=1;//项目集总数
//求闭包
int checkProduction(int id){
	if(I[id].size()==0)return -1;
	queue<Grammar>g_queue;//语法队列
	map<Grammar,int>g_vis;//语法队列
	for(auto i:I[id]){//获取初始I，且
		if(i.pos<i.right.size()&&Vn.count(i.right[i.pos])&&!g_vis.count(i)){
			g_queue.push(i);
            i.search.clear();
			g_vis[i]++;
		}
	}
	while(g_queue.size()){
		auto t=g_queue.front();
		g_queue.pop();
		for(int j=1;j<=47;j++){
			if(t.pos<t.right.size()&&G[j].left==t.right[t.pos]){
                if(!g_vis.count(G[j]))I[id].insert(G[j]);
                for(auto i:I[id]){
                    if(G[j].left==i.left&&G[j].right==i.right){
                        int k=t.pos+1;
                        for(;k<t.right.size();k++){//遍历.pos后面的
                            for(auto p:First[t.right[k]]){
                                if(p!="EPSILON")i.search.insert(p);
                            }
                            if(!First[t.right[k]].count("EPSILON"))break;
                        }
                        if(k>=t.right.size()){
                            i.search.insert(t.search.begin(),t.search.end());
                        }
                        I[id].erase(i);
                        I[id].insert(i);
                        if(Vn.count(i.right[0])&&!g_vis.count(i)){
                            g_queue.push(i);
                            i.search.clear();
                            g_vis[i]++;
                        }
                        if(i.right[i.pos]=="EPSILON"){I[id].erase(i);i.pos++;I[id].insert(i);}
                        break;
                    }
                }
			}
		}
	}
	if(!vis.count(I[id])){

		//输出
		cout<<"\n----------------------\n";
		cout<<id<<endl;
		for(auto i:I[id]){
			cout<<i.left<<"->";
			for(auto j:i.right){
				cout<<j<<' ';
			}
			cout<<i.pos<<" |";
			for(auto j:i.search)cout<<j<<' ';
			cout<<endl;
		}

		production_queue.push(id);
		vis[I[id]]=id;
		num++;
        return id;
	}else {
		int t=vis[I[id]];
		I[id].clear();
		return t;
	}
}

void init_LR(){
	Grammar g=G[1];
	g.search.insert("EOF");
	I[1].insert(g);
	checkProduction(1);
}

void get_LRtable(){
	init_LR();
	while(production_queue.size()){
		int t=production_queue.front();
		cout<<"\n|||||||||||||||||||||||||||||||||\n\n";
		cout<<t<<':'<<endl;
		production_queue.pop();
		set<string>st;//移进的字符
		for(auto i:I[t]){
			if(i.pos<i.right.size())
			st.insert(i.right[i.pos]);
		}
		for(auto i:st){
			cout<<"\nRead "<<i<<endl;
			for(auto j:I[t]){
				if(j.pos<j.right.size()&&j.right[j.pos]==i){
					Grammar g=j;
					g.pos=j.pos+1;
					I[num].insert(g);
				}
			}
			int id=checkProduction(num);
			if(id==-1)continue;
			//规约
			for(auto i:I[num]){
				if(i.pos==i.right.size()){
					for(auto p:i.search){
						for(int j=1;j<=47;j++){
							if(G[j].left==i.left&&G[j].right==i.right){
								LR[t].gy[p]=j;
							}
						}
					}
				}
			}
			if(Vn.count(i)) LR[t].gt[i]=id;
			else LR[t].ac[i]=id;
		}

	}
	cout<<num<<endl;
}

void get_First(string r){
	if(!Vn.count(r)){
		First[r].insert(r);
		return;
	}else{
		for(int j=1;j<=47;j++){
			if(G[j].left==r){
				for(int k=0;k<G[j].right.size();k++){
					if(G[j].right[k]!=r)get_First(G[j].right[k]);
					First[r].insert(First[G[j].right[k]].begin(),First[G[j].right[k]].end());
					if(!First[G[j].right[k]].count("EPSILON")){
						break;
					}
				}
    		}
		}
	}
}

void init_First(){
	for(int j=1;j<=47;j++){
		auto l=G[j].left,r=G[j].right[0];
		if(Vn.count(l)&&!Vn.count(r)){
			First[l].insert(r);
		}
		for(auto i:G[j].right){
			if(!Vn.count(i))First[i].insert(i);
		}
	}
	for(auto [i,j]:Vn)get_First(i);
}

int main(){
	// freopen("testfile.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	init();
	init_First();
	get_LRtable();
}