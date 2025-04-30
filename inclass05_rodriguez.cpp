#include <iostream>
#include <regex>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	fstream SourceFile("source.txt");
	string line;

	while (getline(SourceFile, line))
	{
		int digit = 0;
		int letter = 0;
		int symbol = 0;
		int whitespace = 0;
		string arr[line.length()];

		cout << line << endl;

		for (int i = 0; i < line.length(); i++)
		{
			arr[i] = line[i];
		}
		for (string i : arr)
		{
			cout << i << " : ";
			if (regex_match(i, regex("\\s")))
			{
				cout << "Whitespace" << endl;
				whitespace++;
			}
			else if (regex_match(i, regex("\\d")))
			{
				cout << "Digit" << endl;
				digit++;
			}
			else if (regex_match(i, regex("[a-zA-Z]")))
			{
				cout << "Letter" << endl;
				letter++;
			}
			else
			{
				cout << "Symbol" << endl;
				symbol++;
			}
		}
		cout << "NO. DIGITS = " << digit << endl;
		cout << "NO. LETTERS = " << letter << endl;
		cout << "NO. SYMBOLS = " << symbol << endl;
		cout << "NO. WHITESPACE = " << whitespace << endl;
	}

	SourceFile.close();
	return 0;
}