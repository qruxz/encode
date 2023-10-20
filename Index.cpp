#include <iostream>
#include <string>
using namespace std;

namespace SymbolEncoding {
    string encode(const string& message) {
        string encodedMessage = "";
        string symbolKey = "$§¢€¥%÷√π~&@#£∆!}✓^48260/?";
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (char letter : message) {
            if (isalpha(letter)) {
                char uppercaseLetter = toupper(letter);
                size_t position = alphabet.find(uppercaseLetter);
                if (position != string::npos) {
                    encodedMessage += symbolKey[position];
                } else {
                    encodedMessage += letter; // Keep non-alphabetic characters as they are
                }
            } else {
                encodedMessage += letter; // Keep non-alphabetic characters as they are
            }
        }
        return encodedMessage;
    }

    string decode(const string& encodedMessage) {
        string decodedMessage = "";
        string symbolKey = "$§¢€¥%÷√π~&@#£∆!}✓^48260/?";
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (char symbol : encodedMessage) {
            size_t position = symbolKey.find(symbol);
            if (position != string::npos) {
                char decodedLetter = alphabet[position];
                decodedMessage += decodedLetter;
            } else {
                decodedMessage += symbol; // Keep non-alphabetic characters as they are
            }
        }
        return decodedMessage;
    }
}

int main() {
    string message;
    string encodedMessage;
    string decodedMessage;
    char choice;

    cout << "Do you want to encode (E) or decode (D) a message? ";
    cin >> choice;

    cin.ignore(); // Consume the newline character left in the input buffer

    if (choice == 'E' || choice == 'e') {
        cout << "Enter a message to encode: ";
        getline(cin, message);
        encodedMessage = SymbolEncoding::encode(message);
        cout << "Encoded message: " << encodedMessage << endl;
    } else if (choice == 'D' || choice == 'd') {
        cout << "Enter a message to decode: ";
        getline(cin, encodedMessage);
        decodedMessage = SymbolEncoding::decode(encodedMessage);
        cout << "Decoded message: " << decodedMessage << endl;
    } else {
        cout << "Invalid choice. Please select 'E' to encode or 'D' to decode." << endl;
    }

    return 0;
}
