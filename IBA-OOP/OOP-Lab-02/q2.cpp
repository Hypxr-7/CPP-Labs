#include <iostream>
#include <format>

class TicTacToe{
private:
    int Board[3][3];
public:
    TicTacToe(){
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                Board[i][j] = 0;
    }

    void clearBoard(){
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                Board[i][j] = 0;    
    }

    void to_string() const {
            for (int i = 0; i < 3; i++){
                std::cout << " " << Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2];
                std::cout << std::endl << "-----------" << std::endl; 
            }
    }

    int gameStatus() const {
        // checks horizontal rows
        for (int i = 0; i < 3; i++)
            if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && (Board[i][0] == 1 || Board[i][0] == 2))
                return Board[i][0];
        
        // checks vertical rows
        for (int i = 0; i < 3; i++)
            if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && (Board[0][i] == 1 || Board[0][i] == 2))
                return Board[0][i];
        
        // diagonal check
        if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && (Board[0][0] == 1 || Board[0][0] == 2))
            return Board[0][0];
        if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && (Board[0][2] == 1 || Board[0][2] == 2))
            return Board[0][2];
        
        // no one winning
        return 0;
    }

    bool move(int player, int row, int col){
        if (Board[row][col] != 0)
            return false;
        Board[row][col] = player;
        return true;
    }
};

int main(){
    TicTacToe obj;
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    for (int i = 0; i < 5; i++){
        int row;
        int col;
        bool validTurn = false;
        while(!validTurn){
            std::cout << "Play 1 move: enter row and column: ";
            std::cin >> row >> col;
            if (obj.move(1, row, col)){
                validTurn = true;
                obj.to_string();
            }
            if (obj.gameStatus() != 0){
                std::cout << "Player 1 Wins!";
                break;
            }
        }

        if (obj.gameStatus() != 0)
            break;

        if (i == 5){
            std::cout << "Its a Tie!";
            break;
        }

        validTurn = false;
        while(!validTurn){
            std::cout << "Play 2 move: enter row and column: ";
            std::cin >> row >> col;
            if (obj.move(2, row, col)){
                validTurn = true;
                obj.to_string();
            }
            if (obj.gameStatus() != 0){
                std::cout << "Player 2 Wins!";
                break;
            }

        if (obj.gameStatus() != 0)
            break;
        }
    }

    return 0;
}