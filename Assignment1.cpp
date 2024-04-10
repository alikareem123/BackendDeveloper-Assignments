#include <bits/stdc++.h>
using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}


std::string reverse_words(const std::string& sentence) {
    std::string revSentence;
    std::string word;
    

    for (char ch : sentence) {

        if (std::isalnum(ch)) {
            word += ch;
        } else {
            
            for (int i = 0, j = word.length() - 1; i < j; ++i, --j) {
                swap(word[i], word[j]);
            }
            revSentence += word;
            word = "";
            
            revSentence += ch;
        }
    }

    for (int i = 0, j = word.length() - 1; i < j; ++i, --j) {
        swap(word[i], word[j]);
    }
    revSentence += word;
    
    return revSentence;
}

int main() {
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");
    return 0;
}
