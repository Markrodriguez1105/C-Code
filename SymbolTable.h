#include <vector>
#include <string>
typedef struct STEntry
{
    string name;     // lexeme
    string dataType; // data type attribute
    string value;    // value attribute
};
class SymbolTable
{
private:
    vector<STEntry> entry;

public:
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
    // setup the lexeme
    STEntry e;
    e.name = name;
    e.value = value;
    e.dataType = dataType;

    // add it in the symbol table
    entry.push_back(e);
}
// for determining whether an entry
// already exist, on exist, it returns
// the position in the list
SymbolTable::SYMTAB_POS
SymbolTable::search(string s)
{
    // symbol table is empty
    if (entry.size() == 0)
        return NOT_FOUND;
    // search, if found return pos
    // else return NOT_FOUND
    for (int i = 0; i < entry.size(); i++)
        if (s == entry.at(i).name)
            return (SYMTAB_POS)i;
    return NOT_FOUND;
}