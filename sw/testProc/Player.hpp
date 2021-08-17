#include "someClass.hpp"
class Player
{
private:
    int score{0};

public:
    Player() = default;
    int drawCard(Desk &desk);
    int getscore(){
        return score;
    }
    ~Player(){}
};
