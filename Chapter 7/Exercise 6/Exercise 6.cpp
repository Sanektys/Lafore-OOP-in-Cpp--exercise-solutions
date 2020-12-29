#include <iostream>
#include <iomanip>
#include <ctime>

enum class Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum class Power
{
    JACK = 11,
    QUEEN,
    KING,
    ACE
};

class Card
{
    public :
        Card() : _number(0), _suit(Suit::CLUBS) {}

        void set(int n, Suit s) {
            _number = n;
            _suit = s;
        }
        void display() const;

    private :
        int _number;
        Suit _suit;
};

void Card::display() const {
    std::cout << std::resetiosflags(std::ios::left);
    if (_number >= 2 && _number <= 10)
        std::cout << std::setw(2) << _number;
    else {
        switch (_number) {
            case (int)Power::JACK :
                std::cout << std::setw(2) << 'J';
                break;
            case (int)Power::QUEEN :
                std::cout << std::setw(2) << 'Q';
                break;
            case (int)Power::KING :
                std::cout << std::setw(2) << 'K';
                break;
            case (int)Power::ACE :
                std::cout << std::setw(2) << 'A';
                break;
        }
    }
        
    std::cout << std::setiosflags(std::ios::left);
    switch (_suit) {
        case Suit::CLUBS :
            std::cout << std::setw(3) << 'C';
            break;
        case Suit::DIAMONDS :
            std::cout << std::setw(3) << 'D';
            break;
        case Suit::HEARTS :
            std::cout << std::setw(3) << 'H';
            break;
        case Suit::SPADES :
            std::cout << std::setw(3) << 'S';
            break;
    }
    
}

void showCard(const Card[], int);
void showGroupCard(const Card[][13],
                   int GROUP_SIZE = 4, int SUB_GROUP_SIZE = 13);

int main() {
    const int DECK_SIZE = 52;
    Card deck[DECK_SIZE];
    
    for (int i = 0; i < DECK_SIZE; i++) {
        int number = (i % 13) + 2;
        Suit suit = Suit(i / 13);
        deck[i].set(number, suit);
    }

    std::cout << "Source deck:\n";
    showCard(deck, DECK_SIZE);

    srand(time(NULL));
    const int GROUP_SIZE = 4;
    const int SUB_GROUP_SIZE = 13;
    Card groupDeck[GROUP_SIZE][SUB_GROUP_SIZE];

    for (int i = 0; i < DECK_SIZE; i++) {
        int c = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[c];
        deck[c] = temp;
    }

    for (int i = 0; i < DECK_SIZE; i++) {
        switch (i / 13) {
            case 0 :
                groupDeck[0][i % 13] = deck[i];
                break;
            case 1 :
                groupDeck[1][i % 13] = deck[i];
                break;
            case 2 :
                groupDeck[2][i % 13] = deck[i];
                break;
            case 3 :
                groupDeck[3][i % 13] = deck[i];
                break;
        }
    }

    std::cout << "\nMixed deck:\n";
    showGroupCard(groupDeck, GROUP_SIZE, SUB_GROUP_SIZE);

    return 0;
}

void showCard(const Card deck[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        deck[i].display();
        if (!((i + 1) % 13))
            std::cout << std::endl;
    }
}

void showGroupCard(const Card groupDeck[][13],
                   const int FIRST_SIZE, const int SECOND_SIZE) {
    for (int i = 0; i < FIRST_SIZE; i++) {
        std::cout << "Group " << i + 1 << ": ";
        for (int j = 0; j < SECOND_SIZE; j++)
            groupDeck[i][j].display();
        std::cout << std::endl;
    }
}