#include <string>
#include <cassert>
#include <sstream>

std::string reverse_words(const std::string &str) {
    std::istringstream inputStringStream(str);

    std::ostringstream outputStringStream;

    std::string inputWord;

    while (inputStringStream >> inputWord) {
        std::string reversed_word(inputWord.rbegin(), inputWord.rend());
        outputStringStream << reversed_word << " ";
    }
    std::string answer = outputStringStream.str();
    if (!answer.empty()) {
        answer.pop_back();
    }
    return answer;
}

int main() {
    std::string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");
    return 0;
}
