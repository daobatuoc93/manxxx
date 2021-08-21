#ifndef _CLASS_OOP_
#define _CLASS_OOP_
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
#include <math.h>
#include <chrono>
#include <algorithm> // for std::sort
#include <numeric>   // for std::iota
#include <ctime>     // for time()
#include <cstdlib>   // for rand() and srand()
#include <random>
#include <cmath>
using namespace std;

const int g_arrayElements = 10000;

class Point3d;
class Vector3d;
class Simple
{
private:
    int m_nID{};

public:
    int simpleVar;
    Simple(int);
    void setID(int);
    Simple *returnThis();
    int getID();
    ~Simple() {}
};

class Data;

class Display
{
private:
    bool isDisp;

public:
    Display(bool isdisp) { isDisp = isdisp; }
    void disp(const Data &data);
    ~Display() {}
};

class Data
{
private:
    int id;
    string name;

public:
    Data(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    friend void Display::disp(const Data &data);
};

class Point3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }

    void moveByVector(const Vector3d &v);
};

class Vector3d
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    void print() const
    {
        std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
    }
    friend void Point3d::moveByVector(const Vector3d &v);
};

#endif