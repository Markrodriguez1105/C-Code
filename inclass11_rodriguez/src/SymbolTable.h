#include <vector>
#include <string>

using namespace std;

struct STEntry
{
    string name;     // lexeme
    string dataType; // data type attribute
    string value;    // value attribute
};

class SymbolTable
{
private:
public:
    vector<STEntry> entry;
    enum SYMTAB_POS
    {
        NOT_FOUND = -1
    };
    void insert(string name, string value, string dataType);
    SYMTAB_POS search(string);
};

// for adding new entries
void SymbolTable::insert(string name, string value, string dataType)
{
    STEntry e;
    e.name = name;
    e.value = value;
    e.dataType = dataType;
    entry.push_back(e);
}

// for determining whether an entry already exists
SymbolTable::SYMTAB_POS SymbolTable::search(string s)
{
    if (entry.size() == 0)
        return NOT_FOUND;

    for (int i = 0; i < entry.size(); i++)
        if (s == entry.at(i).name)
            return (SYMTAB_POS)i;
    return NOT_FOUND;
}