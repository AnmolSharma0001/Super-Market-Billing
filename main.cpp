#include <bits/stdc++.h>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void recipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t ________________________________" << endl;
    cout << "\t\t|                                |" << endl;
    cout << "\t\t|      SuperMarket Main Menu     |" << endl;
    cout << "\t\t|                                |" << endl;
    cout << "\t\t|________________________________|" << endl;
    cout << "\t\t|                                |" << endl;
    cout << "\t\t|      1. Administrator          |" << endl;
    cout << "\t\t|                                |" << endl;
    cout << "\t\t|      2. Buyer                  |" << endl;
    cout << "\t\t|                                |" << endl;
    cout << "\t\t|      3. Exit                   |" << endl;
    cout << "\t\t|________________________________|" << endl;
    cout << endl;

    cout << "\t\tGive your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t Please Login " << endl;
        cout << "\t\t Enter Email: ";
        cin >> email;
        cout << "\t\t Enter Password: ";
        cin >> password;
        if (email == "admin.123@gmail.com" and password == "admn@987")
        {
            administrator();
        }
        else
        {
            cout << "\t\t Invalid Email/Password";
        }
        break;
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "\t\t Please select the given options: ";
    }
    goto m;
}

void shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\t\t Administrator Menue" << endl;
    cout << endl;
    cout << "\t\t 1. Add the product " << endl;
    cout << "\t\t 2. Modify the product " << endl;
    cout << "\t\t 3. Delete the product " << endl;
    cout << "\t\t 4. To the main menue " << endl;
    cout << "\n\t\t Enter the choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\t\t Please select the given options: ";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\n\n\t\t  Buyer" << endl;
    cout << endl;
    cout << "\t\t 1. Buy product " << endl;
    cout << "\t\t 2. Go Back " << endl;
    cout << "\n\t\t Enter the choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        recipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "\t\t Please select the given options: ";
    }
    goto m;
}

void shopping ::add()
{
    fstream data;
    int c, token = 0;
    float p, d;
    string n;
    cout << "\t\t Add the product " << endl;
    cout << "\t\t Product code of the product: ";
    cin >> pcode;
    cout << "\t\t Name of the product: ";
    cin >> pname;
    cout << "\t\t Price of the product: ";
    cin >> price;
    cout << "\t\t Discount on the product: ";
    cin >> discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
        token++;
        cout << "\t\t Record Inserted " << endl;
    }
    else
    {
        while (!data.eof())
        {
            data >> c >> n >> p >> d;
            if (c == pcode)
            {
                token++;
            }
        }
        data.close();
    }

    if (token == 1)
    {
        administrator();
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
        cout << "\t\t Record Inserted " << endl;
    }
}

void shopping::edit()
{
m:
    fstream data, data1;
    int pkey, token = 0, c;
    float p, d;
    string n;

    cout << "\t\t Modify the record " << endl;
    cout << "\t\t Product code of the product: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t File doesn't exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;

        while (!data.eof())
        {
            data >> pcode >> pname >> price >> discount;
            if (pcode == pkey)
            {
                cout << "\t\t New product code of the product: ";
                cin >> c;
                cout << "\t\t Name of the product: ";
                cin >> n;
                cout << "\t\t Price of the product: ";
                cin >> p;
                cout << "\t\t Discount on the product: ";
                cin >> d;
                token++;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\t\t Record Modified " << endl;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }

    if (token == 0)
    {

        cout << "\t\t Record not found " << endl;
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey, token = 0;

    cout << "\t\t Delete the record " << endl;
    cout << "\t\t Product code of the product: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t File doesn't exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        

        while (!data.eof())
        {
            data >> pcode >> pname >> price >> discount;
            if (pcode == pkey)
            {
                token++;
                continue;
            }
            else
            {
                data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }

    if (token == 0)
    {
        cout << "\t\t Record not found " << endl;
    }
    else
    {
        cout << "\t\t Record deleted successfully" << endl;
    }
}

void shopping::list()
{
    fstream data;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\t\t File doesn't exist" << endl;
    }
    else
    {
        cout << "\t\t The list of the products: " << endl;

        cout << "\t\t ___________________________________________________________________" << endl;
        cout << "\t\t|                                                                   |" << endl;
        cout << "\t\t|ProNo\t\tPrName\t\tPrice" << endl;
        cout << "\t\t|___________________________________________________________________|" << endl;

        while (!data.eof())
        {
            data >> pcode >> pname >> price >> discount;
            cout << "\t\t    " << pcode << "\t\t" << pname << "\t\t" << price << endl;
            cout << "\t\t|___________________________________________________________________|" << endl;
        }
        data.close();
    }
}

void shopping ::recipt()
{
    fstream data;
    int choice, c = 0, q = 0, x;
    float a = 0, d = 0, t = 0;

    cout << "\t\t\t RECEIPT " << endl;
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\t\tEmpty database" << endl;
    }
    else
    {
        list();
        cout << endl;
        cout << "\t\t __________________________________________________________________________________________________" << endl;
        cout << "\t\t|                                                                                                  |" << endl;
        cout << "\t\t|                                        Place the Order                                           |" << endl;
        cout << "\t\t|__________________________________________________________________________________________________|" << endl;
        unordered_map<int, int> m;
        bool f = true;
        while (true)
        {
            cout << "\t\t To add item enter 1: ";
            cin >> q;
            if (q != 1)
            {
                break;
            }
            cout << "\t\t Enter the product code: ";
            cin >> c;
            cout << "\t\t Enter quantity: ";
            cin >> q;
            if (m[c] == 0)
            {
                x++;
            }
            m[c] += q;
        }
        cout << "\t\t The list of the products: " << endl;

        cout << "\t\t ___________________________________________________________________________________________________________________" << endl;
        cout << "\t\t|                                                                                                                   |" << endl;
        cout << "\t\t|ProNo\t\tPrName\t\tPrice\t\tDiscount\tQunatity\tAmount" << endl;
        cout << "\t\t|___________________________________________________________________________________________________________________|" << endl;

        while (!data.eof() and x != 0)
        {
            data >> pcode >> pname >> price >> discount;
            if (m[pcode] != 0)
            {
                a = (price * discount) / 100;
                a = (price-a)*m[pcode];
                t += a;
                cout << "\t\t    " << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << discount << "%\t\t" << m[pcode] << "\t\t" << a <<endl;
                cout << "\t\t|___________________________________________________________________________________________________________________|" << endl;
            }
        }
        data.close();
        cout << "\t\t|                                                                                                                   |" << endl;
        cout << "\t\t|                       Total Amount:        " << fixed << setprecision(5) << t << endl;
        cout << "\t\t|___________________________________________________________________________________________________________________|" << endl;
    }
}


int main(){
    shopping s;
    s.menu();
    return 0;
}