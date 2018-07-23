#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "Instruction.h"
#include <map>
#include <iterator>

using namespace std; 

void cleanLabels(vector<string>& v);
vector<string> read_file(string file);
void removeComments(string& v);
string cutPeriod (string& s);


int main(int argc, char** argv) {
    string file; 
    vector<string> v;
    
    if (argc > 1) {
        file = argv[1];
    }
    else {
        cout << "what is file name?" << endl;
        cin >> file;
    }
    v = read_file(file);

    ofstream out; 
    string output = "my" + cutPeriod(file) + ".hack"; 
    out.open(output); 

    vector<Instruction> insts; 
    string temp; 
    cleanLabels(v);

    for (int i = 0; i < v.size(); ++i) { 
        temp = v.at(i); 
        insts.push_back(temp); 
        out << insts.at(i).getBin() << endl;
    }
    out.close();

    return 0;
}

void cleanLabels(vector<string>& v) {
    map<string, int> labels;
    map<string, int> symbols;

    // place predefined symbols into symbols map 
    for (int i = 0; i < 16; ++i) 
        symbols.insert(pair<string, int>("R" + to_string(i), i));
    symbols.insert(pair<string, int>("KBD", 24575));
    symbols.insert(pair<string, int>("SCREEN", 16384));
    symbols.insert(pair<string, int>("SP"   , 0));
    symbols.insert(pair<string, int>("LCL"  , 1));
    symbols.insert(pair<string, int>("ARG"  , 2));
    symbols.insert(pair<string, int>("THIS" , 3));
    symbols.insert(pair<string, int>("THAT" , 4));

    int numSymbols = 16;
    int numLabels = 0;
    int temp    = 0;

    // find parenth, save position into labels map and remove parenth
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).find('(') <= v.at(i).length()) {
            v.at(i) = v.at(i).substr(1,v.at(i).length()-2);
            temp = i - numLabels;
            labels[v.at(i)] = temp;
            numLabels++;
            temp = 0;
            v.at(i).erase();
        }
    }

    // replace all @ symbols with respective integer values
    string tempStr = "";
    bool ATexists = false;
    bool isLabel = false;
    bool isSymbol = false;
    for (int i = 0; i < v.size(); ++i) {
        ATexists = v.at(i).find("@") >= 0 && v.at(i).find("@") < v.at(i).length();
        if (ATexists) {
            tempStr = v.at(i).substr(1, v.at(i).length()-1) ;

            isLabel = labels.count(tempStr);
            isSymbol = symbols.count(tempStr);
            if (isLabel) {
                v.at(i) = "@" + to_string(labels.find(tempStr)->second);
            }
            else if (isSymbol) {
                v.at(i) = "@" + to_string(symbols.find(tempStr)->second);
            }
            else if (!isSymbol && isalpha(tempStr[0])) {
                symbols.insert(pair<string, int>(tempStr, numSymbols));
                v.at(i) = "@" + to_string(symbols.find(tempStr)->second);
                numSymbols++;
            }
        }
    }

    // remove empty strings in vector v 
    int i = 0;
    while (i < v.size()) {
        if (v.at(i).empty()) {
            v.erase(v.begin() + i);
        }
        else {
            ++i;
        }
    }
}

string cutPeriod (string& s) {
    for(int i = 0; i < s.length(); ++i) { 
        if (s.at(i) == '.') {
            s = s.substr(0,i);
        }
    }
    return s;
}

void removeComments(string& s) {

    int i = 0;
    s.erase(remove_if(s.begin(), s.end(), [](unsigned char x){return std::isspace(x);}), s.end());


    while (i < s.length()) {
        if (s.at(i) == '/' && s.at(i+1) == '/') {
            s = s.substr(0, i);
        }   
        ++i;
    } 

}

vector<string> read_file(string file) {
    vector<string> v;
    ifstream ifs;
    ifs.open(file);
    string s;
    while (!ifs.eof()) {
        getline(ifs, s, '\n');
        removeComments(s); 
        if (s != "") {
            v.push_back(s);
        }
    }
    ifs.close();

    return v;
}