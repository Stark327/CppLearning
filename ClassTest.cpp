#include <iostream>
#include <string>

using namespace std;

class Box
{
public:
    double length;      // ����
    double breadth;     // ���
    double height;      // �߶�

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
    cout << "���캯��ִ��" << endl;
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
    cout << "��������ִ��" << endl;
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

