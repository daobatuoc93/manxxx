#include"Player.hpp"
#include "Card.hpp"

int Player::drawCard(Desk &desk)
{
    score += (desk.dealCard().rank);
    return score;
}