#include <algorithm>
#include <iostream>
#include <unordered_map>

// Функция для замены букв на соответствующие цифры
std::string replaceLetters(const std::string& word) {
    std::unordered_map<char, char> replacements = {
        {'A', '\0'}, {'E', '\0'}, {'H', '\0'}, {'I', '\0'}, {'O', '\0'}, {'U', '\0'}, {'W', '\0'},
        {'Y', '\0'}, {'B', '1'},  {'F', '1'},  {'P', '1'},  {'V', '1'},  {'C', '2'},  {'G', '2'},
        {'J', '2'},  {'K', '2'},  {'Q', '2'},  {'S', '2'},  {'X', '2'},  {'Z', '2'},  {'D', '3'},
        {'T', '3'},  {'L', '4'},  {'M', '5'},  {'N', '5'},  {'R', '6'}};

    std::string code;
    code += word[0];  // Сохраняем первую букву

    for (size_t i = 1; i < word.length(); i++) {
        char c = std::toupper(word[i]);
        if (replacements.find(c) != replacements.end() && replacements[c] != '\0') {
            if (code.back() != replacements[c]) {
                code += replacements[c];
            }
        }
    }

    return code;
}

// Функция для сокращения последовательности одинаковых цифр до одной цифры
std::string compressCode(const std::string& code) {
    std::string compressed;
    if (code.empty()) {
        return compressed;
    }

    compressed += code[0];

    for (size_t i = 1; i < code.length(); i++) {
        if (code[i] != code[i - 1]) {
            compressed += code[i];
        }
    }

    return compressed;
}

// Функция для преобразования кода в итоговую строку
std::string formatCode(const std::string& code) {
    std::string formatted = code.substr(0, 4);
    if (formatted.length() < 4) {
        formatted += std::string(4 - formatted.length(), '0');
    }
    return formatted;
}

// Функция для получения Soundex-кода слова
std::string getSoundexCode(const std::string& word) {
    std::string code = replaceLetters(word);
    std::string compressed = compressCode(code);
    std::string formatted = formatCode(compressed);
    return formatted;
}

int main() {
    std::string word;
    std::cin >> word;

    std::string soundexCode = getSoundexCode(word);
    std::cout << soundexCode << std::endl;

    return 0;
}