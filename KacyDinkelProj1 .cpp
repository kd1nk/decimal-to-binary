// CSCI321 Project 01
// Kacy Dinkel
// 8/22/2024

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int binary_to_decimal(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: the positive decimal integer that is represented by s

string decimal_to_binary(int n);
// precondition: n is a positive integer
// postcondition: nâ€™s binary representation is returned as a string of 0s and 1s
string add_binaries(string b1, string b2);
// precondition: b1 and b2 are strings that consists of 0s and 1s, i.e.
//               b1 and b2 are binary representations of two positive integers
// postcondition: the sum of b1 and b2 is returned. For instance,
//  if b1 = â€œ11â€, b2 = â€œ01â€, then the return value is â€œ100â€


void menu();
// display the menu. Student shall not modify this function
int grade();
// returns an integer that represents the studentâ€™s grade of this projects.
// Student shall NOT modify
bool is_binary(string s);
// returns true if the given string s consists of only 0s and 1s; false otherwise
bool test_binary_to_decimal();
// returns true if the studentâ€™s implementation of binary_to_decimal function
// is correct; false otherwise. Student shall not modify this function
bool test_decimal_to_binary();
//  returns true if the studentâ€™s implementation of decimal_to_binary function is correct; false otherwise. Student shall not modify this function
bool test_add_binaries();
// which returns true if the studentâ€™s implementation of add_binaries function
// is correct; false otherwise. Student shall not modify this function

int main()
{
    int choice;
    string b1, b2;
    int x, score;
    do {
        // display menu
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        // based on choice, perform tasks
        switch (choice) {
            case 1:
                cout << "Enter a binary string: ";
                cin >> b1;
                if (!is_binary(b1))
                    cout << "It is not a binary number\n";
                else
                    cout << "Its decimal value is: " << binary_to_decimal(b1) << endl;
                break;

            case 2:
                cout << "Enter a positive integer: ";
                cin >> x;
                if (x <= 0)
                    cout << "It is not a positive integer" << endl;
                else
                    cout << "Its binary representation is: " << decimal_to_binary(x) << endl;
                break;

            case 3:
                cout << "Enter two binary numbers, separated by white space: ";
                cin >> b1 >> b2;
                if (!is_binary(b1) || !is_binary(b2))
                    cout << "At least one number is not a binary" << endl;
                else
                    cout << "The sum is: " << add_binaries(b1, b2) << endl;
                break;

            case 4:
                score = grade();
                cout << "If you turn in your project on blackboard now, you will get " << score << " out of 10" << endl;
                cout << "Your instructor will decide if one or two more points will be added or not based on your program style, such as good comments (1 point) and good efficiency (1 point)" << endl;
                break;

            case 5:
                cout << "Thanks for using the binary calculator program. Goodbye" << endl;
                break;
            default:
                cout << "Wrong choice. Please choose 1-5 from the menu" << endl;
                break;
        }

    } while (choice != 5);
    return 0;
}

int binary_to_decimal(string s) {
    int decimal = 0;
    int base = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

string decimal_to_binary(int n) {
    if (n == 0) {
        return "0";
    }
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

string add_binaries(string b1, string b2) {
    int carry = 0;
    string result = "";
    int i = b1.length() - 1;
    int j = b2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int bit1 = (i >= 0) ? (b1[i--] - '0') : 0;
        int bit2 = (j >= 0) ? (b2[j--] - '0') : 0;

        int sum = bit1 + bit2 + carry;
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }
    return result;
}

void menu() {
    cout << "******************************\n";
    cout << "*          Menu              *\n";
    cout << "* 1. Binary to Decimal       *\n";
    cout << "* 2. Decimal to Binary       *\n";
    cout << "* 3. Add two Binaries        *\n";
    cout << "* 4. Grade                   *\n";
    cout << "* 5. Quit                    *\n";
    cout << "******************************\n";
}

int grade() {
    int result = 0;
    // binary_to_decimal function worth 3 points
    if (test_binary_to_decimal()) {
        cout << "binary_to_decimal function pass the test" << endl;
        result += 3;
    }
    else
        cout << "binary_to_decimal function failed" << endl;

    // decimal_to_binary function worth 2 points
    if (test_decimal_to_binary()) {
        cout << "decimal_to_binary function pass the test" << endl;
        result += 2;
    }
    else
        cout << "decimal_to_binary function failed" << endl;

    // add_binaries function worth 3 points
    if (test_add_binaries()) {
        cout << "add_binaries function pass the test" << endl;
        result += 3;
    }
    else
        cout << "add_binaries function failed" << endl;
    return result;
}

bool is_binary(string s) {
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '0' && s[i] != '1') // s is not 0 or 1
            return false; // is not a binary number representation
    return true;
}

bool test_binary_to_decimal() {
    if (binary_to_decimal("0") != 0 || binary_to_decimal("1") != 1)
        return false;
    if (binary_to_decimal("010") != 2 || binary_to_decimal("10") != 2)
        return false;
    if (binary_to_decimal("01101") != 13 || binary_to_decimal("1101") != 13)
        return false;
    return true;
}

bool test_decimal_to_binary() {
    if (decimal_to_binary(0) != "0" || decimal_to_binary(1) != "1")
        return false;
    if (decimal_to_binary(2) != "10" || decimal_to_binary(13) != "1101")
        return false;
    return true;
}

bool test_add_binaries() {
    if (add_binaries("0", "0") != "0") return false;
    if (add_binaries("0", "110101") != "110101") return false;
    if (add_binaries("1", "110111") != "111000") return false;
    if (add_binaries("101", "111011") != "1000000") return false;
    return true;
}