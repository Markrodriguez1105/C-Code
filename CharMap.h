// CharMap.h – to identify the type of chars
class CharMap
{
public:
    static const char EOF_CHAR = 127;
    enum CHAR_TYPE
    {
        WHITESPACE,
        LETTER,
        DIGIT,
        SPECIAL,
        QUOTE,
        ERROR,
        EOF_TYPE
    };

    CharMap();
    CHAR_TYPE type(char);

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
    char_table['+'] = SPECIAL;
    char_table['-'] = SPECIAL;
    char_table['*'] = SPECIAL;
    char_table['/'] = SPECIAL;
    //... include other symbols here
    // whitespaces
    char_table['\n'] = WHITESPACE;
    char_table['\t'] = WHITESPACE;
    char_table[' '] = WHITESPACE;
    // string delimiter (double quote)
    char_table['\''];
    // temporary EOF char
    char_table[EOF_CHAR] = EOF_TYPE;
}

CharMap::CHAR_TYPE CharMap::type(char c)
{
    return char_table[c];
}