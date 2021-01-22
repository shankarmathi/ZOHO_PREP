#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int global_num;
int check_valid(int num)
{
    if(num > 0)
    {
        global_num = num;
        return num;
    }
    else
    {
        cout<<"Enter a positive value\n";
        int temp;
        cin>>temp;
        global_num = temp;
        check_valid(temp);
    }
    return global_num;
}

bool comparee(string a,string b)
{
    if(a.length() != b.length())
    {
        return 0;
    }
    for(int i=0;i<a.length();i++)
    {
        if(a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

struct food
{
    string item;
    int available_count;
    int price;
    int max_per_user;
    int item_code;
};

static int next_item_code = 1;

struct username_pass
{
    string username;
    string password;
};

struct namebal
{
    string name;
    int amount;
};

class admin
{
    private:
    string username;
    string password;

    public:
    vector<struct food> v;
    vector<struct username_pass> v1;
    vector<struct namebal> v2;

    void add_userpass(string name,string pass)
    {
        struct username_pass u;
        u.username = name;
        u.password = pass;
        v1.push_back(u);
    }

    void add_acc_balance(string name,int bal)
    {
        struct namebal b;
        b.name = name;
        b.amount = bal;
        v2.push_back(b);
    }

    void add_menu(string item,int available_count,int price,int max_per_user,int nxt_item_no)
    {
        struct food temp;
        temp.item = item;
        temp.available_count = available_count;
        temp.price = price;
        temp.max_per_user = max_per_user;
        temp.item_code = nxt_item_no;
        v.push_back(temp);
    }

    void display(int x)
    {
        //x = 1 admin
        //x = 0 user
        int index = 1;
        for(auto i:v)
        {
            cout<<index<<". ";

            if(x == 1)
            {
                cout<<i.item_code<<" ";
            }

            cout<<i.item<<" "<<i.available_count<<" "<<i.price<<" ";
            index++;
            if(i.max_per_user == -1)
            {
                cout<<"unlimited"<<'\n';
            }
            else
            {
                cout<<i.max_per_user<<'\n';
            }
        }
    }

    void modify(int itemno)
    {
        queue<pair<int,int>> q;
        cout<<"item from main"<<itemno<<'\n';
        int index = 0;
        vector<struct food>:: iterator i = v.begin(); 
        for(;i != v.end();i++)
        {
            //cout<<i.item_code<<" "<<itemno<<'\n';
            if((*i).item_code == itemno)
            {
                //cout<<"your item code is"<<i.item_code<<"\n\n";

                cout<<"\t\t 1.change available count";
                cout<<"\t\t 2.change price";
                cout<<"\t\t 3.change maximum count per user";
                cout<<"\t\t 4.exit\n\n";
                int number,flag = 1;
                do
                {
                    cin>>number;
                    switch(number)
                    {
                        case 1:
                        cout<<"The current count is: "<<(*i).available_count<<"\n";
                        cout<<"ENTER MODIFIED AVAILABLE COUNT\n";
                        int count;
                        cin>>count;
                        (*i).available_count = check_valid(count);

                        break;
                        case 2:
                        cout<<"The current price is: "<<(*i).price<<"\n";
                        cout<<"ENTER MODIFIED PRICE\n";
                        int price;
                        cin>>price;
                        
                        //cout<<"before"<<i.price<<" ";
                        (*i).price = check_valid(price);
                        //cout<<"after"<<i.price<<" ";
                        break;
                        case 3:
                        cout<<"The current maximum count is: "<<(*i).max_per_user<<'\n';
                        cout<<"ENTER MODIFIED MAX.COUNT PER PERSON\n";
                        int n;
                        cin>>n;
                        (*i).max_per_user = check_valid(n);
                        break;
                        case 4:
                        flag = 0;
                        cout<<'\n';
                        break;
                    }
                    index+=1;
                    cout<<"ENTER NEXT VALUE:";
                } 
                while (flag);
                
            }
        }
    }

    void deletee(int itemcode)
    {
        auto itr = v.begin();
        int index = 0;
        for(auto i:v)
        {
            if(i.item_code == itemcode)
            {
                advance(itr,index);
                v.erase(itr);
            }
            index++;
        }
    }
};

class user:public admin
{
    private:
    string username;
    string password;

    public:
    int verification(string uname,string upass)
    {
        for(auto i:v1)
        {
            if(comparee(i.username,uname) && comparee(i.password,upass))
            {
                return 1;
            }
        }
        return 0;
    }

    int check_balance(string name)
    {
        for(auto i:v2)
        {
            if(i.name == name)
            {
                return i.amount;
            }
        }
        return -1;
    }

};

int main()
{

    cout<<"\t\tCANTEEN MANAGEMENT SYSTEM\n\n\n";
    admin a;
    user u;
    a.add_userpass("admin","admin");
    a.add_userpass("akash","password");
    a.add_userpass("vignesh","Admin@123");

    a.add_acc_balance("admin",500);
    a.add_acc_balance("akash",500);
    a.add_acc_balance("vignesh",500);

    a.add_menu("DOSA",5,30,-1,next_item_code++);
    a.add_menu("IDLI",15,10,-1,next_item_code++);
    a.add_menu("MASALA DOSA",3,50,1,next_item_code++);
    a.add_menu("VADA",10,10,2,next_item_code++);
    a.add_menu("PONGAL",8,25,-1,next_item_code++);
    int flag = 1;

    do
    {
        cout<<"\t\t 1.Create new administrator\n";
        cout<<"\t\t 2.Create new user\n";
        cout<<"\t\t 3.Admin Login\n";
        cout<<"\t\t 4.Add food items\n";
        cout<<"\t\t 5.Modify food items\n";
        cout<<"\t\t 6.Delete food items\n";
        cout<<"\t\t 7.Display food items\n";
        cout<<"\t\t 8.User Login\n";
        cout<<"\t\t 9.Add accountbalance\n";
        cout<<"\t\t 10.View balance\n";

        cout<<"\n\nENTER YOU CHOICE\n";
        int choice;
        string xyz,name1,name2;
        char str1[100],str2[100];
        cin>>choice;

        //cout<<"your choice is"<<choice<<'\n';

        switch(choice)
        {
            case 1:
            break;
            
            case 2:
            cout<<"Welcome to ZOHO CANTEEN\n";
            cout<<"Setup Your Account\n";
            cout<<"ENTER YOUR USERNAME: \n";
            cin>>name1;
            cout<<"ENTER PASSWORD: \n";
            cin>>name2;
            a.add_userpass(name1,name2);
            break;

            case 3:
            break;

            case 4:
            int f2,f3,f4;
            cout<<"ENTER FOOD NAME: \n";
            cin>>xyz;
            cout<<"ENTER AVAILABLE COUNT\n";
            cin>>f2;
            f2 = check_valid(f2);
            cout<<"ENTER PRICE\n";
            cin>>f3;
            f3 = check_valid(f3);
            cout<<"ENTER MAX.COUNT PER PERSON\n";
            cin>>f4;
            f4 = check_valid(f4);
            a.add_menu(xyz,f2,f3,f4,next_item_code);
            next_item_code++;
            break;

            case 5:
            a.display(1);
            cout<<"ENTER THE ITEM CODE\n";
            int z;
            cin>>z;
            a.modify(z);
            break;

            case 6:
            a.display(1);
            cout<<"ENTER THE ITEM CODE\n";
            int y;
            cin>>y;
            a.deletee(y);
            break;
            
            case 7:
            a.display(0);
            break;

            case 8:
            cout<<"ENTER USER NAME\n";
            cin>>name1;
            cout<<"ENTER PASSWORD\n";
            cin>>name2;
            if(u.verification(name1,name2))
            {
                cout<<"LOGIN SUCCESS\n";
            }
            else
            {
                cout<<"INCORRECT USERNAME OR PASSWORD\n";
            }
            break;

            case 9:
            int amount;
            cout<<"ENTER YOUR NAME\n";
            cin>>name1;
            cout<<"ENTER THE AMOUNT\n";
            cin>>amount;
            a.add_acc_balance(name1,amount);
            break;

            case 10:
            cout<<"ENTER YOUR USERNAME TO CHECK BALANCE\n";
            cin>>name1;
            u.check_balance(name1);
            break;

            default:
            goto l1;
        }
    }
    while (1);
    l1:
    return 0;
}