// filepath: c:\C++ codes\Scanner.h
// Scanner.h – to tokenize input strings
#include <string>
#include "CharMap.h"
#include "KeywordList.h"

using namespace std;

class Scanner
{
public:
    enum TOKEN_CODE
    {
        ERROR,
        WORD,
        KEYWORDS,
        NUMBER,
        EOF_TOKEN
    };

    // constructors
    Scanner();
    Scanner(string);
    // public member functions
    void accept(string);
    TOKEN_CODE next_token();
    string token_string();
    string lexeme_string();

private:
    CharMap table;
    string source;
    string lexeme;
    TOKEN_CODE token;
    int cchar_ptr;
    char cchar;
    // private member functions
    void skip_whitespace();
    char get_source_char();
    void get_word_token();
    void get_number_token();
    void get_eof_token();
    void get_error();
};

// implementation
Scanner::Scanner()
{
    source = "";
}

Scanner::Scanner(string s)
{
    accept(s);
}

void Scanner::accept(string s)
{
    source = s;
    cchar_ptr = 0;
    cchar = get_source_char();
}

string Scanner::lexeme_string()
{
    return lexeme;
}

Scanner::TOKEN_CODE Scanner::next_token()
{
    skip_whitespace();
    // check first non-whitespace
    switch (table.type(cchar))
    {
    case CharMap::LETTER:
        get_word_token();
        break;
    case CharMap::DIGIT:
        get_number_token();
        break;
    case CharMap::EOF_TYPE:
        get_eof_token();
        break;
    default:
        get_error();
    }
    return token;
}

void Scanner::skip_whitespace()
{
    while (table.type(cchar) == CharMap::WHITESPACE)
        cchar = get_source_char();
}

char Scanner::get_source_char()
{
    char c;
    if (cchar_ptr < source.size())
        c = source.at(cchar_ptr++);
    else
        c = CharMap::EOF_CHAR;
    return c;
}

void Scanner::get_word_token()
{
    lexeme = cchar;
    for (;;)
    {
        cchar = get_source_char();
        if (table.type(cchar) == CharMap::LETTER)
            lexeme += cchar; // append chars
        else
            break;
    }

    KeywordList keywordList;

    KeywordList::KW_CODES kwcode = keywordList.search(lexeme);
    if (kwcode >= 0)
    {
        token = KEYWORDS;
    }
    else
    {
        token = WORD;
    }
}

void Scanner::get_number_token()
{
    lexeme = cchar;
    for (;;)
    {
        cchar = get_source_char();
        if (table.type(cchar) == CharMap::DIGIT)
            lexeme += cchar; // Append digits
        else
            break;
    }
    token = NUMBER;
}

void Scanner::get_error()
{
    lexeme = cchar;
    for (;;)
    {
        cchar = get_source_char();
        if (table.type(cchar) == CharMap::ERROR)
            lexeme += cchar; // append chars
        else
            break;
    }
    token = ERROR;
}

void Scanner::get_eof_token()
{
    lexeme = "";
    token = EOF_TOKEN;
}

string Scanner::token_string()
{
    switch (token)
    {
    case WORD:
        return "WORD";
    case KEYWORDS:
        return "KEYWORD";
    case NUMBER:
        return "NUMBER";
    case EOF_TOKEN:
        return "EOF";
        break;
    default:
        CharMap charmap;
        CharMap::CHAR_TYPE charToken = charmap.type(lexeme.at(0));
        if (charToken != charmap.ERROR && lexeme.size() == 1)
            return charmap.String_typeOf(lexeme.at(0));
        else
            return "ERROR";
    }
}