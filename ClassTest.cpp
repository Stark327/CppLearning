#include <iostream>
#include <string>

using namespace std;

class Box
{
public:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度

    double getVolume(void)
    {
        return length * breadth * height;
    }
};


class User
{
public:
	User();
	~User();

private:
    int age;
    string name;
    Box* b;
};

User::User()
{
    cout << "构造函数执行" << endl;
    age = 23;
    name = "stark1307";
    b = (Box*)malloc(sizeof(Box));
    b->breadth = 1.0;
    b->height = 1.0;
    b->length = 1.1;
    cout << b->getVolume() << endl;
}

User::~User()
{
    cout << "析构函数执行" << endl;
    free(b);
}



int main()
{
    Box b;

    b.breadth = 1; 
    b.height = 2;
    b.length = 3;
    cout << b.getVolume() << endl;

    User user;
    cout << &user << endl;
}

