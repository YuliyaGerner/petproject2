#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <unordered_map>
using namespace std;

string to_lower(string input) {
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

void bot(string text) {
    cout << "[BOT]: " << text << endl;
}

string user() {
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower(question);
    return question;
}

int main() 
{
    unordered_map<string, string> database = {
        {"hello", "Oh, hello human"},
        {"how are you", "I am OK, what about you?"},
        {"what is your name", "My name is Bot20"},
        {"what are you doing", "Answering some silly questions"}
    };


    string question;
    
    bot("Hello user, I can answer your questions!");
    
    while (question.compare("exit") != 0) {
        int found_phrases = 0;
        question = user();
        for (auto entry : database) {
            auto pattern = regex(".*" + entry.first + ".*");
            if(regex_match(question, pattern)) {
                bot(entry.second);
                found_phrases++;
            }
        }
        if (found_phrases == 0) {
            bot("I don't understand, try again");
        }
    }
    bot("Okay, bye!");
}
    
