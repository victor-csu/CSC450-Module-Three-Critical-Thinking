/*
 * Program: Integer Pointers Program
 * a program that will take three integer inputs from a user using an instantiated pointer.
 * The program prints the values of the pointers and their reference.
 * The program deallocates the pointer memories initialised using the "new" keyword.
 */

#include <iostream>
#include <string>
#include <regex>

using namespace std::regex_constants;

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::regex;
using std::regex_replace;
using std::regex_match;
using std::runtime_error;
using std::stoi;
/*
 * str_trim
 * trims the leading and trailing whitespaces in a string
 * avoids mutating original string
 * returns the trimmed string
 */
string str_trim(const string& value) {
    string s;

    s.assign(value);

    return regex_replace(
            regex_replace(s, regex( "^\\s+$" ), ""),
            regex( "\\s+$" ),
            ""
    );
}

/*
 * get_input
 * asks a user to enter an integer
 * recursive
 *
 * returns the input integer pointer
 */
int* get_input(const string& instruction) {
    try {
        cout << instruction;

        string input;

        getline(cin, input);

        string trimmed_input = str_trim(input);

        int *pointer = new int;
        *pointer = stoi(trimmed_input);

        return pointer;
    } catch (const runtime_error& error) {
        cout << error.what();

        return get_input(instruction);
    }
}

int main() {
    cout << "Collecting Three Integer Inputs.\n";

    int* first_input_pointer(get_input("Enter the first integer: "));
    int* second_input_pointer(get_input("Enter the second integer: "));
    int* third_input_pointer(get_input("Enter the third integer: "));

    int first_input = *first_input_pointer;
    int second_input = *second_input_pointer;
    int third_input = *third_input_pointer;

    cout << "First Input Pointer: " << first_input_pointer << "\n";
    cout << "First Input Value: " << first_input << "\n";
    cout << "Second Input Pointer: " << second_input_pointer << "\n";
    cout << "Second Input Value: " << second_input << "\n";
    cout << "Third Input Pointer: " << third_input_pointer << "\n";
    cout << "Third Input Value: " << third_input << "\n";

    delete first_input_pointer;
    delete second_input_pointer;
    delete third_input_pointer;

    return 0;
}
