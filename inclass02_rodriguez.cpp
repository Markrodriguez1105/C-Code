/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <list>

using namespace std;

class Menu
{
public:
	string name;
	float price;

	Menu(string a, float b)
	{
		name = a;
		price = b;
	}
};

class Order
{
public:
	const Menu &selectedMenu;
	int qty;

	Order(const Menu &a, int b) : selectedMenu(a), qty(b) {};
};

int main()
{
	list<Order> orders = {
		Order(Menu("Humberger", 20), 2),
		Order(Menu("Cheeseburger", 35), 1),
		Order(Menu("French Fries", 30), 2),
		Order(Menu("Softdrink", 16), 4),
		Order(Menu("Pearl Shake", 28.50), 1),
	};

	cout << "------------------------------------------------------\n";
	cout << "ITEM\t\tUNIT PRICE\tQTY \tTOTAL" << "\n";
	cout << "------------------------------------------------------\n";

	for (const auto &order : orders)
	{
		cout << order.selectedMenu.name << "\t" << order.selectedMenu.price << "\t\t" << order.qty << "\t" << order.selectedMenu.price * order.qty << "\n";
	}
	cout << "------------------------------------------------------\n";

	float total = 0;
	for (const auto &order : orders)
	{
		total += order.selectedMenu.price * order.qty;
	}

	cout << "Total Bill : " << total;

	return 0;
}