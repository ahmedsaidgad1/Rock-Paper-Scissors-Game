#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

enum enGameChoice
{
    Stone    = 1,
    Paper    = 2,
    Scissors = 3
};
enum enWinner
{
    Player   = 1,
    Computer = 2,
    Draw     = 3
};

int RandomNum(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int ReadIntNumber(string Message)
{
    int Number;
    while (true)
    {
        cout << Message;
        cin >> Number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Input! Please enter a number.\n";
        }
        else
        {
            return Number;
        }
    }
}

int NumOfRound()
{
    int round;
    do
    {
        round = ReadIntNumber("Enter number of rounds [ 1 to 10 ] : ");
    } while (round < 1 || round > 10);
    return round;
}

enGameChoice GetComputerChoise()
{
    return (enGameChoice)(RandomNum(1, 3));
}

enGameChoice GetPlayerChoice()
{
    int choice;
    do
    {
        choice = ReadIntNumber("Enter your Choice [1]Stone, [2]Paper, [3]Scissors: ");
    } while (choice < 1 || choice > 3);
    return (enGameChoice)choice;
}

string ChoiceToString(enGameChoice Choice)
{
    switch (Choice)
    {
    case Stone:
        return "Stone";
    case Paper:
        return "Paper";
    case Scissors:
        return "Scissors";
    default:
        return "Unknown";
    }
}

string WinnerToString(enWinner Winner)
{
    switch (Winner)
    {
    case Player:
        return "Player Wins! ";
    case Computer:
        return "Computer Wins! ";
    case Draw:
        return "Draw! ";
    default:
        return "Unknown";
    }
}

enWinner WinnerOfRound(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
    {
        system("color 6F");
        return Draw;
    }
    else if (
        (PlayerChoice == Stone && ComputerChoice == Scissors) ||
        (PlayerChoice == Paper && ComputerChoice == Stone) ||
        (PlayerChoice == Scissors && ComputerChoice == Paper))
    {
        system("color 2F");
        return Player;
    }
    else
    {
        cout << "\a";
        system("color 4F");
        return Computer;
    }
}

void PlayRound(int RoundNumber, int &PlayerScore, int &ComputerScore, int &Draws)
{
    cout << endl;
    cout << "==================== Round [" << RoundNumber << "] ======================" << endl;

    enGameChoice PlayerChoice = GetPlayerChoice();
    enGameChoice ComputerChoice = GetComputerChoise();
    enWinner Winner = WinnerOfRound(PlayerChoice, ComputerChoice);

    cout << "Player choice       : " << ChoiceToString(PlayerChoice) << endl;
    cout << "Computer choice     : " << ChoiceToString(ComputerChoice) << endl;
    cout << "Result              : " << WinnerToString(Winner) << endl;

    if (Winner == Player)
        PlayerScore++;
    else if (Winner == Computer)
        ComputerScore++;
    else
        Draws++;
}

void DisplayFinalResults(int PlayerScore, int ComputerScore, int Draws, int TotalRounds)
{
    cout << "\n";
    cout << "=============================================\n";
    cout << "              GAME OVER - FINAL RESULTS      \n";
    cout << "=============================================\n";
    cout << "Total Rounds Played : " << TotalRounds << endl;
    cout << "---------------------------------------------\n";
    cout << "Player Wins   : " << PlayerScore << endl;
    cout << "Computer Wins : " << ComputerScore << endl;
    cout << "Draws         : " << Draws << endl;
    cout << "---------------------------------------------\n";

    if (PlayerScore > ComputerScore)
    {
        system("color 2F");
        cout << "CONGRATULATIONS! YOU ARE THE FINAL WINNER! .\n";
    }
    else if (PlayerScore < ComputerScore)
    {
        system("color 4F");
        cout << "GAME OVER! THE COMPUTER IS THE FINAL WINNER. .\n";
    }
    else
    {
        system("color 6F");
        cout << "FINAL RESULT: IT'S A DRAW! .\n";
    }
    cout << endl;
}

void StartGame()
{
    int round = NumOfRound();
    int PlayerScore = 0;
    int ComputerScore = 0;
    int Draws = 0;

    for (int i = 1; i <= round; i++)
    {
        PlayRound(i, PlayerScore, ComputerScore, Draws);
    }
    DisplayFinalResults(PlayerScore, ComputerScore, Draws, round);
}

bool AskPlayAgain()
{
    char ask;
    cout << "Do you want to play again? (y/n): ";
    cin >> ask;

    cin.ignore(10000, '\n');

    return (ask == 'y' || ask == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    do
    {
        cout << endl;
        system("color 07");
        StartGame();
    } while (AskPlayAgain());

    return 0;
}