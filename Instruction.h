#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std; 



class Instruction {
    
    // beginning and final stage data members
    string inst = "";
    string bin = "";     

    // parser data members
    string lhs = "";
    string rhs = "";
    string jmp = "";
    string AT  = "";

    int Avalue = {};

    // binary data members
    string compB = "";
    string destB = "";
    string jumpB = "";
    


public: 
    Instruction(string i = {}) : inst(i) { 
        update(); 
    }
    string getInstruction() { return inst; }
    void update();
    string testOut();
    string makeDest();
    string makeComp();
    string makeJump();
    string makeAT();
    string getBin() { return bin; };

};

string Instruction::makeDest() {
    string d;
    string case1 = "M";
    string case2 = "D";
    string case3 = "MD";
    string case4 = "A";
    string case5 = "AM";
    string case6 = "AD";
    string case7 = "AMD";
    
    if (lhs.compare(case1) == 0) {
        d = "001";
    }
    else if (lhs.compare(case2) == 0) {
        d = "010";
    }
    else if (lhs.compare(case3) == 0) {
        d = "011";
    }
    else if (lhs.compare(case4) == 0) {
        d = "100";
    }
    else if (lhs.compare(case5) == 0) {
        d = "101";
    }
    else if (lhs.compare(case6) == 0) {
        d = "110";
    }
    else if (lhs.compare(case7) == 0) {
        d = "111";
    }
    else {
        d = "000";
    }
    return d;
}

string Instruction::makeComp() {
    string c = "" ;
    char a = '0';

    string case0  = "0";
    string case1  = "1";
    string case2  = "-1";
    string case3  = "D";
    string case4  = "A";
    string case5  = "!D";
    string case6  = "!A";
    string case7  = "-D";
    string case8  = "-A";
    string case9  = "D+1";
    string case10 = "A+1";
    string case11 = "D-1";
    string case12 = "A-1";
    string case13 = "D+A";
    string case14 = "D-A";
    string case15 = "A-D";
    string case16 = "D&A";
    string case17 = "D|A";

    string case4M  = "M";
    string case6M  = "!M";
    string case8M  = "-M";
    string case10M = "M+1";
    string case12M = "M-1";
    string case13M = "D+M";
    string case14M = "D-M";
    string case15M = "M-D";
    string case16M = "D&M";
    string case17M = "D|M";

    if (rhs.compare(case0) == 0) {
        c = "101010";
        a = '0';
    }
    else if (rhs.compare(case1) == 0) {
        c = "111111";
        a = '0';
    }
    else if (rhs.compare(case2) == 0) {
        c = "111010";
        a = '0';
    }
    else if (rhs.compare(case3) == 0) {
        c = "001100";
        a = '0';
    }
    else if (rhs.compare(case4) == 0) {
        c = "110000";
        a = '0';
    }
    else if (rhs.compare(case4M) == 0) {
        c = "110000";
        a = '1';
    }
    else if (rhs.compare(case5) == 0) {
        c = "001101";
        a = '0';
    }
    else if (rhs.compare(case6) == 0) {
        c = "110001";
        a = '0';
    }
    else if (rhs.compare(case6M) == 0) {
        c = "110001";
        a = '1';
    }
    else if (rhs.compare(case7) == 0) {
        c = "001111";
        a = '0';
    }
    else if (rhs.compare(case8) == 0) {
        c = "110011";
        a = '0';
    }
    else if (rhs.compare(case8M) == 0) {
        c = "110011";
        a = '1';
    }
    else if (rhs.compare(case9) == 0) {
        c = "011111";
        a = '0';
    }
    else if (rhs.compare(case10) == 0) {
        c = "110111";
        a = '0';
    }
    else if (rhs.compare(case10M) == 0) {
        c = "110111";
        a = '1';
    }
    else if (rhs.compare(case11) == 0) {
        c = "001110";
        a = '0';
    }
    else if (rhs.compare(case12) == 0) {
        c = "110010";
        a = '0';
    }
    else if (rhs.compare(case12M) == 0) {
        c = "110010";
        a = '1';
    }
    else if (rhs.compare(case13) == 0) {
        c = "000010";
        a = '0';
    }
    else if (rhs.compare(case13M) == 0) {
        c = "000010";
        a = '1';
    }
    else if (rhs.compare(case14) == 0) {
        c = "010011";
        a = '0';
    }
    else if (rhs.compare(case14M) == 0) {
        c = "010011";
        a = '1';
    }
    else if (rhs.compare(case15) == 0) {
        c = "000111";
        a = '0';
    }
    else if (rhs.compare(case15M) == 0) {
        c = "000111";
        a = '1';
    }
    else if (rhs.compare(case16) == 0) {
        c = "000000";
        a = '0';
    }
    else if (rhs.compare(case16M) == 0) {
        c = "000000";
        a = '1';
    }
    else if (rhs.compare(case17) == 0) {
        c = "010101";
        a = '0';
    }
    else if (rhs.compare(case17M) == 0) {
        c = "010101";
        a = '1';
    }

    return a + c;
}

string Instruction::makeJump() {
    string j = "";
    string case1 = "JGT";
    string case2 = "JEQ";
    string case3 = "JGE";
    string case4 = "JLT";
    string case5 = "JNE";
    string case6 = "JLE";
    string case7 = "JMP";

    if (jmp.compare(case1) == 0) {
        j = "001";
    }
    else if (jmp.compare(case2) == 0) {
        j = "010";
    }
    else if (jmp.compare(case3) == 0) {
        j = "011";
    }
    else if (jmp.compare(case4) == 0) {
        j = "100";
    }
    else if (jmp.compare(case5) == 0) {
        j = "101";
    }
    else if (jmp.compare(case6) == 0) {
        j = "110";
    }
    else if (jmp.compare(case7) == 0) {
        j = "111";
    }
    else {
        j = "000";
    }
    return j;
}

string Instruction::makeAT() {
    char c = AT[0];

    if (isalpha(c)) {
        cout << "Error: mistake in cleanLabels()!" << endl;
    }
    else {
        Avalue = stoi(AT); 
    }

    string binary = std::bitset<16>(Avalue).to_string();
    bin = binary;

    return binary;
}

void Instruction::update() {
    int semiPos = {};
    int equalPos = {};
    int ATPos = {};
    int parPos = {};

    semiPos = inst.find(';');
    if (semiPos > inst.size()) {
        semiPos = -1;
    }
    equalPos = inst.find('=');
    if (equalPos > inst.size()) {
        equalPos = -1;
    }
    ATPos = inst.find('@');
    if (ATPos > inst.size()) {
        ATPos = -1;
    }


    if (equalPos >= 0 && semiPos >= 0) {
        lhs = inst.substr(0, equalPos);
        rhs = inst.substr(equalPos + 1, semiPos - 2);
        jmp = inst.substr(semiPos + 1, inst.length());
    }
    else if (equalPos >= 0 && semiPos < 0) {
        lhs = inst.substr(0, equalPos);
        rhs = inst.substr(equalPos + 1, inst.length());
    }
    else if (equalPos < 0 && semiPos >= 0) {
        rhs = inst.substr(0, semiPos);
        jmp = inst.substr(semiPos + 1, inst.length());
    }
    else if (ATPos >= 0) {
        AT = inst.substr(ATPos + 1 , inst.length());
    }

    if (ATPos < 0) {
        destB = makeDest();

        compB = makeComp();

        jumpB = makeJump();
        
        bin = "111" + compB + destB + jumpB;
    }
    if (ATPos >= 0) {
        makeAT();
    }

}

ostream& operator<<(ostream& out, Instruction inst) {

    out << inst.getInstruction();

    return out;
}