#include <iostream>
#include <vector>

using namespace std;

bool almostIncreasingSequence0(std::vector<int> sequence) {
    int prev = INT_MIN, preprev = INT_MIN;
    int count = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        if (sequence[i] <= prev) {
            count++;
            if (sequence[i] > preprev)
                prev = sequence[i];
        }
        else {
            preprev = prev;
            prev = sequence[i];
        }
    }
    return count <= 1;
}

bool almostIncreasingSequence1(std::vector<int> sequence) {
    bool a = true, b = true;
    for (int i = 1; i < sequence.size(); i++) {
        if (sequence[i] - sequence[i - 1] <= 0) {
            int temp = sequence[i];
            int j = 0;
            while (j < i - 1) {
                if (temp <= sequence[j]) {
                    a = false;
                    break;
                }
                j++;
            }
            for (int j = i + 1; j < sequence.size(); j++) {
                if (sequence[i] >= sequence[j]) {
                    a = false;
                    break;
                }
            }
        }
        if (sequence[i] - sequence[i - 1] <= 0) {
            int temp1 = sequence[i - 1];
            for (int j = 0; j < i - 1; j++) {
                if (sequence[i - 1] <= sequence[j]) {
                    b = false;
                    break;
                }
            }
            for (int j = i + 1; j < sequence.size(); j++) {
                if (temp1 >= sequence[j]) {
                    b = false;
                    break;
                }
            }
        }
    }
    if ((a == false) && (b == false)) {
        return false;
    }
    return true;
}

bool almostIncreasingSequence2(std::vector<int> a) {
    int n = a.size(), p, c = 0;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] >= a[i + 1]) {
            p = i + 1;
            ++c;
            std::cout << c << " " << p << std::endl;
        }

    if (c > 1) return 0;
    else if (c == 0) return 1;
    else { // c == 1
        if (p == n - 1 || p == 1) return 1;
        else return a[p - 2] < a[p] || a[p - 1] < a[p + 1];
    }
}

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
    int sizeMax = -1, s;
    for (string str : inputArray) {
        if (sizeMax < (s = str.size()))
            sizeMax = s;
        cout << str.size();
    }

    std::cout << sizeMax;

    vector<string> ret;
    for (const auto& str : inputArray) {
        if (str.size() == sizeMax) ret.push_back(str);
    }
    return ret;
}

vector<int> getDigits(int n) {
    vector<int> ret;
    while (n) {
        ret.push_back(n % 10);
        n /= 10;
    }
    return ret;
}

bool isLucky(int n) {
    vector<int> digits = getDigits(n);
    int size = digits.size(), sum1 = 0, sum2 = 0;
    for (int i = 0; i < size / 2; ++i) {
        sum1 += digits[i];
        sum2 += digits[n - 1 - i];
    }
    return sum1 == sum2;
}

int main() {
    bool b = isLucky(1230);
    return 0;
}