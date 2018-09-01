#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
class User
{
protected :
    char *fname,*lname,*city,*state,*add,*pc;
    double i,DD,MM,YY;
public :
    long double balance;
    User() {}
    User(char *f,char *l,char *ad,char *c,char *s,char *p,double D,double M,double Y,double a)
    {
        fname=new char[strlen(f)+1];
        lname=new char[strlen(l)+1];
        city=new char[strlen(c)+1];
        state=new char[strlen(s)+1];
        add=new char[strlen(ad)+1];
        pc=new char[strlen(p)+1];
        strcpy(fname,f);
        strcpy(lname,l);
        strcpy(city,c);
        strcpy(state,s);
        strcpy(add,ad);
        strcpy(pc,p);
        DD=D;
        MM=M;
        YY=Y;
        i=a;
    }
};
class new_user:public User
{
protected :

public :
    double ac;
    new_user(char *F,char *L,char *AD,char *C,char *S,char *p,double Dd,double Mm,double Yy,double Aa):User(F,L,AD,C,S,p,Dd,Mm,Yy,Aa)
    {
    }
    void account_no()
    {
        long double bbl;
        string USS;
        fstream fo;
        fo.open("data.txt");
        while(!fo.eof())
        {
            cout<<"reading file";
            fo>>fname>>lname>>i>>DD>>MM>>YY>>pc>>add>>city>>state>>bbl>>USS>>ac;
        }
        fo.close();
        ac=ac+1;
        cout<<"\nYour Account No is :  "<<ac;
    }
    void show()
    {
        cout<<"Account holder name : "<<fname<<" "<<lname;
        cout<<"\nMobile No : "<<i;
        cout<<"\nBirth Date is : "<<DD<<"-"<<MM<<"-"<<YY;
        cout<<"\nPancard No : "<<pc;
        cout<<"\nAddress : "<<add;
        cout<<"\nCity  :"<<city;
        cout<<"\nState : "<<state;
    }
    virtual void detail() {}
};
class sa:public new_user
{
    string un;
public:
    sa(string UN,char *FN,char *LN,char *ADD,char *CY,char *ST,char *P,double DA,double MO,double YE,double AA):new_user(FN,LN,ADD,CY,ST,P,DA,MO,YE,AA)
    {
        un=UN;
    }
    void detail()
    {
        cout<<"**Account details**";
        cout<<"\nThis account is Saving Account";
        show();
        account_no();
    }
};
class ca:public new_user
{
    string us;
public:
    ca(string Us,char *FN,char *LN,char *ADD,char *CY,char *ST,char *P,double DA,double MO,double YE,double AA):new_user(FN,LN,ADD,CY,ST,P,DA,MO,YE,AA)
    {
        us=Us;
    }
    void detail()
    {
        cout<<"**Account details**";
        cout<<"\nThis Account is Current Account";
        show();
        account_no();
    }
};
class exi_user:public User
{
    long double balance;
public :
    double j;
    int ZZ;
    exi_user(double B,double b,char *f,char *l,char *AD,char *C,char *S,char *pc,double D,double M,double Y,double a):User(f,l,AD,C,S,pc,D,M,Y,a)
    {
        j=b;
        balance=B;
    }
    void details(long double BB)
    {
        balance=BB;
        cout<<"Account holder name : "<<fname<<" "<<lname;
        cout<<"\nAccount No"<<j;
        cout<<"\nBirth Date is : "<<DD<<"-"<<MM<<"-"<<YY;
        cout<<"\nMobile No : "<<i;
        cout<<"\nPancard No : "<<pc;
        cout<<"\nAddress : "<<add;
        cout<<"\nCity  :"<<city;
        cout<<"\nState : "<<state;
        cout<<"\nYour current Balance is : "<<balance;
    }
    int check(long double amtt)
    {
        if(balance==amtt)
        {
            ZZ=1;
            return ZZ;
        }
        else
        {
            ZZ=0;
            return ZZ;
        }
    }
};
class transaction
{
    long double amt;
    User *u1;
public:
    transaction(long double AMT,User *U)
    {
        amt=AMT;
        u1=U;
    }
    void withdraw(long double amt)
    {
        u1->balance=u1->balance-amt;
        cout<<"Transaction Done!!";
        cout<<"\nUpdated Balance is : "<<u1->balance;
    }
    void deposite(long double amt)
    {
        u1->balance=u1->balance+amt;
        cout<<"Transaction Done!!";
        cout<<"\nUpdated Balance is : "<<u1->balance;
    }
};
void put(char *First,char *last,double Mo,double DDD,double MMM,double YYY,char *pa,char *ADD,char *CIty,char *STate,long double BAlance,string Uname,double Ac)
{
    fstream myfile;
    myfile.open("data.txt",ios_base::app);
    myfile<<First<<" ";
    myfile<<last<<" ";
    myfile<<Mo<<" ";
    myfile<<DDD<<" ";
    myfile<<MMM<<" ";
    myfile<<YYY<<" ";
    myfile<<pa<<" ";
    myfile<<ADD<<" ";
    myfile<<CIty<<" ";
    myfile<<STate<<" ";
    myfile<<BAlance<<" ";
    myfile<<Uname<<" ";
    myfile<<Ac<<"\n";
    myfile.close();
}
void uipa(string USER,string PASS)
{
    fstream uids;
    uids.open("uid.txt",ios_base::app);
    uids<<USER<<"\n";
    uids.close();
    fstream pass;
    pass.open("pass.txt",ios_base::app);
    pass<<USER<<" "<<PASS<<"\n";
    pass.close();
}
int main()
{
    int choice;
    cout<<"***Welcome to Bank***";
    do
    {
        cout<<"\n**Main Menu**";
        cout<<"\npress 1-For new user";
        cout<<"\npress 2-For Existing User";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            while(1)
            {
                int l;
                cout<<"*Menu*";
                cout<<"\n Which type of Account do you want to create";
                cout<<"\nEnter 1 for Saving Account";
                cout<<"\nEnter 2 for Current Account";
                cout<<"\nEnter your Choice : ";
                cin>>l;
                double x,dd,mm,yy;
                long double amount;
                char z[30],i[30],p[30],Addr[30],City[10],State[10];
                string uname,pas;
                if(l==1)
                {
                    cout<<"Enter your Mobile No : ";
                    cin>>x;
                    cout<<"Enter your First Name : ";
                    cin>>z;
                    cout<<"Enter your Last Name : ";
                    cin>>i;
                    cout<<"Enter your Birth Date :";
                    cin>>dd;
                    cin>>mm;
                    cin>>yy;
                    cout<<"Enter your Pancard no : ";
                    cin>>p;
                    cout<<"Enter your Address : ";
                    cin>>Addr;
                    cout<<"Enter your City Name : ";
                    cin>>City;
                    cout<<"Enter your State Name : ";
                    cin>>State;
                    cout<<"Set a New User_Name : ";
                    cin>>uname;
                    cout<<"Set a password : ";
                    cin>>pas;
                    User U1;
                    U1.balance=0;
                    new_user *c1;
                    sa s1(uname,z,i,Addr,City,State,p,dd,mm,yy,x);
                    c1=&s1;
                    c1->detail();
                    while(1)
                    {
                        cout<<"\nyou need deposit some amount for creating account.";
                        cout<<"\nEnter amount to be deposit : ";
                        cin>>amount;
                        if(amount<=500)
                        {
                            cout<<"Insufficient amount!! Please Enter amount more than 500";
                        }
                        else
                        {
                            transaction t1(amount,&U1);
                            t1.deposite(amount);
                            break;
                        }
                    }
                    string y;
                    cout<<"\nDo u want to make another transaction?"<<"\ntype yes for continue transaction ";
                    cin>>y;
                    if(y=="yes")
                    {
                        while(1)
                        {
                            int Choice;
                            transaction t1(amount,&U1);
                            cout<<"Select option";
                            cout<<"\n1-Withdraw Money";
                            cout<<"\n2-Deposit Money";
                            cout<<"\nEnter your choice : ";
                            cin>>Choice;
                            if(Choice==1)
                            {
                                cout<<"Enter amount to be withdraw : ";
                                cin>>amount;
                                if((U1.balance-amount)<=500)
                                {
                                    cout<<"Minimum Balance of 500 Rs. Required for account!!";
                                }
                                else
                                    t1.withdraw(amount);
                                cout<<"\nYour account balance :"<<U1.balance;
                            }
                            else
                            {
                                cout<<"Enter amount to be deposit : ";
                                cin>>amount;
                                t1.deposite(amount);
                                cout<<"\nYour account balance :"<<U1.balance;
                            }
                            string y;
                            cout<<"\nDo u want to make another transaction?";
                            cin>>y;
                            if(y=="yes")
                            {
                                break;
                            }
                            else
                            {
                                put(z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                                uipa(uname,pas);
                                exit(0);
                            }
                        }
                    }
                    else
                    {
                        put(z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                        uipa(uname,pas);
                        exit(0);
                    }
                    break;
                }
                if(l==2)
                {
                    cout<<"Enter your Mobile No : ";
                    cin>>x;
                    cout<<"Enter your First Name : ";
                    cin>>z;
                    cout<<"Enter your Last Name : ";
                    cin>>i;
                    cout<<"Enter your Birth Date :";
                    cin>>dd;
                    cin>>mm;
                    cin>>yy;
                    cout<<"Enter your Pancard no : ";
                    cin>>p;
                    cout<<"Enter your Address : ";
                    cin>>Addr;
                    cout<<"Enter your City Name : ";
                    cin>>City;
                    cout<<"Enter your State Name : ";
                    cin>>State;
                    cout<<"Set a New User Name : ";
                    cin>>uname;
                    cout<<"Set a password : ";
                    cin>>pas;
                    User U1;
                    U1.balance=0;
                    new_user *c1;
                    ca s1(uname,z,i,Addr,City,State,p,dd,mm,yy,x);
                    c1=&s1;
                    c1->detail();
                    while(1)
                    {
                        cout<<"\nyou need deposit some amount for creating account.";
                        cout<<"\nEnter amount to be deposit : ";
                        cin>>amount;
                        if(amount<=5000)
                        {
                            cout<<"Insufficient amount!! Please Enter amount more than 5000";
                        }
                        else
                        {
                            transaction t1(amount,&U1);
                            t1.deposite(amount);
                            break;
                        }
                    }
                    string y;
                    cout<<"\nDo u want to make another transaction?"<<"\ntype yes for continue transaction ";
                    cin>>y;
                    if(y=="yes")
                    {
                        while(1)
                        {
                            while(1)
                            {
                                int Choice;
                                transaction t1(amount,&U1);
                                cout<<"Select option";
                                cout<<"\n1-Withdraw Money";
                                cout<<"\n2-Deposit Money";
                                cout<<"\nEnter your choice : ";
                                cin>>Choice;
                                if(Choice==1)
                                {
                                    cout<<"Enter amount to be withdraw : ";
                                    cin>>amount;
                                    if(500>=(U1.balance-amount))
                                    {
                                        cout<<"Minimum Balance of 500 Rs. Required for account!!";
                                    }
                                    else
                                        t1.withdraw(amount);
                                }
                                if(Choice==2)
                                {
                                    cout<<"Enter amount to be deposit : ";
                                    cin>>amount;
                                    t1.deposite(amount);
                                }
                                else
                                    cout<<"\nInvalid Choice!!";
                                string y;
                                cout<<"\nDo u want to make another transaction?";
                                cin>>y;
                                if(y=="yes")
                                {
                                    break;
                                }
                                else
                                {
                                    put(z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                                    uipa(uname,pas);
                                    exit(0);
                                }
                            }
                        }
                    }
                    else
                    {
                        put(z,i,x,dd,mm,yy,p,Addr,City,State,U1.balance,uname,s1.ac);
                        uipa(uname,pas);
                        exit(0);
                    }
                }
                else
                    cout<<"Invalid Choice!!!\n";
            }
        }
        if(choice==2)
        {
            int k;
            char z[30],i[30],p[30],Addr[30],City[10],State[10];
            long double Amount,mo,Bal,Bil;
            double ac,dd,mm,yy;
            string user,uid,UI,pass;
            fstream file;
            int I,j=0;
            while(j<3)
            {
                file.open("uid.txt");
                cout<<"Enter your User Name : ";
                cin>>uid;
                while(!file.eof())
                {
                    file>>user;
                    if(uid==user)
                    {
                        I=1;
                        k=1;
                        break;
                    }
                }
                file.close();
                if(I==1)
                    break;
                else
                {
                    cout<<"Invalid user name\n";
                    if(j==1)
                        cout<<"Last chance\n";
                    if(j==2)
                        exit(0);
                }
                j++;
            }
            int J,Pa=0;
            string usid,pas;
            while(Pa<3)
            {
                cout<<"Enter password : ";
                cin>>pass;
                file.open("pass.txt");
                while(!file.eof())
                {
                    file>>usid>>pas;
                    if(usid==user && pas==pass)
                    {
                        J=1;
                        break;
                    }
                    else
                        J=2;
                }
                if(J==1)
                {
                    break;
                }
                else
                {
                    if(Pa==1||Pa==0)
                        cout<<"Access denied!!\n";
                    else
                        exit(0);
                }
                Pa++;
                file.close();
            }
            while(1)
            {
                int Choice;
                double AC;
                User U1;
                fstream file;
                file.open("data.txt");
                while(!file.eof())
                {
                    file>>z>>i>>mo>>dd>>mm>>yy>>p>>Addr>>City>>State>>Bal>>UI>>AC;
                    if(UI==uid)
                    {
                        k=1;
                        break;
                    }
                }
                file.close();
                if(k==1)
                {
                    cout<<"Access Granted";
                }
                else
                {
                    cout<<"No such account exist";
                    exit(0);
                }
                file.close();
                exi_user e1(Bal,AC,z,i,Addr,City,State,p,dd,mm,yy,mo);
                U1.balance=Bal;
                Bil=Bal;
                transaction t1(Amount,&U1);
                while(1)
                {
                    cout<<"\nSelect option";
                    cout<<"\n1-Account_Info";
                    cout<<"\n2-Withdraw Money";
                    cout<<"\n3-Deposit Money";
                    cout<<"\n4-Exit";
                    cout<<"\nEnter your choice : ";
                    cin>>Choice;
                    fstream Fol;
                    fstream nw;
                    switch(Choice)
                    {
                    case 1 :
                        e1.details(U1.balance);
                        break;
                    case 2 :

                        cout<<"Enter amount to be withdraw : ";
                        cin>>Amount;
                        if(500>=(U1.balance-Amount))
                        {
                            cout<<"Minimum Balance of 500 Rs. Required for account!!";
                        }
                        else
                            t1.withdraw(Amount);
                        Bil=U1.balance;
                        break;
                    case 3 :
                        cout<<"Enter amount to be deposit : ";
                        cin>>Amount;
                        t1.deposite(Amount);
                        Bil=U1.balance;
                        break;
                    case 4 :
                        Fol.open("data.txt");
                        nw.open("Dat.txt");

                        while(!Fol.eof())
                        {
                            long double bil;
                            //if(Fol.eof())
                            //break;
                            Fol>>z>>i>>mo>>dd>>mm>>yy>>p>>Addr>>City>>State>>bil>>UI>>ac;
                            if(Bal==bil)
                            {
                                if(Fol.eof())
                                    break;
                                nw<<z<<" "<<i<<" "<<mo<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<p<<" "<<Addr<<" "<<City<<" "<<State<<" "<<Bil<<" "<<UI<<" "<<ac<<endl;
                            }
                            else
                            {
                                if(Fol.eof())
                                    break;
                                nw<<z<<" "<<i<<" "<<mo<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<p<<" "<<Addr<<" "<<City<<" "<<State<<" "<<bil<<" "<<UI<<" "<<ac<<endl;
                            }
                            //if(Fol.eof())
                            //break;
                        }

                        Fol.close();
                        nw.close();
                        Fol.open("data.txt",std::ofstream::out | std::ofstream::trunc);
                        Fol.close();
                        nw.open("Dat.txt");
                        Fol.open("data.txt");
                        while(!nw.eof())
                        {
                            long double bil;
                            nw>>z>>i>>mo>>dd>>mm>>yy>>p>>Addr>>City>>State>>bil>>UI>>ac;
                            if(nw.eof())
                                break;
                            Fol<<z<<" "<<i<<" "<<mo<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<p<<" "<<Addr<<" "<<City<<" "<<State<<" "<<bil<<" "<<UI<<" "<<ac<<"\n";
                        }
                        Fol.close();
                        nw.close();
                        nw.open("Dat.txt",std::ofstream::out | std::ofstream::trunc);
                        nw.close();
                        exit(0);
                    default :
                        cout<<"Invalid Choice";
                    }
                }
            }
        }
        else
            cout<<"Invalid choice!!";
    }
    while(1);
    return 0;
}
