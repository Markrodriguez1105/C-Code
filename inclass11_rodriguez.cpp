#include <iostream>
#include <string>
#include <fstream>
#include "KeywordList.h"
#include "CharMap.h"
#include "Scanner.h"

using namespace std;

int main()
{
    ifstream file("input.txt");
    string line;

    Scanner s;
    Scanner::TOKEN_CODE t;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            s.accept(line);
            do
            {
                t = s.next_token();
                cout << s.token_string() << " - "
                     << s.lexeme_string() << endl;
            } while (t != Scanner::EOF_TOKEN);
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open file" << endl;
    }
}