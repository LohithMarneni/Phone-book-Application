#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
namespace std2
{
    class contact
    {
        private:
        string name, phone;

    public:
        bool is_empty()
        {
            string x;
            ifstream fin("contacts.txt");
            if (!(getline(fin, x)))
            {
                cout << "********No Contacts created.********" << endl;
                fin.close();
                return true;
            }
            else
                fin.close();
            return false;
        }
        void getdata()
        {
            cout << "Enter the name of contact: ";
            cin.ignore();
            getline(cin, name);
            while (1)
            {
                cout << "Enter the phone number: ";
                cin >> phone;
                int n = phone.length();
                if (n != 10)
                {
                    cout << "Phone number should have 10 digits" << endl;
                    continue;
                }
                bool isvalid = true;
                for (int i = 0; phone[i] != '\0'; i++)
                {
                    if (!(isdigit(phone[i])))
                    {
                        isvalid = false;
                        break;
                    }
                }
                if (!isvalid)
                {
                    cout << "Enter a valid phone number with only digits" << endl;
                    continue;
                }
                break;
            }
        }
        void current_contact()
        {
            cout << endl;
            cout << "Name: " << name << endl;
            cout << "Phone Number: " << phone << endl;
        }
        void updatecontact(string n, string p)
        {
            ifstream read("contacts.txt");
            ofstream write("temp.txt", ios::app);
            bool exist = false;
            string x, y;
            while (getline(read, x))
            {
                getline(read, y);
                if (x == n)
                {
                    y = p;
                    exist = true;
                }
                write << x << endl
                      << y << endl;
            }
            read.close();
            write.close();
            if (!exist == true)
            {
                ofstream out("contacts.txt", ios::app);
                out << n << endl
                    << p << endl;
                out.close();
                remove("temp.txt");
            }
            else
            {
                remove("contacts.txt");
                rename("temp.txt", "contacts.txt");
            }
        }
        void addcontact()
        {
            getdata();
            string n, p;
            n = name;
            p = phone;
            updatecontact(name, phone);
        }
        void searchcontact(string key)
        {
            string x, y;
            ifstream read("contacts.txt");
            bool exist = false;
            while (getline(read, x))
            {
                getline(read, y);
                if (x == key)
                {
                    cout << "********Contact Found!********" << endl;
                    cout << "Name: " << x << endl
                         << "Phone Number: " << y << endl;
                    exist = true;
                    break;
                }
            }
            read.close();
            if (!exist)
                cout << "********Contact not found!!********" << endl;
        }
        void displaycontacts()
        {
            string x, y;
            ifstream read("contacts.txt");
            bool exist = false;
            cout << "*******Contacts in file are*******" << endl;
            while (getline(read, x))
            {
                getline(read, y);
                cout << "------------------------------------------" << endl;
                cout << setw(20) << "Name: " << x << endl;
                cout << setw(28) << "Phone Number: " << y << endl;
            }
            cout << "------------------------------------------" << endl;
            read.close();
        }
        void deletecontact(string n)
        {
            string x, y;
            ifstream read("contacts.txt");
            ofstream fout("temp.txt", ios::trunc);
            fout.close();
            ofstream write("temp.txt", ios::app);
            bool exist = false;
            while (getline(read, x))
            {
                getline(read, y);
                if (x == n)
                {
                    exist = true;
                    continue;
                }
                write << x << endl
                      << y << endl;
            }
            read.close();
            write.close();
            if (exist == true)
            {
                remove("contacts.txt");
                rename("temp.txt", "contacts.txt");
                cout << "*******Contact Deleted Successfully*******" << endl;
            }
            else
            {
                cout << "********Contact with name " << n << " is not present in list.********" << endl;
            }
        }
        void deletecontacts()
        {
            string x;
            ofstream write("contacts.txt", ios::trunc);
            write.close();
            cout << "*******Deleted all the contacts*******" << endl;
            cout << "********File is now Empty.********" << endl;
        }
    };
}