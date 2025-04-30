// sample driver program
using namespace std;
#include <string>
#include <iostream>
#include "CharMap.h"
#include "Scanner.h"
int main()
{
    Scanner scan;
    scan.accept(" compiler design 12 ");
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