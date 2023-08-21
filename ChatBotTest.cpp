// chatbot.cpp
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> knowledgeBase = {
    {"how are you", "I'm just a simple chatbot, but I'm functioning well."},
    {"what is your name", "I'm ChatBot++."},
    {"bye", "Goodbye! Have a great day."},
    // Add more question-answer pairs here
};

std::string getAnswer(const std::string& question) {
    std::string lowerQuestion = question;
    for (char& c : lowerQuestion) {
        c = std::tolower(c);
    }

    auto it = knowledgeBase.find(lowerQuestion);
    if (it != knowledgeBase.end()) {
        return it->second;
    } else {
        return "I'm sorry, I don't have an answer for that question.";
    }
}

int main() {
    std::cout << "ChatBot++: Hello! Ask me a question or say 'bye' to exit." << std::endl;
    while (true) {
        std::string question;
        std::cout << "You: ";
        std::getline(std::cin, question);

        if (question == "bye") {
            std::cout << "ChatBot++: Goodbye! Have a great day." << std::endl;
            break;
        }

        std::string answer = getAnswer(question);
        std::cout << "ChatBot++: " << answer << std::endl;
    }

    return 0;
}
