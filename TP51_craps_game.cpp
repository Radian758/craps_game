//
//  Adrian Vazquez
//  CSCI 40
//  TP51 Craps Game
//  This program allows the user to play Craps as long as he/she wants and displays the # of games they won when they quit.

// ---- Algorithm ----
//  Define accumulators, variables to be used in point round, variables used in the initial round
//  Define variables to store user input
//  Seed based on system time
//  Display greeting
//  Do-while loop
//      set hasPoint to false
//      set rollCount to 0
//      increment totalGames
//      display totalGames
//      roll dice
//      display diceSum
//      If diceSum is equal to 7 or 11
//          display 'You Win'
//          increment wins
//      End if
//      Else if diceSum is equal to 2, 3, or 12
//          display 'You Lose'
//      End else if
//      Else
//          assign diceSum to point
//          display point (i.e. the established point)
//          set hasPoint to true
//      End else
//      If hasPoint is true
//          display "Point Round has begun!"
//          Do-while loop
//              assign rollDice return value to ptDiceSum
//              increment rollCount
//              display rollCount
//              display ptDiceSum
//              If ptDiceSum is equal to 7
//                  display "You Lose"
//              End if
//              Else if ptDiceSum is equal to point
//                  display "You Win"
//                  increment wins
//              End else if
//          End do-while (if ptDiceSum is not equal to point and not equal to 7)
//      End if
//      ask user if they wish to play again
//      uppercase user input
//  End do-while (if choice is equal to 'Y')
//  display wins and win loss ratio
//  display "Thanks for playing"


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
using namespace std;

// ---- Function Prototypes ----
void greeting();
int rollDice();
void repeat (char &);
void displayWinLoss(const int, const int);

// ---- Main ----
int main()
{
    int diceSum,   // sum of dice in intial round
        ptDiceSum, // sum of dice during *point round*
        point, // the established point
        rollCount,     // keep track of rolls during *point round*
        totalGames = 0, // keep track of # of games
        wins = 0;   // keep track of wins
    bool hasPoint;    // to be used to determine whether a point has been established
    char choice, // to repeat game
    
    srand(time(NULL)); // seeding
    
    greeting();
    
    // create game loop
    do
    {
        hasPoint = false;
        rollCount = 0;
        totalGames++;
        
        cout << "\nGame: " << totalGames << endl;
        cout << "----------\n";
        cout << "Rolling...\n";
        
        diceSum = rollDice();
        
        cout << "\n\t\tRollTotal = " << diceSum << endl;
        
        if (diceSum == 7 || diceSum == 11) // win on first roll
        {
            cout << "Natural! You Win!\n";
            wins++;
        }

        else if (diceSum == 2 || diceSum == 3 || diceSum == 12) // lose on first roll
            cout << "Craps! You Lose\n";

        else
        {
            point = diceSum;
            cout << "The point has been established as: " << point << endl;
            hasPoint = true; // point has been established
        }
    
        // if the point has been established and user wishes to continue
        if (hasPoint)
        {
            cout << "------------------------------\n";
            cout << "The Point Round has now begun!\n";
            cout << "------------------------------\n";
            do
            {
                rollCount++; // increment for each roll
                cout << "Roll " << rollCount << ": ";
                ptDiceSum = rollDice();
                cout << "\n\t\tRollTotal = " << ptDiceSum << endl;
                
                if (ptDiceSum == 7) // roll equal to 7
                    cout << "You Lose\n";
          
                else if (ptDiceSum == point) // roll is equal to established point
                {
                    cout << "You Win!\n";
                    wins++;
                }
                
            } while(ptDiceSum != point && ptDiceSum != 7);
        }
        repeat(choice);
    } while(choice == 'Y'); // end game loop
    
    displayWinLoss(wins, totalGames);
    cout << "\nThanks for playing!\n";
    return 0;
}

// ---- Function Definitions ----

void greeting()
{
    cout << "*************************************************\n";
    cout << "********  Welcome to the Zhu Que Casino  ********\n";
    cout << "*** Step up to the table and place your bets! ***\n";
    cout << "*************************************************\n";
}

// displays # of games won and win loss ratio
void displayWinLoss(const int winCount, const int gameCount)
{
    cout << setprecision(3) << fixed;
    cout << "\nYou won " << winCount << " out of " << gameCount << " games\n";
    cout << "Your Win/Loss Ratio is: " << static_cast<double>(winCount) / gameCount << endl;
}

int rollDice()
{
    int die1, die2, sum;
    
    // any # from 1-6
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    
    cout << "You rolled a " << die1 << " and a " << die2;
    // any % from 2-12
    sum = die1 + die2;
    return sum;
}

// uppercases user input
void repeat (char &finalC)
{
    cout << "Do you want to play again? (y/n): ";
    cin >> finalC;
    finalC = toupper(finalC);
}

