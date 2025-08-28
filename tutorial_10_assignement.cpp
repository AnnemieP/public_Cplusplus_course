/*
 * Creating a letter pyramid from a user input string.
 */

#include <iostream>
#include <string>

int main(){
    std::cout << "Please enter a string of characters: ";
    std::string user_string {};
    std::cin >> user_string;

    // int pyramid_bottom_length = (user_string.length() - 1)*2 +1;
    std::string prev_string {};

    // for each character in the string
    for (char letter: user_string){
        // print whitespaces to center
        std::string ws (user_string.length()-prev_string.length()-1, ' ');
        std::cout << ws;
        // print prev_string, current letter, inverse prev_string
        std::cout << prev_string << letter;
        for (int end_char_pos = 0; end_char_pos<prev_string.length(); end_char_pos++){
            std::cout << prev_string.at(prev_string.length()-1-end_char_pos);
        }
        // add current letter to prev_string
        prev_string += letter;
        // print newline
        std::cout << std::endl;
    }
    return 0;
}
