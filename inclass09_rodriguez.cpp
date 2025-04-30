using namespace std;
#include <iostream>
#include "SymbolTable.h"
int main()
{
    SymbolTable st;
    // add some entries

    while (true)
    {
        string name;
        string value;
        string dataType;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter value: ";
        cin >> value;

        cout << "Enter data type: ";
        cin >> dataType;

        SymbolTable::SYMTAB_POS loc;
        loc = st.search(name);
        if (loc == SymbolTable::NOT_FOUND)
        {

            st.insert(name, value, dataType);
            cout << "New Keyword Added: " << name << endl;
        }
        else
            cout << "Found at Index#: " << loc << endl;
    }

    return 0;
}