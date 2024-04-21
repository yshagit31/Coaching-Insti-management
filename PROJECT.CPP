#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
class student
{
char select[14];
char scode[4];
char sname[30];
char fname[30];
char phno[11];
char batch;
char add[50];
int marks;
char dob[11];
char course[5];
char branch[11];
char gender;
long prize;
long fees;
char feestatus[7];
public:
student()
{
strcpy(select," ");
strcpy(scode," ");
strcpy(sname," ");
strcpy(phno," ");
strcpy(fname," ");
batch='A';
strcpy(add," ");
strcpy(dob," ");
marks=0;
strcpy(course," ");
strcpy(branch," ");
gender='M';
prize=0;
fees=0;
strcpy(feestatus," ");
}
void input()
{
cout<<endl<<"Enter the following details:";
cout<<endl<<"Student's code:";
gets(scode);
cout<<endl<<"Student's name:";
gets(sname);
cout<<endl<<"Enter Gender:";
cin>>gender;
cout<<endl<<"Father's name:";
gets(fname);
cout<<endl<<"Date of birth:";
gets(dob);
cout<<endl<<"Phone number:";
gets(phno);
cout<<endl<<"Address:";
gets(add);
cout<<endl<<"Branch:";
gets(branch);
cout<<endl<<"Course:";
gets(course);
cout<<endl<<"Batch:";
cin>>batch;
cout<<endl<<"Fees:";
cin>>fees;
feestat();
cout<<endl<<"Marks:";
cin>>marks;
sprize();
sselect();
}
void sprize()
{
if(marks>=80&&marks<90)
{
prize=20000;
}
if(marks>=90&&marks<95)
{
prize=50000;
}
if(marks>=95)
{
prize=100000;
}
if(marks<80)
{
prize=0;
}
}
void sselect()
{
if(marks>=60)
{
strcpy(select,"Selected");
}
if(marks<60)
{
strcpy(select,"Not Selected");
}
}
char* returnbranch()
{
return branch;
}
char* returnname()
{
return sname;
}
char returnbatch()
{
return batch;
}
char* returnscode()
{
return scode;
}
char* returnselection()
{
return select;
}
void feestat()
{
if(fees>=100000)
{
strcpy(feestatus,"Paid");
}
else
{
strcpy(feestatus,"Unpaid");
}
}
char* returndob()
{
return dob;
}
char returngender()
{
return gender;
}
char* returncourse()
{
return course;
}
int returnmarks()
{
return marks;
}
long returnfees()
{
return fees;
}
char* returnfeestatus()
{
return feestatus;
}
char* returnfname()
{
return fname;
}
char* returnphno()
{
return phno;
}
char* returnadd()
{
return add;
}
long returnprize()
{
return prize;
}
}S;
void disp()
{
cout<<endl<<"Student's code: "<<S.returnscode();
cout<<endl<<"Student's name: "<<S.returnname();
cout<<endl<<"Gender: "<<S.returngender();
cout<<endl<<"Father's name: "<<S.returnfname();
cout<<endl<<"Date of birth: "<<S.returndob();
cout<<endl<<"Phone number: "<<S.returnphno();
cout<<endl<<"Address: "<<S.returnadd();
cout<<endl<<"Branch: "<<S.returnbranch();
cout<<endl<<"Course: "<<S.returncourse();
cout<<endl<<"Batch: "<<S.returnbatch();
cout<<endl<<"Fees: "<<S.returnfees();
S.feestat();
cout<<endl<<"Feestatus: "<<S.returnfeestatus();
cout<<endl<<"Marks:"<<S.returnmarks();
S.sprize();
cout<<endl<<"Prize:"<<S.returnprize()<<endl;
getch();
}
int o1,o12,o2,o3,o4,o7,o71;
void showcourse()
{
cout<<endl<<"\t\t\t\tSelect course";
cout<<endl<<"1. JEE";
cout<<endl<<"2. NEET";
cout<<endl<<"3. CLAT";
cout<<endl<<"4. Return to main menu";
}
void showbranch()
{
cout<<endl<<"\t\t\t\tSelect Branch";
cout<<endl<<"1. Lucknow";
cout<<endl<<"2. Mumbai";
cout<<endl<<"3. Delhi";
cout<<endl<<"4. Kharagpur";
cout<<endl<<"5. Roorkee";
cout<<endl<<"6. Return to main menu";
}
int countselections()
{
fstream xfile;
int qs=0;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(S.returnmarks()>60)
{
qs++;
}
}
return qs;
xfile.close();
}
void countstu3(int o7)
{
char a[5];
if(o7==1)
{strcpy(a,"JEE");}
if(o7==2)
{strcpy(a,"NEET");}
if(o7==3)
{strcpy(a,"CLAT");}
int nos=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(strcmpi(S.returncourse(),a)==0)
{
disp();
clrscr();
nos++;
}}
cout<<endl<<"Total number of students:"<<nos;
xfile.close();
}
int countstu()
{
int nos=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
nos++;
}
return nos;
xfile.close();
}
void create()
{
 char ch;
 fstream sfile;
 sfile.open("INSTI.dat",ios::binary|ios::app);
 S.input();
 sfile.write((char*)&S,sizeof(S));
 for(int i=0;i<149;i++)
 {
 cout<<endl<<"Want to add more?";
 cin>>ch;
 if(ch=='Y'||ch=='y')
 {
 S.input();
 sfile.write((char*)&S,sizeof(S));
 }
 else
 {
 break;
 }
 }
 sfile.close();
}
void countgender()
{
int m=0,g=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(S.returngender()=='M')
{
m++;
}
if(S.returngender()=='F')
{
g++;
}
}
cout<<endl<<"Total number of girls:"<<g;
cout<<endl<<"Total number of boys:"<<m;
xfile.close();
}
void searchparticular()
{
char stucode[4];
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
cout<<endl<<"Enter the student code:";
gets(stucode);
while(xfile.read((char*)&S,sizeof(S)))
{
if(strcmpi(stucode,S.returnscode())==0)
{
disp();
getch();
}
}
xfile.close();
}
void details()
{
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
disp(); clrscr();
}
xfile.close();
}
void modify()
{
 fstream sfile;
 sfile.open("INSTI.dat",ios::binary|ios::in);
 char n[5];
 int rec=0,pos;
 cout<<endl<<"Which Student Number:";
 gets(n);
 while(!sfile.eof())
 {
  sfile.read((char*)&S,sizeof(S));
  if(strcmp(S.returnscode(),n)!=0)
  { rec+=1;
   }
   else
   {
   break ;
   }
   }
  pos=(rec*sizeof(S));
  sfile.seekg(pos);
  sfile.read((char*)&S,sizeof(S));
  disp();
  char rep;
  cout<<endl<<"WISH TO MODIFY";
  cin>>rep;
  fstream xfile;
  xfile.open("INSTI.dat",ios::binary|ios::ate|ios::out);
  if(rep=='y')
  {
  S.input();
  xfile.seekp(pos);
  xfile.write((char*)&S,sizeof(S));
  disp();
  }
  else
  {
  cout<<endl<<"Record Not Found";
  }
  sfile.close();
  xfile.close();
}
void smarks(o1)
{
char a[10];
if(o1==1)
{strcpy(a,"Lucknow");}
if(o1==2)
{strcpy(a,"Mumbai");}
if(o1==3)
{strcpy(a,"Delhi");}
if(o1==4)
{strcpy(a,"Kharagpur");}
if(o1==5)
{strcpy(a,"Roorkee");}
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(strcmpi(S.returnbranch(),a)==0&&S.returnmarks()>60)
{
cout<<"Name:"<<S.returnname()<<endl<<"Course:"<<S.returncourse()<<endl<<"Marks:"<<S.returnmarks()<<endl<<endl;
getch();
}}
xfile.close();
}
void showselected(o1,o12)
{
char a[10];
if(o1==1)
{strcpy(a,"Lucknow");}
if(o1==2)
{strcpy(a,"Mumbai");}
if(o1==3)
{strcpy(a,"Delhi");}
if(o1==4)
{strcpy(a,"Kharagpur");}
if(o1==5)
{strcpy(a,"Roorkee");}
char b[5];
if(o12==1)
{strcpy(b,"JEE");}
if(o12==2)
{strcpy(b,"NEET");}
if(o12==3)
{strcpy(b,"CLAT");}
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(S.returnmarks()>60&&(strcmpi(S.returnbranch(),a)==0)&&(strcmpi(S.returncourse(),b)==0))
{
disp();
clrscr();
}
}
xfile.close();
}
long revenue()
{
long rev=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
rev=rev+S.returnfees();
}
xfile.close();
return rev;
}
void toprankers(o3)
{
fstream xfile;
char a[5];
if(o3==1)
{strcpy(a,"JEE");}
if(o3==2)
{strcpy(a,"NEET");}
if(o3==3)
{strcpy(a,"CLAT");}
int x=0,m1=0;
char str1[20],c1[4];
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
m1=S.returnmarks();
if(x<m1&&(strcmpi(a,S.returncourse())==0))
{
x=m1;
strcpy(str1,S.returnname());
strcpy(c1,S.returnscode());
}}
cout<<endl<<"Topper of "<<a<<" :"<<endl;
cout<<endl<<"Scode: "<<c1;
cout<<endl<<"Name: "<<str1;
cout<<endl<<"Marks: "<<x;
xfile.close();
getch();
}
void addrec()
{
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::app);
S.input();
xfile.write((char*)&S,sizeof(S));
xfile.close();
}
void unpaid(o4)
{
fstream xfile;
char a[10];
xfile.open("INSTI.dat",ios::binary|ios::in);
if(o4==1)
{strcpy(a,"Lucknow");}
if(o4==2)
{strcpy(a,"Mumbai");}
if(o4==3)
{strcpy(a,"Delhi");}
if(o4==4)
{strcpy(a,"Kharagpur");}
if(o4==5)
{strcpy(a,"Roorkee");}
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returnfeestatus(),"Unpaid")==0)&&(strcmpi(S.returnbranch(),a)==0))
{
disp(); clrscr();
}
}
xfile.close();
}
void countunpaid()
{
int s=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(strcmpi(S.returnfeestatus(),"Unpaid")==0)
{
s++;
}
}
cout<<endl<<"Unpaid fee students:"<<s;
xfile.close();
}
void del()
{
 ifstream xfile;
 char ch[4];
 cout<<endl<<"Enter Student Code of Record To Be Deleted";
 gets(ch);
 xfile.open("INSTI.dat",ios::binary|ios::in);
 ofstream yfile;
 yfile.open("temp.dat",ios::binary|ios::out) ;
 while(xfile.read((char*)&S,sizeof(S)))
 {
 if(strcmpi(S.returnscode(),ch)!=0)
 {
 yfile.write((char*)&S,sizeof(S));
 }
 }
 xfile.close();
 yfile.close();
 remove("INSTI.dat");
 rename("temp.dat","INSTI.dat");
 }
void countselections3(int o7)
{
char a[5];
if(o7==1)
{strcpy(a,"JEE");}
if(o7==2)
{strcpy(a,"NEET");}
if(o7==3)
{strcpy(a,"CLAT");}
fstream xfile;
int qs=0;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(S.returnmarks()>60&&(strcmpi(S.returncourse(),a)==0))
{
disp();
clrscr();
qs++;
}
}
cout<<endl<<"Total selected:"<<qs;
xfile.close();
}
void feestat7(int o7)
{
fstream xfile;
char fs[5];
if(o7==1)
{strcpy(fs,"JEE");}
if(o7==2)
{strcpy(fs,"NEET");}
if(o7==3)
{strcpy(fs,"CLAT");}
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returnfeestatus(),"Unpaid")==0)&&(strcmpi(S.returncourse(),fs)==0))
{
cout<<endl<<S.returnname()<<":Fee Unpaid";getch();
}
else if((strcmpi(S.returnfeestatus(),"Paid")==0)&&(strcmpi(S.returncourse(),fs)==0))
{
cout<<endl<<S.returnname()<<":Fee Paid"; getch();
}}
xfile.close();
}
void performance(o2)
{
char a[10];
if(o2==1)
{strcpy(a,"Lucknow");}
if(o2==2)
{strcpy(a,"Mumbai");}
if(o2==3)
{strcpy(a,"Delhi");}
if(o2==4)
{strcpy(a,"Kharagpur");}
if(o2==5)
{strcpy(a,"Roorkee");}
int c=0,d=0,e=0;float c1=0,d1=0,e1=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(strcmpi(S.returnbranch(),a)==0)
{
if(strcmpi(S.returncourse(),"JEE")==0)
{
c++;
if(S.returnmarks()>60)
{
c1++;
}}
else if(strcmpi(S.returncourse(),"NEET")==0)
{
d++;
if(S.returnmarks()>60)
{
d1++;
}}
else if(strcmpi(S.returncourse(),"CLAT")==0)
{
e++;
if(S.returnmarks()>60)
{
e1++;
}}}}
cout<<endl<<"Centre: "<<a<<endl;
cout<<endl<<"JEE::Number of students: "<<c<<endl<<"Selected: "<<((c1/c)*100)<<"%"<<endl;
cout<<endl<<"NEET::Number of students: "<<d<<endl<<"Selected: "<<((d1/d)*100)<<"%"<<endl;
cout<<endl<<"CLAT::Number of students: "<<e<<endl<<"Selected: "<<((e1/e)*100)<<"%"<<endl;
getch();
xfile.close();
}
void countstu1(int o1)
{
char a[10];
if(o1==1)
{strcpy(a,"Lucknow");}
if(o1==2)
{strcpy(a,"Mumbai");}
if(o1==3)
{strcpy(a,"Delhi");}
if(o1==4)
{strcpy(a,"Kharagpur");}
if(o1==5)
{strcpy(a,"Roorkee");}
int nos=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if(strcmpi(S.returnbranch(),a)==0)
{
disp();clrscr();
nos++;
}}
cout<<endl<<"Total number of students:"<<nos;
xfile.close();
}
void feestat1(o1)
{
fstream xfile;
char a[10];
xfile.open("INSTI.dat",ios::binary|ios::in);
if(o1==1)
{strcpy(a,"Lucknow");}
if(o1==2)
{strcpy(a,"Mumbai");}
if(o1==3)
{strcpy(a,"Delhi");}
if(o1==4)
{strcpy(a,"Kharagpur");}
if(o1==5)
{strcpy(a,"Roorkee");}
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returnfeestatus(),"Unpaid")==0)&&(strcmpi(S.returnbranch(),a)==0))
{
cout<<endl<<S.returnname()<<":Fee unpaid";getch();
}
else if((strcmpi(S.returnfeestatus(),"Paid")==0)&&(strcmpi(S.returnbranch(),a)==0))
{
cout<<endl<<S.returnname()<<":Fee Paid"; getch();
}
}
xfile.close();
}
void feestat5(int o4)
{
fstream xfile;
char a[10];
if(o4==1)
{strcpy(a,"Lucknow");}
else if(o4==2)
{strcpy(a,"Mumbai");}
else if(o4==3)
{strcpy(a,"Delhi");}
else if(o4==4)
{strcpy(a,"Kharagpur");}
else if(o4==5)
{strcpy(a,"Roorkee");}
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returnfeestatus(),"Unpaid")==0)&&(strcmpi(S.returnbranch(),a)==0))
{
cout<<endl<<S.returnname()<<":Fee unpaid";getch();
}
else if((strcmpi(S.returnfeestatus(),"Paid")==0)&&(strcmpi(S.returnbranch(),a)==0))
{
cout<<endl<<S.returnname()<<":Fee Paid";   getch();
}
}
xfile.close();
}
void countstu2(o1,o12)
{
char b[10];
if(o1==1)
{strcpy(b,"Lucknow");}
if(o1==2)
{strcpy(b,"Mumbai");}
if(o1==3)
{strcpy(b,"Delhi");}
if(o1==4)
{strcpy(b,"Kharagpur");}
if(o1==5)
{strcpy(b,"Roorkee");}
char c12[5];
if(o12==1)
{strcpy(c12,"JEE");}
if(o12==2)
{strcpy(c12,"NEET");}
if(o12==3)
{strcpy(c12,"CLAT");}
int nos=0;
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returncourse(),c12)==0)&&(strcmpi(S.returnbranch(),b)==0))
{
disp();clrscr();
nos++;
}}
cout<<endl<<"Total number of students of "<<b<<" "<<c12<<" are: "<<nos;
xfile.close();
}
void batch1(int o1,int o12,int l)
{
char a;
if(l==1)
{
a='A';
}
else
{
a='B';
}
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
char b=S.returnbatch();
if(a=='A'&&b==a)
{
if(o1==1&&(strcmpi(S.returnbranch(),"Lucknow")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1)){
disp();clrscr();                                        }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2)){
disp();clrscr(); 					 }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3)){
disp();clrscr(); 					  }
}
if(o1==2&&(strcmpi(S.returnbranch(),"Mumbai")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1))
				    {
disp();clrscr();
				      }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2))
				   {
disp(); clrscr(); 			    }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3) )
				 {
disp(); clrscr(); 			      }
}
if(o1==3&&(strcmpi(S.returnbranch(),"Delhi")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1))
{
disp();clrscr(); }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2)){
disp();clrscr();}
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3) )
{
disp();clrscr(); }
}
if(o1==4&&(strcmpi(S.returnbranch(),"Kharagpur")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1) )
{
disp();clrscr(); }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2) )
{
disp();clrscr(); }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3)){
disp();clrscr();}
}
if(o1==5&&(strcmpi(S.returnbranch(),"Roorkee")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1) )
{
disp();clrscr();}
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2)){
disp();clrscr(); }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3)){
disp();clrscr();}
}
}
if(a=='B'&&b==a)
{
if(o1==1&&(strcmpi(S.returnbranch(),"Lucknow")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1)){
disp();clrscr();                                        }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2)){
disp();clrscr(); 					 }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3)){
disp();clrscr(); 					  }
}
if(o1==2&&(strcmpi(S.returnbranch(),"Mumbai")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1))
				    {
disp();clrscr();
				      }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2))
				   {
disp(); clrscr(); 			    }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3) )
				 {
disp(); clrscr(); 			      }
}
if(o1==3&&(strcmpi(S.returnbranch(),"Delhi")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1))
{
disp();clrscr(); }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2)){
disp();clrscr();}
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3) )
{
disp();clrscr(); }
}
if(o1==4&&(strcmpi(S.returnbranch(),"Kharagpur")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1) )
{
disp();clrscr(); }
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2) )
{
disp();clrscr(); }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3)){
disp();clrscr();}
}
if(o1==5&&(strcmpi(S.returnbranch(),"Roorkee")==0))
{
if((strcmpi(S.returncourse(),"JEE")==0)&&(o12==1) )
{
disp();clrscr();}
if((strcmpi(S.returncourse(),"NEET")==0)&&(o12==2)){
disp();clrscr(); }
if((strcmpi(S.returncourse(),"CLAT")==0)&&(o12==3)){
disp();clrscr();}
}
}
}
xfile.close();
}
void countselections2(int o1,int o12)
{
char a[5];
if(o12==1)
{strcpy(a,"JEE");}
if(o12==2)
{strcpy(a,"NEET");}
if(o12==3)
{strcpy(a,"CLAT");}
char d12[10];
if(o1==1)
{strcpy(d12,"Lucknow");}
if(o1==2)
{strcpy(d12,"Mumbai");}
if(o1==3)
{strcpy(d12,"Delhi");}
if(o1==4)
{strcpy(d12,"Kharagpur");}
if(o1==5)
{strcpy(d12,"Roorkee");}
int nos=0;
fstream xfile;
int qs=0;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if((S.returnmarks()>60)&&(strcmpi(S.returncourse(),a)==0)&&(strcmpi(S.returnbranch(),d12)==0))
{
disp();clrscr();
qs++;
}
}
cout<<endl<<"Total selected of "<<d12<<" of "<<a<<" are: "<<qs;
}
void feestats(o1,o12)
{
char a[10],e12[5];
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
if(o1==1)
{strcpy(a,"Lucknow");}
if(o1==2)
{strcpy(a,"Mumbai");}
if(o1==3)
{strcpy(a,"Delhi");}
if(o1==4)
{strcpy(a,"Kharagpur");}
if(o1==5)
{strcpy(a,"Roorkee");}
if(o12==1)
{strcpy(e12,"JEE");}
if(o12==2)
{strcpy(e12,"NEET");}
if(o12==3)
{strcpy(e12,"CLAT");}
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returnfeestatus(),"Unpaid")==0)&&
(strcmpi(S.returnbranch(),a)==0)&&(strcmpi(S.returncourse(),e12)==0))
{
cout<<endl<<S.returnname()<<":Fee Unpaid"<<endl;getch();
}
else if((strcmpi(S.returnfeestatus(),"Paid")==0)&&
(strcmpi(S.returnbranch(),a)==0)&&(strcmpi(S.returncourse(),e12)==0))
{
cout<<endl<<S.returnname()<<":Fee Paid"<<endl;   getch();
}}
xfile.close();
}
void performance2(o1,o12)
{
char a[10],e12[5];
if(o1==1)
{strcpy(a,"Lucknow");}
if(o1==2)
{strcpy(a,"Mumbai");}
if(o1==3)
{strcpy(a,"Delhi");}
if(o1==4)
{strcpy(a,"Kharagpur");}
if(o1==5)
{strcpy(a,"Roorkee");}
if(o12==1)
{strcpy(e12,"JEE");}
if(o12==2)
{strcpy(e12,"NEET");}
if(o12==3)
{strcpy(e12,"CLAT");}
fstream xfile;
xfile.open("INSTI.dat",ios::binary|ios::in);
while(xfile.read((char*)&S,sizeof(S)))
{
if((strcmpi(S.returnbranch(),a)==0)&&(strcmpi(S.returncourse(),e12)==0))
{
cout<<endl<<"Name:"<<S.returnname()<<endl<<" Marks:"<<S.returnmarks()<<endl;
getch();
}
}
getch();
xfile.close();
}
void box()
{
clrscr();
textcolor(WHITE);
clrscr();
int R1=10,R2=70,C1=1,C2=25;
gotoxy(R1,C1);cout<<(char)201;
gotoxy(R1,C2);cout<<(char)200;
gotoxy(R2,C1);cout<<(char)187;
gotoxy(R2,C2);cout<<(char)188;
for(int i=R1+1;i<R2;i++)
{
gotoxy(i,C1);cout<<(char)205;
gotoxy(i,C2);cout<<(char)205;
}
for(int b=C1+1;b<C2;b++)
{
gotoxy(R1,b);cout<<(char)186;
gotoxy(R2,b);cout<<(char)186;
}
getch();
}
void menu()
{
box();
gotoxy(5,5);
gotoxy(12,5);
gotoxy(12,6);cout<<"\t\tOption Menu"<<endl;
gotoxy(12,7);cout<<"\t\t1.  Branch"<<endl;
gotoxy(12,8);cout<<"\t\t2.  Performance of Centres"<<endl;
gotoxy(12,9);cout<<"\t\t3.  Top Rankers"<<endl;
gotoxy(12,10);cout<<"\t\t4.  Fees"<<endl;
gotoxy(12,11);cout<<"\t\t5.  Search Particular"<<endl;
gotoxy(12,12);cout<<"\t\t6.  Details"<<endl;
gotoxy(12,13);cout<<"\t\t7.  Course"<<endl;
gotoxy(12,14);cout<<"\t\t8.  Modify/Delete"<<endl;
gotoxy(12,15);cout<<"\t\t9.  Add a record"<<endl;
gotoxy(12,16);cout<<"\t\t10. Exit"<<endl;
int ch;
gotoxy(12,18);cout<<"\t\tSelect an option number:"<<endl;
gotoxy(49,18);cin>>ch;
clrscr();
switch(ch)
{
case 1: {showbranch();
	cout<<endl<<"Select Branch:";
	cin>>o1;
	int a=o1;
	if(o1==1||o1==2||o1==3||o1==4||o1==5)
	{
	a=1;
	}
	else
	{
	a=6;
	}
	switch(a)
	{
	case 1:cout<<endl<<"1. Course"<<endl<<"2. Number of students and their details"<<endl<<
	"3. Performance of selected students"<<endl<<
	"4. Fee and its status"<<endl<<"5. Return to the main menu";
	cout<<endl<<"Select an option:";
	int n1;
	cin>>n1;
	clrscr();
		switch(n1)
		{
		case 1: cout<<"1. JEE"<<endl<<"2. NEET"<<endl<<"3. CLAT";
			cout<<endl<<"Select the option number";
			cin>>o12;
			int j=o12;
			if(o12==1||o12==2||o12==3)
			{
			j=1;
			}
				switch(j)
				{
				case 1:	cout<<endl<<"1. Batch"<<endl<<"2. Students's Details"<<endl<<
				 "3. Selections"<<endl<<"4. Fee status"<<endl<<"5. Performance of students"<<endl<<"6. Return to the main menu";
				cout<<endl<<"Select option number:";
				int o121;
				cin>>o121;
clrscr();
					switch(o121)
						{
					 case 1:  cout<<endl<<"1. A";
					  cout<<endl<<"2. B";
					 int h;
					 cout<<endl<<"Select Batch";
					 cin>>h;
					 getch();
clrscr();
								  switch(a)
						       {
							   case 1: batch1(o1,o12,h);break;  menu();
							   case 2: batch1(o1,o12,h);break;  menu();
							}
						 break;
				 case 2: countstu2(o1,o12);break;
				 case 3: showselected(o1,o12);break;
				 case 4: feestats(o1,o12);break;
				 case 5: performance2(o1,o12);break;
				 case 6: menu();
				 }menu();}break;
		case 2: countstu1(o1); break;
		case 3: smarks(o1); break;
		case 4: feestat1(o1); break;
		case 5: cout<<endl<<"To return to main menu press enter key";menu();
		}break;
      case 6:menu();
      }menu();} break;

case 2: {showbranch();
	cout<<endl<<"Select option number:";
	cin>>o2;
	clrscr();
	int r;
	if(o2==1||o2==2||o2==3||o2==4||o2==5)
	{
	r=1;
	}
	else
	{
	r=6;}
	switch(r)
	{
	case 1: performance(o2);break;
	case 6: menu();}
	menu();}
	break;
case 3: {showcourse();
	cout<<endl<<"Select option number:";
	cin>>o3;
	clrscr();
	int x;
	if(o3==1||o3==2||o3==3)
	{
	x=1;
	}
	else  if(o3!=1||o3!=2||o3!=3)
	{
	x=4;
	}
	switch(x)
	{
	case 1:
	toprankers(o3);break;
	case 4: menu();
	}menu();}  break;
case 4: showbranch();
	cout<<endl<<"Select option number:";
	cin>>o4;
	int e;
	if(o4==1||o4==2||o4==3||o4==4||o4==5)
	{
	e=1;
	}
	else
	{
	e=6;}
	clrscr();
	switch(e)
	{
	case 1: cout<<endl<<"\t\t\t\tSelect option number";
		cout<<endl<<"1. Fee status";
		cout<<endl<<"2. Unpaid records";
		cout<<endl<<"3. Return to main menu";
		int o41;
		cin>>o41;
		getch();
		clrscr();
		switch(o41)
		{
		case 1: feestat5(o4); break;
		case 2: unpaid(o4); break;
		case 3: menu();
		}
	case 6: menu();
	}break;
case 5: {searchparticular();menu();} break;
case 6: {cout<<endl<<"Total number of students:"<<countstu();
	cout<<endl<<"Total number of selections:"<<countselections();
	countgender();
	countunpaid();
	cout<<endl<<"Total Fees Collected:"<<revenue();
	getch();
	cout<<endl<<"To return to main menu press enter key";
	menu();}
	break;
	getch();
clrscr();
case 7: showcourse();
	cout<<endl<<"Select option number:";
	cin>>o7;
	clrscr();
	int f;
	if(o7==1||o7==2||o7==3)
	{
	f=1;
	}
	else
	{
	f=4;}
	switch(f)
	{
	case 1: cout<<endl<<"\t\t\t\tSelect option number";
		cout<<endl<<"1. Students and their details";
		cout<<endl<<"2. Selections";
		cout<<endl<<"3. Fee and its status";
		cout<<endl<<"4. Return to main menu";
		cin>>o71;
		getch();
		clrscr();
		switch(o71)
		{
		case 1 : countstu3(o7); break;
		case 2 : countselections3(o7); break;
		case 3 : feestat7(o7); break;
		case 4 : menu();
		}
	case 4: menu();}
		getch();
	clrscr();
	break;
case 8: {cout<<endl<<"\tSelect option";
	cout<<endl<<"1. Modify";
	cout<<endl<<"2. Delete";
	cout<<endl<<"3. Return To Main Menu";
	cout<<endl<<"SELECT OPTION";
	int o8;
	cin>>o8;
	switch(o8)
	{
	case 1: modify(); break;
	case 2: del(); break;
	case 3: menu();
	}menu();}break;
case 9:{ clrscr();
	addrec();
	menu();}  break;
case 10: exit(0);  break;
}
}
void pass()
{
 clrscr();
 gotoxy(20,10);cout<<endl<<"Enter Password :";
 int r=10,c=30,i;
 char ps[16];
 for(i=0,r=10,c=30;c<35,i<16;c++,i++)
{
 gotoxy(c,r);
 ps[i]=getch();
 gotoxy(c,r);cout<<"*";
}
ps[i]='\0';
if(strcmp(ps,"theintellectuals")==0)
{
 cout<<endl<<"You are welcomed (^o^)";
 getch();
 menu();
 }
else
{
 cout<<endl<<"You are not authorised to enter!";
 }
getch();
}
void main()
{
clrscr();
pass();
getch();
}
