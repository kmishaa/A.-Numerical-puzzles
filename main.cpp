#include <iostream>
#include <algorithm>

using namespace std;

string int_to_string(const long long int& i) {
    return to_string(i);
}

int char_to_int(const char& c) {
    return c - '0';
}

char int_to_char(const int& i) {
    return int_to_string(i)[0];
}

string reverse_string(const string& s) {
    string result;
    for (int i = s.size() - 1; i >= 0; i--) {
        result += s[i];
    }
    return result;
}

string remove_the_first_zeros(const string& s) {
    if (s.size() == 0) return s;
    string result = s;
    while (result[0] == '0') {
        result.erase(0, 1);
        if (result.size() == 0) return "0";
    }
    return result;
}

string remove_all_spaces(const string& s) {
    if (s.size() == 0) return s;
    string result = s;
    for (unsigned int i = 0; i < result.size(); i++) {
        if (result[i] == ' ') result.erase(0, 1);
    }
    return result;
}

string decimal_to_binary(const string& s) {
    if (s == "0") return s;
    string result = "";
    string remains = s;
    bool overflow;
    while (remains != string(remains.size(), '0') || overflow) {
        overflow = false;
        for (unsigned int i = 0; i < remains.size(); i++) {
            int divider = char_to_int(remains[i]);
            if (overflow) {
                divider += 10;
                overflow = false;
            }
            if (divider == 0) continue;
            if (divider == 1) {
                overflow = true;
                remains[i] = '0';
                continue;
            }
            if (divider%2 == 1) overflow = true;
            remains[i] = int_to_char(divider / 2);
        }
        if (overflow) result += '1';
        else result += '0';
    }
    return remove_the_first_zeros(reverse_string(result));
}

string decimal_to_binary(const int& i) {
    return decimal_to_binary(int_to_string(i));
}

string fill_in_with_zeros(const string& s) {
    return string(27 - s.size(), '0') + s;
}

int find_changed_discharge(const string& W, const string& binary_number) {
    for (unsigned int i = 0; i < W.size(); i++) {
        if (W[i] != binary_number[i]) return W.size() - 1 - i;
    }
    return -1;
}

char convert_discharge_to_letter(const int& i) {
    const string list_of_chars = "abcdefghijklmnopqrstuvwxyz ";
    return list_of_chars[i];
}

int main() {
    string result = "";
    string W(27, '0');
    int number_of_letters;
    cin >> number_of_letters;
    for (int i = 0; i < number_of_letters; i++) {
        int decimal_number;
        cin >> decimal_number;
        string binary_number = fill_in_with_zeros(decimal_to_binary(decimal_number));
        int changed_discharge = find_changed_discharge(W, binary_number);
        result += convert_discharge_to_letter(changed_discharge);
        W = binary_number;
    }
    cout << result;

    return 0;
}

