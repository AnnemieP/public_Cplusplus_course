/*
 * Creating a user interface to interact with a list of integers.
 * The user is given a choice of options to choose from and can only quit when
 * entering either `Q` or `q`.
 */

#include <iostream>
#include <vector>

void display_options();
bool allow_duplicates();
bool is_list_empty(const std::vector<int> &integer_list);
void print_nums(const std::vector<int> &integer_list);
bool compare_value_to_list(const int new_value, const std::vector<int> &integer_list);
void add_num_to_list(std::vector<int> &integer_list);
int mean(const std::vector<int> &integer_list);
int smallest(const std::vector<int> &integer_list);
int largest(const std::vector<int> &integer_list);
int duplicates(const std::vector<int> &integer_list);
void clearlist(std::vector<int> &integer_list);
void make_choice(std::vector<int> &integer_list);

void display_options() {
    std::cout << "P - Print numbers" << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "F - Find how many times number is in list" << std::endl;
    std::cout << "C - Clear list" << std::endl;
    std::cout << "Q - Quit" << std::endl;
    std::cout << "Please enter your choice: ";
}

bool allow_duplicates(){
    bool allow_duplicate_entries {false};
    char c_allow_duplicate_entries {'n'};
    std::cout << "Allow duplicate entries? (y/n) ";
    std::cin >> c_allow_duplicate_entries;
    std::cout << std::endl;
    if (std::cin.fail()) {
        std::cout << "Invalid choice. Defaulting to no.";
        std::cin.clear();  // clear error flags
        std::cin.ignore();  // discard invalid input
    }
    else if (c_allow_duplicate_entries == 'y')
        allow_duplicate_entries = true;
    else if (c_allow_duplicate_entries == 'n')
        allow_duplicate_entries = false;
    else
        std::cout << "Invalid choice. Defaulting to no." << std::endl;
    return allow_duplicate_entries;
}

bool is_list_empty(const std::vector<int> &integer_list) {
    if (integer_list.size() == 0){
        std::cout << "Unable to do calculation - no data - empty list";
        std::cout << std::endl << std::endl;
        return true;
    }
    return false;
}

void print_nums(const std::vector<int> &integer_list){
    std::cout << "Printing list:" << std::endl << "[ ";
    for (size_t i {0}; i<integer_list.size(); i++){
        std::cout << integer_list.at(i) << " ";
    }
    std::cout << "]";
    if (integer_list.size() == 0){
        std::cout << " - the list is empty";
    }
    std::cout << std::endl << std::endl;
}

bool compare_value_to_list(const int new_value, const std::vector<int> &integer_list){
    for (auto value_in_list: integer_list) {
        if (new_value == value_in_list) {
            std::cout << new_value << " already in list and duplicate "
                                      "entries are not allowed.";
            return true;
        }
    }
    return false;
}

void add_num_to_list(std::vector<int> &integer_list){
    int new_value {};
    std::cout << "Enter integer to add to the list: ";
    std::cin >> new_value;
    if (std::cin.fail()) {
        std::cout << "Value entered is not an integer.";
        std::cin.clear();  // clear error flags
        std::cin.ignore();  // discard invalid input
    }
    else if (allow_duplicates()) {
        integer_list.push_back(new_value);
        std::cout << new_value << " added";
    }
    else {
        bool duplicate {false};
        duplicate = compare_value_to_list(new_value, integer_list);
        if (!duplicate) {
            integer_list.push_back(new_value);
            std::cout << new_value << " added";
        }
    }
    std::cout << std::endl << std::endl;
}

int mean(const std::vector<int> &integer_list){
    float avg {};  // could change to double if expecting large num
    float sum {0};  // using float/double here eliminating static_cast
    if (is_list_empty(integer_list) == false){
        for (auto value_in_list: integer_list) {
            sum += value_in_list;
        }
        avg = sum / integer_list.size();
        std::cout << "Mean or average: " << avg;
        std::cout << std::endl << std::endl;
    }
    return avg;
}

int smallest(const std::vector<int> &integer_list){
    int smallest_num {};
    if (is_list_empty(integer_list) == false){
        smallest_num = integer_list.at(0);
        for (auto value_in_list: integer_list) {
            if (smallest_num > value_in_list){
                smallest_num = value_in_list;
            }
        }
        std::cout << "The smallest number is " << smallest_num;
        std::cout << std::endl << std::endl;
    }
    return smallest_num;
}

int largest(const std::vector<int> &integer_list) {
    int largest_num {};
    if (is_list_empty(integer_list) == false){
        largest_num = {integer_list.at(0)};
        for (auto value_in_list: integer_list) {
            largest_num = (largest_num < value_in_list) ?
                            value_in_list : largest_num;
        }
        std::cout << "The largest number is " << largest_num;
        std::cout << std::endl << std::endl;
    }
    return largest_num;
}

int duplicates(const std::vector<int> &integer_list){
    int search_value {};
    int count {0};
    std::cout << "Enter integer to search how many times it "
                    "occurs in the list: ";
    std::cin >> search_value;
    if (std::cin.fail()) {
        std::cout << "Value entered is not an integer."
                    << std::endl;
        std::cin.clear();  // clear error flags
        std::cin.ignore();  // discard invalid input
    }
    else {
        for (auto value_in_list: integer_list) {
            if (search_value == value_in_list) {
                count++;
            }
        }
        std::cout << search_value << " occurs " << count
                    << " times in the list" << std::endl;
    }
    std::cout << std::endl;
    return count;
}

void clearlist(std::vector<int> &integer_list) {
    std::cout << "Clearing list. ";
    integer_list.clear();
    std::cout << "List now empty." << std::endl;
    std::cout << std::endl;
}

void make_choice(std::vector<int> &integer_list){
    display_options();

    char user_choice {};
    std::cin >> user_choice;
    std::cout << std::endl;

    char capital_user_choice = toupper(user_choice);

    if (capital_user_choice == 'Q') {
        std::cout << "Goodbye";
        return;
    }

    switch (capital_user_choice) {
        case 'P': {
            print_nums(integer_list);
            break;
        }
        case 'A':{
            add_num_to_list(integer_list);
            break;
        }
        case 'M':{
            int avg = mean(integer_list);
            break;
        }
        case 'S': {
            int small = smallest(integer_list);
            break;
        }
        case 'L': {
            int large = largest(integer_list);
            break;
        }
        case 'F': {
            int num_of_duplicates = duplicates(integer_list);
            break;
        }
        case 'C': {
            clearlist(integer_list);
            break;
        }
        default: {
            std::cout << "Unknown selection, please try again";
            std::cout << std::endl << std::endl;
            break;
        }
    }

    make_choice(integer_list);
    // return only if capital_user_choice is Q
}

int main(){
    // Start with an arbitrary integer list:
    std::vector<int> integer_list {5, 6, 84, 2, 65, 89, 99, 12, 73};

    make_choice(integer_list);

}
