#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

//图书类 
class Book{
public:
	Book();
	char Book_Code[100];
	//书籍编号
	char ISBN[100];
	char Book_Name[100];
	//储存书籍名称，50字以内
	char Publisher[30];
	//出版社名称
	char Book_Auther[50];
	//作者名称国籍 
	char Book_Type;
	//选择实体资源（A）or电子资源 （E）
	char Book_Store[100];
	//书籍存放路径分电子-文件路径和实体-书架
	char Book_State[10]; 
	//书籍状态 in-在库，out-在借，abnormal-异常
	char Book_Keeper[100];
	//当前保管人，在借状态下 
	~Book();
};

//构造函数 
Book::Book (){
}
//析构函数 
Book::~Book(){
}

//论文类
class Paper{
public: 
	Paper();
	char Paper_Code[100];
	//论文编号
	char Paper_Name[100];
	//论文标题
	char auther[50][20];
	//论文作者（多个）
	char Publish;
	//若为论文则选择是否出版过，出版过为Y，没出版过为N 
	char  Publication[100];
	//刊物名称
	char Public_Time[10];
	//出版时间
	char Paper_Type;
	//选择实体资源（A）or电子资源 （E）
	char Paper_Store[50];
	//论文存放路径-分为纸质和电子 
	char Paper_State[10]; 
	//书籍状态 in-在库，out-在借，abnormal-异常
	char Paper_Keeper[100];
	//当前保管人，在借状态下 
	~Paper();
}; 
//构造函数
Paper::Paper(){
} 
//析构函数
Paper::~Paper(){
} 

//资源管理器
class Source_Manage{
public:
	Source_Manage();
	void Data_Input();
	//书籍信息录入
	void Refresh();
	//书籍信息更新修改
	void Search();
	//搜索函数
	~Source_Manage();
}; 
//构造函数
Source_Manage::Source_Manage(){
}
//析构函数
Source_Manage::~Source_Manage(){
}
//用户
class User{
public:
	User();
	void User_entry();
	~User();
private:
	char User_Name[50];
	char User_Password[50];
	char User_Character;
	//角色-用户U或管理员A
	void Borrow(char* user_nameb);
	//借书函数 
	void Return(char*user_namer);
	//还书函数
	void Read_online();
	//电子资源在线阅读
};
//构造函数
User::User(){
}
//析构函数
User::~User(){
}

//帐户管理
class Account_Manage{
public:
	Account_Manage();
	void Add_user();
	//添加用户 ,存在用户表，设定用户角色 
	void Delete_user();
	//删除用户 
	~Account_Manage();
}; 
//构造函数
Account_Manage::Account_Manage(){
}
//析构函数
Account_Manage::~Account_Manage(){
}

int main(){
	char Try;
	Source_Manage NowSM;
	User NowU; 
//	NowSM.Data_Input();
	cout<<"书籍信息检索请输入S,用户登录请输入E"<<"\n";
	cin>>Try;
	if(Try=='S')
	NowSM.Search();
//	NowSM.Refresh();
	if(Try=='E') 
	NowU.User_entry();
	return 0;
}

//书籍信息录入 
void Source_Manage::Data_Input(){
	char a;
	cout<<"录入的为书籍请输入B，论文请输入P"<<"\n";
	cin>>a;
	if(a=='B'){ 
		Book BB;
		cout<<"请输入图书内部编号"<<"\n";
		cin>>BB.Book_Code; 
		ofstream fp;
		ofstream fp1;
		ofstream fp2;
		fp2.open("list",ios::app);
		fp1.open("booklist",ios::app);
		fp.open(BB.Book_Code,ios::trunc);
		fp<<BB.Book_Code<<"\n";
		cout<<"请输入书籍的ISBN码"<<"\n";
		cin>>BB.ISBN;
		fp<<BB.ISBN<<"\n";
		cout<<"请输入书籍的名称"<<"\n";
		cin>>BB.Book_Name;
		fp<<BB.Book_Name<<"\n";
		fp1<<BB.Book_Name<<"\n";
		fp1<<BB.Book_Code<<"\n";
		fp2<<BB.Book_Name<<"\n";
		fp2<<BB.Book_Code<<"\n";
		cout<<"请输入书籍的出版社名称"<<"\n";
		cin>>BB.Publisher;
		fp<<BB.Publisher<<"\n";
		cout<<"请输入作者姓名"<<"\n";
		cin>>BB.Book_Auther;
		fp<<BB.Book_Auther<<"\n";
		cout<<"若书籍为实体资源请输入A，若为电子资源请输入E"<<"\n";
		cin>>BB.Book_Type;
		fp<<BB.Book_Type<<"\n";
		cout<<"请输入书籍存放路径"<<"\n";
		cin>>BB.Book_Store;
		fp<<BB.Book_Store<<"\n";
		cout<<"请输入书籍状态in-在库，out-在借，abnormal-异常"<<"\n";
		cin>>BB.Book_State;
		fp<<BB.Book_State<<"\n";
		if(BB.Book_State[0]=='o'){
			cout<<"请输入保管人"<<"\n";
			cin>>BB.Book_Keeper;
			fp<<BB.Book_Keeper<<"\n";
		}
		else{
			BB.Book_Keeper[0]='N';
			BB.Book_Keeper[1]='O';
			BB.Book_Keeper[2]='N';
			BB.Book_Keeper[3]='E';
		}
		fp.close();
		fp1.close();
		fp2.close();
	}
	if(a=='P'){
		int i,j=1;
		Paper PP;
		cout<<"请输入论文内部编号"<<"\n";
		cin>>PP.Paper_Code;
		ofstream fp;
		ofstream fp1;
		ofstream fp2;
		fp2.open("list",ios::app);
		fp1.open("paperlist",ios::app);
		fp.open(PP.Paper_Code,ios::trunc);
		fp<<PP.Paper_Code<<"\n"; 
		cout<<"请输入论文标题"<<"\n";
		cin>>PP.Paper_Name;
		fp<<PP.Paper_Name<<"\n";
		fp1<<PP.Paper_Name<<"\n";
		fp1<<PP.Paper_Code<<"\n";
		fp2<<PP.Paper_Name<<"\n";
		fp2<<PP.Paper_Code<<"\n";
		cout<<"请输入该论文作者数量"<<'\n';
		cin>>i; 
		cout<<"请输入论文作者"<<"\n";
		while (j<=i){
			cin>>PP.auther[j];
			fp<<PP.auther[j]<<" ";
			j++;
		}
		fp<<"\n";
		cout<<"论文若出版过请输入Y，没出版过输入N"<<"\n";
		cin>>PP.Publish;
		fp<<PP.Publish<<"\n";
		if(PP.Publish=='Y'){
			cout<<"请输入出版刊物名称"<<"\n";
			cin>>PP.Publication;
			fp<<PP.Publication<<"\n";
			cout<<"请输入出版时间"<<"\n";
			cin>>PP.Public_Time;
			fp<<PP.Public_Time<<"\n";
		}
		cout<<"若为实体资源请输入A，若为电子资源请输入E"<<"\n";
		cin>>PP.Paper_Type;
		fp<<PP.Paper_Type<<"\n";
		cout<<"请输入论文存放路径"<<"\n";
		cin>>PP.Paper_Store;
		fp<<PP.Paper_Store<<"\n";
		cout<<"请输入论文状态in-在库，out-在借，abnormal-异常"<<"\n";
		cin>>PP.Paper_State;
		fp<<PP.Paper_State<<"\n";
		if(PP.Paper_State[0]=='o'){
			cout<<"请输入保管人"<<"\n";
			cin>>PP.Paper_Keeper;
			fp<<PP.Paper_Keeper<<"\n";
		}
		else{
			PP.Paper_Keeper[0]='N';
			PP.Paper_Keeper[1]='O';
			PP.Paper_Keeper[2]='N';
			PP.Paper_Keeper[3]='E';
		}
		fp.close();
		fp1.close();
		fp2.close();
	}
	
}

//搜索函数 
void Source_Manage::Search(){
	char b;
	string c;
	string d;
	string e;
	cout<<"查找书籍请输入B，论文请输入P，暂不清楚请输入其他"<<"\n"; 
	cin>>b;
	if(b=='B'){
		cout<<"请输入想要查找的书籍名称"<<"\n";
		cin>>c; 
		ifstream fp;
		fp.open("booklist",ios::in);
		do{
			getline(fp,d);
		} while(c!=d);
		getline(fp,d);
		fp.close();
		char filename[100]={0};
		const char*myd=d.c_str();//string-char
		sprintf(filename,"%s",myd);
		fstream fp1(filename);
		cout<<"图书编号 图书ISBN码 书籍名称 出版社名称 作者 资源形式 存放路径 书籍状态" <<"\n"; 
		while(getline(fp1,e)){
			cout<<e<<" ";
		}
		fp1.close();
	}
	else if(b=='P'){
		cout<<"请输入想要查找的论文名称"<<"\n";
		cin>>c; 
		ifstream fp;
		fp.open("paperlist",ios::in);
		do{
			getline(fp,d);
		} while(c!=d);
		getline(fp,d);
		fp.close();
		char filename[100]={0};
		const char*myd=d.c_str();//string-char
		sprintf(filename,"%s",myd);
		fstream fp1(filename);
		cout<<"论文编号 论文标题 作者名称 论文是否出版 出版刊物名称 出版时间 资源形式 存放路径" <<"\n"; 
		while(getline(fp1,e)){
			cout<<e<<" ";
		}
		fp1.close();
	}
	else{
		cout<<"请输入想要查找的书籍名称"<<"\n";
		cin>>c;
		ifstream fp;
		fp.open("list",ios::in);
		do{
			getline(fp,d);
		} while(c!=d);
		getline(fp,d);
		fp.close();
		char filename[100]={0};
		const char*myd=d.c_str();//string-char
		sprintf(filename,"%s",myd);
		fstream fp1(filename);
		while(getline(fp1,e)){
			cout<<e<<" ";
		}
		fp1.close();
	}
}

//用户登陆 
void User::User_entry(){
	string f;
	string ff;
	string fff;
	char g; 
	cout<<"请输入用户名"<<"\n";
	cin>>User_Name;
	cout<<"请输入密码"<<"\n";
	cin>>User_Password;
	ifstream fp;
	fp.open("username_list",ios::in);
	do{
		getline(fp,f);
		getline(fp,ff);
		getline(fp,fff);
	}while(((f!=User_Name)||(ff!=User_Password))&&(!fp.eof()));
	if((f==User_Name)&&(ff==User_Password)){
		cout<<"借书请输入B,还书请输入R,在线阅读请输入O"<<"\n";
		cin>>g;
		if(g=='B') 
		Borrow(User_Name);
		if(g=='R')
		Return(User_Name);
		if(g=='O')
		Read_online();
		const char*myfff=fff.c_str();
		if(myfff[0]=='A'){
		Account_Manage AM;
		Source_Manage Nowsm;
		char gg;
			cout<<"添加用户请输入A，删除用户请输入D"
					<<"书籍信息录入请输入E,书籍信息更新请输入R"<<"\n";
			cin>>gg;
			if(gg=='A')
			AM.Add_user();
			if(gg=='D')
			AM.Delete_user();
			if(gg=='E')
			Nowsm.Data_Input();
			if(gg=='R')
			Nowsm.Refresh();
		}
	}
}

//借阅
void User::Borrow(char* user_nameb){
	string cc;
	string dd;
	string ee;
	string in("in");
	string out("out");
	string abnormal("abnormal");
	char bb;
	cout<<"请输入想借阅的书籍名称"<<"\n";
	cin>>cc;
	ifstream fp;
	fp.open("list",ios::in);
	do{
		getline(fp,dd);
	} while(cc!=dd);
	getline(fp,dd);
	fp.close();
	char filename[100]={0};
	const char*mydd=dd.c_str();//string-char
	sprintf(filename,"%s",mydd);
	fstream fp1(filename);
	ofstream fp2;
	fp2.open("1",ios::trunc);
	while(getline(fp1,ee)){
		if((ee.compare(in)==0)||(ee.compare(out)==0)||(ee.compare(abnormal)==0))
		break;
		fp2<<ee<<"\n";
	}
	if(ee.compare(in)==0){
		cout<<"确认借阅请输入Y"<<"\n";
		cin>>bb;
		if(bb=='Y'){
			fp2<<"out"<<"\n";
			fp2<<user_nameb<<"\n";
			fp2.close();
			ifstream fp4;
			fp4.open("1",ios::in);
			ofstream fp3;
			fp3.open(filename,ios::trunc);
			while(getline(fp4,ee)){
				fp3<<ee<<"\n";
			}
			fp3.close();
			fp4.close();
		}
		else{
			fp2.close();
		}
		fp2.close();
		cout<<"借阅成功"<<"\n";
	}
	else{
		cout<<"当前书籍不可借阅"<<"\n";
	} 
	fp1.close();
}

//还书
void User::Return(char* user_namer){
	string cc;
	string dd;
	string ee;
	string in("in");
	string out("out");
	string abnormal("abnormal");
	char bb;
	int i=1;
	cout<<"请输入要归还的书籍名称"<<"\n";
	cin>>cc;
	ifstream fp;
	ofstream fp2;
	ifstream fp4;
	ofstream fp3;
	fp2.open("casual",ios::trunc);
	fp.open("list",ios::in);
	do{
		getline(fp,dd);
	} while(cc!=dd);
	getline(fp,dd);
	fp.close();
	char filename[100]={0};
	const char*mydd=dd.c_str();//string-char
	sprintf(filename,"%s",mydd);
	fstream fp1(filename);
	while(getline(fp1,ee)){		
		if((ee.compare(in)==0)||(ee.compare(out)==0)||(ee.compare(abnormal)==0))
		break;
		cout<<ee<<" ";
		fp2<<ee<<"\n";
		i++;
	}
	cout<<"确认归还请输入Y"<<"\n";
	cin>>bb;
	if(bb=='Y'){ 
	fp2<<"in"<<"\n";
	fp1.close();
	fp2.close();
	fp4.open("casual",ios::in);
	sprintf(filename,"%s",mydd);
	fp3.open(filename,ios::trunc);
	while(getline(fp4,ee)){		
		if(fp4.eof())
		break;
		fp3<<ee<<"\n";
		i++;
	}
	cout<<"归还成功"<<"\n";
	}
	fp1.close();
	fp4.close();
	fp3.close();	
} 

//添加用户 ,存在用户表
void Account_Manage::Add_user(){
	char user_name[100];
	char user_code[100];
	char user_character[100];
	cout<<"请输入想添加的用户名称"<<"\n";
	cin>>user_name;
	cout<<"请输入密码"<<"\n";
	cin>>user_code;
	cout<<"管理员请输入A，一般用户请输入U"<<"\n";
	cin>>user_character; 
	ofstream fp;
	fp.open("username_list",ios::app);
	fp<<user_name<<"\n";
	fp<<user_code<<"\n";
	fp<<user_character<<"\n";
	cout<<"添加成功"<<"\n";
	fp.close();
}

//删除用户函数 
void Account_Manage::Delete_user(){
	string aa;
	string bb;
	char user_name[100];
	char user_code[100];
	char user_character[100];
	ifstream fp;
	ofstream fp1;
	fp.open("username_list",ios::in);
	fp1.open("exchange",ios::trunc);
	cout<<"请输入想要删除的用户名称"<<"\n";
	cin>>user_name;
	bb=user_name;
	while (getline(fp,aa)){
		if(aa==bb)
		break;
		fp1<<aa<<"\n";
	}
	getline(fp,aa);
	getline(fp,aa);
	while(getline(fp,aa)){
		fp1<<aa<<"\n";
	}
	fp.close();
	fp1.close();
	ifstream fp3;
	fp3.open("exchange",ios::in);
	ofstream fp2;
	fp2.open("username_list",ios::trunc);
	while(getline(fp3,aa)){
		fp2<<aa<<"\n";
	}
	cout<<"删除成功"<<"\n";
	fp3.close();
	fp2.close();
} 

//书籍信息更新修改
void Source_Manage::Refresh(){
	string str;
	char a;
	string book_name;
	string book_code;
	string book_store; 
	string A("A");
	string E("E");
	cout<<"请输入想更新或修改的书籍名称"<<"\n";
	cin>>book_name;
	ifstream fp;
	fp.open("list",ios::in);
	while(getline(fp,str)){
		if(str==book_name)
		break;
	}
	getline(fp,str);
	book_code=str;
	fp.close();
	ifstream fp1;
	ofstream fp2;
	const char*mybc=book_code.c_str();
	fp1.open(mybc,ios::in);
	fp2.open("mid",ios::out);
	getline(fp1,str);
	fp2<<str<<"\n";
	cout<<"更改书籍类别请输入T，更改存放路径请输入S"<<"\n";
	cin>>a;
	while(getline(fp1,str)){
		if((str==A)||(str==E))
		break;
		fp2<<str<<"\n";
	}
	if(a=='T'){
		if(str==A)
		fp2<<"E"<<"\n";
		if(str==E)
		fp2<<"A"<<"\n";
		while(getline(fp1,str)){
			fp2<<str<<"\n";
		}
	}
	if(a=='S'){
		fp2<<str<<"\n";
		cout<<"请输入更改后的文件路径"<<"\n";
		cin>>book_store;
		fp2<<book_store<<"\n";
		getline(fp1,str);
		while(getline(fp1,str)){
			fp2<<str<<"\n";
		}
	}
	fp2.close();
	ifstream fp3;
	fp3.open("mid",ios::in);
	ofstream fp4;
	fp4.open(mybc,ios::trunc);
	while(getline(fp3,str)){
		fp4<<str<<"\n";
	}
	fp3.close();
	fp4.close();
} 

//电子资源在线阅读
void User::Read_online(){
	char book_name[100];
	string str;
	string str1;
	string A("A");
	string E("E"); 
	cout<<"请输入想在线阅读的书籍"<<"\n";
	cin>>book_name; 
	ifstream fp;
	fp.open("list",ios::in);
	while(getline(fp,str)){
		string str2=book_name;
		if(str2==str)
		break;
	}
	getline(fp,str);
	fp.close();
	ifstream fp1;
	const char*mystr=str.c_str();
	fp1.open(mystr,ios::in);
	while(getline(fp1,str1)){
		if(str1==A||str1==E)
		break;
	}
	if(str1==A)
	cout<<"此书不提供在线阅读功能"<<"\n";
	if(str1==E){
		getline(fp1,str1);
	}
	fp1.close();
	char filename[100]={0};
	const char*mystr1=str1.c_str();//string-char
	sprintf(filename,"%s",mystr1);
	fstream fp2(filename);
	while(getline(fp2,str1)){
		cout<<str1<<"\n";
	}
	fp2.close();
}


 
