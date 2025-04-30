#include <iostream>
using namespace std;

class Rectangle
{
private:
    /* data */
    double width;
    double length;

public:
    void set_values(double a, double b);
    double area();
};

void Rectangle::set_values(double a, double b)
{
    width = a;
    length = b;
}

double Rectangle::area(){
    return width * length;
}

int main()
{
    Rectangle  rec;

    double length;
    double width;

    cout << "Enter Length : ";
    cin >> length;
    
    cout << "Enter Width : ";
    cin >> width;

    rec.set_values(width,length);
        
    cout << "Area : " << rec.area();
    return 0;
}
