#include<iostream>
using namespace std;
class list
{

public:
    int* arr, size, current;
    list()
    {

        cout << "Enter the size of List : ";
        cin >> size;
        current = -1;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }
    }
    bool check()
    {
        if (current == size - 1)
        {
            char opt;
            cout << "List Size Limit Reached\nTo increase the size Press 'y' else Press any-key \n";
            cin >> opt;
            if (opt == 'y')
            {
                size++;
            }
            else
                return false;
        }
        else
            return true;

    }
    void add()
    {
        int shift_pos, data;
        if (current == -1)
        {

            cout << "Enter the value to enter : ";
            cin >> data;
            current++;
            arr[current] = data;

        }
        else
        {
            if (check())
            {
                cout << "Enter the value to enter : ";
                cin >> data;
                current++;
                arr[current] = data;
            }
        }
    }

    void update()
    {
        int data;
        cout << "Enter the value to update with : ";
        cin >> data;
        arr[current] = data;
    }
    int get()
    {
        int a;
        a = arr[current];
        return a;
    }
    int length()
    {
        return size;
    }
    void start()
    {
        current = 0;
    }
    void end()
    {
        current = size - 1;
    }
    int remove()
    {
        int a;
        a = arr[current];
        arr[current] = -1;
        return a;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                if (i == 0)
                    cout << "List is Empty\n";
                break;
            }
            else
                cout << i + 1 << ". " << arr[i] << endl;
        }
    }
};
    int main()
    {
        list l;
        int opt;
        do {
            cout << "*****************************************\n";
            cout << "******************MENU*******************\n";
            cout << "*****************************************\n";
            cout << "Press Button According to options below\n";
            cout << "1. To Check Length of List\n";
            cout << "2. To Get value Current value of List\n";
            cout << "3. To Move to the Start\n";
            cout << "4. To Move to the End\n";
            cout << "5. To Add a value\n";
            cout << "6. To Remove a Value\n";
            cout << "7. To Update a Value\n";
            cout << "8. To Display List\n";
            cout << "0. To EXIT\n";
            cin >> opt;
            if (opt == 1)
            {
                cout << "Current List Length is: " << l.length() << endl;
            }
            if (opt == 2)
            {
                cout << "Value is : " << l.get() << endl;
            }
            if (opt == 3)
            {
                l.start();
            }
            if (opt == 4)
            {
                l.end();
            }
            if (opt == 5)
            {
                l. add();
            }
            if (opt == 6)
            {
                cout << "Removed Value is: " << l.remove() << endl;
            }

            if (opt == 7)
            {
               l. update();
            }
            if (opt == 8)
            {
               l. display();
            }

        } while (opt != 0);
        return 0;
    }

