#include <iostream>
using namespace std;

const int NUMBER_OF_CARDS = 52;

void createCards(int cards[], int numberOfCards){
    for (int i = 0; i < numberOfCards; i++){
        cards[i] = i;
    }
}

void shuffleCards(int cards[], int numberOfCards){
    for (int i = 0; i < numberOfCards; i++){
        int firstCard = rand() % (numberOfCards - 1);
        int secondCard = rand() % (numberOfCards - 1);
        int tmp = cards[firstCard];
        cards[firstCard] = cards[secondCard];
        cards[secondCard] = tmp;
    }
}

int dealCards(int cards[], int &remainCards){
    int returnCard = cards[remainCards - 1];
    remainCards--;
    return returnCard;
}

void PrintCard(int cardSuit, int cardNumber){
    switch(cardSuit){
        case 1:
            cout << "S";
            break;
        case 2:
            cout << "H";
            break;
        case 3:
            cout << "D";
            break;
        case 4:
            cout << "C";
            break;
    }
    switch(cardNumber){
        case 1:
            cout << "A ";
            break;
        case 11:
            cout << "J ";
            break;
        case 12:
            cout << "Q ";
            break;
        case 13:
            cout << "K ";
            break;
        default:
            cout << cardNumber << " ";
            break;
    }
}

int main(){
    int cards[NUMBER_OF_CARDS];
    int totalCards = NUMBER_OF_CARDS;
    int s;
    cin >> s;
    srand(s);
    createCards(cards, totalCards);
    shuffleCards(cards, totalCards);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            int x = dealCards(cards, totalCards);
            PrintCard(x / 13 + 1, x % 13 + 1);
        }
        cout << endl;
    }
    return 0;
}