#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Scanner.h"
#include "SymbolTable.h"

using namespace std;

Scanner scanner;
KeywordList keywordList;
SymbolTable symbolTable;
CharMap charMap;

void processTokens(string line)
{
    Scanner tokenSc;
    tokenSc.accept(line);
    Scanner::TOKEN_CODE t;
    do
    {
        t = tokenSc.next_token();
        cout << tokenSc.token_string() << "('"
             << tokenSc.lexeme_string() << "')" << endl;
    } while (t != Scanner::EOF_TOKEN);
}

void listKeywords(string line)
{
    Scanner keywordSc;
    keywordSc.accept(line);
    Scanner::TOKEN_CODE t;
    do
    {
        t = keywordSc.next_token();
        if (t == Scanner::KEYWORDS)
        {
            cout << keywordSc.token_string() << "('"
                 << keywordSc.lexeme_string() << "')" << endl;
        }
    } while (t != Scanner::EOF_TOKEN);
}

void generateSymbolTable(string line)
{
    Scanner symbolSc;
    symbolSc.accept(line);
    string variable;
    string value;
    string type;
    Scanner::TOKEN_CODE t;
    do
    {
        t = symbolSc.next_token();
        variable = symbolSc.lexeme_string();

        t = symbolSc.next_token();
        if (symbolSc.token_string() == "ASSIGN")
        {
            t = symbolSc.next_token();
            value = symbolSc.lexeme_string();
            if (t == Scanner::NUMBER)
            {
                type = "int";
            }
            else
            {
                type = "string";
            }

            if (symbolTable.search(variable) == SymbolTable::NOT_FOUND)
            {
                symbolTable.insert(variable, value, type);
            }
            else
            {
                cout << "Variable (" << variable << ") already exists" << endl;
            }
        }
        else
        {
            variable = "";
        }
    } while (t != Scanner::EOF_TOKEN);
}

int main()
{

    while (true)
    {

        int input;

        cout << "1. Process Tokens" << endl;
        cout << "2. List Keywords" << endl;
        cout << "3. Generate Symbol Table" << endl;
        cout << "4. Execute All" << endl;
        cout << "Enter your choice: ";
        cin >> input;

        ifstream inputFile("c:\\C++ codes\\inclass11_rodriguez\\input.txt");
        string line;

        switch (input)
        {
        case 1:

            cout << "--------------------------" << endl;
            cout << "PROCESS TOKENS" << endl;
            cout << "--------------------------" << endl;
            while (getline(inputFile, line))
            {
                processTokens(line);
            }
            inputFile.close();
            break;
        case 2:
            cout << "--------------------------" << endl;
            cout << "LIST KEYWORDS" << endl;
            cout << "--------------------------" << endl;
            while (getline(inputFile, line))
            {
                listKeywords(line);
            }
            break;
        case 3:
            cout << "--------------------------" << endl;
            cout << "SYMBOLS TABLE" << endl;
            cout << "--------------------------" << endl;
            while (getline(inputFile, line))
            {
                generateSymbolTable(line);
            }

            cout << "Data Type" << "\t|" << "Variable Name" << "\t|" << "Value" << endl;
            for (int i = 0; i < symbolTable.entry.size(); i++)
            {
                cout << symbolTable.entry.at(i).dataType << "\t\t|" << symbolTable.entry.at(i).name << "\t\t|" << symbolTable.entry.at(i).value << endl;
            }
            break;
        case 4:

            ifstream inputToken("c:\\C++ codes\\inclass11_rodriguez\\input.txt");
            string lineToken;
            cout << "--------------------------" << endl;
            cout << "PROCESS TOKENS" << endl;
            cout << "--------------------------" << endl;
            while (getline(inputToken, lineToken))
            {
                processTokens(lineToken);
            }

            inputToken.close();

            ifstream inputKeyword("c:\\C++ codes\\inclass11_rodriguez\\input.txt");
            string lineKeyword;

            cout << "--------------------------" << endl;
            cout << "LIST KEYWORDS" << endl;
            cout << "--------------------------" << endl;
            while (getline(inputKeyword, lineKeyword))
            {
                listKeywords(lineKeyword);
            }
            inputKeyword.close();

            ifstream inputSymbol("c:\\C++ codes\\inclass11_rodriguez\\input.txt");
            string lineSymbol;

            cout << "--------------------------" << endl;
            cout << "SYMBOLS TABLE" << endl;
            cout << "--------------------------" << endl;
            while (getline(inputSymbol, lineSymbol))
            {
                generateSymbolTable(lineSymbol);
            }

            cout << "Data Type" << "\t|" << "Variable Name" << "\t|" << "Value" << endl;
            for (int i = 0; i < symbolTable.entry.size(); i++)
            {
                cout << symbolTable.entry.at(i).dataType << "\t\t|" << symbolTable.entry.at(i).name << "\t\t|" << symbolTable.entry.at(i).value << endl;
            }

            inputSymbol.close();
            break;
        }

        string continueInput;
        cout << "Continue (y/n) ?";
        cin >> continueInput;
        if (continueInput != "y")
        {
            break;
        }

        inputFile.close();
    }

    return 0;
}