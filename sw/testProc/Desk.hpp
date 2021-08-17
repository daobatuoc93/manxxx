#include "someClass.hpp"


class Desk
{
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

    void printDeck(const Desk &deck)
    {
        for (const Card &card : deck.deskcard)
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

