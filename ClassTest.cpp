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
    User();//����������������
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
    cout << " ���캯��ִ��" << endl;
    age = 23;
    name = "stark1307";
    // ������������ɷ�ʽ
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
    cout << " ��������ִ��" << endl;
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
    Line(int len);               // �򵥵Ĺ��캯��
    Line(const Line& obj);       // �������캯��
    ~Line();                     // ��������

private:
    int* ptr;
};

// ��Ա�������壬�������캯��
Line::Line(int len)
{
    cout << "���ù��캯��" << endl;
    // Ϊָ������ڴ�
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj)
{
    cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // ����ֵ
}

Line::~Line(void)
{
    cout << "�ͷ��ڴ�" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line ��С : " << obj.getLength() << endl;
}

void getName(User user) //��Ԫ�����������κ��࣬�����Է��ʸ����private��protected��Ա�����ڸ�������������Ԫ����.
{
    cout << "��Ԫ������ȡ˽�г�Աname: " << user.name << endl;
}

int main()
{
    User userd(10);//���췽����һ��д��
    User *usere = new User(13);//���췽������һ��д��
    usere->toString();
    cout << (userd.getName().append("123")) << endl;
    userd.toString();

    Line line(10);
    Line line1 = line;//����Ҳ�����˿������캯��
    display(line);
    User user = *new User;
    getName(user);
    user.toString();
    if (&user != NULL)
    {
        cout << endl;
    }
}

