#include <iostream>
#include <string>

int main(){
    using namespace std;

    string sentence;
    cout << "Enter Sentence: ";
    getline(cin, sentence);
    sentence += " ";

    string latinSentence;
    string currentWord = "";
    bool wordComplete = false;
    for (int i = 0; i < size(sentence); i++){
        if (sentence[i] != ' '){
            currentWord += sentence[i];
        }
        else{
            wordComplete = true;
        }
        if (wordComplete){
            for (int j = 0; j < size(currentWord)-1; j++){
                int temp = currentWord[j];
                currentWord[j] = currentWord[j+1];
                currentWord[j+1] = temp;
            }
            currentWord += "ay";
            latinSentence += currentWord;
            latinSentence += " ";
            wordComplete = false;
            currentWord = "";
        }
    }

    cout << "New Sentence: " << latinSentence << endl;

    return 0;
}