#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include <sstream>
using namespace std;

int dfa = 0;
int i = 0, a = 0, b = 0;
string token = " ";
string keywords[] = { "int", "float", "cout", "cin", "if", "else", "else if" };

string tokenType[] = {
"Multi-line Comment: ", "Keyword: ", "Identifier: ", "Operator: ", "Constant: ",
"Special Character: ", "String: ", "Single-line Comment: ", "Character: ", "Special Character: "
};

string Token_List[50][2] = {};

class Lexical {
public:
    void STATE00(char c) {
        if (c == '/') {
            dfa = 1;
            token = token + c;
        }

        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
            dfa = 5;
            token = token + c;
        }

        else if (c == '|') {
            dfa = 6;
            token = token + c;
        }

        else if (c == '&') {
            dfa = 7;
            token = token + c;
        }

        else if (c >= '0' && c <= '9') {
            dfa = 10;
            token = token + c;
        }

        else if (c == '"') {
            dfa = 12;
            token = token + c;
        }

        else if (c == ';') {
            dfa = 13;
            token = token + c;
        }

        else if (c == '\'') {
            dfa = 14;
            token = token + c;
        }

        else if (c == '?') {
            dfa = 15;
            token = token + c;
        }

        else if (c == '(') {
            dfa = 16;
            token = token + c;
        }


        else if (c == ')') {
            dfa = 17;
            token = token + c;
        }


        else if (c == '^' || c == '~') {
            dfa = 18;
            token = token + c;
        }

        else if (c == '-') {
            dfa = 20;
            token = token + c;
        }

        else if (c == '+') {
            dfa = 22;
            token = token + c;
        }

        else if (c == '<') {
            dfa = 24;
            token = token + c;
        }

        else if (c == '%' || c == '*' || c == '/' || c == '=' || c == '!') {
            dfa = 25;
            token = token + c;
        }

        else if (c == '>') {
            dfa = 26;
            token = token + c;
        }

    }

    void STATE01(char c) {
        if (c == '/') {
            dfa = 2;
            token = token + c;
        }

        else if (c == '*') {
            dfa = 3;
            token = token + c;
        }

        else {
            dfa = 0;
            token = token + c;
        }

    }

    void STATE02(char c) {
        if (!(c == '\n')) {
            dfa = 2;
            token = token + c;
        }

        if (c == '\n') {
            cout << tokenType[7];
            token = token + c;
            cout << token;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

    }

    void STATE03(char c) {
        if (c != '*') {
            dfa = 3;
            token = token + c;
        }

        else if (c == '*') {
            dfa = 4;
            token = token + c;
        }
    }

    void STATE04(char c) {
        if (c == '/') {
            cout << tokenType[0];
            token = token + c;
            cout << token << endl;

            Token_List[a][b] = tokenType[0];
            Token_List[a][b + 1] = token;
            a++;

            token = "\0";
            dfa = 0;
            return;
        }

        else if (!(c == '/')) {
            dfa = 3;
            token = token + c;
        }

    }

    void STATE05(char c) {
        bool ifKeyword = 0;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            dfa = 5;
            token = token + c;
        }

        else if (c == ' ') {

            if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
                ifKeyword = 1;
                token = token + c;
            }

            else {
                ifKeyword = 0;
            }

            if (ifKeyword) {
                cout << tokenType[1];
                cout << token << endl;
                Token_List[a][b] = tokenType[1];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }

            else if (!ifKeyword) {
                cout << tokenType[2];
                cout << token << endl;
                Token_List[a][b] = tokenType[2];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }

        }

        else if (c == '=') {

            if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
                ifKeyword = 1;
                token = token + c;
            }

            else {
                ifKeyword = 0;
            }

            if (ifKeyword) {
                cout << tokenType[1];
                cout << token << endl;
                Token_List[a][b] = tokenType[1];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }

            else if (!ifKeyword) {
                cout << tokenType[2];
                cout << token << endl;
                Token_List[a][b] = tokenType[2];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }
        }

        else if (c == ';') {
            if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
                ifKeyword = 1;
                token = token + c;
            }

            else {
                ifKeyword = 0;
            }

            if (ifKeyword) {
                cout << tokenType[1];
                cout << token << endl;
                Token_List[a][b] = tokenType[1];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }

            else if (!ifKeyword) {
                cout << tokenType[2];
                cout << token << endl;
                Token_List[a][b] = tokenType[2];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }
        }

        else if (c == '(') {
            if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
                ifKeyword = 1;
                token = token + c;
            }

            else {
                ifKeyword = 0;
            }

            if (ifKeyword) {
                cout << tokenType[1];
                cout << token << endl;
                Token_List[a][b] = tokenType[1];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }

            else if (!ifKeyword) {
                cout << tokenType[2];
                cout << token << endl;
                Token_List[a][b] = tokenType[2];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }
        }

        else if (c == ')') {
            if (token == "int" || token == "float" || token == "cout" || token == "cin" || token == "if" || token == "else if" || token == "else") {
                ifKeyword = 1;
                token = token + c;
            }

            else {
                ifKeyword = 0;
            }

            if (ifKeyword) {
                cout << tokenType[1];
                cout << token << endl;
                Token_List[a][b] = tokenType[1];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }

            else if (!ifKeyword) {
                cout << tokenType[2];
                cout << token << endl;
                Token_List[a][b] = tokenType[2];
                Token_List[a][b + 1] = token;
                a++;
                i--;
                token = "\0";
                dfa = 0;
                return;
            }
        }

        else
            dfa = 0;
    }

    void STATE06(char c) {
        if (c == '|') {
            cout << tokenType[2];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[2];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c != '|') {
            cout << "Unidentified Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == ' ') {
            cout << "Unidentified Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE07(char c) {
        if (c == '&') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c != '&') {
            cout << "Unidentified Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == ' ') {
            cout << "Unidentified Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE10(char c) {
        if (c >= '0' && c <= '9') {
            dfa = 10;
            token = token + c;
        }

        else if (c == '.') {
            dfa = 11;
            token = token + c;
        }

        else if (c == ' ') {
            cout << tokenType[4];
            cout << token << endl;
            Token_List[a][b] = tokenType[4];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[4];
            cout << token << endl;
            Token_List[a][b] = tokenType[4];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

    }

    void STATE11(char c) {
        if (c >= '0' && c <= '9') {
            dfa = 11;
            token = token + c;
        }

        else if (c == ' ') {
            cout << tokenType[4];
            cout << token << endl;
            Token_List[a][b] = tokenType[4];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == ';') {
            cout << tokenType[4];
            cout << token << endl;
            Token_List[a][b] = tokenType[4];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[4];
            cout << token << endl;
            Token_List[a][b] = tokenType[4];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

    }

    void STATE12(char c) {
        if (c != '"') {
            dfa = 12;
            token = token + c;
        }

        else if (c == '"') {
            cout << tokenType[6];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[6];
            Token_List[a][b + 1] = token;
            a++;
            token = "\0";
            dfa = 0;
            return;
        }

    }

    void STATE13(char c) {
        cout << tokenType[5];
        cout << token << endl;
        Token_List[a][b] = tokenType[5];
        Token_List[a][b + 1] = token;
        a++;
        token = "\0";
        dfa = 0;
        return;
    }

    void STATE14(char c) {
        if (c != '\'') {
            dfa = 14;
            token = token + c;
        }

        else if (c == '\'') {
            cout << tokenType[8];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[8];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

    }

    void STATE15(char c) {
        if (c == ':') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << "Unknown Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE16(char c) {
        if (c == ';') {
            cout << "Unknown Token: ";
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[9];
            cout << token << endl;
            Token_List[a][b] = tokenType[9];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE17(char c) {
        if (c == ';') {
            cout << "Unknown Token: ";
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[9];
            cout << token << endl;
            Token_List[a][b] = tokenType[9];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE18(char c) {
        if (c == ' ') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == ';') {
            cout << "Unknown Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE20(char c) {
        if (c == ';') {
            cout << "Unknown Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '-') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '=') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

    }

    void STATE22(char c) {
        if (c == ';') {
            cout << "Unknown Token: ";
            token = token + c;
            cout << token << endl;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '+') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '=') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE24(char c) {
        if (c == ' ') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '<') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == ';') {
            cout << "Unknown Token: ";
            token = token + c;
            cout << token << endl;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE25(char c) {
        if (c == ' ') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '=') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }

        else {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            i--;
            token = "\0";
            dfa = 0;
            return;
        }
    }

    void STATE26(char c) {
        if (c == ' ') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == '>') {
            cout << tokenType[3];
            token = token + c;
            cout << token << endl;
            Token_List[a][b] = tokenType[3];
            Token_List[a][b + 1] = token;
            a++;
            token = "\0";
            dfa = 0;
            return;
        }

        else if (c == ';') {
            cout << "Unknown Token: ";
            token = token + c;
            cout << token << endl;
            token = "\0";
            dfa = 0;
            return;
        }
    }


    void Lexical_Analyzer(string s) 
    {
        int L = s.length();

        for (i; i < L; i++) {
            if (dfa == 0) /* */ STATE00(s[i]);
            else if (dfa == 1)  STATE01(s[i]);
            else if (dfa == 2)  STATE02(s[i]);
            else if (dfa == 3)  STATE03(s[i]);
            else if (dfa == 4)  STATE04(s[i]);
            else if (dfa == 5)  STATE05(s[i]);
            else if (dfa == 6)  STATE06(s[i]);
            else if (dfa == 7)  STATE07(s[i]);
            else if (dfa == 10) STATE10(s[i]);
            else if (dfa == 11) STATE11(s[i]);
            else if (dfa == 12) STATE12(s[i]);
            else if (dfa == 13) STATE13(s[i]);
            else if (dfa == 14) STATE14(s[i]);
            else if (dfa == 15) STATE15(s[i]);
            else if (dfa == 16) STATE16(s[i]);
            else if (dfa == 17) STATE16(s[i]);
            else if (dfa == 18) STATE18(s[i]);
            else if (dfa == 20) STATE20(s[i]);
            else if (dfa == 22) STATE22(s[i]);
            else if (dfa == 24) STATE24(s[i]);
            else if (dfa == 25) STATE25(s[i]);
            else if (dfa == 26) STATE26(s[i]);
        }
    }

};

stack<string> parseStack;

class Syntax
{
public:

    void Syntax_Analyzer(string tokenList[][2], int tokenCount)
    {
        int i = 0;
        string stackTop, inputToken, production;
        parseStack.push("$");
        parseStack.push("E");
        inputToken = tokenList[i][1];

        map<string, map<string, string>> parsingTable;
        parsingTable["E"] = { {"+","E->E+T"},{"-","E->E-T"},{"id","E->id"},{"(","E->T"},{")",""},{"$",""},{"num","E->T"} };
        parsingTable["T"] = { {"","T->TF"},{"/","T->T/F"},{"+",""},{"-",""},{"id","T->id"},{"(","T->F"},{"$",""},{"num","T->F"} };
        parsingTable["F"] = { {"*",""},{"/",""},{"+",""},{"-",""},{"id","F->id"},{"(","F->(E)"},{"$",""},{"num","F->num"} };

        while (i < tokenCount) {
            stackTop = parseStack.top();
            if (stackTop == inputToken) {
                parseStack.pop();
                i++;
                inputToken = tokenList[i][1];
            }
            else {
                production = parsingTable[stackTop][inputToken];
                parseStack.pop();
                if (production != "") {
                    for (int j = production.length() - 1; j >= 3; j--) {
                        parseStack.push(string(1, production[j]));
                    }
                }
                else {
                    cout << "Error: Invalid input At:" << Token_List[i][32] << endl;
                    return;
                }

            }
        }
        if (parseStack.top() == "$" && inputToken == "$") {
            cout << "Parsing successful" << endl;
        }
        else {
            cout << "Parsing failed" << endl;
        }
    }

};



int main() {

    Lexical Analyzer;
    fstream file;
    file.open("code.txt", ios::in);
    stringstream buffer;
    Syntax LL1_Parser;
    string str;


    if (!file.is_open())
        cout << "The file you're looking for doesn't exist, or the program wasn't able to access it." << endl;
    else if (file.is_open()) {
        cout << "FILE CONTENTS: " << endl;
        buffer << file.rdbuf(); // read the entire file into the buffer
        str = buffer.str(); // convert the buffer to a string
        cout << str << endl;

        cout << "\n\nTOKENS:" << endl;
        Analyzer.Lexical_Analyzer(str);
    }

    /*cout << "\n\n\t\tSAVED TOKENS" << endl;
    cout << "Token Type" << "\t\t\t" << "Token" << endl;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 2; j++) {
            cout << Token_List[i][j] << "\t\t\t";
        }
        cout << endl;
    }*/

    int tokenCount = 1;
    for (int i = 0; i < 50; i++) {
        if (Token_List[i][0] != "" || Token_List[i][1] != "") {
            tokenCount++;
        }
    }
    cout << "\nToken Count: " << tokenCount << endl;

    LL1_Parser.Syntax_Analyzer(Token_List, tokenCount);

    return 0;
}