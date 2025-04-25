#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Задание 1
float mean(const vector<float>& v) {
    if (v.empty()) return 0;
    float sum = 0;
    for (float num : v) sum += num;
    return sum / v.size();
}

// Задание 2
pair<float, float> minMax(const vector<float>& v) {
    if (v.empty()) return {numeric_limits<float>::max(), numeric_limits<float>::min()};
    
    float min_val = v[0], max_val = v[0];
    for (float num : v) {
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }
    return {min_val, max_val};
}

// Задание 3
int argmax(const vector<float>& v) {
    if (v.empty()) return -1;
    
    int max_index = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[max_index]) max_index = i;
    }
    return max_index;
}

// Задание 4
void sort(vector<float>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] < v[j]) {
                float temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Задание 5
bool remove_first_negative_element(vector<int>& v, int& removed_element) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            removed_element = v[i];
            v.erase(v.begin() + i);
            return true;
        }
    }
    removed_element = 0;
    return false;
}

// Задание 6
string replace(const string& str, const string& old_s, const string& new_s) {
    string result = str;
    size_t pos = 0;
    while ((pos = result.find(old_s, pos)) != string::npos) {
        result.replace(pos, old_s.length(), new_s);
        pos += new_s.length();
    }
    return result;
}

// Задание 7
vector<string> split(const string& s, char sep) {
    vector<string> result;
    string current;
    for (char c : s) {
        if (c == sep) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) result.push_back(current);
    return result;
}

// Задание 8
string join(const vector<string>& v, const string& sep) {
    string result;
    for (int i = 0; i < v.size(); i++) {
        result += v[i];
        if (i != v.size() - 1) result += sep;
    }
    return result;
}

int main() {
    // Примеры использования функций
    vector<float> v1 = {1.5, 2.5, 3.5};
    cout << mean(v1) << endl;

    auto mm = minMax(v1);
    cout << mm.first << " " << mm.second << endl;

    cout << argmax(v1) << endl;

    sort(v1);
    for (float num : v1) cout << num << " ";
    cout << endl;

    vector<int> v2 = {1, -2, 3, -4};
    int removed;
    if (remove_first_negative_element(v2, removed)) {
        cout << "Removed: " << removed << endl;
    }

    string s = "Can you can a can as a canner can can a can?";
    cout << replace(s, "can", "CAN") << endl;

    vector<string> words = split(s, ' ');
    for (const string& word : words) cout << word << endl;

    cout << join(words, " ") << endl;

    return 0;
}
