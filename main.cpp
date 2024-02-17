#include <iostream>
#include <random>

using namespace std;

int RandomNumber(int range);
string SuccessMessage(int numberOfTries, const string &winnerName);

const string DifficultiesInWords[] = {"Easy", "Medium", "Hard"};

const int Difficulties[][3] = {{0, 100, 10}, {1, 50, 5}, {2, 20, 3}};

int main(void)
{

    int Difficulty, maxGuesses, secretNumber, userGuess;
    string userName;

    // Welcome message
    cout << "\nWelcome to the Guessing Game!\n";

    // Get player's name
    cout << "What is your name? ";
    cin >> userName;

    // Display available difficulty levels
    cout << "This game has 3 levels \n";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ") " << DifficultiesInWords[Difficulties[i][0]] << endl;
    }

    // Choose difficulty level
    cout << "Choose(1-3): ";
    do
    {
        cin >> Difficulty;
        if (Difficulty < 1 || Difficulty > 3)
            cout << "Invalid difficulty level." << endl
                 << "Try again: ";
    } while ((Difficulty < 1 || Difficulty > 3));

    // Set game parameters based on chosen difficulty
    maxGuesses = Difficulties[Difficulty - 1][2];
    secretNumber = RandomNumber(Difficulties[Difficulty - 1][1]);

    // Display game information
    cout << "You have " << maxGuesses << " guesses to find a number between 1 and " << Difficulties[Difficulty - 1][1] << ".\n";

    // Guessing loop
    int i;
    for (i = 1; i <= maxGuesses; i++)
    {
        do
        {
            // Get user's guess
            cout << "Enter your guess: ";
            cin >> userGuess;
            if (!(userGuess >= 1 && userGuess <= Difficulties[Difficulty - 1][1]))
                cout << "Invalid Input.\nTry again.\n";
        } while (!(userGuess >= 1 && userGuess <= Difficulties[Difficulty - 1][1]));

        // Check if the guess is correct and provide feedback
        if (userGuess == secretNumber)
            break;
        else if (userGuess > secretNumber)
        {
            cout << "Your guess is higher than the secret number.\n";
            if (i < maxGuesses)
                cout << "Try a lower number.\n";
        }
        else if (userGuess < secretNumber)
        {
            cout << "Your guess is lower than the secret number.\n";
            if (i < maxGuesses)
                cout << "Try a higher number.\n";
        }
    }
    // Display the result based on the number of guesses
    if (i <= maxGuesses)
        if ((maxGuesses == 3 && i == 3) || (maxGuesses == 5 && i == 5))
            cout << SuccessMessage(11, userName);
        else
            cout << SuccessMessage(i, userName);
    else
    {
        cout << "Oh no, " << userName << "! It seems you didn't win this time.\n";
        cout << "The secret number is " << secretNumber;
    }

    return 0;
}

// Generate a random number within the specified range
int RandomNumber(int range)
{
    // Seed the random number generator with better randomness
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(1, range);

    return distribution(generator);
}

// Generate success message based on the number of tries
string SuccessMessage(int numberOfTries, const string &winnerName)
{
    const string messages[] = {
        "**MIND BLOWN, " + winnerName + "!!** You won in just ONE guess?!  Unbelievable!",
        "WOW, " + winnerName + ", you cracked it in only TWO guesses!  That's impressive!",
        "Amazing job, " + winnerName + "! You figured it out in just THREE guesses!",
        "Impressive win, " + winnerName + "! You solved it in FOUR guesses!",
        "Great victory, " + winnerName + "! It took you FIVE guesses, a solid win!",
        "Congrats, " + winnerName + "! You won in SIX guesses! Keep up the strategic thinking!",
        "Well done, " + winnerName + "! You achieved victory in SEVEN guesses!",
        "Nice win, " + winnerName + "! You figured it out in EIGHT guesses!",
        "Congratulations, " + winnerName + "! You won in NINE guesses! Persistence pays off!",
        winnerName + ", you won!  It took you TEN guesses, but a win is a win!",
        "**Clutch victory, " + winnerName + "!** You saved the day with your final guess! That was an epic last-guess win!"};

    return messages[numberOfTries - 1];
}
