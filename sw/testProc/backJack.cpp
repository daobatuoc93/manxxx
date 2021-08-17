#include "someClass.hpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

class Card
{
public:
    enum CardRank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };
    enum CardSuit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

private:
    CardRank rank{};
    CardSuit suit{};

public:
    Card() = default;
    Card(Card::CardRank crank, Card::CardSuit csuit)
    {
        rank = crank;
        suit = csuit;
    }
    void print() const
    {
        switch (suit)
        {
        case rank_2:
            std::cout << '2';
            break;
        case rank_3:
            std::cout << '3';
            break;
        case rank_4:
            std::cout << '4';
            break;
        case rank_5:
            std::cout << '5';
            break;
        case rank_6:
            std::cout << '6';
            break;
        case rank_7:
            std::cout << '7';
            break;
        case rank_8:
            std::cout << '8';
            break;
        case rank_9:
            std::cout << '9';
            break;
        case rank_10:
            std::cout << 'T';
            break;
        case rank_jack:
            std::cout << 'J';
            break;
        case rank_queen:
            std::cout << 'Q';
            break;
        case rank_king:
            std::cout << 'K';
            break;
        case rank_ace:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
        }

        switch (suit)
        {
        case CardSuit::club:
            std::cout << 'C';
            break;
        case CardSuit::diamond:
            std::cout << 'D';
            break;
        case CardSuit::heart:
            std::cout << 'H';
            break;
        case CardSuit::spade:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
            break;
        }
    }

    int value() const
    {
        switch (rank)
        {
        case rank_2:
            return 2;
        case rank_3:
            return 3;
        case rank_4:
            return 4;
        case rank_5:
            return 5;
        case rank_6:
            return 6;
        case rank_7:
            return 7;
        case rank_8:
            return 8;
        case rank_9:
            return 9;
        case rank_10:
            return 10;
        case rank_jack:
            return 10;
        case rank_queen:
            return 10;
        case rank_king:
            return 10;
        case rank_ace:
            return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }

    int getRank()
    {
        return rank;
    }
};

class Desk
{
public:
    using deck_type = std::array<Card, 52>;
    using deck_size = std::array<Card, 52>::size_type;

private:
    deck_type deskcard{};
    deck_size sizedesk{};
    int m_cardIndex{0};

public:
    Desk()
    {
        for (int suit{0}; suit < static_cast<int>(Card::CardSuit::max_suits); ++suit)
        {
            for (int rank{0}; rank < static_cast<int>(Card::CardRank::max_ranks); ++rank)
            {
                deskcard[sizedesk] = {static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit)};
                ++sizedesk;
            }
        }
    }

    void shuffleDeck()
    {
        static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

        std::shuffle(deskcard.begin(), deskcard.end(), mt);
    }

    void printDeck()
    {
        for (const Card &card : deskcard)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    const Card &dealCard()
    {
        assert(m_cardIndex < sizedesk);
        return deskcard[m_cardIndex++];
    }
    ~Desk() {}
};


class Player
{
private:
    int score{0};

public:
    Player() = default;
    int drawCard(Desk &desk)
    {
        score += desk.dealCard().value();
        return score;
    }
    int getscore()
    {
        return score;
    }
    ~Player() {}
};

// Maximum score before losing.
constexpr int maximumScore{21};

// Minimum score that the dealer has to have.
constexpr int minimumDealerScore{17};

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Desk &deck, Player &player)
{
    while (true)
    {
        if (player.getscore() > maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                player.drawCard(deck);
                std::cout << " now have " << player.getscore() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Desk &deck, Player &dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.getscore() < minimumDealerScore)
    {
        dealer.drawCard(deck);
        std::cout << " now has " << dealer.getscore() << '\n';
    }

    // If the dealer's score is too high, they went bust.
    if (dealer.getscore() > maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Desk &deck)
{
    // Create the dealer and give them 1 card.
    Player dealer{};

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.drawCard(deck) << '\n';

    // Create the player and give them 2 cards.
    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    std::cout << "You have: " << player.getscore() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.getscore() > dealer.getscore());
}

int main()
{
    Desk deck{};

    deck.shuffleDeck();
    deck.printDeck();
    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
    return 0;
}