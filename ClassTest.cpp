#include <iostream>
#include <string>

using namespace std;

typedef signed   char  sint8;
typedef unsigned char  uint8;
typedef signed   short sint16;
typedef unsigned short uint16;
typedef signed   int   sint32;
typedef unsigned int   uint32;

class Box
{
public:
    double length;
    double breadth;
    double height;

    double getVolume(void)
    {
        return length * breadth * height;
    }
};


class User
{
public:
    User(int age);
    User();//构造析构函数声明
	~User();
    void setAge(int);
    void setNmae(string);
    void toString(void);
    string getName(void);
    friend void getName(User user);

private:
    int age;
    string name;
    Box* b;
};

User::User(int age)
{
    this->age = age;
}

User::User()
{
    cout << " 构造函数执行" << endl;
    age = 23;
    name = "stark1307";
    // 对象的两种生成方式
    b = (Box*)malloc(sizeof(Box));
    free(b);
    b = new Box;

    b->breadth = 1.0;
    b->height = 1.0;
    b->length = 1.1;
    cout << " The value of b.Volume is: "<<b->getVolume() << endl;
}

User::~User()
{
    cout << " 析构函数执行" << endl;
    //free(b);
}

void User::setAge(int age)
{
    this->age = age;
}

void User::setNmae(string name)
{
    this->name = name;
}

void User::toString(void)
{
    cout << " user:@"<< this << " age:" << this->age << " name:" << this->name << endl;
}

string User::getName(void)
{
    return name;
}

class Line
{
public:
    int getLength(void);
    Line(int len);               // 简单的构造函数
    Line(const Line& obj);       // 拷贝构造函数
    ~Line();                     // 析构函数

private:
    int* ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line 大小 : " << obj.getLength() << endl;
}

void getName(User user) //友元函数不属于任何类，但可以访问该类的private，protected成员，需在该类中声明该友元函数.
{
    cout << "友元函数获取私有成员name: " << user.name << endl;
}

int main()
{
    User userd(10);//构造方法的一种写法
    User *usere = new User(13);//构造方法的另一种写法
    usere->toString();
    cout << (userd.getName().append("123")) << endl;
    userd.toString();

    Line line(10);
    Line line1 = line;//这里也调用了拷贝构造函数
    display(line);
    User user = *new User;
    getName(user);
    user.toString();
    if (&user != NULL)
    {
        cout << endl;
    }
}

