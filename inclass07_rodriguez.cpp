using namespace std;

#include <string>
#include <iostream>
#include "CharMap.h"
#include "Scanner.h"

int main()
{
    CharMap table;
    string text = " ====+ xy 123";
    string s(text);
    for (int i = 0; i < s.size(); i++)
    {
        int result = table.type(s.at(i));
        switch (result)
        {
        case 0:
            cout << s.at(i) << ":" << "Whitespace" << endl;
            /* code */
            break;
        case 1:
            cout << s.at(i) << ":" << "Letter" << endl;
            /* code */
            break;
        case 2:
            cout << s.at(i) << ":" << "Digit" << endl;
            /* code */
            break;
        case 3:
            cout << s.at(i) << ":" << "Special Character" << endl;
            /* code */
            break;
        case 4:
            cout << s.at(i) << ":" << "Qoute" << endl;
            /* code */
            break;
        case 5:
            cout << s.at(i) << ":" << "Error" << endl;
            /* code */
            break;
        case 6:
            cout << s.at(i) << ":" << "eor_type" << endl;
            /* code */
            break;
        }
    }

    Scanner scan;
    scan.accept(text);
    // get all tokens
    Scanner::TOKEN_CODE t;
    do
    {
        t = scan.next_token();
        cout << scan.token_string() << " - "
             << scan.lexeme_string() << endl;
    } while (t != Scanner::EOF_TOKEN);
    system("pause");
    return 0;
}