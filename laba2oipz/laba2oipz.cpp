#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <limits>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void checkValidInput() {
    if (cin.fail()) {
        clearInput();
        throw invalid_argument("Incorrect input");
    }
}

void checkValidParams(int n) {
    if (n <= 4) {
        throw logic_error("Input correct data (n must be > 4)");
    }
}

void checkValidParams(double a, double b) {
    if (a > b) {
        throw logic_error("Input correct data (a must be <= b)");
    }
}

void checkValidParams(double h) {
    if (h <= 0) {
        throw logic_error("Input correct data (h must be > 0)");
    }
}

void checkFile(ofstream& fout) {
    if (!fout.is_open()) {
        throw invalid_argument("File error");
    }
}

void typeIntoFile(int writeIntoFile) {
    if (writeIntoFile != 0 && writeIntoFile != 1) {
        throw invalid_argument("Input correct data (0 or 1)");
    }
}

void readData(double& a, double& b, double& h, int& n, int& writeIntoFile) {
    cout << "Введiть n (n > 4): ";
    cin >> n;
    checkValidInput();
    checkValidParams(n);

    cout << "Введiть А (початок iнтервалу): ";
    cin >> a;
    checkValidInput();

    cout << "Введiть кiнець b: ";
    cin >> b;
    checkValidInput();
    checkValidParams(a, b);

    cout << "Введiть крок h: ";
    cin >> h;
    checkValidInput();
    checkValidParams(h);

    cout << "Чи бажаете ви записати результат (1 = так, 0 = нi): ";
    cin >> writeIntoFile;
    checkValidInput();
    typeIntoFile(writeIntoFile);
}

double calculate_y(double x, int n) {
    double y = 0;

    if (x < 0) {
        for (int i = 0; i <= n; i++) {
            double product = 1.0;
            for (int j = i; j <= n - 1; j++) {
                if (i != j) {  // Виправлення!
                    product *= (i - j);
                }
            }
            y += product;
        }
    }
    else {
        for (int i = 1; i <= n - 2; i++) {
            y += (i - x) * (i - x);
        }
    }

    return y;
}

void printResult(double x, double y, int writeIntoFile, ofstream& fout) {
    cout << "x = " << x << "; y = " << y << endl;
    if (writeIntoFile == 1) {
        fout << "x = " << x << "; y = " << y << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    double a, b, h;
    int n;
    int writeIntoFile;
    ofstream fout;

    try {
        readData(a, b, h, n, writeIntoFile);

        if (writeIntoFile == 1) {
            fout.open("notes.txt");
            checkFile(fout);
        }

        for (double x = a; x <= b; x += h) {
            double y = calculate_y(x, n);
            printResult(x, y, writeIntoFile, fout);
        }

        if (fout.is_open()) {
            fout.close();
            cout << "\nРезультати збережено у файл 'notes.txt'" << endl;
        }
    }
    catch (const logic_error& ex) {
        cerr << "Logic error: " << ex.what() << endl;
        return -1;
    }
    catch (const invalid_argument& ex) {
        cerr << "Invalid argument: " << ex.what() << endl;
        return -1;
    }
    catch (...) {
        cerr << "Unknown error" << endl;
        return -2;
    }

    return 0;
}