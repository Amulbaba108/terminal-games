#include "hangman.h"

#include <iostream>
#include <random>
#include <vector>

bool Hangman::guess(char letter) {
    if (guessed_.count(letter)) return word_.find(letter) != std::string::npos;
    guessed_.insert(letter);
    if (word_.find(letter) != std::string::npos) return true;
    wrong_++;
    return false;
}

std::string Hangman::masked() const {
    std::string out;
    for (size_t i = 0; i < word_.size(); i++) {
        if (i > 0) out += ' ';
        out += guessed_.count(word_[i]) ? word_[i] : '_';
    }
    return out;
}

bool Hangman::won() const {
    for (char c : word_)
        if (!guessed_.count(c)) return false;
    return true;
}

void playHangman() {
    const std::vector<std::string> words = {"compiler", "pointer", "variable", "function", "github", "binary", "keyboard"};
    std::mt19937 rng(std::random_device{}());
    Hangman game(words[std::uniform_int_distribution<size_t>(0, words.size() - 1)(rng)]);

    while (!game.won() && !game.lost()) {
        std::cout << "\n" << game.masked() << "    (lives left: " << Hangman::MAX_WRONG - game.wrongGuesses() << ")\nGuess a letter: ";
        char letter;
        std::cin >> letter;
        std::cout << (game.guess(tolower(letter)) ? "Yes!\n" : "Nope.\n");
    }
    if (game.won()) std::cout << "\nYou got it: " << game.word() << "\n";
    else std::cout << "\nOut of lives! The word was: " << game.word() << "\n";
}
