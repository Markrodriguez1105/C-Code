/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	
	int weigth;
	string active;

	cout << "Enter Weigth: ";
	cin >> weigth;

	bool repeat;
	do {

		repeat = false;
		cout << "Are you Physically Active?(y/n) : ";
		cin >> active;
		

		if(active == "yes" || active == "y" || active == "YES" || active == "Y") {
			cout << "Recommended Calories : " << weigth * 15;
		}
		else if(active == "no" || active == "n" || active == "NO" || active == "N") {
			cout << "Recommended Calories : " << weigth * 13;
		} else {
			cout << "invalid input. Try Again\n";
			repeat = true;
		}
	} while(repeat);


	return 0;
}
