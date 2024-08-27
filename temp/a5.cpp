#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
const int N=200;

string transform(string &s){
	if(s=="main")return "MAINTK";
	if(s=="const")return "CONSTTK";
	if(s=="int")return "INTTK";
	if(s=="break")return "BREAKTK";
	if(s=="continue")return "CONTINUETK";
	if(s=="if")return "IFTK";
	if(s=="else")return "ELSETK";
	if(s=="!")return "NOT";
	if(s=="&&")return "AND";
	if(s=="||")return "OR";
	if(s=="while")return "WHILETK";
	if(s=="getint")return "GETINTTK";
	if(s=="printf")return "PRINTFTK";
	if(s=="return")return "RETURNTK";
	if(s=="+")return "PLUS";
	if(s=="-")return "MINU";
	if(s=="void")return "VOIDTK";
	if(s=="*")return "MULT";
	if(s=="/")return "DIV";
	if(s=="%")return "MOD";
	if(s=="<")return "LSS";
	if(s=="<=")return "LEQ";
	if(s==">")return "GRE";
	if(s==">=")return "GEQ";
	if(s=="==")return "EQL";
	if(s=="!=")return "NEQ";
	if(s=="=")return "ASSIGN";
	if(s==";")return "SEMICN";
	if(s==",")return "COMMA";
	if(s=="(")return "LPARENT";
	if(s==")")return "RPARENT";
	if(s=="[")return "LBRACK";
	if(s=="]")return "RBRACK";
	if(s=="{")return "LBRACE";
	if(s=="}")return "RBRACE";
	return "NONE";
}

queue<pair<string,string>> q;

void getWord(){
	ifstream fin;
	fin.open("testfile.txt",ios::in);
	char c;
	int flag=0;
	string now;
	while(1){
		int ok=1;
		if(c!='_'&&!isalpha(c)&&!isdigit(c)){
			if(now.size()){
				if(transform(now)!="NONE")q.push({transform(now),now});
				else{
					if(flag)q.push({"IDENFR",now});
					else q.push({"INTCON",now});
				}
			}
			flag=0;
			now.clear();
		}
		if(c=='/'){
			char pre=c;
			c=fin.get();
			if(c=='/'){
				string tmp;
				getline(fin,tmp);	
			}else{
				if(c=='*'){
					while((c=fin.get())!='*');
					c=fin.get();
				}else{
					string tmp; tmp+=pre;
					q.push({transform(tmp),tmp});
					ok=0;
				}
			}
		}
		else if(c=='"'){
			string tmp="\"";
			while((c=fin.get())!='"')tmp+=c;
			tmp+="\"";
			q.push({"STRCON",tmp});
		}
		else if(c=='|'||c=='&'){
			string tmp; tmp+=c; tmp+=c;
			c=fin.get();
			q.push({transform(tmp),tmp});
		}
		else if(c=='!'||c=='<'||c=='>'||c=='='){
			string tmp; tmp+=c;
			c=fin.get();
			if(c=='=')tmp+="=";
			else ok=0;
			q.push({transform(tmp),tmp});
		}
		else if(isalpha(c)||c=='_'){
			flag=1;
			now+=c;
		}
		else if(isdigit(c))now+=c;
		else{
			string tmp; tmp+=c;
			if(transform(tmp)!="NONE")q.push({transform(tmp),tmp});
		}
		if(ok)if((c=fin.get())==EOF)break;
	}
	q.push({"#","#"});
}

struct Production{
	int pos;
	string left;
	vector<string> right;
	bool operator<(const Production& x)const{
		if(left==x.left){
			if(right.size()==x.right.size()){
				for(int i=0;i<right.size();++i)if(right[i]!=x.right[i])return right[i]<x.right[i];
				return pos<x.pos;
			}
			return right.size()<x.right.size();
		}
		return left<x.left;
	}
	
	void print(){
		cout<<left<<"->";
		for(auto x:right)cout<<x<<' ';
		cout<<','<<pos;
	}
};

vector<pair<string,vector<string>>> proAll;
map<pair<string,vector<string>>,int> proIdx;
map<string,vector<vector<string>>> proMap;
map<string,set<string>> First;
map<string,int> aop,cop;

void getfirst(string left){
	if(First.count(left))return ;
	for(auto right:proMap[left]){
		for(auto str:right){
			if(str==left){
				if(left=="BlockItemList"||left=="ExpList")continue;
				else break;
			}
			if(!proMap.count(str)){
				First[left].insert(str);
				break;
			}
			getfirst(str);
			int flag=0;
			for(auto x:First[str]){
				if(x=="EPSILON")flag=1;
				else First[left].insert(x);
			}
			if(!flag)break;
		}
	}
}

void init(){
	vector<pair<string,vector<string>>> v;
	// 1.Compunit -> Block
	v.pb({"Compunit",vector<string>{"Block"}});
	
	// 2.Block -> '{' BlockItemList '}'
	v.pb({"Block",vector<string>{"{","BlockItemList","}"}});
	
	// 3.BlockItemList ->  BlockItemList BlockItem 
	v.pb({"BlockItemList",vector<string>{"BlockItemList","BlockItem"}});
	
	// 4.BlockItemList ->  EPSILON
	v.pb({"BlockItemList",vector<string>{"EPSILON"}});
	
	// 5.BlockItem -> VarDecl
	v.pb({"BlockItem",vector<string>{"VarDecl"}});
	
	// 6.BlockItem -> Stmt
	v.pb({"BlockItem",vector<string>{"Stmt"}});
	
	// 7.VarDecl -> 'int' VarDeclList ';' 
	v.pb({"VarDecl",vector<string>{"int","VarDeclList",";"}});
	
	// 8.VarDeclList -> VarDeclList  ',' VarDef
	v.pb({"VarDeclList",vector<string>{"VarDeclList",",","VarDef"}});
	
	// 9.VarDeclList -> VarDef
	v.pb({"VarDeclList",vector<string>{"VarDef"}});
	
	// 10.VarDef -> Ident
	v.pb({"VarDef",vector<string>{"Ident"}});
	
	// 11.VarDef -> Ident '=' Exp
	v.pb({"VarDef",vector<string>{"Ident","=","Exp"}});
	
	// 12.Stmt -> Ident '=' Exp ';' 
	v.pb({"Stmt",vector<string>{"Ident","=","Exp",";"}});
	
	// 13.Stmt -> Exp ';'
	v.pb({"Stmt",vector<string>{"Exp",";"}});
	
	// 14.Stmt -> ';'
	v.pb({"Stmt",vector<string>{";"}});
	
	// 15.Stmt -> Block
	v.pb({"Stmt",vector<string>{"Block"}});
	
	// 16.Stmt -> 'if' '(' Cond ')' Block
	v.pb({"Stmt",vector<string>{"if","(","Cond",")","Block"}});
	
	// 17.Stmt -> 'if' '(' Cond ')' Block 'else' Block
	v.pb({"Stmt",vector<string>{"if","(","Cond",")","Block","else","Block"}});
	
	// 18.Stmt -> 'while' '(' Cond ')' Stmt
	v.pb({"Stmt",vector<string>{"while","(","Cond",")","Stmt"}});
	
	// 19.Stmt -> Ident '=' 'getint''('')'';'
	v.pb({"Stmt",vector<string>{"Ident","=","getint","(",")",";"}});
	
	// 20.Stmt -> 'printf''('FormatString ExpList ')'';' 
	v.pb({"Stmt",vector<string>{"printf","(","FormatString","ExpList",")",";"}});
	
	// 21.ExpList -> ExpList ',' Exp
	v.pb({"ExpList",vector<string>{"ExpList",",","Exp"}});
	
	// 22.ExpList-> EPSILON
	v.pb({"ExpList",vector<string>{"EPSILON"}});
	
	// 23.Exp -> AddExp 
	v.pb({"Exp",vector<string>{"AddExp"}});
	
	// 24.Cond -> LOrExp
	v.pb({"Cond",vector<string>{"LOrExp"}});
	
	// 25.PrimaryExp -> '(' Exp ')'
	v.pb({"PrimaryExp",vector<string>{"(","Exp",")"}});
	
	// 26.PrimaryExp -> Ident
	v.pb({"PrimaryExp",vector<string>{"Ident"}});
	
	// 27.PrimaryExp -> IntConst
	v.pb({"PrimaryExp",vector<string>{"IntConst"}});
	
	// 28.UnaryExp -> PrimaryExp
	v.pb({"UnaryExp",vector<string>{"PrimaryExp"}});
	
	// 29.MulExp -> UnaryExp 
	v.pb({"MulExp",vector<string>{"UnaryExp"}});
	
	// 30.MulExp -> MulExp '*' UnaryExp
	v.pb({"MulExp",vector<string>{"MulExp","*","UnaryExp"}});
	
	// 31.MulExp -> MulExp '/' UnaryExp
	v.pb({"MulExp",vector<string>{"MulExp","/","UnaryExp"}});
	
	// 32.MulExp -> MulExp '%' UnaryExp
	v.pb({"MulExp",vector<string>{"MulExp","%","UnaryExp"}});
	
	// 33.AddExp -> MulExp
	v.pb({"AddExp",vector<string>{"MulExp"}});
	
	// 34.AddExp -> AddExp '+' MulExp
	v.pb({"AddExp",vector<string>{"AddExp","+","MulExp"}});
	
	// 35.AddExp -> AddExp '-' MulExp
	v.pb({"AddExp",vector<string>{"AddExp","-","MulExp"}});
	
	// 36.RelExp -> AddExp
	v.pb({"RelExp",vector<string>{"AddExp"}});
	
	// 37.RelExp -> RelExp '<' AddExp
	v.pb({"RelExp",vector<string>{"RelExp","<","AddExp"}});
	
	// 38.RelExp -> RelExp '>' AddExp
	v.pb({"RelExp",vector<string>{"RelExp",">","AddExp"}});
	
	// 39.RelExp -> RelExp '<=' AddExp
	v.pb({"RelExp",vector<string>{"RelExp","<=","AddExp"}});
	
	// 40.RelExp -> RelExp '>=' AddExp
	v.pb({"RelExp",vector<string>{"RelExp",">=","AddExp"}});
	
	// 41.EqExp -> RelExp
	v.pb({"EqExp",vector<string>{"RelExp"}});
	
	// 42.EqExp -> EqExp '==' RelExp 
	v.pb({"EqExp",vector<string>{"EqExp","==","RelExp"}});
	
	// 43.EqExp -> EqExp '!=' RelExp 
	v.pb({"EqExp",vector<string>{"EqExp","!=","RelExp"}});
	
	// 44.LAndExp -> EqExp 
	v.pb({"LAndExp",vector<string>{"EqExp"}});
	
	// 45.LAndExp -> LAndExp '&&' EqExp 
	v.pb({"LAndExp",vector<string>{"LAndExp","&&","EqExp"}});
	
	// 46.LOrExp -> LAndExp
	v.pb({"LOrExp",vector<string>{"LAndExp"}});
	
	// 47.LOrExp -> LOrExp '||' LAndExp
	v.pb({"LOrExp",vector<string>{"LOrExp","||","LAndExp"}});
	
	aop["&&"]=1; aop["||"]=1; aop["+"]=1; aop["-"]=1; aop["*"]=1; aop["/"]=1;
	cop["<"]=1; cop[">"]=1; cop[">="]=1; cop["<="]=1; cop["=="]=1; cop["!="]=1;
	
	proAll=v;
	for(int i=0;i<v.size();++i){
		auto [left,right]=v[i];
		proMap[left].pb(right);
		proIdx[{left,right}]=i;
	}
	
	for(auto [left,v]:proMap)getfirst(left);
	First["BlockItemList"].erase("EPSILON");
	First["ExpList"].erase("EPSILON");
}

struct ProjectSet{
	set<Production> productions;
	map<string,int> mp;
	map<Production,set<string>> ne;
	map<string,pair<string,vector<string>>> reduction;
	bool operator<(const ProjectSet& x)const{
		if(productions.size()!=x.productions.size())return productions.size()<x.productions.size();
		auto p1=productions.begin(); auto p2=x.productions.begin();
		while(p1!=productions.end()){
			if(*p1<*p2||*p2<*p1)return *p1<*p2;
			p1++; p2++;
		}
		for(auto [p,s]:ne){
			auto k=x.ne.at(p);
			if(s.size()!=k.size())return s.size()<k.size();
			auto p1=s.begin(),p2=k.begin();
			while(p1!=s.end()){
				if(*p1!=*p2)return *p1<*p2;
				p1++; p2++;
			}
		}
		return false;
	}
}projectSets[N];

int idx;
map<ProjectSet,int> projectIndex;

void getclosure(string left,ProjectSet& ps,set<string> fir){
	if(!proMap.count(left))return ;
	for(auto right:proMap[left]){
		Production p;
		if(right[0]=="EPSILON")p={1,left,right};
		else p={0,left,right};
		ps.productions.insert(p);
		int n=ps.ne[p].size();
		for(auto x:fir)ps.ne[p].insert(x);
		if(n!=ps.ne[p].size()){
			if(right.size()>1){
				if(proMap.count(right[1]))getclosure(right[0],ps,First[right[1]]);
				else getclosure(right[0],ps,set<string>{right[1]});
			}
			else getclosure(right[0],ps,ps.ne[p]);
		}
	}
}

struct node{
	string id;
	string second;
	vector<string> tac;
};

vector<string> ans;
int num,idx2,idx3;
stack<int> status;
stack<node> sign;
map<string,int> val;

node translate(int op,vector<node> t){
	node v;
	reverse(all(t));
	auto [left,right]=proAll[op];
	v.id=left;
	if(op==26){
		v.tac.push_back("li $t0,"+t[0].second);
		v.second="var"+to_string(idx3++);
		v.tac.push_back("sw $t0,"+v.second);
		ans.push_back(v.second+": .word 0");
		return v;
	}
	if(op==9){
		v.second=t[0].second;
		ans.push_back(v.second+": .word 0");
		return v;
	}
	if(op==9||op==10||op==11){
		for(auto x:t[2].tac)v.tac.push_back(x);
		v.tac.push_back("lw $t0,"+t[2].second);
		v.tac.push_back("sw $t0,"+t[0].second);
		if(op==10){
			v.second=t[0].second;
			ans.push_back(v.second+": .word 0");
		}
		return v;
	}
	if(op==19){
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
		return v;
	}
	if(op==20){
		for(auto x:t[2].tac)t[0].tac.push_back(x);
		t[0].second+=t[2].second+'!';
		v=t[0];
		return v;
	}
	if(op==18){
		v.tac.push_back("la $a0,"+t[0].second);
		v.tac.push_back("li $v0,5");
		v.tac.push_back("syscall");
		v.tac.push_back("sw $v0,"+t[0].second);
		return v;
	}
	if(op==29||op==30||op==31||op==33||op==34){
		v.second="var"+to_string(idx3++);
		ans.push_back(v.second+": .word 0");
		for(auto x:t[0].tac)v.tac.push_back(x);
		for(auto x:t[2].tac)v.tac.push_back(x);
		v.tac.push_back("lw $t0,"+t[0].second);
		v.tac.push_back("lw $t1,"+t[2].second);
		if(op==29)v.tac.push_back("mulo $t2,$t0,$t1");
		if(op==30)v.tac.push_back("div $t2,$t0,$t1");
		if(op==31)v.tac.push_back("rem $t2,$t0,$t1");
		if(op==33)v.tac.push_back("add $t2,$t0,$t1");
		if(op==34)v.tac.push_back("sub $t2,$t0,$t1");
		v.tac.push_back("sw $t2,"+v.second);
		return v;
	}
	if(op==15||op==16||op==17){
		int s1=t[2].tac.size(),s2=t[4].tac.size();
		for(int i=0;i<s1;++i){
			string s=t[2].tac[i];
			if(s.back()=='?'){
				if(s[0]=='b'){
					t[2].tac[i]=s.substr(0,s.size()-1)+"p"+to_string(s1-i);
				}else{
					t[2].tac[i]=s.substr(0,s.size()-1)+"p"+to_string(s1+s2-i+(op==16||op==17));
				}
			}
		}
		for(auto x:t[2].tac)v.tac.push_back(x);
		for(auto x:t[4].tac)v.tac.push_back(x);
		if(op==16){
			v.tac.push_back("k p"+to_string(t[6].tac.size()+1));
			for(auto x:t[6].tac)v.tac.push_back(x);
		}
		if(op==17){
			v.tac.push_back("k p"+to_string(sz(v.tac)*(-1)));
		}
		return v;
	}
	if(op==24){
		v.second=t[1].second;
		for(auto x:t[1].tac)v.tac.push_back(x);
		return v;
	}
	if(op==44){
		int s1=t[0].tac.size(),s2=t[2].tac.size();
		for(int i=0;i<s1;++i){
			string x=t[0].tac[i];
			if(x[0]=='b'&&x.back()=='?')x=x.substr(0,x.size()-1)+"p"+to_string(s1-i);
			v.tac.push_back(x);
		}
		for(auto x:t[2].tac)v.tac.push_back(x);
		return v;
	}
	if(op==46){
		int s1=t[0].tac.size(),s2=t[2].tac.size();
		for(int i=0;i<s1;++i){
			string x=t[0].tac[i];
			if(x[0]!='b'&&x.back()=='?')x=x.substr(0,x.size()-1)+"p"+to_string(s1-i);
			v.tac.push_back(x);
		}
		for(auto x:t[2].tac)v.tac.push_back(x);
		return v;
	}
	if(right.size()>1&&cop[right[1]]){
		for(auto x:t[0].tac)v.tac.push_back(x);
		for(auto x:t[2].tac)v.tac.push_back(x);
		v.tac.push_back("lw $t0,"+t[0].second);
		v.tac.push_back("lw $t1,"+t[2].second);
		if(op==36)v.tac.push_back("blt $t0,$t1,?");
		if(op==37)v.tac.push_back("bgt $t0,$t1,?");
		if(op==38)v.tac.push_back("ble $t0,$t1,?");
		if(op==39)v.tac.push_back("bge $t0,$t1,?");
		if(op==41)v.tac.push_back("beq $t0,$t1,?");
		if(op==42)v.tac.push_back("bne $t0,$t1,?");
		v.tac.push_back("k ?");
		return v;
	}
	for(auto [id,second,sts]:t){
		v.second+=second;
		for(auto x:sts)v.tac.push_back(x);
	}
	if(op==0)v.tac.push_back("nop");
	return v;
}

int main(){
	init();
	getWord();
	ProjectSet ps0; ps0.ne[{0,"CompUnit",vector<string>{"Block"}}]=set<string>{"#"};
	ps0.productions.insert({0,"CompUnit",vector<string>{"Block"}});
	getclosure("Block",ps0,set<string>{"#"});
	projectSets[idx]=ps0;
	projectIndex[ps0]=idx++;
	for(int i=0;i<idx;++i){
		auto [pros,mp,ne,reduction]=projectSets[i];
		set<string> s;
		for(auto [pos,left,right]:pros){
			if(pos==right.size()){
				for(auto x:ne[{pos,left,right}]){
					if(transform(x)=="NONE")projectSets[i].reduction[x]={left,right};
					else projectSets[i].reduction[transform(x)]={left,right};
				}
			}else s.insert(right[pos]);
		}
		for(auto x:s){
			ProjectSet ps;
			for(auto p:pros){
				auto [pos,left,right]=p;
				if(pos==right.size()||right[pos]!=x)continue;
				pos++;
				Production now={pos,left,right};
				ps.productions.insert(now);
				int n=ps.ne[now].size();
				for(auto x:ne[p])ps.ne[now].insert(x);
				if(n!=ps.ne[now].size()){
					if(pos<right.size()){
						if(pos+1<right.size()){
							if(proMap.count(right[pos+1]))getclosure(right[pos],ps,First[right[pos+1]]);
							else getclosure(right[pos],ps,set<string>{right[pos+1]});
						}
						else getclosure(right[pos],ps,ps.ne[{pos,left,right}]);
					}
				}
			}
			if(!projectIndex.count(ps)){
				projectSets[idx]=ps;
				projectIndex[ps]=idx++;
			}
			if(transform(x)=="NONE")projectSets[i].mp[x]=projectIndex[ps];
			else projectSets[i].mp[transform(x)]=projectIndex[ps];
		}
	}
	status.push(0); sign.push({"#","#",vector<string>{}});
	while(1){
		auto [nw,fnw]=q.front(); auto ns=status.top();
		auto tnw=nw;
		if(tnw=="INTCON")tnw="IntConst";
		else if(tnw=="IDENFR")tnw="Ident";
		else if(tnw=="STRCON")tnw="FormatString";
		auto [pros,mp,ne,reduction]=projectSets[ns];
		if(mp.count(tnw)){
			status.push(mp[tnw]);
			q.pop(); sign.push({tnw,fnw,vector<string>{}});
		}else if(reduction.count(tnw)){
			auto [left,right]=reduction[tnw];
			vector<node> v;
			int sz=right.size()-(right[0]=="EPSILON");
			while(sz--){
				v.pb(sign.top());
				sign.pop(),status.pop();
			}
			status.push(projectSets[status.top()].mp[left]);
			sign.push(translate(proIdx[{left,right}],v));
		}else break;
	}
	auto [id,second,sts]=sign.top();
	vector<string> v;
	for(int i=0;i<sts.size();++i){
		string s=sts[i];
		if(s[0]=='b'||s[0]=='k'){
			int res=0,now=1;
			for(int j=s.size()-1;;j--){
				if(s[j]=='p'||s[j]=='-'){
					if(s[j]=='-')s=s.substr(0,j)+to_string(-res+i);
					else s=s.substr(0,j)+"p"+to_string(res+i);
					v.pb(s);
					break;
				}
				res=res+(s[j]-'0')*now;
				now*=10;
			}
		}else v.pb(s);
	}
	for(int i=v.size()-1;i>=0;--i){
		string s=v[i];
		if(s[0]=='k'){
			int res=0,now=1;
			for(int j=s.size()-1;;j--){
				if(s[j]=='p'||s[j]=='-'){
					if(s[j]=='-')res=-res;
					break;
				}
				res=res+(s[j]-'0')*now;
				now*=10;
			}
			if(v[res][0]=='k')v[i]=v[res];
		}
	}
	ofstream fout;
	fout.open("mips.txt",ios::out);
	fout<<".data"<<endl;
	for(auto x:ans)fout<<x<<endl;
	fout<<".text"<<endl;
	for(int i=0;i<v.size();++i){
		if(v[i][0]=='k')v[i]="b"+v[i].substr(1);
		fout<<"p"+to_string(i)<<": "<<v[i]<<endl;
	}
	fout.close();
}
