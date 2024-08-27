#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
using namespace std;
const int N=200;
struct Grammar
{
	int pos;
	string left;
	set<string> search;//搜索符
	vector<string> right;
	bool operator<(const Grammar& a)const
	{
        if(left==a.left){
            if(right==a.right){
				if(pos==a.pos){
					return search<a.search;
				}else return pos<a.pos;
            }else return right<a.right;
        }else return left<a.left;
	}
}G[N];//语法

struct LR_table
{
	map<string,int> Goto;
	map<string,int> Shift;//移进
	map<string,int> Reduce;//规约
}LR[N];//LR分析表

struct node
{
    string first;
    string second;
    vector<string> tac;//三地址代码
};//符号栈节点

set<Grammar> I[N];//项目集闭包
map<string,set<string>> First;//非终结符的First集合
map<string,bool> Vn;//非终结符
queue<int> production_queue;//项目集队列,通过此队列获取LR自动机
map<set<Grammar>,int> vis;//项目集是否出现，与项目集队列配套
int num=1;//项目集数量
int idx=0;//TAC下标
int idx2=0;

map<string,string>Vt;
void init_1(){
    Vt["!"]="NOT";
    Vt["<"]="LSS";
    Vt[">"]="GRE";
    Vt["="]="ASSIGN";
    Vt["!="]="NEQ";
    Vt["%"]="MOD";
    Vt["&&"]="AND";
    Vt["("]="LPARENT";
    Vt[")"]="RPARENT";
    Vt["*"]="MULT";
    Vt["+"]="PLUS";
    Vt[","]="COMMA";
    Vt["-"]="MINU";
    Vt["/"]="DIV";
    Vt[";"]="SEMICN";
    Vt["<="]="LEQ";
    Vt["=="]="EQL";
    Vt[">="]="GEQ";
    Vt["["]="LBRACK";
    Vt["]"]="RBRACK";
    Vt["break"]="BREAKTK";
    Vt["const"]="CONSTTK";
    Vt["continue"]="CONTINUETK";
    Vt["else"]="ELSETK";
    Vt["getint"]="GETINTTK";
    Vt["if"]="IFTK";
    Vt["int"]="INTTK";
    Vt["main"]="MAINTK";
    Vt["printf"]="PRINTFTK";
    Vt["return"]="RETURNTK";
    Vt["void"]="VOIDTK";
    Vt["while"]="WHILETK";
    Vt["{"]="LBRACE";
    Vt["||"]="OR";
    Vt["}"]="RBRACE";
}

void check(string &tmp,queue<pair<string,string>>& q){
    if(tmp==""||tmp==" "||tmp=="\t"||tmp=="\n"){tmp="";return;}
    else if(Vt.count(tmp)){
        q.push(make_pair(Vt[tmp],tmp));
    }
    else if(tmp[0]>='0'&&tmp[0]<='9'){
        q.push(make_pair("INTCON",tmp));
    }else {
        q.push(make_pair("IDENFR",tmp));
    }
    tmp="";
}

queue<pair<string,string>> get_Word()
{
    queue<pair<string,string>>q;
    string line;
    while(getline(cin, line)){
        string tmp="";
        line+="        ";
        int flag=0;//注释标记
        for(int i=0;i<line.size();i++){
            if(flag==1){
                if(i+1<line.size()&&line[i]=='*'&&line[i+1]=='/'){
                    i++;
                    flag=0;
                }
            }
            else if(line[i]=='"'){
                check(tmp,q);
                tmp+='"';
                int j=i+1;
                while(j<line.size()&&line[j]!='"'){
                    tmp+=line[j];
                    j++;
                }
                i=j;
                q.push(make_pair("STRCON",tmp+'"'));
                tmp="";
            }
            else if(i+1<line.size()&&line[i]=='/'&&line[i+1]=='*'){
                check(tmp,q);
                flag=1;
                break;
            }
            else if(i+1<line.size()&&line[i]=='/'&&line[i+1]=='/'){
                check(tmp,q);
                break;
            }
            else if(line[i]==' '||line[i]=='\t'||line[i]=='\n'||line[i]=='\r'){
                check(tmp,q);
            }else if(Vt.count(string(&line[i],1))){
                if(i+1<line.size()&&Vt.count(string(&line[i],2))){
                    check(tmp,q);
                    q.push(make_pair(Vt[string(&line[i],2)],string(&line[i],2)));
                    i++;
                }
                else{
                    check(tmp,q);
                    q.push(make_pair(Vt[string(&line[i],1)],string(&line[i],1)));
                }
            }else {
                tmp+=line[i];
            }
        }
    }
    return q;
}

int get_Closure(int id){
	if(!I[id].size())return -1;
	queue<Grammar>g_queue;//临时语法队列
	map<Grammar,bool>g_vis;//语法队列标记
	for(auto i:I[id]){//获取语法
		if(i.pos<i.right.size()&&Vn.count(i.right[i.pos])&&!g_vis.count(i)){
			g_queue.push(i);
			g_vis[i]=true;
		}
	}

	while(g_queue.size()){
		auto t=g_queue.front();
		g_queue.pop();
		for(int j=1;j<=47;j++){
			if(G[j].left==t.right[t.pos]){
                Grammar i=G[j];
                if(i.right[i.pos]=="EPSILON")i.pos++;
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
                if(Vn.count(i.right[0])&&!g_vis.count(i)){
                    g_queue.push(i);
                    g_vis[i]=true;
                }
                I[id].insert(i);
			}
		}
	}
	if(!vis.count(I[id])){
        //合并项目集的语法
        // set<Grammar> tmp;
        // for(auto i:I[id]){
        //     Grammar tmp2=i;
        //     for(auto j:I[id]){
        //         if(i.left==j.left&&i.right==j.right&&i.pos==j.pos){
        //             tmp2.search.insert(j.search.begin(),j.search.end());
        //         }
        //     }
        //     if(!tmp.count(tmp2))tmp.insert(tmp2);
        // }
        // I[id]=tmp;

		//输出
		// cout<<"\n----------------------\n";
		// cout<<id<<endl;
		// for(auto i:I[id]){
		// 	cout<<i.left<<"->";
		// 	for(auto j:i.right){
		// 		cout<<j<<' ';
		// 	}
		// 	cout<<i.pos<<" |";
		// 	for(auto j:i.search)cout<<j<<' ';
		// 	cout<<endl;
		// }

		production_queue.push(id);
		vis[I[id]]=id;
		num++;
	}else {
        int t=id;
        id=vis[I[id]];
		I[t].clear();
	}
    return id;
}
void init_LR(){
	Grammar g=G[1];
	g.search.insert("#");
	I[1].insert(g);
	get_Closure(1);
}
void get_LRtable(){
	init_LR();
	while(production_queue.size()){
		int t=production_queue.front();

		production_queue.pop();
		set<string>st;//移进的字符
		for(auto i:I[t]){
			if(i.pos<i.right.size())
			st.insert(i.right[i.pos]);
		}
		for(auto i:st){
			for(auto j:I[t]){
				if(j.pos<j.right.size()&&j.right[j.pos]==i){
					Grammar g=j;
					g.pos=j.pos+1;
					I[num].insert(g);
				}
			}
			int id=get_Closure(num);
            if(id==-1)continue;
            //判断归约
            for(auto i:I[id]){
                if(i.pos>=i.right.size()){
                    for(auto p:i.search){
                        for(int j=1;j<=47;j++){
                            if(G[j].left==i.left&&G[j].right==i.right){
                                if(G[j].left=="CompUnit")LR[id].Reduce[p]=-j;
                                else LR[id].Reduce[p]=j;
                            }
                        }
                    }
                }
            }
            if(Vn.count(i)) LR[t].Goto[i]=id;
            else LR[t].Shift[i]=id;
		}
	}
	// cout<<num-1<<endl;
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

void init_2(){
    init_1();
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
    G[10].right.push_back("IDENFR"); 
    G[11].left="VarDef";
    G[11].right.push_back("IDENFR"); G[11].right.push_back("="); G[11].right.push_back("Exp"); 
    G[12].left="Stmt";
    G[12].right.push_back("IDENFR"); G[12].right.push_back("="); G[12].right.push_back("Exp"); G[12].right.push_back(";"); 
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
    G[19].right.push_back("IDENFR"); G[19].right.push_back("="); G[19].right.push_back("getint"); G[19].right.push_back("("); G[19].right.push_back(")"); G[19].right.push_back(";"); 
    G[20].left="Stmt";
    G[20].right.push_back("printf"); G[20].right.push_back("("); G[20].right.push_back("STRCON"); G[20].right.push_back("ExpList"); G[20].right.push_back(")"); G[20].right.push_back(";"); 
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
    G[26].right.push_back("IDENFR"); 
    G[27].left="PrimaryExp";
    G[27].right.push_back("INTCON"); 
    G[28].left="UnaryExp";
    G[28].right.push_back("PrimaryExp"); 
    G[29].left="MulExp";
    G[29].right.push_back("MulExp"); G[29].right.push_back("*"); G[29].right.push_back("UnaryExp"); 
    G[30].left="MulExp";
    G[30].right.push_back("MulExp"); G[30].right.push_back("/"); G[30].right.push_back("UnaryExp"); 
    G[31].left="MulExp";
    G[31].right.push_back("MulExp"); G[31].right.push_back("%"); G[31].right.push_back("UnaryExp"); 
    G[32].left="MulExp";
    G[32].right.push_back("UnaryExp"); 
    G[33].left="AddExp";
    G[33].right.push_back("AddExp"); G[33].right.push_back("+"); G[33].right.push_back("MulExp"); 
    G[34].left="AddExp";
    G[34].right.push_back("AddExp"); G[34].right.push_back("-"); G[34].right.push_back("MulExp"); 
    G[35].left="AddExp";
    G[35].right.push_back("MulExp"); 
    G[36].left="RelExp";
    G[36].right.push_back("RelExp"); G[36].right.push_back("<"); G[36].right.push_back("AddExp"); 
    G[37].left="RelExp";
    G[37].right.push_back("RelExp"); G[37].right.push_back(">"); G[37].right.push_back("AddExp"); 
    G[38].left="RelExp";
    G[38].right.push_back("RelExp"); G[38].right.push_back("<="); G[38].right.push_back("AddExp"); 
    G[39].left="RelExp";
    G[39].right.push_back("RelExp"); G[39].right.push_back(">="); G[39].right.push_back("AddExp"); 
    G[40].left="RelExp";
    G[40].right.push_back("AddExp"); 
    G[41].left="EqExp";
    G[41].right.push_back("EqExp"); G[41].right.push_back("=="); G[41].right.push_back("RelExp"); 
    G[42].left="EqExp";
    G[42].right.push_back("EqExp"); G[42].right.push_back("!="); G[42].right.push_back("RelExp"); 
    G[43].left="EqExp";
    G[43].right.push_back("RelExp"); 
    G[44].left="LAndExp";
    G[44].right.push_back("LAndExp"); G[44].right.push_back("&&"); G[44].right.push_back("EqExp"); 
    G[45].left="LAndExp";
    G[45].right.push_back("EqExp"); 
    G[46].left="LOrExp";
    G[46].right.push_back("LOrExp"); G[46].right.push_back("||"); G[46].right.push_back("LAndExp"); 
    G[47].left="LOrExp";
    G[47].right.push_back("LAndExp"); 

	Vn["AddExp"]=true;
	Vn["Block"]=true;
	Vn["BlockItem"]=true;
	Vn["BlockItemList"]=true;
	Vn["CompUnit"]=true;
	Vn["Cond"]=true;
	Vn["EqExp"]=true;
	Vn["Exp"]=true;
	Vn["ExpList"]=true;
	Vn["LAndExp"]=true;
	Vn["LOrExp"]=true;
	Vn["MulExp"]=true;
	Vn["PrimaryExp"]=true;
	Vn["RelExp"]=true;
	Vn["Stmt"]=true;
	Vn["UnaryExp"]=true;
	Vn["VarDecl"]=true;
	Vn["VarDeclList"]=true;
	Vn["VarDef"]=true;
    
	init_First();
}

void ProcessIfStatements(vector<string> &statements, int s1, int s2, int id) {
    for (int i = 0; i < s1; ++i) {
        string s = statements[i];
        if (s.back() == '-') {
            if (s.find("if") < s.size()) {
                statements[i] = s.substr(0, s.size() - 1) + to_string(s1 - i);
            } else {
                statements[i] = s.substr(0, s.size() - 1) + to_string(s1 + s2 - i + (id == 17 || id == 18));
            }
        }
    }
}

vector<string> ans;

node Translate(int id, vector<node> &t) {
    node v;
    v.first = G[id].left;
    int s1,s2;
    switch (id) {
        case 27:
            v.tac.push_back("li $t0,"+t[0].second);
            v.second="var"+to_string(idx++);
            v.tac.push_back("sw $t0,"+v.second);
            ans.push_back(v.second+": .word 0");
            break;
        case 10:
            v.second=t[0].second;
            ans.push_back(v.second+": .word 0");
            break;




        case 11:
        case 12: {
            for(auto x:t[2].tac)v.tac.push_back(x);
            v.tac.push_back("lw $t0,"+t[2].second);
            v.tac.push_back("sw $t0,"+t[0].second);
            if(id==10){
                v.second=t[0].second;
                ans.push_back(v.second+": .word 0");
            }
            break;



            for (auto i : t[2].tac) v.tac.push_back(i);
            v.tac.push_back(t[0].second + "=" + t[2].second);
            break;
        }
        case 16:
        case 17:
        case 18: {
            int s1=t[2].tac.size(),s2=t[4].tac.size();
            for(int i=0;i<s1;++i){
                string s=t[2].tac[i];
                if(s.back()=='?'){
                    if(s[0]=='b'){
                        t[2].tac[i]=s.substr(0,s.size()-1)+"p"+to_string(s1-i);
                    }else{
                        t[2].tac[i]=s.substr(0,s.size()-1)+"p"+to_string(s1+s2-i+(id==16||id==17));
                    }
                }
            }
            for(auto x:t[2].tac)v.tac.push_back(x);
            for(auto x:t[4].tac)v.tac.push_back(x);
            if(id==17){
                v.tac.push_back("k p"+to_string(t[6].tac.size()+1));
                for(auto x:t[6].tac)v.tac.push_back(x);
            }
            if(id==18){
                v.tac.push_back("k p"+to_string(v.tac.size()*(-1)));
            }
            break;


            // s1 = t[2].tac.size(), s2 = t[4].tac.size();
            // ProcessIfStatements(t[2].tac, s1, s2, id);
            // for (auto i : t[2].tac) v.tac.push_back(i);
            // for (auto i : t[4].tac) v.tac.push_back(i);
            // if (id == 17) {
            //     v.tac.push_back("goto " + to_string(t[6].tac.size() + 1));
            //     for (auto i : t[6].tac) v.tac.push_back(i);
            // } else if (id == 18) {
            //     v.tac.push_back("goto " + to_string(v.tac.size() * (-1)));
            // }
            // break;
        }
        case 19:
            v.tac.push_back("la $a0,"+t[0].second);
            v.tac.push_back("li $v0,5");
            v.tac.push_back("syscall");
            v.tac.push_back("sw $v0,"+t[0].second);
            break;

            // v.tac.push_back(t[0].second + "=getint()");
            // break;
        case 20:
            for(auto x:t[3].tac)v.tac.push_back(x);
            int cnt=0;
            string s=t[2].second,tmp="";
            vector<string> vv;
            for(int i=0;i<t[3].second.size();++i){
                if(t[3].second[i]=='!')vv.push_back(tmp),tmp="";
                else tmp+=t[3].second[i];
            }
            for(int i=1;i<s.size()-1;++i){
                if(s[i]=='%'&&i+1<s.size()-1&&s[i+1]=='d'){
                    if(tmp.size()){
                        tmp='"'+tmp+'"';
                        ans.push_back("str"+to_string(idx2)+": .asciiz "+tmp);
                        v.tac.push_back("la $a0,str"+to_string(idx2++));
                        v.tac.push_back("li $v0,4");
                        v.tac.push_back("syscall");
                    }
                    v.tac.push_back("lw $a0,"+vv[cnt++]);
                    v.tac.push_back("li $v0,1");
                    v.tac.push_back("syscall");
                    i++; tmp="";
                }else tmp+=s[i];
            }
            if(tmp.size()){
                tmp='"'+tmp+'"';
                ans.push_back("str"+to_string(idx2)+": .asciiz "+tmp);
                v.tac.push_back("la $a0,str"+to_string(idx2++));
                v.tac.push_back("li $v0,4");
                v.tac.push_back("syscall");
            }
            break;

            // v.tac.push_back("param " + t[2].second);
            // for (auto i : t[3].tac) v.tac.push_back("param " + i);
            // v.tac.push_back("call printf," + to_string(v.tac.size()));
            // break;

        case 21:
            {
                for(auto i:t[2].tac)t[0].tac.push_back(i);
                t[0].second+=t[2].second+'!';
                v=t[0];
            }
            break;



            // t[0].tac.push_back(t[2].second);
            // v = t[0];
            // break;
            
        case 25:{
            v.second = t[1].second;
            for (auto i : t[1].tac) v.tac.push_back(i);
            break;}
        case 29:
        case 30:
        case 31:
        case 33:
        case 34:
            {v.second="var"+to_string(idx++);
            ans.push_back(v.second+": .word 0");
            for(auto x:t[0].tac)v.tac.push_back(x);
            for(auto x:t[2].tac)v.tac.push_back(x);
            v.tac.push_back("lw $t0,"+t[0].second);
            v.tac.push_back("lw $t1,"+t[2].second);
            if(id==29)v.tac.push_back("mulo $t2,$t0,$t1");
            if(id==30)v.tac.push_back("div $t2,$t0,$t1");
            if(id==31)v.tac.push_back("rem $t2,$t0,$t1");
            if(id==33)v.tac.push_back("add $t2,$t0,$t1");
            if(id==34)v.tac.push_back("sub $t2,$t0,$t1");
            v.tac.push_back("sw $t2,"+v.second);
            break;


            // v.second = "T" + to_string(++idx);
            // for (auto i : t[0].tac) v.tac.push_back(i);
            // for (auto i : t[2].tac) v.tac.push_back(i);
            // v.tac.push_back(v.second + "=" + t[0].second + t[1].second + t[2].second);
            // break;}
        case 36:
        case 37:
        case 38:
        case 39:
        case 41:
        case 42:
            {for(auto x:t[0].tac)v.tac.push_back(x);
            for(auto x:t[2].tac)v.tac.push_back(x);
            v.tac.push_back("lw $t0,"+t[0].second);
            v.tac.push_back("lw $t1,"+t[2].second);
            if(id==36)v.tac.push_back("blt $t0,$t1,?");
            if(id==37)v.tac.push_back("bgt $t0,$t1,?");
            if(id==38)v.tac.push_back("ble $t0,$t1,?");
            if(id==39)v.tac.push_back("bge $t0,$t1,?");
            if(id==41)v.tac.push_back("beq $t0,$t1,?");
            if(id==42)v.tac.push_back("bne $t0,$t1,?");
            v.tac.push_back("k ?");
            }
            break;



            // for (auto i : t[0].tac) v.tac.push_back(i);
            // for (auto i : t[2].tac) v.tac.push_back(i);
            // v.second = t[0].second + G[id].right[1] + t[2].second;
            // v.tac.push_back("if " + v.second + " goto -");
            // v.tac.push_back("goto -");
            // break;}
        case 44:
        case 46:
        {
            
            s1=t[0].tac.size(),s2=t[2].tac.size();
            for(int i=0;i<s1;++i){
                string x=t[0].tac[i];
                if(x[0]=='b'&&x.back()=='?')x=x.substr(0,x.size()-1)+"p"+to_string(s1-i);
                v.tac.push_back(x);
            }
            for(auto x:t[2].tac)v.tac.push_back(x);
            break;



            // s1 = t[0].tac.size(), s2 = t[2].tac.size();
            // for (int i = 0; i < s1; ++i) {
            //     string x = t[0].tac[i];
            //     if (x.find("if") < x.size() && x.back() == '-') x = x.substr(0, x.size() - 1) + to_string(s1 - i);
            //     v.tac.push_back(x);
            // }
            // for (auto i : t[2].tac) v.tac.push_back(i);
            // break;}
        }
        default:
            for (auto [first, second, tac] : t) {
                v.second += second;
                v.tac.insert(v.tac.end(), tac.begin(), tac.end());
            }
            break;
    }
    
    if (id == 1) v.tac.push_back("nop");
    return v;
}


void ProcessGotoStatements(vector<string> &TAC, int i, int res) {
    if (TAC[i].find("goto") < TAC[i].size()) {
        for (int j = TAC.size() - 1; j >= 0; --j) {
            if (TAC[i][0]=='k') {
                int tempRes = 0, now = 1;
                for (int k = TAC[j].size() - 1;; k--) {
                    if (TAC[j][k] == 'p' || TAC[j][k] == '-') {
                        if (TAC[j][k] == '-') tempRes = -tempRes;
                        break;
                    }
                    tempRes = tempRes + (TAC[j][k] - '0') * now;
                    now *= 10;
                }
                if (tempRes == res && TAC[j][0] == 'g') {
                    TAC[i] = TAC[j];
                    break;
                }
            }
        }
    }
}

void GenerateTAC(vector<string> &tac) {
    vector<string> TAC;
    for (int i = 0; i < tac.size(); ++i) {
        string s = tac[i];
        if (s[0]=='b'||s[0]=='k') {
            int res = 0, now = 1;
            for (int j = s.size() - 1;; j--) {
                if (s[j] == 'p' || s[j] == '-') {
                    if (s[j] == '-') s = s.substr(0, j) + to_string((-res + i));
                    else s = s.substr(0, j ) + to_string(res + i);
                    TAC.push_back(s);
                    break;
                }
                res = res + (s[j] - '0') * now;
                now *= 10;
            }
        } else {
            TAC.push_back(s);
        }
    }

    for (int i = TAC.size() - 1; i >= 0; --i) {
        ProcessGotoStatements(TAC, i, 0);
    }

    cout<<".data"<<endl;
	for(auto i:ans)cout<<i<<endl;
	cout<<".text"<<endl;
	for(int i=0;i<TAC.size();++i){
		if(TAC[i][0]=='k')cout<<"p"<<i<<": b"<<TAC[i].substr(1)<<endl;
        else cout<<"p"<<i<<": "<<TAC[i]<<endl;
	}
}

void LR_Analysis(queue<pair<string,string>> &in){
    stack<int>state;state.push(1);//状态栈
    stack<node>sign;sign.push({"","#",vector<string>{}});//符号栈
    in.push(make_pair("","#"));
    while(in.size()){
        auto i=in.front().second;
        if(in.front().first=="IDENFR"||in.front().first=="INTCON"||in.front().first=="STRCON")i=in.front().first;
        if(LR[state.top()].Shift.count(i)){
            state.push(LR[state.top()].Shift[i]);
            sign.push({in.front().first,in.front().second,vector<string>{}});
            in.pop();
        }else if(LR[state.top()].Reduce.count(i)){
            vector<node> t;//记录符号栈中规约的信息
            int j=LR[state.top()].Reduce[i];
            bool flag=0;
            if(j<0){j=-j;flag=1;}
            int cnt=G[j].right.size();
            if(G[j].right[0]=="EPSILON")cnt=0;
            for(int j=0;j<cnt;j++){
                t.insert(t.begin(),sign.top());
                sign.pop();
                state.pop();
            }
            sign.push(Translate(j,t));
            if(flag)break;
            if(LR[state.top()].Goto.count(sign.top().first)){
                state.push(LR[state.top()].Goto[sign.top().first]);
            }else{
                cout<<"ERROR\n";
                break;
            }
        }else{
            cout<<"ERROR\n";
            break;
        }
    }
	GenerateTAC(sign.top().tac);
}

int main(){
	freopen("testfile.txt","r",stdin);
    freopen("mips.txt","w",stdout);
	init_2();
	get_LRtable();
    queue<pair<string,string>>in=get_Word();
    LR_Analysis(in);
}