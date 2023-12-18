#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Newfile(const char* filename) {
    ofstream os(filename);

    if (!os) {
        return "error";
    }

    string str;

    cout << "Save the line to HDD." << endl;
    getline(cin, str);
    os << str << endl;

    os.close();
    return str;
}

void Text(string str) {
    cout << "String without capital letters: ";
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] > 64 && str[i] < 91) {
            str[i] += 32;
        }
        cout << str[i];
    }
    ofstream file("input.txt");

    cout << endl;
}

string Word(string str) {
    string NEword = "";
    string LOword = "";
    int c = 0;
    int max = 0;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            NEword = "";
            c = 0;
            for (size_t j = i; j < str.length(); j++) {
                if (str[j] > 64 && str[j] < 91 || str[j]>96 && str[j] < 123) {
                    c++;
                    NEword += str[j];
                }
                if (str[j] == ' ') {
                    break;
                }
            }
            if (c > max) {
                max = c;
                LOword = NEword;
            }
        }
    }
    return LOword;
}

string Line(string str) {
    string LINE = "";
    string word = "";
    int H = 0;
    int j;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            word = "";
            H = 0;
            for (j = i; j < str.length(); j++) {
                if (str[j] > 64 && str[j] < 91 || str[j]>96 && str[j] < 123) {
                    word += str[j];
                    if (str[j] != 'A' && str[j] != 'E' && str[j] != 'Y' && str[j] != 'U' && str[j] != 'O' && str[j] != 'I' && str[j] != 'o' && str[j] != 'a' && str[j] != 'e' && str[j] != 'y' && str[j] != 'u' && str[j] != 'i') {
                        H++;
                    }
                }
                if (str[j] == ' ') {
                    break;
                }
            }
            i = j;
            if (H % 2 == 0) {
                LINE += word;
                LINE += ' ';
            }
        }
    }
    return LINE;
}

bool File(const char* readFile, const char* writeFile) {

    ifstream rf(readFile, ios::in | ios::binary);

    if (!rf) {
        cout << "Cannot open source file." << endl;
        return false;
    }

    ofstream wf(writeFile, ios::out | ios::binary);

    if (!wf) {
        rf.close();
        cout << "Cannot open the files." << endl;
        return false;
    }

    char sym;

    while (rf) {
        rf.get(sym);
        if (rf) {
            wf << sym;
        }
    }

    cout << "Copy result: OK!" << endl;

    rf.close();
    wf.close();
}

struct ITINERARY {

public:
    void add() {
        cout << "\nFirst: ";
        cin >> FIRST;
        cout << "Final: ";
        cin >> FINAL;
        cout << "Number: ";
        cin >> NUM;
        cout << "Distanse: ";
        cin >> DISTANSE;
        ofstream DataBase("struct.txt", ios::app);
        DataBase << "| " << FIRST << " | " << FINAL << " | " << NUM << " | " << DISTANSE << endl;
    }

    void getWay() {
        cout << "First:    " << FIRST << endl;
        cout << "Final:    " << FINAL << endl;
        cout << "Number:   " << NUM << endl;
        cout << "Distanse: " << DISTANSE << endl;
    }

    void findReq(string key) {
        if (this->FIRST == key || this->FINAL == key || this->NUM == key || this->DISTANSE == key) {
            getWay();
        }
    }

private:
    string FIRST;
    string FINAL;
    string NUM;
    string DISTANSE;
};

void edit() {
    system("notepad.exe struct.txt");
}

void Way() {
    int N;
    cout << "\nEnter number for new itinerarys: " << endl;
    cin >> N;

    ITINERARY* WAY;
    WAY = new ITINERARY[N];
    for (size_t i = 0; i < N; i++)
    {
        WAY[i].add();
    }
    cout << "\nSearch ... ";
    string word;
    cin >> word;
    for (size_t i = 0; i < N; i++)
    {
        WAY[i].findReq(word);
    }
    cout << "\nEnter number. 1-add, 2-dell: ";
    int x;
    cin >> x;
    cout << endl;
    int xz = 0;
    xz = N + 1;
    ITINERARY* NEW;
    int index;
    NEW = new ITINERARY[xz];
    ITINERARY New;
    switch (x) {
    case(1):

        for (int i = 0; i < N; i++)
        {
            NEW[i] = WAY[i];
        }
        New.add();
        NEW[N] = New;
        N = N + 1;
        WAY = NEW;
        break;

    case(2):

        cout << "Enter index of element: " << endl;
        cin >> index;
        for (size_t i = index; i < N - 1; i++)
        {

            WAY[i] = WAY[i + 1];

        }
        N = N - 1;
        for (size_t i = 0; i < N; i++)
        {
            WAY[i].getWay();
        }
        break;

    default:
        break;
    }
}

int main() {
    string str = Newfile("input.txt");
    Text(str);
    cout << "The longest word: " << Word(str) << endl;
    cout << "New string: " << Line(str) << endl;
    File("input.txt", "output.txt");
    Way();
    edit();
    return 0;
}

