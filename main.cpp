#include <iostream>
#include <string>

#include "cstlist.h"

using namespace std;

int main()
{
    /*
    CstList<int> test, right;

    for(int i=0; i<15; i++) {
        test << i;
    }

    cout << test.getSize() << endl;
    test.print();
    cout << endl << endl;

    test.split(right, 7);

    cout << test.getSize() << endl;
    cout << right.getSize() << endl;
    cout << endl;

    test.print();
    cout << endl;
    right.push_back(666);
    right.print();

    cout << endl << endl;

    test.merge(right);
    cout << test.getSize() << endl;
    test.print();

    cout << endl << right.getSize() << endl;
    right.print();

    return 0;
    */

    cout << "Program started, this program is infinite!" << endl;
    cout << "Type insert, pop_back, push_back, pop_front, push_front, erase, unique, size, set, clear, print or sort" << endl;
    cout << "You can type fill_rand or fill_order to fill list with numbers" << endl;
    cout << "Type end to end the program" << endl;

    CstList<int> list;
    string input;
    while(true) {
        cout << endl;
        cin >> input;

        if(input == "insert") {
            int value = 0;
            cout << "Type value to insert: ";
            cin >> value;

            unsigned long pos = 0;
            cout << "Type pos before which value will be inserted: ";
            cin >> pos;

            list.insert(pos, value);
        }
        else if(input == "pop_back") {
            int value = list.pop_back();
            cout << "Popped value: " << value << endl;
        }
        else if(input == "push_back") {
            int value = 0;
            cout << "Type value to push back: ";
            cin >> value;

            list.push_back(value);
        }
        else if(input == "pop_front") {
            int value = list.pop_front();
            cout << "Popped value: " << value << endl;
        }
        else if(input == "push_front") {
            int value = 0;
            cout << "Type value to push front: ";
            cin >> value;

            list.push_front(value);
        }
        else if(input == "erase") {
            unsigned long pos = 0;
            cout << "Type pos to erase: ";
            cin >> pos;

            list.erase(pos);
        }
        else if(input == "unique") {
            cout << "Unique casted" << endl;
            list.unique();
        }
        else if(input == "size") {
            cout << "Size of the list: " << list.getSize() << endl;
        }
        else if(input == "set") {
            unsigned long pos = 0;
            cout << "Type pos of the element to set: ";
            cin >> pos;

            int value = 0;
            cout << "Type value to set: ";
            cin >> value;

            list.set(pos, value);
        }
        else if(input == "print") {
            cout << "Contains of the list:" << endl;
            list.print();
        }
        else if(input == "sort") {
            cout << "Sort casted" << endl;
            list.sort();
        }
        else if(input == "clear") {
            cout << "List cleared" << endl;
            list.clear();
        }
        else if(input == "fill_rand") {
            unsigned long num = 0;
            cout << "Type the number of elements:" << endl;
            cin >> num;

            list.clear();
            for(unsigned long i=0; i<num; i++) {
                list << rand();
            }
        }
        else if(input == "fill_order") {
            unsigned long num = 0;
            cout << "Type the number of elements:" << endl;
            cin >> num;

            list.clear();
            for(unsigned long i=0; i<num; i++) {
                list << static_cast<int>(i);
            }
        }
        else if(input == "end") {
            cout << "Ending the program" << endl;
            break;
        }
        else {
            continue;
        }
        input = "";
    }

    cin >> input;
    return 0;
}
