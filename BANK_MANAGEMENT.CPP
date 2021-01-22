#include <iostream>
#include <map>

using namespace std;

class account
{
    private:
    long accountnumber;
    string firstname;
    string lastname;
    int balance;
    static long nextaccountnumber;
    
    public:
    account(){};
    account(string f,string l,int b){
        firstname = f;
        lastname = l;
        balance = b;
    }
    void setnamefirst(string arr)
    {
        firstname = arr;
    }   

    void setnamesecond(string arr)
    {
        lastname = arr;
    }   
    void setbalance(int x)
    {
        balance = x;
    }
    long getaccno()
    {
        accountnumber = nextaccountnumber++;
        return accountnumber;
    }
    string getfirstname()
    {
        return firstname;
    }

    string getlastname()
    {
        return lastname;
    }

};

class bank
{
    private:
    map<long,account> m;
    public:
    account openaccount(string fn,string ln,int b)
    {
        account a(fn,ln,b);
        m.insert({a.getaccno(),a});
        return a;
    } 

    void display()
    {
       
    }
};

int main()
{
    bank b;
    account acc;
    int choice;
    string firstname,lastname;
    long accountnum;
    float balance;
    float amount;
    int flag = 1;
    cout<<"\t\t BANKING SYSTEM \t\t";
    do
    {
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"ENTER FIRST NAME: ";
            cin>>firstname;
            cout<<"ENTER LAST NAME: ";
            cin>>lastname;
            cout<<"ENTER INITIAL BALANCE: ";
            cin>>balance;
            acc = b.openaccount(firstname,lastname,balance);
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            b.display();
            break;
            case 7:
            flag = 0;
            break;
        }

    } 
    while (flag);
}