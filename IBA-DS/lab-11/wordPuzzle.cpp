#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "hashMap.hpp"
#include "stopWatch.hpp"

using std::vector, std::string, std::ifstream, std::cin, std::cout, std::endl;

string getWordInGrid(const vector<vector<char>>& grid, int startRow, int startCol, int dir, int len);
vector<vector<char>> readInGrid(string filename);
vector<string> getWords(string filename);
string getDirection(int dir);
string getCoords(int x, int y);

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <dictionary_file> <grid_file>" << endl;
        return 1;
    }

    string dictFile = argv[1];
    string gridFile = argv[2];

    vector<vector<char>> grid = readInGrid(gridFile);
    vector<string> words = getWords(dictFile);

    std::cout << '\n'
              << '\n';

    hashMap hp(words.size() * 2);
    for (const auto& word : words)
        hp.put(word);

    int rows = grid.size();
    int cols = grid[0].size();
    int wordsFound = 0;

    Stopwatch sw;
    sw.reset();

    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            for (int dir = 0; dir < 8; ++dir) {
                int maxLength;
                if (dir == 0)
                    maxLength = x + 1;
                else if (dir == 1)
                    maxLength = std::min(x + 1, cols - y);
                else if (dir == 2)
                    maxLength = cols - y;
                else if (dir == 3)
                    maxLength = std::min(rows - x, cols - y);
                else if (dir == 4)
                    maxLength = rows - x;
                else if (dir == 5)
                    maxLength = std::min(rows - x, y + 1);
                else if (dir == 6)
                    maxLength = x + 1;
                else if (dir == 7)
                    maxLength = std::min(x + 1, y + 1);

                for (int l = 3; l <= maxLength; ++l) {
                    string word = getWordInGrid(grid, x, y, dir, l);
                    if (word.length() < 3) continue;
                    if (!hp.isPrefix(word)) break;  // breaks out of the loop if the current word is not a prefix of any other word
                    if (hp.isWord(word)) {
                        cout << getDirection(dir) << " (" << x << ", " << y << "): " << word << endl;
                        ++wordsFound;
                    }
                }
            }
        }
    }

    cout << wordsFound << " words found" << endl;
    cout << "Found all words in " << sw.elapsedTime() << " seconds" << endl;

    return 0;
}

vector<string> getWords(string filename) {
    vector<string> words;
    ifstream fin(filename.c_str());
    string word;
    while (fin >> word)
        words.push_back(word);

    fin.close();

    return std::move(words);
}

string getDirection(int dir) {
    if (dir == 0) return "N";
    if (dir == 1) return "NE";
    if (dir == 2) return "E";
    if (dir == 3) return "SE";
    if (dir == 4) return "S";
    if (dir == 5) return "SW";
    if (dir == 6) return "W";
    if (dir == 7) return "NW";

    return "";
}

string getCoords(int x, int y) {
    return " (" + std::to_string(x) + ',' + std::to_string(y) + ") ";
}

vector<vector<char>> readInGrid(string filename) {
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream fin(filename.c_str());

    // upon an error, return empty grid
    if (!fin.is_open())
        return vector<vector<char>>();

    // the first line is the number of rows: read it in
    int rows, cols;
    fin >> rows >> cols;
    cout << "There are " << rows << " rows." << endl;
    cout << "There are " << cols << " cols." << endl;

    vector<vector<char>> grid(rows, vector<char>(cols));

    // convert the string read in to the 2-D vector format into the grid.
    // In the process, we'll print the grid to the screen as well.
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            fin >> grid[r][c];
            cout << grid[r][c];
        }
        cout << endl;
    }

    // close the file
    fin.close();

    // return grid
    return grid;
}

string getWordInGrid(const vector<vector<char>>& grid, int startRow, int startCol, int dir, int len) {
    int numRows = grid.size(), numCols = grid[0].size();
    string output;
    // the current row, and the current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if ((c >= numCols) || (r >= numRows) || (r < 0) || (c < 0))
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) {  // assumes grid[0][0] is in the upper-left
        case 0:
            r--;
            break;  // north
        case 1:
            r--;
            c++;
            break;  // north-east
        case 2:
            c++;
            break;  // east
        case 3:
            r++;
            c++;
            break;  // south-east
        case 4:
            r++;
            break;  // south
        case 5:
            r++;
            c--;
            break;  // south-west
        case 6:
            c--;
            break;  // west
        case 7:
            r--;
            c--;
            break;  // north-west
        }
    }
    // return the string we found.
    return output;
}