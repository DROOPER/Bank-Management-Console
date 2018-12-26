
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
int j=0,id,pin,sum;
struct accounts
{
int id;
string firstname;
string lastname;
int pin;
int balance;

}account[999];

void banner()
{
system("clear");	
cout<<"BANK MANAGEMENT SYSTEM (created by DROOPER)"<<endl<<endl;	
}

void message()
{
cout<<"1.Create a new account"<<endl;
cout<<"2.Check account details"<<endl;
cout<<"3.Deposit"<<endl;
cout<<"4.Withdraw"<<endl;
cout<<"5.Transfer"<<endl;
cout<<"6.Delete an account"<<endl;
cout<<"7.Exit"<<endl<<endl;
cout<<"Choose an option:";
}

void auth()
{
cout<<"Enter account ID:";
cin>>id;
cout<<"Hello, "<<account[id].firstname<<" "<<account[id].lastname<<endl;
cout<<"Please enter your PIN:";
}


void wrongPIN()
{
cout<<"WRONG PIN...RETURNING TO MAIN MENU";
cout<<endl;
usleep(2000000);
}

void create()
{
banner();	
account[j].id=j;
account[j].balance=0;
cout<<"Enter first name:";
cin>>account[j].firstname;
cout<<"Enter last name:";
cin>>account[j].lastname;
cout<<"Choose a PIN:";
cin>>account[j].pin;
cout<<endl;
cout<<"Your account ID is ----> "<<j<<" <---- (Please note it somewhere)"<<endl;
j++;
usleep(3000000);
}


void details()
{
banner();
auth();
cin>>pin;
if (pin==account[id].pin)
{
banner();
cout<<"Account ID: "<<account[id].id<<endl;
cout<<"First name: "<<account[id].firstname<<endl;
cout<<"Last name: "<<account[id].lastname<<endl;
cout<<"Balance: "<<account[id].balance<<"$"<<endl;
usleep(9000000);
}
else wrongPIN();



}

void deposit()
{
	
banner();
auth();
cin>>pin;
if (pin==account[id].pin)
{
banner();
cout<<"Enter the sum you want to deposit:";
cin>>sum;
account[id].balance=account[id].balance+sum;
}
else wrongPIN();


}

void transfer()
{
int k,sum2;
banner();
auth(); 
cin>>pin;
if (pin==account[id].pin)
{
banner();
cout<<"Please select a destination account ID:";
cin>>k;
cout<<"Enter the sum you want to transfer:";
cin>>sum2;
if (account[id].balance-sum2>0)
{
account[k].balance=account[k].balance+sum2;
account[id].balance=account[id].balance-sum2;
}

else {cout<<"Insufficient funds!";usleep(500000);}

}
else wrongPIN();


}


void withdraw()
{
int sum2;
banner();
auth();
cin>>pin;
if (pin==account[id].pin)
{
banner();
cout<<"Enter the sum you want to withdraw:";
cin>>sum2;
if(account[id].balance-sum2>0)
{
account[id].balance=account[id].balance-sum2;
}
else {cout<<"Insufficient funds!";usleep(500000);}
}

else wrongPIN();
}





int main()
{
bool continuity=true;
while(continuity==1)
{
banner();
int n;
message();
cin>>n;
switch(n) {
case 1 : create();
break;
case 2 : details();
break;
case 3 : deposit();
break;
case 4 : withdraw();
break;
case 5 : transfer();
break;
case 6 : cout<<n;
break;
case 7 : continuity=false;
break;
}

}


}
