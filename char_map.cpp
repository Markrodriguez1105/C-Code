// sample driver program
#include <string>
#include <iostream>
#include "CharMap.h"

using namespace std;

int main()
{
    CharMap table;
    string s("xy 123 +-$%");
    for (int i = 0; i < s.size(); i++)
        cout << table.type(s.at(i)) << endl;
    return 0;
}