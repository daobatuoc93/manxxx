#include <algorithm>
#include <array>
#include <stdio.h>
#include <iostream>
#include <string_view>
#include <vector>
#include <functional>
#include <cassert>

#include <string>
using namespace std;


class Caculator
{
private:
    /* data */
    int d1;
    int d2;
public:
    using  numtype = int;
    vector <numtype> arr{};
    numtype add (numtype a, numtype b){
        auto res {a+b};
        arr.push_back(res);
        return res;
    }
    Caculator(int,int);
    ~Caculator();
};

Caculator::Caculator(int D1, int D2) : d1{D1},d2{D2}
{
    
}

Caculator::~Caculator()
{
}

int main(){
    Caculator cal(2,3);
    cout<<cal.add(3,4) <<endl;
    cout<<cal.add(6,7) <<endl;
    for (Caculator::numtype x :cal.arr)
    {
        /* code */
        cout<<x<<endl;
    }
    double x(2.3);
    return 0;
}


int binarySearch(const int* array, int target, int min, int max)
{
    assert(array); // make sure array exists
 
    // implement this recursively
 
    if (min > max)
        return -1;
 
    int midpoint{(min+(max-min) / 2) };
    // Before C++20
    // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow
 
    if (array[midpoint] > target)
    {
        return binarySearch(array, target, min, midpoint - 1);
    }
    else if (array[midpoint] < target)
    {
        return binarySearch(array, target, midpoint + 1, max);
    }
    else
    {
        return midpoint;
    }
}
int binarySearchMain()
{
    constexpr int array[]{3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 22};
    constexpr int numTestValues{9};
    constexpr int testValues[numTestValues]{11, 3, 12, 13, 22, 26, 43, 44, 49};
    int expectedValues[numTestValues]{-1, 0, 3, 1, -1, 8, -1, 13, -1};
    for (int count{0}; count < numTestValues; ++count)
    { 
        // See if our test value is in the array
        int index{binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1)};
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }
    return 0;
}

typedef struct
{
    /* data */
    std::string_view name{};
    double averageTemperature{};
} Season;

auto makeWalrus(const std::string &name)
{
    // Capture name by reference and return the lambda.
    return [&]()
    {
        std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
    };
}
int ex5(const string &);
int makeWal()
{
    auto sayName{makeWalrus("xxx")};
    // Call the lambda function that makeWalrus returned.
    sayName();
    sayName();
    return 0;
}

int ex5(const string &x)
{
    vector<int> areas{100, 25, 67, 55, 44, 32, 64};
    int w{0};
    int h{0};
    cin >> w >> h;

    auto found{find_if(areas.begin(), areas.end(),
                       [userA = h * w](int knowareas)
                       {
                           return knowareas == userA;
                       })};
    if (found == areas.end())
    {
        cout << "not found!" << endl;
        return -1;
    }
    cout << "Yeah found " << *found << " in areas!" << endl;

    return 0;
}

int ex3()
{
    vector<string_view> varr{"banana", "apple", "walnut", "lemon"};
    string search{"apple"};
    bool isY{true};
    auto getstring{find_if(varr.begin(), varr.end(),
                           [=](const auto &str) mutable
                           {
                               if (isY)
                                   cout << "yeah" << endl;
                               isY = false;
                               return (str.find(search) != string_view::npos);
                           })};

    if (getstring == varr.end())
    {
        std::cout << "Not found\n";
    }

    else
    {
        std::cout << "Found " << *getstring << '\n';
    }
    cout << search;
    return 0;
}

int ex2()
{
    vector<Season> seasons{
        {"Spring", 285.0},
        {"Summer", 296.0},
        {"Fall", 288.0},
        {"Winter", 263.0}};

    sort(seasons.begin(), seasons.end(),
         [](const auto &a, const auto &b)
         {
             return (a.averageTemperature < b.averageTemperature);
         });

    for (const auto &season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}

typedef struct student
{
    string name;
    int score;
    /* data */
} Student;

int bt1()
{
    vector<Student> vec{
        {"Albert", 3},
        {"Ben", 5},
        {"Christine", 2},
        {"Dan", 8}, // Dan has the most points (8).
        {"Enchilada", 4},
        {"Francis", 1},
        {"Greg", 3},
        {"Hagrid", 5}};

    auto maxScore = max_element(vec.begin(), vec.end(),
                                [](Student a, Student b)
                                {
                                    return (b.score > a.score);
                                });

    cout << "max element at: " << maxScore->name << '\n'; //vec.at(distance(vec.begin(),maxScore)).name
    return 0;
}
