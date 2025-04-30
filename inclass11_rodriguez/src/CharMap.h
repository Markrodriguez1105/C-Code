// filepath: c:\C++ codes\CharMap.h
// CharMap.h – to identify the type of chars
#include <vector>
#include <string>

using namespace std;

class CharMap
{
public:
    static const char EOF_CHAR = 127;
    enum CHAR_TYPE
    {
        WHITESPACE,
        ASSIGN,
        LETTER,
        DIGIT,
        SPECIAL,
        QUOTE,
        COLON,
        ADDING,
        SUBTRACTING,
        MULTIPLYING,
        DIVIDING,
        INDENT,
        LEFT_BRACKET,
        RIGHT_BRACKET,
        LEFT_PARENTESIS,
        RIGHT_PARENTESIS,
        ERROR,
        EOF_TYPE
    };

    CharMap();
    CHAR_TYPE type(char);
    string String_typeOf(char c);

private:
    static const int ALL_CHARS = 256;
    CHAR_TYPE char_table[ALL_CHARS];
};

CharMap::CharMap()
{
    int i;
    // initialize all to error
    for (i = 0; i < ALL_CHARS; i++)
        char_table[i] = ERROR;
    // letters
    for (i = 'A'; i <= 'Z'; i++)
        char_table[i] = LETTER;
    for (i = 'a'; i <= 'z'; i++)
        char_table[i] = LETTER;
    // digits
    for (i = '0'; i <= '9'; i++)
        char_table[i] = DIGIT;
    // special symbol characters
    char_table['+'] = ADDING;
    char_table['-'] = SUBTRACTING;
    char_table['*'] = MULTIPLYING;
    char_table['/'] = DIVIDING;

    char_table['='] = ASSIGN;
    char_table[':'] = COLON;

    char_table['['] = LEFT_BRACKET;
    char_table[']'] = RIGHT_BRACKET;
    char_table['('] = LEFT_PARENTESIS;
    char_table[')'] = RIGHT_PARENTESIS;

    // whitespaces
    char_table['\n'] = WHITESPACE;
    char_table['\t'] = INDENT;
    char_table[' '] = WHITESPACE;

    // string delimiter (single quote)
    char_table['\"'] = QUOTE;
    // temporary EOF char
    char_table[EOF_CHAR] = EOF_TYPE;
}

CharMap::CHAR_TYPE CharMap::type(char c)
{
    return char_table[c];
}

string CharMap::String_typeOf(char c)
{
    CharMap::CHAR_TYPE token = type(c);
    switch (token)
    {
    case WHITESPACE:
        return "WHITESPACE";
    case ASSIGN:
        return "ASSIGN";
    case LETTER:
        return "LETTER";
    case DIGIT:
        return "DIGIT";
    case SPECIAL:
        return "SPECIAL";
    case QUOTE:
        return "QUOTE";
    case COLON:
        return "COLON";
    case ADDING:
        return "ADDING";
    case SUBTRACTING:
        return "SUBTRACTING";
    case MULTIPLYING:
        return "MULTIPLYING";
    case DIVIDING:
        return "DIVIDING";
    case INDENT:
        return "INDENT";
    case LEFT_BRACKET:
        return "LEFT_BRACKET";
    case RIGHT_BRACKET:
        return "RIGHT_BRACKET";
    case LEFT_PARENTESIS:
        return "LEFT_PARENTESIS";
    case RIGHT_PARENTESIS:
        return "RIGHT_PARENTESIS";
    default:
        return "ERROR";
    }
}