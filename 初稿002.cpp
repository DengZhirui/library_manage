#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;

//ͼ���� 
class Book{
public:
	Book();
	char Book_Code[100];
	//�鼮���
	char ISBN[100];
	char Book_Name[100];
	//�����鼮���ƣ�50������
	char Publisher[30];
	//����������
	char Book_Auther[50];
	//�������ƹ��� 
	char Book_Type;
	//ѡ��ʵ����Դ��A��or������Դ ��E��
	char Book_Store[100];
	//�鼮���·���ֵ���-�ļ�·����ʵ��-���
	char Book_State[10]; 
	//�鼮״̬ in-�ڿ⣬out-�ڽ裬abnormal-�쳣
	char Book_Keeper[100];
	//��ǰ�����ˣ��ڽ�״̬�� 
	~Book();
};

//���캯�� 
Book::Book (){
}
//�������� 
Book::~Book(){
}

//������
class Paper{
public: 
	Paper();
	char Paper_Code[100];
	//���ı��
	char Paper_Name[100];
	//���ı���
	char auther[50][20];
	//�������ߣ������
	char Publish;
	//��Ϊ������ѡ���Ƿ������������ΪY��û�����ΪN 
	char  Publication[100];
	//��������
	char Public_Time[10];
	//����ʱ��
	char Paper_Type;
	//ѡ��ʵ����Դ��A��or������Դ ��E��
	char Paper_Store[50];
	//���Ĵ��·��-��Ϊֽ�ʺ͵��� 
	char Paper_State[10]; 
	//�鼮״̬ in-�ڿ⣬out-�ڽ裬abnormal-�쳣
	char Paper_Keeper[100];
	//��ǰ�����ˣ��ڽ�״̬�� 
	~Paper();
}; 
//���캯��
Paper::Paper(){
} 
//��������
Paper::~Paper(){
} 

//��Դ������
class Source_Manage{
public:
	Source_Manage();
	void Data_Input();
	//�鼮��Ϣ¼��
	void Refresh();
	//�鼮��Ϣ�����޸�
	void Search();
	//��������
	~Source_Manage();
}; 
//���캯��
Source_Manage::Source_Manage(){
}
//��������
Source_Manage::~Source_Manage(){
}
//�û�
class User{
public:
	User();
	void User_entry();
	~User();
private:
	char User_Name[50];
	char User_Password[50];
	char User_Character;
	//��ɫ-�û�U�����ԱA
	void Borrow(char* user_nameb);
	//���麯�� 
	void Return(char*user_namer);
	//���麯��
	void Read_online();
	//������Դ�����Ķ�
};
//���캯��
User::User(){
}
//��������
User::~User(){
}

//�ʻ�����
class Account_Manage{
public:
	Account_Manage();
	void Add_user();
	//����û� ,�����û����趨�û���ɫ 
	void Delete_user();
	//ɾ���û� 
	~Account_Manage();
}; 
//���캯��
Account_Manage::Account_Manage(){
}
//��������
Account_Manage::~Account_Manage(){
}

int main(){
	char Try;
	Source_Manage NowSM;
	User NowU; 
//	NowSM.Data_Input();
	cout<<"�鼮��Ϣ����������S,�û���¼������E"<<"\n";
	cin>>Try;
	if(Try=='S')
	NowSM.Search();
//	NowSM.Refresh();
	if(Try=='E') 
	NowU.User_entry();
	return 0;
}

//�鼮��Ϣ¼�� 
void Source_Manage::Data_Input(){
	char a;
	cout<<"¼���Ϊ�鼮������B������������P"<<"\n";
	cin>>a;
	if(a=='B'){ 
		Book BB;
		cout<<"������ͼ���ڲ����"<<"\n";
		cin>>BB.Book_Code; 
		ofstream fp;
		ofstream fp1;
		ofstream fp2;
		fp2.open("list",ios::app);
		fp1.open("booklist",ios::app);
		fp.open(BB.Book_Code,ios::trunc);
		fp<<BB.Book_Code<<"\n";
		cout<<"�������鼮��ISBN��"<<"\n";
		cin>>BB.ISBN;
		fp<<BB.ISBN<<"\n";
		cout<<"�������鼮������"<<"\n";
		cin>>BB.Book_Name;
		fp<<BB.Book_Name<<"\n";
		fp1<<BB.Book_Name<<"\n";
		fp1<<BB.Book_Code<<"\n";
		fp2<<BB.Book_Name<<"\n";
		fp2<<BB.Book_Code<<"\n";
		cout<<"�������鼮�ĳ���������"<<"\n";
		cin>>BB.Publisher;
		fp<<BB.Publisher<<"\n";
		cout<<"��������������"<<"\n";
		cin>>BB.Book_Auther;
		fp<<BB.Book_Auther<<"\n";
		cout<<"���鼮Ϊʵ����Դ������A����Ϊ������Դ������E"<<"\n";
		cin>>BB.Book_Type;
		fp<<BB.Book_Type<<"\n";
		cout<<"�������鼮���·��"<<"\n";
		cin>>BB.Book_Store;
		fp<<BB.Book_Store<<"\n";
		cout<<"�������鼮״̬in-�ڿ⣬out-�ڽ裬abnormal-�쳣"<<"\n";
		cin>>BB.Book_State;
		fp<<BB.Book_State<<"\n";
		if(BB.Book_State[0]=='o'){
			cout<<"�����뱣����"<<"\n";
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
		cout<<"�����������ڲ����"<<"\n";
		cin>>PP.Paper_Code;
		ofstream fp;
		ofstream fp1;
		ofstream fp2;
		fp2.open("list",ios::app);
		fp1.open("paperlist",ios::app);
		fp.open(PP.Paper_Code,ios::trunc);
		fp<<PP.Paper_Code<<"\n"; 
		cout<<"���������ı���"<<"\n";
		cin>>PP.Paper_Name;
		fp<<PP.Paper_Name<<"\n";
		fp1<<PP.Paper_Name<<"\n";
		fp1<<PP.Paper_Code<<"\n";
		fp2<<PP.Paper_Name<<"\n";
		fp2<<PP.Paper_Code<<"\n";
		cout<<"�������������������"<<'\n';
		cin>>i; 
		cout<<"��������������"<<"\n";
		while (j<=i){
			cin>>PP.auther[j];
			fp<<PP.auther[j]<<" ";
			j++;
		}
		fp<<"\n";
		cout<<"�����������������Y��û���������N"<<"\n";
		cin>>PP.Publish;
		fp<<PP.Publish<<"\n";
		if(PP.Publish=='Y'){
			cout<<"��������濯������"<<"\n";
			cin>>PP.Publication;
			fp<<PP.Publication<<"\n";
			cout<<"���������ʱ��"<<"\n";
			cin>>PP.Public_Time;
			fp<<PP.Public_Time<<"\n";
		}
		cout<<"��Ϊʵ����Դ������A����Ϊ������Դ������E"<<"\n";
		cin>>PP.Paper_Type;
		fp<<PP.Paper_Type<<"\n";
		cout<<"���������Ĵ��·��"<<"\n";
		cin>>PP.Paper_Store;
		fp<<PP.Paper_Store<<"\n";
		cout<<"����������״̬in-�ڿ⣬out-�ڽ裬abnormal-�쳣"<<"\n";
		cin>>PP.Paper_State;
		fp<<PP.Paper_State<<"\n";
		if(PP.Paper_State[0]=='o'){
			cout<<"�����뱣����"<<"\n";
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

//�������� 
void Source_Manage::Search(){
	char b;
	string c;
	string d;
	string e;
	cout<<"�����鼮������B������������P���ݲ��������������"<<"\n"; 
	cin>>b;
	if(b=='B'){
		cout<<"��������Ҫ���ҵ��鼮����"<<"\n";
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
		cout<<"ͼ���� ͼ��ISBN�� �鼮���� ���������� ���� ��Դ��ʽ ���·�� �鼮״̬" <<"\n"; 
		while(getline(fp1,e)){
			cout<<e<<" ";
		}
		fp1.close();
	}
	else if(b=='P'){
		cout<<"��������Ҫ���ҵ���������"<<"\n";
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
		cout<<"���ı�� ���ı��� �������� �����Ƿ���� ���濯������ ����ʱ�� ��Դ��ʽ ���·��" <<"\n"; 
		while(getline(fp1,e)){
			cout<<e<<" ";
		}
		fp1.close();
	}
	else{
		cout<<"��������Ҫ���ҵ��鼮����"<<"\n";
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

//�û���½ 
void User::User_entry(){
	string f;
	string ff;
	string fff;
	char g; 
	cout<<"�������û���"<<"\n";
	cin>>User_Name;
	cout<<"����������"<<"\n";
	cin>>User_Password;
	ifstream fp;
	fp.open("username_list",ios::in);
	do{
		getline(fp,f);
		getline(fp,ff);
		getline(fp,fff);
	}while(((f!=User_Name)||(ff!=User_Password))&&(!fp.eof()));
	if((f==User_Name)&&(ff==User_Password)){
		cout<<"����������B,����������R,�����Ķ�������O"<<"\n";
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
			cout<<"����û�������A��ɾ���û�������D"
					<<"�鼮��Ϣ¼��������E,�鼮��Ϣ����������R"<<"\n";
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

//����
void User::Borrow(char* user_nameb){
	string cc;
	string dd;
	string ee;
	string in("in");
	string out("out");
	string abnormal("abnormal");
	char bb;
	cout<<"����������ĵ��鼮����"<<"\n";
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
		cout<<"ȷ�Ͻ���������Y"<<"\n";
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
		cout<<"���ĳɹ�"<<"\n";
	}
	else{
		cout<<"��ǰ�鼮���ɽ���"<<"\n";
	} 
	fp1.close();
}

//����
void User::Return(char* user_namer){
	string cc;
	string dd;
	string ee;
	string in("in");
	string out("out");
	string abnormal("abnormal");
	char bb;
	int i=1;
	cout<<"������Ҫ�黹���鼮����"<<"\n";
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
	cout<<"ȷ�Ϲ黹������Y"<<"\n";
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
	cout<<"�黹�ɹ�"<<"\n";
	}
	fp1.close();
	fp4.close();
	fp3.close();	
} 

//����û� ,�����û���
void Account_Manage::Add_user(){
	char user_name[100];
	char user_code[100];
	char user_character[100];
	cout<<"����������ӵ��û�����"<<"\n";
	cin>>user_name;
	cout<<"����������"<<"\n";
	cin>>user_code;
	cout<<"����Ա������A��һ���û�������U"<<"\n";
	cin>>user_character; 
	ofstream fp;
	fp.open("username_list",ios::app);
	fp<<user_name<<"\n";
	fp<<user_code<<"\n";
	fp<<user_character<<"\n";
	cout<<"��ӳɹ�"<<"\n";
	fp.close();
}

//ɾ���û����� 
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
	cout<<"��������Ҫɾ�����û�����"<<"\n";
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
	cout<<"ɾ���ɹ�"<<"\n";
	fp3.close();
	fp2.close();
} 

//�鼮��Ϣ�����޸�
void Source_Manage::Refresh(){
	string str;
	char a;
	string book_name;
	string book_code;
	string book_store; 
	string A("A");
	string E("E");
	cout<<"����������»��޸ĵ��鼮����"<<"\n";
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
	cout<<"�����鼮���������T�����Ĵ��·��������S"<<"\n";
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
		cout<<"��������ĺ���ļ�·��"<<"\n";
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

//������Դ�����Ķ�
void User::Read_online(){
	char book_name[100];
	string str;
	string str1;
	string A("A");
	string E("E"); 
	cout<<"�������������Ķ����鼮"<<"\n";
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
	cout<<"���鲻�ṩ�����Ķ�����"<<"\n";
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


 
