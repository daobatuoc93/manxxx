#include <algorithm>
#include <array>
#include <stdio.h>
#include <iostream>
#include <string_view>
#include <vector>
#include <functional>
#include <cassert>
#include <cstring>
#include <string>
#include "someClass.hpp"
using namespace std;

class Stack
{
private:
    /* data */
    int *prtarr;
    int count = 0;

public:
    Stack()
    {
        prtarr = new int[10];
    }
    void print()
    {
        cout << "(";
        for (int i = 0; i < 10; i++)
        {

            if (prtarr[i] == 0)
                continue;
            cout << prtarr[i] << " ";
        }
        cout << ")" << endl;
    }
    void push(int num)
    {
        prtarr[count] = num;
        count++;
    }
    void pop()
    {
        prtarr[count] = 0;
        count--;
    }

    void reset()
    {
        memset(prtarr, 0, 10);
    }
    ~Stack()
    {
        delete[] prtarr;
    }
};

class Fraction
{
private:
    int m_num;
    int m_deno;
    /* data */
public:
    Fraction(int, int);
    Fraction();
    ~Fraction();
    int getNumerator() { return m_num; }
    int getDenominator() { return m_deno; }
    double getValue() { return static_cast<double>(m_num) / m_deno; }
};

class Test
{
private:
    const int mAr[5];

public:
    Test(/* args */) : mAr{1, 2}
    {
    }
    const int *getmaAr()
    {
        return mAr;
    }
    ~Test() {}
};

class A
{
public:
    A(int x) { std::cout << "A " << x << endl; }
};

class B
{
private:
    A a;

public:
    B(int y) : a{y - 1}
    {
        std::cout << "B " << y << endl;
    }
};

class RGBA
{
private:
    /* data */
    uint_fast8_t m_red{};
    uint_fast8_t m_green{};
    uint_fast8_t m_blue{};
    uint_fast8_t m_alpha{};

public:
    RGBA(uint_fast8_t red = 0, uint_fast8_t green = 0, uint_fast8_t blue = 0, uint_fast8_t alpha = 255)
        : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
    {
    }
    
    void print()
    {
        cout << "r = " << static_cast<int>(m_red) << " g = " << static_cast<int>(m_green) << " b = " << static_cast<int>(m_blue) << " a = " << static_cast<int>(m_alpha) << endl;
    }
    ~RGBA() {}
};

class Ball
{
private:
    std::string m_color{"black"};
    double m_radius{10.0};

public:
    // Constructor with only color parameter (radius will use default value)
    Ball(const std::string &color = "black", double radius = 10.0)
        : m_color(color),
          m_radius(radius)
    {
    }

    // Constructor with only radius parameter (color will use default value)
    Ball(double radius) : m_radius(radius)
    {
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

class Rectangle
{
private:
    /* data */
    double m_length{1.0};
    double m_h{1.0};

public:
    Rectangle(double len, double h) : m_length{len}, m_h{h}
    {
    }
    ~Rectangle() {}
};

class Employee
{
private:
    string name;
    int age;

public:
    Employee(int age = 0, const string &name = "") : age(age), name(name) {}
    Employee(const string &name) : Employee(0, name) {}

    ~Employee()
    {
        cout << "destructor Employee!" << endl;
    }
};

Simple *Prt;
class IntArr
{
private:
    int *m_arr{};
    int len{};

public:
    IntArr(int length)
    {
        assert(length > 0);
        m_arr = new int[static_cast<int>(length)]{};
        this->len = length;
    }
    void setValue(int index, int value) { m_arr[index] = value; }
    int getValue(int index) { return m_arr[index]; }
    void printArr()
    {
        for (int i = 0; i < this->len; i++)
        {
            cout << m_arr[i] << " ";
        }
    }
    ~IntArr()
    {
        delete[] m_arr;
        cout << "\n delete arr!" << endl;
    }
};
Simple *Simple::returnThis()
{
    return this;
}

Simple::Simple(int nID)
    : m_nID{nID}
{
    Prt = this;
    cout << "Create new Simple!" << endl;
}
void Simple::setID(int x)
{
    if (Prt->getID() == 0)
    {
        cout << " get 0!" << endl;
    }
    m_nID = x;
}

int Simple::getID()
{
    return m_nID;
}

class Cal
{
private:
    /* data */
    int m_val;

public:
    static int sCal;
    Cal(int val) { this->m_val = val; }
    Cal *add(int var)
    {
        m_val += var;
        return this;
    }
    Cal *sub(int var)
    {
        m_val -= var;
        return this;
    }
    Cal *mul(int var)
    {
        m_val += var;
        return this;
    }
    Cal *div(int var)
    {
        m_val += var;
        return this;
    }
    int get() { return m_val; }
    ~Cal() {}
};

class StaticVal
{
private:
    static int s_id;
    int id;

public:
    StaticVal(/* args */) { s_id++; }
    static int getID()
    {
        return s_id;
    }
    ~StaticVal() {}
};

int StaticVal::s_id{1};

class MyCal
{
private:
    static vector<char> s_mychars;

public:
    class s_initial
    {
    public:
        s_initial()
        {
            for (char i = 'a'; i <= 'z'; i++)
            {
                s_mychars.push_back(i);
            }
        }
    };
    ~MyCal() {}

    vector<char> getObj()
    {
        return s_mychars;
    }

private:
    static s_initial newStaticObj;
};

vector<char> MyCal::s_mychars{};
MyCal::s_initial MyCal::newStaticObj{};

void Display::disp(const Data &data)
{
    cout << " data id is : " << data.id << endl;
    cout << " name is : " << data.name << endl;
}

void Point3d::moveByVector(const Vector3d &v)
{
    this->m_x = v.m_x;
    this->m_y = v.m_y;
    this->m_z = v.m_z;
}

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) { m_cents = cents; }

    int getCents() const { return m_cents; }
};

Cents add(const Cents &c1, const Cents &c2)
{
    return (c1.getCents() + c2.getCents());
}

class Fruits
{
public:
    enum class FruitType
    {
        apple,
        banana,
        cherry
    };

private:
    FruitType e_fruit;
    int m_percentageEaten;

public:
    Fruits(FruitType type)
    {
        e_fruit = type;
    }
    FruitType getType()
    {
        return e_fruit;
    }
    int getPercentageEaten() const
    {
        return m_percentageEaten;
    }
    ~Fruits() {}
};

class Timer
{
private:
    using clock_t = chrono::steady_clock;
    using second_t = chrono::duration<double, ratio<1>>;
    std::chrono::time_point<clock_t> m_beg;

public:
    Timer(/* args */) : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }

    ~Timer() {}
};

class Point2d
{
private:
    double m_x{0};
    double m_y{0};

public:
    Point2d(double mx = 0, double my = 0)
    {
        m_x = mx;
        m_y = my;
    }
    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    int distanceTo(const Point2d &obj)
    {
        return (sqrt((m_x - obj.m_x) * (m_x - obj.m_x) + (m_y - obj.m_y) * (m_y - obj.m_y)));
    }
    friend int distanceFrom(const Point2d &obj1, const Point2d &obj2);
    ~Point2d() {}
};

int distanceFrom(const Point2d &obj1, const Point2d &obj2)
{
    return (sqrt((obj1.m_x - obj2.m_x) * (obj1.m_x - obj2.m_x) + (obj1.m_y - obj2.m_y) * (obj1.m_y - obj2.m_y)));
}

class HelloWorld
{
private:
    char *m_data{};

public:
    HelloWorld()
    {
        m_data = new char[14];
        const char *init{"Hello, World!"};
        for (int i = 0; i < 14; ++i)
            m_data[i] = init[i];
    }

    ~HelloWorld()
    {
        delete[] m_data;
        cout << "Destructor HelloWorld! " << endl;
    }

    void print() const
    {
        std::cout << m_data << '\n';
    }
};

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

private:
    Type monType{};
    string m_name{};
    string m_roar{};
    int m_hit{};

public:
    Monster(Type type, string name, string roar, int hit) : monType(type), m_name(name), m_roar(roar), m_hit(hit)
    {
    }
    std::string_view getTypeString() const
    {
        switch (monType)
        {
        case Type::dragon:
            return "dragon";
        case Type::goblin:
            return "goblin";
        case Type::ogre:
            return "ogre";
        case Type::orc:
            return "orc";
        case Type::skeleton:
            return "skeleton";
        case Type::troll:
            return "troll";
        case Type::vampire:
            return "vampire";
        case Type::zombie:
            return "zombie";
        default:
            return "???";
        }
    }

    void print()
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hit << " hit points and says " << m_roar << '\n';
    }
    ~Monster() {}
};

class MonsterGenerator
{
private:
    /* data */
public:
    static Monster generateMonster()
    {
        // If your compile is not C++17 capable, use std::array<const char*, 6> instead.
        static constexpr std::array s_names{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
        static constexpr std::array s_roars{"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
        int hitPoints{ getRandomNumber(1, 100) };
        Monster::Type type =  static_cast<Monster::Type>(0,Monster::max_monster_types-1);
        auto name{ s_names[getRandomNumber(0, static_cast<int>(s_names.size()-1))] };
		auto roar{ s_roars[getRandomNumber(0, static_cast<int>(s_roars.size()-1))] };
        return {type, name, roar, hitPoints};
    }

    static int getRandomNumber(int min, int max)
    {
        // static used for efficiency, so we only calculate this value once
        static constexpr double fraction{1.0 / (static_cast<double>(RAND_MAX) + 1.0)};
        // evenly distribute the random number across our range
        return min + static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
};

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1
    Timer t;

    /* write code here */

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand();                                               // If using Visual Studio, discard first random value

    Monster m{MonsterGenerator::generateMonster()};
    m.print();

    /* end code here */

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";
    return 0;
}