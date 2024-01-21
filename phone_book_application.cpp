#include <bits/stdc++.h>
#include "contact.h"
using namespace std;
using namespace std2;
int main()
{
    contact obj;
    string name, number;
    cout << "............................................." << endl;
    cout << "           PHONE BOOK APPLICATION " << endl;
    cout << "............................................." << endl;
    cout << ":::::::::::::::: PROGRAM MENU :::::::::::::::" << endl;
    int a = 1;
    while (a == 1)
    {
        int ch;
        cout << "1 to add contact" << endl;
        cout << "2 to update an existing contact" << endl;
        cout << "3 to search for a contact" << endl;
        cout << "4 to display contacts" << endl;
        cout << "5 to delete an existing contact" << endl;
        cout << "6 to delete all the contacts created" << endl;
        cout << "7 to exit" << endl;
        cout << "Enter choice: ";
        if (!(cin >> ch))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1-7." << endl;
            continue;
        }
        switch (ch)
        {
        case 1:
            obj.addcontact();
            cout << "*******Contact added successfully*******" << endl;
            break;
        case 2:
            if (obj.is_empty())
                break;
            cout << "Enter name to update the contact: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter number to update the contact: ";
            getline(cin, number);
            obj.updatecontact(name, number);
            cout << "*******Contact is updated with new number*******" << endl;
            break;
        case 3:
            if (obj.is_empty())
                break;
            cout << "Enter name to search the contact: ";
            cin.ignore();
            getline(cin, name);
            obj.searchcontact(name);
            break;
        case 4:
            if (obj.is_empty())
                break;
            obj.displaycontacts();
            break;
        case 5:
            if (obj.is_empty())
                break;
            cout << "Enter name to delete the contact: ";
            cin.ignore();
            getline(cin, name);
            obj.deletecontact(name);
            break;
        case 6:
            if (obj.is_empty())
                break;
            obj.deletecontacts();
            break;
        case 7:
            a = 0;
            break;
        default:
            cout << "Please Enter a Valid Input from 1-7 only" << endl;
            break;
        }
    }
 cout << "*************** END OF PROGRAM ***************" << endl;
    cout << "---------------------------------------------" << endl;
    return 0;
}