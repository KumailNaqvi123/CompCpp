# CompCpp
A simple compiler made in c++. which will take code in a text file as input and check it whether it is lexically and syntaxically correct or not. it will also print tokens.

# Features
Multi-line Comment Detection: Identifies and categorizes multi-line comments.<br>
Keyword Detection: Recognizes reserved keywords such as int, float, cout, cin, if, else, and else if.<br>
Identifier Recognition: Differentiates between keywords and user-defined identifiers.<br>
Operator Recognition: Identifies common operators such as +, -, *, /, =, etc.<br>
Constant Recognition: Detects numeric constants, including integers and floating-point numbers.<br>
Special Character Detection: Recognizes special characters and categorizes them appropriately.<br>
String and Character Recognition: Identifies string literals and character constants.<br>
Single-line Comment Detection: Detects single-line comments and categorizes them.<br>
Error Handling: Identifies unknown or unidentified tokens and outputs them for review.<br>

# How It Works
The lexical analyzer operates using a deterministic finite automaton (DFA) to process each character in the input file. Depending on the state and the character read, it transitions between states to categorize the input tokens.

# Example Usage
Prepare a code.txt file with the code you want to analyze.<br>
Compile the LexicalAnalyzer.cpp file using a C++ compiler.<br>
Run the compiled executable, and it will read the code.txt file, process the code, and output the recognized tokens.<br>

# Code Structure
The main class Lexical contains methods for each state of the DFA:<br>
**STATE00** to **STATE26**: Handle different types of characters and transitions based on the current DFA state.<br>
Lexical_Analyzer(string s): The main method that processes the input string and categorizes tokens.<br>

# Example Code
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

// Define token types and keywords
int dfa = 0;
int i = 0, a = 0, b = 0;
string token = " ";
string keywords[] = { "int", "float", "cout", "cin", "if", "else", "else if" };
string tokenType[] = {
"Multi-line Comment: ", "Keyword: ", "Identifier: ", "Operator: ", "Constant: ",
"Special Character: ", "String: ", "Single-line Comment: ", "Character: ", "Special Character: "
};
string Token_List[50][2] = {};

// Lexical class definition
class Lexical {
public:
    // State handling methods
    void STATE00(char c) { /*...*/ }
    void STATE01(char c) { /*...*/ }
    void STATE02(char c) { /*...*/ }
    // Additional state methods
    void STATE05(char c) { /*...*/ }
    // Other state methods
    void Lexical_Analyzer(string s) { /*...*/ }
};

// Main function to execute the lexical analyzer
int main() {
    Lexical lex;
    ifstream file("code.txt");
    stringstream buffer;
    buffer << file.rdbuf();
    string code = buffer.str();
    lex.Lexical_Analyzer(code);
    return 0;
}```
