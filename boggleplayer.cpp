#include "boggleplayer.h"
#include "baseboggleplayer.h"
#include <set>
#include <vector>
#include <string>
#include <cctype>

const char* lexfile = "boglex.txt";
void BogglePlayer::buildLexicon(const set<string>& word_list){

//variable declarations
set<string>::iterator beginList = word_list.cbegin();
set<string>::iterator endList = word_list.cend();
std::vector<string> vector;
const int minWordLength = 3;
string newWord;

//iterates from beginning to end of list
for(beginList; beginList != endList; ++beginList){

    //adds value of word list passed into the vector
    vector.push_back(*beginList);

}


//iterates through vector and gets value
for(set<string>::iterator it = vector.begin(); it != vector.end(); it++){

    //string::assign
    newWord.assign(*it);
    //checks length to see if it's at least min length
    if(newWord.length >= minWordLength){
        //adds word to ternary tree
        trie->add(newWord);
    }
}
}
