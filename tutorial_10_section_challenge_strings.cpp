#include <iostream>
#include <string>
#include <vector>

int solution_1();
void solution_2();
void solution_3();
int solution_4();

int solution_1(){
    std::cout << "solution_1: " << std::endl;
    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string secret_mes;
    std::string encrypted_mes;
    std::string decrypted_mes;

    std::cout << "Enter your secret message:";
    std::getline(std::cin, secret_mes);
    std::cout << std::endl;

    std::cout << "Encrypting message..." << std::endl;

    for (int message_letter_pos=0; message_letter_pos < secret_mes.length(); message_letter_pos++){
        for (int alph_letter=0; alph_letter < alphabet.length(); alph_letter++){
            if (secret_mes.at(message_letter_pos)==alphabet.at(alph_letter)){
                encrypted_mes += (key.at(alph_letter));
                break;  // break out of for loop
            }
            else if ((alph_letter+1) == alphabet.length()){  // if not a letter in alphabet
                encrypted_mes += secret_mes.at(message_letter_pos);
            }
        }
    }

    std::cout << "Encrypted message: " << encrypted_mes << std::endl;

    std::cout << "Decrypting message..." << std::endl;

    for (int encrypt_mes_pos=0; encrypt_mes_pos < encrypted_mes.length(); encrypt_mes_pos++){
        for (int key_letter=0; key_letter < key.length(); key_letter++){
            if (encrypted_mes.at(encrypt_mes_pos)==key.at(key_letter)){
                decrypted_mes += (alphabet.at(key_letter));
                break;  // break out of for loop
            }
            else if ((key_letter+1) == key.length()){  // if not a letter in alphabet
                decrypted_mes += encrypted_mes.at(encrypt_mes_pos);
            }
        }
    }

    std::cout << "Decrypted message: " << decrypted_mes << std::endl;

    return 0;
}

void solution_2(){
    std::cout << "solution_2: " << std::endl;
    std::string secret_mes;
    std::string encrypted_mes;
    std::string decrypted_mes;

    std::cout << "Enter your secret message:";
    std::getline(std::cin, secret_mes);
    std::cout << std::endl;

    std::cout << "Encrypting message..." << std::endl;

    for (int letter_pos=0; letter_pos<secret_mes.length(); letter_pos++){
        encrypted_mes += (secret_mes.at(letter_pos)-15);
    }


    std::cout << "Encrypted message: " << encrypted_mes << std::endl;

    std::cout << "Decrypting message..." << std::endl;

    for (int e_letter_pos=0; e_letter_pos<encrypted_mes.length(); e_letter_pos++){
        decrypted_mes += (encrypted_mes.at(e_letter_pos)+15);
    }

    std::cout << "Decrypted message: " << decrypted_mes << std::endl;
}

void solution_3(){
    std::cout << "solution_3: " << std::endl;
    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::vector<char> alphabet_v {};
    std::vector<char> key_v {};

    for (int letter=0; letter<alphabet.size(); letter++){
        alphabet_v.push_back(alphabet.at(letter));
        key_v.push_back(key.at(letter));
    }

    std::vector<std::vector<char>> key_mapped {alphabet_v, key_v};

    std::string secret_mes;
    std::string encrypted_mes;
    std::string decrypted_mes;

    bool letter_encrypted {false};
    bool letter_decrypted {false};

    std::cout << "Enter your secret message:";
    std::getline(std::cin, secret_mes);
    std::cout << std::endl;

    std::cout << "Encrypting message..." << std::endl;

    for (int letter=0; letter<secret_mes.length(); letter++){
        for (int position_alphabet=0; position_alphabet<alphabet.length(); position_alphabet++){
            if (secret_mes.at(letter) == key_mapped.at(0).at(position_alphabet)){
                encrypted_mes += key_mapped.at(1).at(position_alphabet);
                letter_encrypted = true;
                break;
            }
        }
        if (letter_encrypted==false){
            encrypted_mes += secret_mes.at(letter);
        }
        letter_encrypted=false;
    }

    std::cout << "Encrypted message: " << encrypted_mes << std::endl;

    std::cout << "Decrypting message..." << std::endl;

    for (int letter=0; letter<encrypted_mes.length(); letter++){
        for (int position_key=0; position_key<key.length(); position_key++){
            if (encrypted_mes.at(letter) == key_mapped.at(1).at(position_key)){
                decrypted_mes += key_mapped.at(0).at(position_key);
                letter_decrypted = true;
                break;
            }
        }
        if (letter_decrypted==false){
            decrypted_mes += encrypted_mes.at(letter);
        }
        letter_decrypted=false;
    }

    std::cout << "Decrypted message: " << decrypted_mes << std::endl;

}


int solution_4(){
    std::cout << "solution_4: " << std::endl;
    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string secret_mes;
    std::string encrypted_mes;
    std::string decrypted_mes;

    std::cout << "Enter your secret message:";
    std::getline(std::cin, secret_mes);
    std::cout << std::endl;

    std::cout << "Encrypting message..." << std::endl;
    for (char letter: secret_mes){
        size_t letter_pos = alphabet.find(letter);
        if (letter_pos != std::string::npos){  // found
            encrypted_mes += key.at(letter_pos);
        }
        else {  // not found
            encrypted_mes += letter;
        }
    }
    std::cout << "Encrypted message: " << encrypted_mes << std::endl;

    std::cout << "Decrypting message..." << std::endl;
    for (char letter: encrypted_mes){
        size_t letter_pos = key.find(letter);
        if (letter_pos != std::string::npos){  // found
            decrypted_mes += alphabet.at(letter_pos);
        }
        else {  // not found
            decrypted_mes += letter;
        }
    }
    std::cout << "Decrypted message: " << decrypted_mes << std::endl;

    return 0;
}

int solution_5(){
    std::cout << "solution_5: " << std::endl;
    std::string alphabet {" 4321abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key {"# !*[XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string secret_mes;
    std::string encrypted_mes;
    std::string decrypted_mes;

    std::cout << "Enter your secret message:";
    std::getline(std::cin, secret_mes);
    std::cout << std::endl;

    std::cout << "Encrypting message..." << std::endl;
    for (char letter: secret_mes){
        size_t letter_pos = alphabet.find(letter);
        if (letter_pos != std::string::npos){  // found
            encrypted_mes += key.at(letter_pos);
        }
        else {  // not found
            encrypted_mes += letter;
        }
    }
    std::cout << "Encrypted message: " << encrypted_mes << std::endl;

    std::cout << "Decrypting message..." << std::endl;
    for (char letter: encrypted_mes){
        size_t letter_pos = key.find(letter);
        if (letter_pos != std::string::npos){  // found
            decrypted_mes += alphabet.at(letter_pos);
        }
        else {  // not found
            decrypted_mes += letter;
        }
    }
    std::cout << "Decrypted message: " << decrypted_mes << std::endl;

    return 0;
}

int main(){
    solution_1();
    solution_2();
    solution_3();
    solution_4();

    return 0;
}
