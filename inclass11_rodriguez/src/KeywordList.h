#include <vector>
#include <string>

using namespace std;

class KeywordList
{
public:
    KeywordList(); // constructor
    // the keyword's token codes
    enum KW_CODES
    {
        NOT_FOUND = -1,
        KW_FALSE,
        KW_NONE,
        KW_TRUE,
        KW_AND,
        KW_AS,
        KW_ASSERT,
        KW_ASYNC,
        KW_AWAIT,
        KW_BREAK,
        KW_CLASS,
        KW_CONTINUE,
        KW_DEF,
        KW_DEL,
        KW_ELIF,
        KW_ELSE,
        KW_EXCEPT,
        KW_FINALLY,
        KW_FOR,
        KW_FROM,
        KW_GLOBAL,
        KW_IF,
        KW_IMPORT,
        KW_IN,
        KW_IS,
        KW_LAMBDA,
        KW_NONLOCAL,
        KW_NOT,
        KW_OR,
        KW_PASS,
        KW_RAISE,
        KW_RETURN,
        KW_TRY,
        KW_WHILE,
        KW_WITH,
        KW_YIELD,
        KW_END_MARKER
    };

    KW_CODES search(string);
    vector<string> GetKwlist();

private:
    vector<string> kwlist;
    vector<KW_CODES> kwcodes;
};

vector<string> KeywordList::GetKwlist()
{
    return kwlist;
}

KeywordList::KeywordList()
{
    // predefined list of keywords
    kwlist.push_back("False");
    kwlist.push_back("None");
    kwlist.push_back("True");
    kwlist.push_back("and");
    kwlist.push_back("as");
    kwlist.push_back("assert");
    kwlist.push_back("async");
    kwlist.push_back("await");
    kwlist.push_back("break");
    kwlist.push_back("class");
    kwlist.push_back("continue");
    kwlist.push_back("def");
    kwlist.push_back("del");
    kwlist.push_back("elif");
    kwlist.push_back("else");
    kwlist.push_back("except");
    kwlist.push_back("finally");
    kwlist.push_back("for");
    kwlist.push_back("from");
    kwlist.push_back("global");
    kwlist.push_back("if");
    kwlist.push_back("import");
    kwlist.push_back("in");
    kwlist.push_back("is");
    kwlist.push_back("lambda");
    kwlist.push_back("nonlocal");
    kwlist.push_back("not");
    kwlist.push_back("or");
    kwlist.push_back("pass");
    kwlist.push_back("raise");
    kwlist.push_back("return");
    kwlist.push_back("try");
    kwlist.push_back("while");
    kwlist.push_back("with");
    kwlist.push_back("yield");

    for (int i = KW_FALSE; i < KW_END_MARKER; i++)
    {
        kwcodes.push_back(static_cast<KW_CODES>(i));
    }
}

KeywordList::KW_CODES
KeywordList::search(string key)
{
    // perform binary search
    int l = 0;
    int r = kwlist.size() - 1;
    int m;
    bool found = false;
    while (l <= r && found == false)
    {
        m = (l + r) / 2;
        if (kwlist.at(m) == key)
            found = true;
        else if (kwlist.at(m) > key)
            r = m - 1;
        else
            l = m + 1;
    }
    if (found) // return the token code
        return kwcodes.at(m);
    else
        return NOT_FOUND;
}