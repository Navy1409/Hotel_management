#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<cstdlib>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
/*168�169�170�171�172�173�174�175�176�177�178�179�180�181�182�183�184�185�186�198�188�189�190�191�192�193�194�195�196�197�198� 199�200�201�202�203�204�205�206�207�208�209�210�211�212�213�214�215�*/
struct datea
{
 int dd;
 int mm;
 int yy;
};
struct timeb
{
 int hh,mm;
};
struct distc
{
 int km,m;
};
void border()
{
 clrscr();
 randomize();
 int a=random(13)+2;
 textcolor(a);
 textbackground(0);
 for(int i=2;i<=79;i+=2)
 {
  gotoxy(i,2);  cprintf("�");
  gotoxy(i,24); cprintf("�");
 }
 for(i=3;i<=79;i+=2)
 {
  gotoxy(i,2);   cprintf("�");
  gotoxy(i,24);  cprintf("�");
 }
 for(i=2;i<=24;i++)
 {
  gotoxy(2,i);   cprintf("��");
  gotoxy(79,i);  cprintf("��");
 }
}
void name1()
{
 border();
 gotoxy(30,4);
 cprintf("THE GRANGER ORION");
 gotoxy(28,5);
 cprintf("�------------------�");
 getch();
}
class guest
{
 private:
	 int rno;
	 char name[20];
	 datea doci;
	 datea doco;
	 int days;
	 char room[20];
	 long int pay;
	 long int tpay;
	 char pno[10];
	 void day1()
	 {
	  int n;
	  if(doci.mm<doco.mm)
	  {
	   n=doco.mm-doci.mm;
	   if(doci.mm==1||doci.mm==3||doci.mm==5||doci.mm==7||doci.mm==8||doci.mm==10||doci.mm==12)
	    days=(doco.mm+(31*n))-doci.mm;
	   if(doci.mm==4||doci.mm==6||doci.mm==9||doci.mm==11)
	    days=(doco.dd+(30*n))-doci.dd;
	   if(doci.mm==2)
	   {
	    if(doci.yy%4==0)
	     days=(doco.dd+(29))-doci.dd;
	    else
	     days=(doco.dd+28)-doci.dd;
	   }
	  }
	  else
	   days=doco.dd-doci.dd;
	 }
	 void calpay()
	 {
	  pay=0,tpay=0;
	  if(strcmpi(room,"single")==0)
	   pay=1000;
	  if(strcmpi(room,"double")==0)
	   pay=2000;
	  if(strcmpi(room,"delux")==0)
	   pay=3000;
	  tpay=days*pay;
	 }
 public:
	void inputdetails();
	void displaydetails();
	int retrno()
	{
	 return rno;
	}
	char* retname()
	{
	 return name;
	}
	int cidated()
	{
	 return doci.dd;
	}
	int cidatem()
	{
	 return doci.mm;
	}
	int cidatey()
	{
	 return doci.yy;
	}
	int codated()
	{
	 return doco.dd;
	}
	int codatem()
	{
	 return doco.mm;
	}
	int codatey()
	{
	 return doco.yy;
	}
	char* retpno()
	{
	 return pno;
	}
	void updaterno()
	{
	 border();
	 name1();
	 int t;
	 gotoxy(29,9);
	 cprintf("Enter new room number:");
	 cin>>t;
	 rno=t;
	 getch();
	}
}g;
void guest::inputdetails()
{
 border();
 name1();
 for(int i=4;i<=21;i++)
 {
  gotoxy(i,7);cprintf("�");
  gotoxy(i,9);cprintf("�");
  gotoxy(i,13);cprintf("�");
 }
 for(i=7;i<=13;i++)
 {
  gotoxy(4,i);cprintf("�");
  gotoxy(14,i);cprintf("�");
  gotoxy(21,i);cprintf("�");
 }
 gotoxy(5,8);   cprintf("Room Type");
 gotoxy(15,8);  cprintf("Price");
 gotoxy(5,10);  cprintf("Single");
 gotoxy(15,10); cprintf("1000");
 gotoxy(5,11);  cprintf("Double");
 gotoxy(15,11); cprintf("2000");
 gotoxy(5,12);  cprintf("Delux");
 gotoxy(15,12); cprintf("3000");
 gotoxy(29,6);  cprintf("ENTER DETAILS:");cout<<endl;
 gotoxy(29,7);  cprintf("Enter room no.:");
 cin>>rno;
 gotoxy(29,8);  cprintf("Enter Name:");
 gets(name);
 gotoxy(29,9);  cprintf("Enter Date of checkin:");
 gotoxy(53,9); cin>>doci.dd;
 gotoxy(56,9); cin>>doci.mm;
 gotoxy(59,9); cin>>doci.yy;
 gotoxy(29,10);
 cprintf("Enter Date of checkout:");
 gotoxy(53,10);cin>>doco.dd;
 gotoxy(56,10);cin>>doco.mm;
 gotoxy(59,10);cin>>doco.yy;
 day1();
 gotoxy(29,11); cprintf("Enter type of room:");
 gets(room);
 calpay();
 gotoxy(29,12); cprintf("Enter phone no:");
 cin>>pno;
 getch();
}
void guest::displaydetails()
{
 border();
 name1();
 gotoxy(29,9);
 cprintf("Room no.:");cout<<rno;
 gotoxy(29,10);
 cprintf("Name:");cout<<name;
 gotoxy(29,11);
 cprintf("Date of checkin:");cout<<doci.dd<<"/"<<doci.mm<<"/"<<doci.yy;
 gotoxy(29,12);
 cprintf("Date of checkout:");cout<<doco.dd<<"/"<<doco.mm<<"/"<<doco.yy;
 gotoxy(29,13);
 cprintf("Payment:");cout<<tpay;
 gotoxy(29,14);
 cprintf("Phone no:");cout<<pno;
 getch();
}
void cnrecord()
{
 border();
 name1();
 textcolor(1);
 ofstream fo("guest.txt",ios::binary);
 g.inputdetails();
 fo.write((char*)&g,sizeof(g));
 fo.close();
}
void arecord()
{
 border();
 name1();
 textcolor(4);
 ofstream fo("guest.txt",ios::binary||ios::app);
 fo.seekp(0,ios::end);
 g.inputdetails();
 fo.write((char*)&g,sizeof(g));
 fo.close();
}
void drecord()
{
 border();
 name1();
 ifstream fi("guest.txt",ios::binary);
 while(fi.read((char*)&g,sizeof(g)))
	   g.displaydetails();
 fi.close();
}
void sbyrno()
{
 border();
 name1();
 ifstream fi("guest.txt",ios::binary);
 int r;
 gotoxy(29,9);
 cprintf("Enter room no. for searching:");
 cin>>r;
 while(fi.read((char*)&g,sizeof(g)))
 {
  if(r==g.retrno())
  {
   g.displaydetails();
   getch();
  }
 }
 fi.close();
 getch();
}
void sbyname()
{
 border();
 name1();
 ifstream fi("guest.txt",ios::binary);
 char n[20];
 gotoxy(29,9);
 cprintf("Enter name for searching:");
 gets(n);
 while(fi.read((char*)&g, sizeof(g)))
 {
  if(strcmpi(n,g.retname())==0)
   g.displaydetails();
 }
 fi.close();
 getch();
}
void sbydoci()
{
 border();
 name1();
 ifstream fi("guest.txt",ios::binary);
 guest g;
 datea d;
 gotoxy(19,9);
 cprintf("Enter date of checkin for searching:");
 gotoxy(66,9);
 cin>>d.dd;
 gotoxy(69,9);
 cin>>d.mm;
 gotoxy(72,9);
 cin>>d.yy;
 while(fi.read((char*)&g, sizeof(g)))
 {
  if(d.dd==g.cidated()&&d.mm==g.cidatem()&&d.yy==g.cidatey())
   g.displaydetails();
 }
 fi.close();
 getch();
}
void sbydoco()
{
 border();
 name1();
 ifstream fi("guest.txt",ios::binary);
 datea d;
 gotoxy(19,9);
 cprintf("Enter date of checkout for searching:");
 gotoxy(67,9);  cin>>d.dd;
 gotoxy(70,9);  cin>>d.mm;
 gotoxy(73,9);  cin>>d.yy;
 while(fi.read((char*)&g, sizeof(g)))
 {
  if(d.dd==g.codated()&&d.mm==g.codatem()&&d.yy==g.codatey())
   g.displaydetails();
 }
 fi.close();
 getch();
}
void sbypno()
{
 border();
 name1();
 ifstream fi("guest.txt",ios::binary);
 char p[10];
 gotoxy(29,9);
 cprintf("Enter phone no. for searching:");
 cin>>p;
 while(fi.read((char*)&g,sizeof(g)))
 {
  if(strcmpi(g.retpno(),p)==0)
   g.displaydetails();
 }
 fi.close();
 getch();
}
void changerno()
{
 border();
 name1();
 fstream fi("guest.txt",ios::binary|ios::in|ios::out);
 fstream fo("temp.txt",ios::binary|ios::in|ios::out);
 int r;
 gotoxy(29,9);
 cprintf("Enter current room no.:");
 cin>>r;
 while(fi.read((char*)&g,sizeof(g)))
 {
  if(g.retrno()==r)
  {
   g.updaterno();
  }
  fo.write((char*)&g,sizeof(g));
 }
 fi.close();
 fo.close();
 remove("guest.txt");
 rename("temp.txt","guest.txt");
}
class visitor
{
 private:
	 char name[20];
	 int rno;
	 char nameoo[20];
	 timeb toe;
	 timeb tox;
	 datea dov;
 public:
	void inputdetails();
	void displaydetails();
	char* retnov()
	{
	 return name;
	}
	char* retnog()
	{
	 return nameoo;
	}
	int retdate()
	{
	 return dov.dd;
	}
	int retmon()
	{
	 return dov.mm;
	}
	int retyear()
	{
	 return dov.yy;
	}
	int retrnv()
	{
	 return rno;
	}
}v;
void visitor::inputdetails()
{
 border();
 name1();
 gotoxy(29,8);
 cprintf("Enter visitor details");cout<<endl;
 gotoxy(28,9);
 cprintf("**====================**");cout<<endl;
 gotoxy(20,10);
 cprintf("Enter name of visitor:");
 gets(name);
 gotoxy(20,11);
 cprintf("Enter room no. to visit:");
 cin>>rno;
 gotoxy(20,12);
 cprintf("Enter name of guest staying in room no.");cout<<rno<<":";
 gets(nameoo);
 gotoxy(20,13);
 cprintf("Enter time of entry:");
 gotoxy(41,13);
 cin>>toe.hh;
 gotoxy(44,13);
 cin>>toe.mm;
 gotoxy(20,14);
 cprintf("Enter time of exit:");
 gotoxy(41,14);
 cin>>tox.hh;
 gotoxy(44,14);
 cin>>tox.mm;
 gotoxy(20,15);
 cprintf("Enter date of visiting:");
 gotoxy(43,15);
 cin>>dov.dd;
 gotoxy(46,15);
 cin>>dov.mm;
 gotoxy(49,15);
 cin>>dov.yy;
 getch();
}
void visitor::displaydetails()
{
 border();
 name1();
 gotoxy(29,7);
 cprintf("VISITOR DETAILS:");cout<<endl;
 gotoxy(27,8);
 cprintf("**------------------**");cout<<endl;
 gotoxy(29,9);
 cprintf("Name of visitor:");cout<<name<<endl;
 gotoxy(29,10);
 cprintf("Room no. visited:");cout<<rno<<endl;
 gotoxy(29,11);
 cprintf("Guest staying in room no. ");cout<<rno<<":"<<nameoo<<endl;
 gotoxy(29,12);
 cprintf("Time of entry :");cout<<toe.hh<<":"<<toe.mm<<endl;
 gotoxy(29,13);
 cprintf("Time of exit :");cout<<tox.hh<<":"<<tox.mm<<endl;
 gotoxy(29,14);
 cprintf("Date of visiting:");cout<<dov.dd<<"/"<<dov.mm<<"/"<<dov.yy<<endl;
 getch();
}
void createn()
{
 border();
 name1();
 ofstream fo("visitor.txt",ios::binary);
 visitor v;
 v.inputdetails();
 fo.write((char*)&v,sizeof(v));
 fo.close();
}
void addn()
{
 border();
 name1();
 ofstream fo("visitor.txt",ios::binary||ios::app||ios::in);
 fo.seekp(0,ios::end);
 v.inputdetails();
 fo.write((char*)&v,sizeof(v));
 fo.close();
}
void display()
{
 border();
 name1();
 ifstream fi("visitor.txt",ios::binary);
 fi.read((char*)&v,sizeof(v));
 v.displaydetails();
 getch();
 fi.close();
}
void sbnv()
{
 border();
 name1();
 ifstream fi("visitor.txt",ios::binary);
 char nov[20];
 gotoxy(20,9);cprintf("Enter Name of visitor : ");
 gets(nov);
 while(fi.read((char*)&v,sizeof(v)))
 {
  if(strcmpi(v.retnov(),nov)==0)
  {
   v.displaydetails();
   getch();
  }
 }
 fi.close();
 getch();
}
void sbnog()
{
 border();
 name1();
 ifstream fi("visitor.txt",ios::binary);
 char noo[20];
 gotoxy(20,9);
 cprintf("Enter Name of guest staying : ");
 gets(noo);
 while(fi.read((char*)&v,sizeof(v)))
 {
  if(strcmpi(v.retnog(),noo)==0)
   {
    v.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbrnv()
{
 border();
 name1();
 ifstream fi("visitor.txt",ios::binary);
 int r;
 gotoxy(20,9);
 cprintf("Enter room no. : ");
 cin>>r;
 while(fi.read((char*)&v,sizeof(v)));
 {
  if(v.retrnv()==r)
   {
    v.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbdate()
{
 border();
 name1();
 ifstream fi("visitor.txt",ios::binary);
 datea d;
 gotoxy(20,9);
 cprintf("Enter Date of visiting : ");
 gotoxy(46,9);cin>>d.dd;
 gotoxy(49,9);cin>>d.mm;
 gotoxy(52,9);cin>>d.yy;
 while(fi.read((char*)&v,sizeof(v)));
 {
  if(v.retdate()==d.dd&&v.retmon()==d.mm&&v.retyear()==d.yy)
   {
    v.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
class transport
{
 private:
	 char carno[20];
	 char name[20];
	 distc di;
	 datea d;
	 timeb vleft;
	 timeb varrived;
	 int pay;
	 char dname[20];
	 int td;
	 char dest[20];
	 int rno;
 public:
	void inputdetails();
	void displaydetails()
       {
	border();
	name1();
	gotoxy(29,7);
	cprintf("Guest Details");cout<<endl;
	gotoxy(29,8);
	cprintf("+++++++++++++++++");
	gotoxy(29,9);
	cprintf("Name of guest:");
	puts(name);
	gotoxy(29,10);
	cprintf("Name of driver:");
	puts(dname);
	gotoxy(29,11);
	cprintf("Car no.:");
	puts(carno);
	gotoxy(29,12);
	cprintf("Room no. of guest:");cout<<rno<<endl;
	gotoxy(29,13);
	cprintf("Date:");cout<<d.dd<<"/"<<d.mm<<"/"<<d.yy<<endl;
	gotoxy(29,14);
	cprintf("Leaving time:");cout<<vleft.hh<<":"<<vleft.mm<<endl;
	gotoxy(29,15);
	cprintf("Arriving time:");cout<<varrived.hh<<":"<<varrived.mm<<endl;
	gotoxy(29,16);
	cprintf("Destination :");
	puts(dest);
	gotoxy(29,17);
	cprintf("Distance covered:");cout<<di.km<<di.m;
	gotoxy(29,18);
	cprintf("Total payment:");cout<<pay;
	getch();
       }
       char* retng()
       {
	return name;
       }
       char* retnd()
       {
	return dname;
       }
       char* retcn()
       {
	return carno;
       }
       int dated()
       {
	return d.dd;
       }
       int datem()
       {
	return d.mm;
       }
       int datey()
       {
	return d.yy;
       }
       char* desti()
       {
	return dest;
       }
       int retrng()
       {
	return rno;
       }
}t;
void transport::inputdetails()
{
 border();
 name1();
 gotoxy(29,8);cprintf("Enter guest details");
 gotoxy(27,9);cprintf("<<------------------->>");
 gotoxy(29,10);cprintf("Enter car no:");
 gets(carno);;
 gotoxy(29,11);cprintf("Enter name of guest hired car:");
 gets(name);
 gotoxy(29,12);cprintf("Enter name of driver:");
 gets(dname);
 gotoxy(29,13);cprintf("Enter date:");
 gotoxy(41,13);cin>>d.dd;
 gotoxy(44,13);cin>>d.mm;
 gotoxy(47,13);cin>>d.yy;
 gotoxy(29,14);cprintf("Enter room no.:");
 cin>>rno;
 gotoxy(29,15);
 cprintf("Enter time at which vehicle left:");
 gotoxy(63,15);
 cin>>vleft.hh;
 gotoxy(66,15);
 cin>>vleft.mm;
 gotoxy(29,16);
 cprintf("Enter time at which vehicle arrived:");
 gotoxy(66,16);
 cin>>varrived.hh;
 gotoxy(69,16);
 cin>>varrived.mm;
 gotoxy(29,17);
 cprintf("Enter distance to be covered:");
 gotoxy(59,17);
 cin>>di.km;
 gotoxy(62,17);
 cin>>di.m;
 gotoxy(29,18);
 cprintf("Enter destination:");
 gets(dest);
 td=di.km*1000+di.m;
 for(int n=1;n<=10;n++)
 {
  if(td<=n*1000&&td>(n-1)*1000)
   pay=n*100;
 }
 getch();
}
void indetails()
{
 border();
 name1();
 ofstream fo("trans.txt",ios::binary);
 t.inputdetails();
 fo.write((char*)&t,sizeof(t));
 fo.close();
}
void addetails()
{
 border();
 name1();
 ofstream fo("trans.txt",ios::binary||ios::app);
 fo.seekp(0,ios::end);
 t.inputdetails();
 fo.write((char*)&t,sizeof(t));
 fo.close();
}
void ddetails()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 while(fi.read((char*)&t,sizeof(t)))
  {
   t.displaydetails();
   getch();
  }
 fi.close();
}
void sbng()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 char ng[20];
 gotoxy(29,6);
 cprintf("Enter name of guest:");
 gets(ng);
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(strcmpi(t.retng(),ng)==0)
   {
    t.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbnd()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 char nd[20];
 gotoxy(29,6);
 cprintf("Enter name of driver:");
 gets(nd);
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(strcmpi(t.retnd(),nd)==0)
   {
    t.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbcn()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 char cn[30];
 gotoxy(29,6);
 cprintf("Enter car no.:");
 gets(cn);
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(strcmpi(t.retcn(),cn)==0)
   {
    t.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbrnog()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 int cn;
 gotoxy(29,6);
 cprintf("Enter room no. to search:");
 cin>>cn;
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(t.retrng()==cn)
   {
    t.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbtdate()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 datea d;
 gotoxy(29,6);
 cprintf("Enter date:");
 gotoxy(45,6);
 cin>>d.dd;
 gotoxy(48,6);
 cin>>d.mm;
 gotoxy(51,6);
 cin>>d.yy;
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(t.dated()==d.dd&&t.datem()==d.mm&&t.datey()==d.yy)
   {
    t.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbdesti()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 char dest[20];
 gotoxy(29,6);
 cprintf("Enter Destination");
 gets(dest);
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(strcmpi(t.desti(),dest)==0)
   {
    t.displaydetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbrno1()
{
 border();
 name1();
 ifstream fi("trans.txt",ios::binary);
 int r;
 gotoxy(29,9);
 cprintf("Enter room no. for searching:");
 cin>>r;
 while(fi.read((char*)&t,sizeof(t)))
 {
  if(r==t.retrng())
  {
   t.displaydetails();
   getch();
  }
 }
 fi.close();
 getch();
}
class employee
{
 private:
	 int emp;
	 char name[20];
	 char fname[20];
	 datea dob;
	 datea doj;
	 char post[20];
	 char dept[20];
	 float salary;
 public:
	void inputdetails()
	{
	  border();
	  name1();
	  gotoxy(32,7);
	  cprintf("ENTER DETAILS:");cout<<endl;
	  gotoxy(33,8);
	  cprintf("Enter Name:");
	  gets(name);
	  gotoxy(29,9);
	  cprintf("Enter Date of birth:");
	  gotoxy(50,9);
	  cin>>dob.dd;
	  gotoxy(53,9);
	  cin>>dob.mm;
	  gotoxy(56,9);
	  cin>>dob.yy;
	  gotoxy(29,10);
	  cprintf("Enter Date of joining:");
	  gotoxy(53,10);
	  cin>>doj.dd;
	  gotoxy(56,10);
	  cin>>doj.mm;
	  gotoxy(58,10);
	  cin>>doj.yy;
	  gotoxy(29,11);
	  cprintf("Enter employee no.:");
	  cin>>emp;
	  gotoxy(29,12);
	  cprintf("Enter type of department:");
	  gets(dept);
	  if(strcmpi(dept,"mess")==0)
	  {
	   gotoxy(29,13);cprintf("Enter post:");
	   gets(post);
	   if(strcmpi(post,"chef")==0)
	    salary=50000;
	   if(strcmpi(post,"waiter")==0)
	    salary=15000;
	  }
	  if(strcmpi(dept,"room service")==0)
	  {
	   salary=15000;
	  }
	  if(strcmpi(dept,"Financial")==0)
	  {
	   gotoxy(29,13);cprintf("Enter post:");
	   gets(post);
	   if(strcmpi(post,"manager")==0)
	    salary=60000;
	   if(strcmpi(post,"Receptionist")==0)
	    salary=30000;
	  }
	  getch();
	 }
	void disdetails()
	{
	  border();
	  name1();
	  gotoxy(32,6);
	  cprintf("EMPLOYEE DETAILS:");cout<<endl;
	  gotoxy(29,7);
	  cprintf("Name:");
	  gotoxy(35,7);
	  puts(name);
	  gotoxy(29,8);
	  cprintf("Date of birth:");
	  gotoxy(44,8);
	  cout<<dob.dd;
	  gotoxy(47,8);
	  cout<<dob.mm;
	  gotoxy(50,8);
	  cout<<dob.yy;
	  gotoxy(29,9);
	  cprintf("Date of joining:");
	  gotoxy(46,9);
	  cout<<doj.dd;
	  gotoxy(49,9);
	  cout<<doj.mm;
	  gotoxy(52,9);
	  cout<<doj.yy;
	  gotoxy(29,10);
	  cprintf("Employee no.:");
	  gotoxy(44,10);
	  cout<<emp;
	  gotoxy(29,11);
	  cprintf("Type of department:");
	  gotoxy(50,11);
	  puts(dept);
	  gotoxy(29,12);
	  cprintf("Post:");
	  gotoxy(36,12);
	  puts(post);
	  gotoxy(29,13);
	  cprintf("Salary:");cout<<salary;
	  }
	  char* retname1()
	  {
	   return name;
	  }
	  int retemp()
	  {
	   return emp;
	  }
	  char* retdept()
	  {
	   return dept;
	  }
	  char* retpost()
	  {
	   return post;
	  }
}e;
void cnrcrd()
{
 ofstream fo("emp.txt",ios::binary);
 e.inputdetails();
 fo.write((char*)&e,sizeof(e));
 fo.close();
}
void arcrd()
{
 ofstream fo("emp.txt",ios::binary||ios::app);
 fo.seekp(0,ios::end);
 e.inputdetails();
 fo.write((char*)&e,sizeof(e));
 fo.close();
}
void drcrd()
{
 ifstream fi("emp.txt",ios::binary);
 while(fi.read((char*)&e,sizeof(e)))
 {
  e.disdetails();
  getch();
 }
 fi.close();
}
void sbyempno()
{
 border();
 name1();
 ifstream fi("emp.txt",ios::binary);
 int r;
 gotoxy(29,9);
 cprintf("Enter employee no. for searching:");
 cin>>r;
 while(fi.read((char*)&e,sizeof(e)))
 {
  if(e.retemp()==r)
   {
    e.disdetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbyename()
{
 border();
 name1();
 ifstream fi("emp.txt",ios::binary);
 char n[20];
 gotoxy(29,9);cprintf("Enter name for searching:");
 gets(n);
 while(fi.read((char*)&e, sizeof(e)))
 {
  if(strcmpi(e.retname1(),n)==0)
   {
    e.disdetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbydept()
{
 border();
 name1();
 ifstream fi("emp.txt",ios::binary);
 char n[20];
 gotoxy(29,9);
 cprintf("Enter department for searching:");
 gets(n);
 while(fi.read((char*)&e, sizeof(e)))
 {
  if(strcmpi(e.retdept(),n)==0)
   {
    e.disdetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void sbypost()
{
 border();
 name1();
 ifstream fi("emp.txt",ios::binary);
 char n[20];
 gotoxy(29,9);
 cprintf("Enter post for searching:");
 gets(n);
 while(fi.read((char*)&e,sizeof(e)))
 {
  if(strcmpi(e.retpost(),n)==0)
   {
    e.disdetails();
    getch();
   }
 }
 fi.close();
 getch();
}
void front()
{
 int a,b,i;
 border();
 for(i=27;i<=50;i++)
 {
  gotoxy(i,5);cprintf("");
  gotoxy(i,6);cprintf("");
  gotoxy(i,9);cprintf("");
  gotoxy(i,12);cprintf("");
  gotoxy(i,18);cprintf("");
  gotoxy(i,19);cprintf("");
 }
 for(i=6;i<=18;i++)
 {
  gotoxy(27,i);cprintf("�");
  gotoxy(50,i);cprintf("�");
 }
 gotoxy(55,8);
 cprintf("���������");
 gotoxy(55,9);
 cprintf("��       ");
 gotoxy(55,10);
 cprintf("��   ����ranger");
 gotoxy(55,11);
 cprintf("��     ����������");
 gotoxy(55,12);
 cprintf("�����������    ��");
 gotoxy(55,13);
 cprintf("         ��    ��");
 gotoxy(55,14);
 cprintf("         ��    ��");
 gotoxy(55,15);
 cprintf("         ��������rion");
 gotoxy(30,7);cprintf("THE GRANGER ORIEN");cout<<endl;
 gotoxy(29,8);cprintf("x==================x");cout<<endl;
 gotoxy(32,10);cprintf("LUCKNOW,INDIA");cout<<endl;
 gotoxy(29,11);cprintf("x=================x");cout<<endl;
 gotoxy(30,13);cprintf("1.Guest details");cout<<endl;
 gotoxy(30,14);cprintf("2.Visitor Details");cout<<endl;
 gotoxy(30,15);cprintf("3.Vehicle Details");cout<<endl;
 gotoxy(30,16);cprintf("4.Worker Details");cout<<endl;
 gotoxy(30,17);cprintf("5.Exit");cout<<endl;
 gotoxy(12,20);cprintf("Enter the no. of which you want to find details");
 gotoxy(61,20);cin>>a;
 if(a==1)
 {
  do
  {
   border();
   name1();
   gotoxy(30,7);cprintf("1..Create new record\n");
   gotoxy(30,8);cprintf("2..Add new record\n");
   gotoxy(30,9);cprintf("3..Display record\n");
   gotoxy(30,10);cprintf("4..Search by room no.\n");
   gotoxy(30,11);cprintf("5..Search by name\n");
   gotoxy(30,12);cprintf("6..Search by date of checkin\n");
   gotoxy(30,13);cprintf("7..Search by date of checkout\n");
   gotoxy(30,14);cprintf("8..Search by phone no.\n");
   gotoxy(30,15);cprintf("9..Change room no.\n");
   gotoxy(30,16);cprintf("10..Front page\n");
   gotoxy(30,17);cprintf("Enter your choice.....");
   gotoxy(53,17);cin>>b;
   switch(b)
   {
    case 1:cnrecord();break;
    case 2:arecord();break;
    case 3:drecord();break;
    case 4:sbyrno();break;
    case 5:sbyname();break;
    case 6:sbydoci();break;
    case 7:sbydoco();break;
    case 8:sbypno();break;
    case 9:changerno();break;
    case 10:front();break;
   }
  }while(b<=10);
 }
 if(a==2)
 {
  do
  {
   border();
   name1();
   gotoxy(30,7);cprintf("1..Create new record\n");
   gotoxy(30,8);cprintf("2..Add new record");
   gotoxy(30,9);cprintf("3..Display record\n");
   gotoxy(30,10);cprintf("4..Search by name of visitor\n");
   gotoxy(30,11);cprintf("5..Search by name of guest staying\n");
   gotoxy(30,12);cprintf("6..Search by date\n");
   gotoxy(30,13);cprintf("7..Search by room no. visited\n");
   gotoxy(30,14);cprintf("8..Front page");
   gotoxy(30,15);cprintf("Enter your choice.....");
   gotoxy(53,15);cin>>b;
   switch(b)
   {
    case 1:createn();break;
    case 2:addn();break;
    case 3:display();break;
    case 4:sbnv();break;
    case 5:sbnog();break;
    case 6:sbdate();break;
    case 7:sbrnog();break;
    case 8:front();break;
   }
  }while(b<=7);
 }
 if(a==3)
 {
  do
  {
   border();
   name1();
   gotoxy(30,7);cprintf("1..Create new record\n");
   gotoxy(30,8);cprintf("2..Add new record\n");
   gotoxy(30,9);cprintf("3..Display record\n");
   gotoxy(30,10);cprintf("4..Search by name of guest\n");
   gotoxy(30,11);cprintf("5..Search by name of driver\n");
   gotoxy(30,12);cprintf("6..Search by car no.\n");
   gotoxy(30,13);cprintf("7..Search by date\n");
   gotoxy(30,14);cprintf("8..Search by desti\n");
   gotoxy(30,15);cprintf("9..Search by room no. of guest\n");
   gotoxy(30,16);cprintf("10..Front page");
   gotoxy(30,17);cprintf("Enter your choice.....");
   gotoxy(54,17);cin>>b;
   switch(b)
   {
    case 1:indetails();break;
    case 2:addetails();break;
    case 3:ddetails();break;
    case 4:sbng();break;
    case 5:sbnd();break;
    case 6:sbcn();break;
    case 7:sbtdate();break;
    case 8:sbdesti();break;
    case 9:sbrno1();break;
    case 10:front();
   }
  }while(b<=8);
 }
 if(a==4)
 {
  do
  {
   border();
   name1();
   gotoxy(30,7);cprintf("1..Create new record\n");
   gotoxy(30,8);cprintf("2..Add new record\n");
   gotoxy(30,9);cprintf("3..Display record\n");
   gotoxy(30,10);cprintf("4..Search by employee no.\n");
   gotoxy(30,11);cprintf("5..Search by name\n");
   gotoxy(30,12);cprintf("6..Search by department \n");
   gotoxy(30,13);cprintf("7..Search by post\n");
   gotoxy(30,14);cprintf("8..Front page");
   gotoxy(30,15);cprintf("Enter your choice.....");
   gotoxy(54,15);cin>>b;
   switch(b)
   {
    case 1:cnrcrd();break;
    case 2:arcrd();break;
    case 3:drcrd();break;
    case 4:sbyempno();break;
    case 5:sbyename();break;
    case 6:sbydept();break;
    case 7:sbypost();break;
    case 8:front();
   }
  }while(b<=10);
 }
 if(a==5)
  exit(0);
 getch();
}
void main()
{
 clrscr();
 for(int i=3;i<55;i++)
 {
  border();
  gotoxy(i,9);cprintf(" �������������������������");
  gotoxy(i,10);cprintf(" ��     WELCOME TO      ��");
  gotoxy(i,11);cprintf(" �������������������������");
  gotoxy(i,12);cprintf(" ��  THE GRANGER ORION  ��");
  gotoxy(i,13);cprintf(" �������������������������");
  delay(100);

 }
 front();
}