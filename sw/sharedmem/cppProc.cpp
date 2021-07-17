#include<iostream>
#include<string>

using namespace std;

class Woman
{
private:
    bool zin;
    string name;
public:
    int age;
    string nhac_cu;
    void playintrumental(string instrument){
        cout<< "instrumental mucic is "<<this->nhac_cu<<endl;
    }
    Woman(const string &namearg,int age);
    ~Woman();
};

Woman::Woman(const string &namearg,int age) : name(namearg),age(age)
{

}

Woman::~Woman()
{
}


int main(){
    

    return 0;
}