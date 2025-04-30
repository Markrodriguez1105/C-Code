using namespace std;
#include <iostream>
#include "KeywordList.h" // import the KeywordList.h class

int main()
{
    KeywordList kw; // object of KeywordList

    // Ask the user for the number of test cases
    int numTests = 0;
    cout << "Enter the number of test cases: ";
    cin >> numTests;

    // Dynamically create an array for test cases based on user input
    vector<string> testCases(numTests);

    // Get the test cases from the user
    cout << "Enter the test cases:" << endl;
    for (int i = 0; i < numTests; i++)
    {
        cout << "Test case " << (i + 1) << ": ";
        cin >> testCases.at(i);

        KeywordList::KW_CODES result = kw.search(testCases.at(i));

        // Check if the keyword exists in the list
        if (result != KeywordList::NOT_FOUND)
        {

            cout << "Existing" << result << endl; // if the keyword found then display
        }
        else
        {

            cout << "Not Exist" << endl; // if the keyword not found then display
        }

        cout << "-------------" << endl;
    }

    return 0;
}
