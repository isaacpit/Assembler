#include <iostream>
#include <fstream>
#include <string> 
#include <sstream> 
#include <vector>

using namespace std;

class File {
    vector<string> data;

    public:
    vector<string> getData() { return data; }
    File(string fileName);
};

File::File(string fileName) {
    string line;
    ifstream ifs;
    ifs.open(fileName);
    if (!ifs) {
        cout << "error opening file!" << endl;
    }
    else {
        while (!ifs.eof()) {
            getline(ifs, line);
            data.push_back(line);
        }
    }
}


bool compare(File file1, File file2, char* arg = new char('n')) {
    bool equal = true;
    string line1 = "";
    string line2 = "";
    char* caseNull = new char('n');
    char* casePrint = new char('p');

    if (file1.getData().size() != file2.getData().size()) {
        equal = false;
    }
    else {
        for (int i = 0; i < file1.getData().size(); ++i) {
            line1 = file1.getData().at(i);
            line2 = file2.getData().at(i);
            if (strncmp (arg, caseNull, 1) == 0) {
                // print nothing
            }
            else if (strncmp (arg, casePrint, 1) == 0) {
                // print files for comparison
                cout << "line " << i << ":" << endl;
                cout << line1 << endl;
                cout << line2 << endl << endl;
            }

            if (line1.compare(line2) != 0) {
                equal = false;
            }
        }
    }

    return equal;
}

int main(int argc, char** argv ) {
    string file1 = "";
    string file2 = "";
    char* p = new char('p');

    cout << "name of file1? " << endl;
    cin >> file1;
    cout << "name of file2? " << endl;
    cin >> file2;

    File f1(file1);
    File f2(file2);

    if (argc == 2 && strncmp( argv[1], p, 1)) {
        if (compare(f1, f2, argv[1])) {
            cout << "files are equal. " << endl;
        }
        else {
            cout << "files are not equal. " << endl;
        }
    }
    else {
        if (compare(f1, f2)) {
            cout << "files are equal. " << endl;
        }
        else {
            cout << "files are not equal. " << endl;
        }
    }




    return 0;
}