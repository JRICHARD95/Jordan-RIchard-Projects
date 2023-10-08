#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

/*
Author: Richard, Jordan
Assignment: Capstone
Course: COMP B12
Instructor: Richard Miles
Date submitted: 2022/11/27
*/





int balance = 1000; // This global variable sets the user's balance to 1000 

class Blackjack {
    public:
        void welcomeToBlackJack();
        void deckCards(string randomCard, int numberCard);
        void dealerDeckCards(string dealerRandom, int dealerNumberCard);
        void hitDeckCards(string oneCard);
        void dealerHitDeckCards(string dealerOneCard);
        bool blackJackContinue();
        string randCard();
        int numCard();
        string dealerRandCard();
        int dealerNumCard();
        string newCard();
        string dealerNewCard();
        void blackJackIntro(string repeat);
        void blackJackGame(int blackJackTotal, int dealerBlackJackTotal);
        int blackJackValue();
        int dealerBlackValue();
        int dealerBlackJackValue();
        
    private:
        string hit;
        string dealerHit;
        string card;
        string cont;
        int num;
        string dealerCard;
        int dealerNum;
        int bjTotal;
        int dbjTotal;
};

void Blackjack::welcomeToBlackJack() { // This is the welcome message that starts onces the user runs the code.
    string gameChoice;
    
    cout << "Hello, and welcome to C++ Blackjack!" << endl;
    cout << "Your starting balance will be " << balance << ", and the game will end if you either reach a balance of $5,000 or if you balance ends in less than 0" << endl;
    cout << "Type 1 to play Blackjack." << endl;
    cout << ">>";
    
    while (gameChoice != "1") { // This loop starts the game of blackjack when 1 is typed.
        cin >> gameChoice;
        
        if (gameChoice == "1") {
            cout << endl << "Here is a short tutorial of the game." << endl;
        }
        
        else {
            cout << endl << "Invalid input, try again." << endl;
            cout << "Type 1 to play Blackjack." << endl;
            cout << ">>";
        }
    }
}

void Blackjack::deckCards(string randomCard, int numberCard) { // This Function holds the users deck of cards.
    srand(time(0));
    string deck[4][13]; // Array of user's card names.
    int numDeck[4][13]; // Array of user's card values.
    
    int s = rand()%4;
    int n = rand()%13;
    
    deck[0][0] = "Ace of Spades";
    deck[0][1] = "Two of Spades";
    deck[0][2] = "Three of Spades";
    deck[0][3] = "Four of Spades";
    deck[0][4] = "Five of Spades";
    deck[0][5] = "Six of Spades";
    deck[0][6] = "Seven of Spades";
    deck[0][7] = "Eight of Spades";
    deck[0][8] = "Nine of Spades";
    deck[0][9] = "Ten of Spades";
    deck[0][10] = "Jack of Spades";
    deck[0][11] = "Queen of Spades";
    deck[0][12] = "King of Spades";
    deck[1][0] = "Ace of Hearts";
    deck[1][1] = "Two of Hearts";
    deck[1][2] = "Three of Hearts";
    deck[1][3] = "Four of Hearts";
    deck[1][4] = "Five of Hearts";
    deck[1][5] = "Six of Hearts";
    deck[1][6] = "Seven of Hearts";
    deck[1][7] = "Eight of Hearts";
    deck[1][8] = "Nine of Hearts";
    deck[1][9] = "Ten of Hearts";
    deck[1][10] = "Jack of Hearts";
    deck[1][11] = "Queen of Hearts";
    deck[1][12] = "King of Hearts";
    deck[2][0] = "Ace of Clubs";
    deck[2][1] = "Two of Clubs";
    deck[2][2] = "Three of Clubs";
    deck[2][3] = "Four of Clubs";
    deck[2][4] = "Five of Clubs";
    deck[2][5] = "Six of Clubs";
    deck[2][6] = "Seven of Clubs";
    deck[2][7] = "Eight of Clubs";
    deck[2][8] = "Nine of Clubs";
    deck[2][9] = "Ten of Clubs";
    deck[2][10] = "Jack of Clubs";
    deck[2][11] = "Queen of Clubs";
    deck[2][12] = "King of Clubs";
    deck[3][0] = "Ace of Diamonds";
    deck[3][1] = "Two of Diamonds";
    deck[3][2] = "Three of Diamonds";
    deck[3][3] = "Four of Diamonds";
    deck[3][4] = "Five of Diamonds";
    deck[3][5] = "Six of Diamonds";
    deck[3][6] = "Seven of Diamonds";
    deck[3][7] = "Eight of Diamonds";
    deck[3][8] = "Nine of Diamonds";
    deck[3][9] = "Ten of Diamonds";
    deck[3][10] = "Jack of Diamonds";
    deck[3][11] = "Queen of Diamonds";
    deck[3][12] = "King of Diamonds";
    
    numDeck[0][0] = 1;
    numDeck[0][1] = 2;
    numDeck[0][2] = 3;
    numDeck[0][3] = 4;
    numDeck[0][4] = 5;
    numDeck[0][5] = 6;
    numDeck[0][6] = 7;
    numDeck[0][7] = 8;
    numDeck[0][8] = 9;
    numDeck[0][9] = 10;
    numDeck[0][10] = 10;
    numDeck[0][11] = 10;
    numDeck[0][12] = 10;
    numDeck[1][0] = 1;
    numDeck[1][1] = 2;
    numDeck[1][2] = 3;
    numDeck[1][3] = 4;
    numDeck[1][4] = 5;
    numDeck[1][5] = 6;
    numDeck[1][6] = 7;
    numDeck[1][7] = 8;
    numDeck[1][8] = 9;
    numDeck[1][9] = 10;
    numDeck[1][10] = 10;
    numDeck[1][11] = 10;
    numDeck[1][12] = 10;
    numDeck[2][0] = 1;
    numDeck[2][1] = 2;
    numDeck[2][2] = 3;
    numDeck[2][3] = 4;
    numDeck[2][4] = 5;
    numDeck[2][5] = 6;
    numDeck[2][6] = 7;
    numDeck[2][7] = 8;
    numDeck[2][8] = 9;
    numDeck[2][9] = 10;
    numDeck[2][10] = 10;
    numDeck[2][11] = 10;
    numDeck[2][12] = 10;
    numDeck[3][0] = 1;
    numDeck[3][1] = 2;
    numDeck[3][2] = 3;
    numDeck[3][3] = 4;
    numDeck[3][4] = 5;
    numDeck[3][5] = 6;
    numDeck[3][6] = 7;
    numDeck[3][7] = 8;
    numDeck[3][8] = 9;
    numDeck[3][9] = 10;
    numDeck[3][10] = 10;
    numDeck[3][11] = 10;
    numDeck[3][12] = 10;
    
    randomCard = deck[s][n];
    card = randomCard;
    
    numberCard = numDeck[s][n];
    num = numberCard;
}

void Blackjack::dealerDeckCards(string dealerRandomCard, int dealerNumberCard) { // This Function holds the users deck of cards. This Function exist to ensure that the Dealer's cards are difference from the user's.
    srand(time(0));
    string dealerDeck[4][13]; // Array of Dealer's card names.
    int dealerNumDeck[4][13]; // Array of Dealer's card values.
    
    int ds = rand()%4;
    int dn = rand()%13;
    
    dealerDeck[0][0] = "Ace of Spades";
    dealerDeck[0][1] = "Two of Spades";
    dealerDeck[0][2] = "Three of Spades";
    dealerDeck[0][3] = "Four of Spades";
    dealerDeck[0][4] = "Five of Spades";
    dealerDeck[0][5] = "Six of Spades";
    dealerDeck[0][6] = "Seven of Spades";
    dealerDeck[0][7] = "Eight of Spades";
    dealerDeck[0][8] = "Nine of Spades";
    dealerDeck[0][9] = "Ten of Spades";
    dealerDeck[0][10] = "Jack of Spades";
    dealerDeck[0][11] = "Queen of Spades";
    dealerDeck[0][12] = "King of Spades";
    dealerDeck[1][0] = "Ace of Hearts";
    dealerDeck[1][1] = "Two of Hearts";
    dealerDeck[1][2] = "Three of Hearts";
    dealerDeck[1][3] = "Four of Hearts";
    dealerDeck[1][4] = "Five of Hearts";
    dealerDeck[1][5] = "Six of Hearts";
    dealerDeck[1][6] = "Seven of Hearts";
    dealerDeck[1][7] = "Eight of Hearts";
    dealerDeck[1][8] = "Nine of Hearts";
    dealerDeck[1][9] = "Ten of Hearts";
    dealerDeck[1][10] = "Jack of Hearts";
    dealerDeck[1][11] = "Queen of Hearts";
    dealerDeck[1][12] = "King of Hearts";
    dealerDeck[2][0] = "Ace of Clubs";
    dealerDeck[2][1] = "Two of Clubs";
    dealerDeck[2][2] = "Three of Clubs";
    dealerDeck[2][3] = "Four of Clubs";
    dealerDeck[2][4] = "Five of Clubs";
    dealerDeck[2][5] = "Six of Clubs";
    dealerDeck[2][6] = "Seven of Clubs";
    dealerDeck[2][7] = "Eight of Clubs";
    dealerDeck[2][8] = "Nine of Clubs";
    dealerDeck[2][9] = "Ten of Clubs";
    dealerDeck[2][10] = "Jack of Clubs";
    dealerDeck[2][11] = "Queen of Clubs";
    dealerDeck[2][12] = "King of Clubs";
    dealerDeck[3][0] = "Ace of Diamonds";
    dealerDeck[3][1] = "Two of Diamonds";
    dealerDeck[3][2] = "Three of Diamonds";
    dealerDeck[3][3] = "Four of Diamonds";
    dealerDeck[3][4] = "Five of Diamonds";
    dealerDeck[3][5] = "Six of Diamonds";
    dealerDeck[3][6] = "Seven of Diamonds";
    dealerDeck[3][7] = "Eight of Diamonds";
    dealerDeck[3][8] = "Nine of Diamonds";
    dealerDeck[3][9] = "Ten of Diamonds";
    dealerDeck[3][10] = "Jack of Diamonds";
    dealerDeck[3][11] = "Queen of Diamonds";
    dealerDeck[3][12] = "King of Diamonds";
    
    dealerNumDeck[0][0] = 1;
    dealerNumDeck[0][1] = 2;
    dealerNumDeck[0][2] = 3;
    dealerNumDeck[0][3] = 4;
    dealerNumDeck[0][4] = 5;
    dealerNumDeck[0][5] = 6;
    dealerNumDeck[0][6] = 7;
    dealerNumDeck[0][7] = 8;
    dealerNumDeck[0][8] = 9;
    dealerNumDeck[0][9] = 10;
    dealerNumDeck[0][10] = 10;
    dealerNumDeck[0][11] = 10;
    dealerNumDeck[0][12] = 10;
    dealerNumDeck[1][0] = 1;
    dealerNumDeck[1][1] = 2;
    dealerNumDeck[1][2] = 3;
    dealerNumDeck[1][3] = 4;
    dealerNumDeck[1][4] = 5;
    dealerNumDeck[1][5] = 6;
    dealerNumDeck[1][6] = 7;
    dealerNumDeck[1][7] = 8;
    dealerNumDeck[1][8] = 9;
    dealerNumDeck[1][9] = 10;
    dealerNumDeck[1][10] = 10;
    dealerNumDeck[1][11] = 10;
    dealerNumDeck[1][12] = 10;
    dealerNumDeck[2][0] = 1;
    dealerNumDeck[2][1] = 2;
    dealerNumDeck[2][2] = 3;
    dealerNumDeck[2][3] = 4;
    dealerNumDeck[2][4] = 5;
    dealerNumDeck[2][5] = 6;
    dealerNumDeck[2][6] = 7;
    dealerNumDeck[2][7] = 8;
    dealerNumDeck[2][8] = 9;
    dealerNumDeck[2][9] = 10;
    dealerNumDeck[2][10] = 10;
    dealerNumDeck[2][11] = 10;
    dealerNumDeck[2][12] = 10;
    dealerNumDeck[3][0] = 1;
    dealerNumDeck[3][1] = 2;
    dealerNumDeck[3][2] = 3;
    dealerNumDeck[3][3] = 4;
    dealerNumDeck[3][4] = 5;
    dealerNumDeck[3][5] = 6;
    dealerNumDeck[3][6] = 7;
    dealerNumDeck[3][7] = 8;
    dealerNumDeck[3][8] = 9;
    dealerNumDeck[3][9] = 10;
    dealerNumDeck[3][10] = 10;
    dealerNumDeck[3][11] = 10;
    dealerNumDeck[3][12] = 10;
    
    dealerRandomCard = dealerDeck[ds][dn];
    dealerCard = dealerRandomCard;
    
    dealerNumberCard = dealerNumDeck[ds][dn];
    dealerNum = dealerNumberCard;
}
    
void Blackjack::hitDeckCards(string oneCard) {
    hit = oneCard;
}

void Blackjack::dealerHitDeckCards(string dealerOneCard) {
    dealerHit = dealerOneCard;
}

string Blackjack::randCard() {
    return card;
}

int Blackjack::numCard() {
    return num;
}

string Blackjack::dealerRandCard() {
    return dealerCard;
}

int Blackjack::dealerNumCard() {
    return dealerNum;
}

string Blackjack::newCard() {
    return hit;
}

string Blackjack::dealerNewCard() {
    return dealerHit;
}

int Blackjack::blackJackValue() {
    return bjTotal;
}

int Blackjack::dealerBlackValue() {
    return dbjTotal;
}

void Blackjack::blackJackIntro(string repeat) { // This Function notifies the user of the general rules of Blackjack, along with some special stipulations.
    while (repeat != "2") {
        cout << "Welcome to BlackJack, in this game you'll be playing against the Dealer to see which one of you hits either 21 or over 21." << endl;
        cout << "If you or the Dealer reaches 21, then the individual that hits 21 first win." << endl;
        cout << "Also if you or the Dealer goes over 21, then that individual loses." << endl;
        cout << "The Dealer can not hit for more cards if their total is or reaches 17 or more" << endl;
        cout << "Blackjack at pays 3 to 2 odds." << endl;
        cout << "To ensure that the game doesn't get exploited by placing low bets..." << endl;
        cout << "Every hand that you win, you win receive an extra $50 to your balance." << endl;
        cout << "But for every hand that you lose, you will lose $51." << endl << endl;
        cout << "If you would like the rules of BlackJack to be repeated..." << endl;
        cout << "Type 1. If not, Type 2." << endl;
        cout << ">>";
        
        cin >> repeat;
        
        if (repeat == "1") {
            cout << endl << "Okay, from the top." << endl << endl;
        }
        else if (repeat == "2") {
            cout << endl << "Good Luck!" << endl << endl;
        }
        else {
            cout << endl << "Invalid input, try again." << endl << endl;
        }
    }
}

void Blackjack::blackJackGame(int blackJackTotal, int dealerBlackJackTotal) { // The game of Blackjack and the heart of this program.
    srand(time(0));
    bjTotal = blackJackTotal;
    dbjTotal = dealerBlackJackTotal;
    bjTotal = 0;
    dbjTotal = 0;
    
    int oneOrEleven;
    int bet;
    int balanceCheck = 1;
    int dealer = 0;
    
    cout << "How much do you want to bet?" << endl; // This is where the user inputs how much of their balance they want to bet.
    cout << ">>$";
    
    while (balanceCheck == 1) {
        cin >> bet;
        
        if (bet > balance) {
            cout << endl << "Invalid input, try again." << endl << endl;
            cout << "How much do you want to bet?" << endl;
            cout << ">>$";
        }
        
        else {
            balance -= bet;
            cout << endl << "Your current Balance is $" << balance << endl;
            break;
        }
    }
    
    cout << "Press 1 to reveal the Dealer's first card." << endl; // This starts the dealer's first card.
    cout << ">>";
    
    while (dealer != 1) {
        cin >> dealerHit;
        dealerDeckCards(dealerCard, dealerNum);
        dealerHitDeckCards(dealerHit);
        
        if (dealerHit == "1") {
    
            cout << endl << "Dealer's first card is ";
            cout << dealerCard << endl;
            
            if (((dealerCard == "Ace of Spades") || (dealerCard == "Ace of Hearts") || (dealerCard == "Ace of Clubs") || (dealerCard == "Ace of Diamonds")) && (dbjTotal <= 10)) {
                dealerNum = 11;
            }
            
            dbjTotal += dealerNum;
            cout << "You: " << bjTotal << endl;
            cout << "Dealer: " << dbjTotal << endl;
            dealer = 1;
        }
    
            else {
                cout << endl << "Invalid input, try again." << endl << endl;
                cout << "Press 1 to reveal the Dealer's first card." << endl;
                cout << ">>";
        }
    }
    
    dealer = 0;        
    
    cout << "Type 1 to draw your first card." << endl; // This starts the user's first hand
    cout << ">>";
    
    while (((bjTotal < 21) && (dbjTotal < 17)) || ((balance > 0) || (balance < 5000))) { // This is the main loop that plays the rest of the hand.
        cin >> hit;
        cout << endl << endl;
        deckCards(card, num);
        hitDeckCards(hit);
            
            if (hit == "1") { // When the user types 1, they hit for another card.
            
                cout << "Your card is ";
                cout << card << " " << endl; 
                
                while ((card == "Ace of Spades") || (card == "Ace of Hearts") || (card == "Ace of Clubs") || (card == "Ace of Diamonds")) { // This loop allows the user to decide if their Ace is worth 1 or 11.
                    if ((card == "Ace of Spades") || (card == "Ace of Hearts") || (card == "Ace of Clubs") || (card == "Ace of Diamonds")) {
                        cout << endl << "You have drawn an Ace!" << endl;
                        cout << "Would you like you Ace to be an One or an Eleven?" << endl;
                        cout << "Type 1, if you want it to be 1 or type 11, if you want it to be eleven" << endl;
                        cout << ">>";
                        cin >> oneOrEleven;
                        
                        if (oneOrEleven == 1) {
                            num = 1;
                            cout << card << " " << endl;
                            break;
                        }
                
                        else if (oneOrEleven == 11) {
                            num = 11;
                            cout << card << " " << endl;
                            break;
                        }
                
                        else {
                            cout << "Invalid input, try again." << endl << endl;
                        }
                    }
                }
                
                cout << endl;
                bjTotal += num;
                cout << "You: " << bjTotal << endl;
                cout << "Dealer: " << dbjTotal << endl;
                
                if (bjTotal == 21) { // If the user card total is 21, they win.
                    cout << endl << "21! You win!" << endl;
                    balance = balance + (bet * 2) + 50;
                    cout << "Your current balance is $" << balance << endl;
                    break;
                }
                
                else if (bjTotal > 21) { // If the user card total is over 21, the Dealer wins.
                    cout << endl << "Dealer wins! You lose..." << endl;
                    balance = balance - 51;
                    cout << "Your current balance is $" << balance << endl;
                    break;
                }
                
                cout << "Type 1 to hit again or type 2 to stand." << endl << ">>"; 
            }    
                    
            else if (hit == "2") { // If the user types 2, then they stand on their card total.
                cout << "You have chosen to stand." << endl;
                cout << "Type 1 repeatedly to finish the Dealer's hand" << endl << ">>";
                
                while ((dealer != 1) && (dbjTotal < 17)) { // This loop ensures that the Dealer doesn't hit over 17.
                    cin >> dealerHit;
                    dealerDeckCards(dealerCard, dealerNum);
                    dealerHitDeckCards(dealerHit);
        
                    if (dealerHit == "1") { // The user has to type 1 to finish the Dealer's hand.
                        
                        cout << endl << "The Dealer has drawn " << dealerCard << endl;
                        
                        if (((dealerCard == "Ace of Spades") || (dealerCard == "Ace of Hearts") || (dealerCard == "Ace of Clubs") || (dealerCard == "Ace of Diamonds")) && (dbjTotal <= 10)) { // If the Dealer draws an Ace and their card total is below 10, then the Ace's value is 11.
                                dealerNum = 11;
                        }
                            
                        dbjTotal += dealerNum;
                        cout << "You: " << bjTotal << endl;
                        cout << "Dealer: " << dbjTotal << endl;
                        cout << ">>";
                    }
                    
                    else if (dealerHit != "1") {
                        cout << endl << "Invalid input, try again." << endl << endl;
                    }
                }
                
                    if (dbjTotal == 21) { // If the Dealer's total is 21, then the Dealer wins.
                        cout << endl << "21! The Dealer wins! You lose..." << endl;
                        balance = balance - 51;
                        cout << "Your current balance is $" << balance << endl;
                        dealer = 1;
                        break;
                    }
                    
                            else if (dbjTotal == bjTotal) { // If the Dealer's total equals the user's, then the hand is tied.
                                cout << endl << "Draw!" << endl;
                                balance = balance + bet;
                                cout << "Your current balance is $" << balance << endl;
                                dealer = 1;
                                break;
                            }
                            
                            else if ((dbjTotal > bjTotal) && (dbjTotal < 21)) { // If the Dealer's hand is greater than the user, then the Dealer wins.
                                cout << endl << "Dealer wins! You Lose..." << endl;
                                balance = balance - 51;
                                cout << "Your current balance is $" << balance << endl;
                                dealer = 1;
                                break;
                            }
                            else if ((dbjTotal < bjTotal) && (dbjTotal >= 17) && (dbjTotal < 21)) { // If the Dealer's hand is less than the user, then the user wins.
                                cout << endl << "You win!" << endl;
                                balance = balance + (bet * 2) + 50;
                                cout << "Your current balance is $" << balance << endl;
                                dealer = 1;
                                break;
                            }
                            else if (dbjTotal > 21) { // If the Dealer's hand is greater than 21, then the user wins.
                                cout << endl << "You win!" << endl;
                                balance = balance + (bet * 2);
                                cout << "Your current balance is $" << balance << endl;
                                dealer = 1;
                                break;
                            }
            }
            
            else {
                cout << "Invalid input, try again." << endl << endl;
            }      
    }
}
    
bool Blackjack::blackJackContinue() { // This Function gives the user the choice between exiting the program, starting a new hand, or getting forced off of the program with a winning or losing statement.
    int cont;

    if ((balance > 0) && (balance < 5000)) { 
        cout << "Would you like to play again?" << endl;
        cout << "Type 1 to continue or any other key to leave" << endl;
        
        cin >> cont;
    }
    
    else if (balance < 0) { 
        cout << "Your balance is below $0..." << endl;
        return false;
    }
    
    else {
        cout << "You beat the Dealer, enjoy your winnings!" << endl;
        return false;
    }
    
    if (cont == 1) {
        
        return true;
    }
    
    else {
        return false;
    }
}

int main() {
    int balance;
    string choice;
    string newCard;
    int intCard;
    string hitCard;
    string instrRepeat;
    int bjT;
    int dbjT;
    bool bjCont = true;
    
    Blackjack main;
    Blackjack blackJack;
    
    main.welcomeToBlackJack();
    
    blackJack.blackJackIntro(instrRepeat);
    
    while (bjCont == true) {
        blackJack.blackJackGame(bjT, dbjT);
        bjCont = blackJack.blackJackContinue();
    }

    return 0;
}
