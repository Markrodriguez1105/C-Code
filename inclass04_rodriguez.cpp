/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{

	while(true) {
		int lower, upper;
		cout << "Enter lower and upper integer limits: ";
		cin >> lower;
		cin >> upper;

		if(lower == upper) break;

		int sum = 0;

		for(int i = lower ; i <= upper ; i++) {
			sum += (i*i);
		}
		cout << "The sums of the squares from " << lower*lower << " to " << upper*upper << " is " << sum << "\n";
	}


	return 0;
}