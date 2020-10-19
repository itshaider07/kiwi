#include <iostream>
#include <ctime> 

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << "  secure room ... \nEnter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

   //Declare the 3 codes 
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //Print CodeSum and CodeProduct to the terminal
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+There are 3 numbers in the code";
    std::cout << "\n+The 3 codes add upto" << CodeSum ;
    std::cout << "\n+The codes multiply to give " << CodeProduct << std::endl ;

    //Store Player Guess
    int GuessA, GuessB , GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC ;

    //Check If the player's message is correct
    if(CodeSum==GuessSum && CodeProduct==GuessProduct)
    {
        std::cout << "\n*** Well done agent! You Have Extracted a file! Keep going ! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You Entered the wrong code ! Careful agent! Try again! ***";
        return false;
    } 
    
}
int main()
{
    srand(time(NULL)); //create new random sequence based on the time of the day 
     int LevelDifficulty = 1;
     int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer  

        if (bLevelComplete)
        {
           ++LevelDifficulty;
        }
        
    }
    std::cout <<"\n*** Great work agent ! You have got all the files ! Now get out of there ! ***\n";
    return 0;
}
