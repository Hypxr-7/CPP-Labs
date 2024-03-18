#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <unistd.h>

#define BLUE std::cout << "\033[0;34m";
#define RED std::cout << "\033[0;31m";
#define WHITE std::cout << "\033[0;37m";

void print_slow(const std::string& str, int speed);

class Hangman {
private:
    std::vector<std::string> words;
    std::vector<char> guessedLetters;
    std::string word;
    bool won;
    bool lost;
    int wrongGuesses;
    std::string guessedWord;
    const std::string m_hangman_art[7] = {
        " +---+\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/    |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/ \\  |\n"
        "     |\n"
        "=========="
    };

    std::vector<std::string> GetWordsFromFile();
    char CheckValidLetter();
    void DrawHangman();
    void HandleGuess(char guess);
    bool CheckWin();
    bool CheckLose();
public:
    Hangman();
    void play();
};

int main(){
    int speed = 50000;
    system("cls");
    print_slow("Welcome to Hangman!\n", speed);
    print_slow("You have to guess the word by entering one letter at a time.\n", speed);
    print_slow("You can only make 6 wrong guesses.\n", speed);
    print_slow("Good luck!\n", speed);
    usleep(1000000);
    std::cout << std::endl;
    system("pause");

    Hangman game;
    game.play();

    WHITE

    return 0;
}

std::vector<std::string> Hangman::GetWordsFromFile(){
    std::ifstream file;
    file.open("data/words.txt");

    std::vector<std::string> words;
    std::string word;
    while (file >> word)
        words.push_back(word);
    file.close();
    return words;
}

char Hangman::CheckValidLetter(){
    char guess;
    WHITE
    std::cout << "Enter a letter: ";
    std::cin >> guess;
    while (true){
        if (std::isalpha(guess) && std::islower(guess))
            return guess;
        else
            std::cout << "Invalid input. Please enter a lowercase letter: ";
        std::cin >> guess;
    }
}

void Hangman::DrawHangman(){
    RED
    std::cout << m_hangman_art[wrongGuesses] << std::endl;

    WHITE
    std::cout << guessedWord << std::endl;
    std::cout << "Guessed letters: ";
    for (char letter : guessedLetters)
        std::cout << letter << " ";
    std::cout << std::endl;
}

Hangman::Hangman(){
    words = GetWordsFromFile();
    srand(time(0));
    word = words[rand() % words.size()];
    won = false;
    lost = false;
    wrongGuesses = 0;
    guessedWord = std::string(word.size(), '_');
    int hintIndex = rand() % word.size();
    HandleGuess(word[hintIndex]);
}

void Hangman::play(){
    while (!won && !lost){
        system("cls");
        DrawHangman();
        char guess = CheckValidLetter();
        HandleGuess(guess);
        won = CheckWin();
        lost = CheckLose();
    }
}

void Hangman::HandleGuess(char guess){
    if (word.find(guess) != std::string::npos){
        for (size_t i = 0; i < word.length(); ++i){
            if (word[i] == guess)
                guessedWord[i] = guess;
        }
    }
    else{
        ++wrongGuesses;
        guessedLetters.push_back(guess);
    }
}

bool Hangman::CheckWin(){
    if (word != guessedWord)
        return false;
    system("cls");
    RED
    std::cout << m_hangman_art[wrongGuesses] << std::endl;
    std::cout << guessedWord << std::endl;
    BLUE
    std::cout << "You win! The word was " << word << std::endl;
    return true;
}

bool Hangman::CheckLose(){
    if (wrongGuesses < 6)
        return false;
    system("cls");
    RED
    std::cout << m_hangman_art[wrongGuesses] << std::endl;
    std::cout << guessedWord << std::endl;
    std::cout << "You lost! The word was " << word << std::endl;
    return true;
}

void print_slow(const std::string& str, int speed){
    for (size_t i = 0; i < str.size(); ++i){
        std::cout << str[i];
        std::cout.flush();
        usleep(speed);
    }
}