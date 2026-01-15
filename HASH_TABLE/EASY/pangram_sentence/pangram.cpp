//wap to check if a string is pangram(A string that contains all letters of the alphabet at least once)
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
bool pangram_brute(const string& sentence){
    for (char c = 'a'; c <= 'z'; c++) {
        bool found = false;
        for (char ch : sentence) {
            if (tolower(ch) == c) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}
bool pangram_optimize(const string& sentence) {
    unordered_map<char, bool> seen;
    for (char c : sentence) {
        if (isalpha(c)) {
            seen[tolower(c)] = true;
        }
    }
    return seen.size() == 26;
}

int main() {
    string sentence,choice;
    cout << "Enter a sentence: ";
    cin>>sentence;
    cout << "Enter 'brute' or 'optimize': ";
    cin>>choice;
    if (choice == "brute") {
        if (pangram_brute(sentence)) {
            cout << "The sentence is a pangram." << endl;
        } else {
            cout << "The sentence is not a pangram." << endl;
        }
    } else if (choice == "optimize") {
        if (pangram_optimize(sentence)) {
            cout << "The sentence is a pangram." << endl;
        } else {
            cout << "The sentence is not a pangram." << endl;
        }
    }
    return 0;
}