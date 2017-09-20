#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

// ------ climbingStaircase
int sum(vector<int> x) {
    int sum = 0;
    for (auto v : x) sum += v;
    return sum;
}

void Attempt(int i, int n, int k, vector<int>& x, vector<vector<int>>& res) {
    for (int j = 1; j <= k; ++j) {
        x[i] = j;
        int sumX = sum(x);
        if (sumX == n) {
            res.push_back(vector<int>(x.begin(), x.begin() + i + 1));
        }
        else if (sumX < n) {
            Attempt(i + 1, n, k, x, res);
        }
        x[i] = 0;
    }
}

std::vector<std::vector<int>> climbingStaircase(int n, int k) {
    vector<vector<int>> res;
    if (n == 0) {
        res.push_back({});
    }
    else {
        vector<int> x(n);
        Attempt(0, n, k, x, res);
    }

    return res;
}

//------------------------------------------------- nQueens

bool OK(int x, int y, vector<int>& a) {
    for (int i = 1; i < x; ++i)
        if (a[i] == y || abs(i-x) == abs(a[i] - y))
            return false;
    return true;
}

void Try(int i, int n, vector<int>& a, vector<vector<int>>& res) {
    for (int j = 1; j <= n; ++j) {
        if (OK(i, j, a)) {
            a[i] = j;
            if (i == n)
                res.push_back(vector<int>(a.begin()+1, a.end()));

            Try(i+1, n, a, res);
        }
    }
}

std::vector<std::vector<int>> nQueens(int n) {
    vector<vector<int>> res;
    vector<int> a(n+1);

    Try(1, n, a, res);
    return res;
}

//------------------------------ sumSubsets

void Attempt(int i, int n, vector<int> arr, int firstJ, vector<int> &x, vector<vector<int>> &res) {
    int k = arr.size();
    for (int j = firstJ; j < k; ++j) {
        x[i] = arr[j];
        int sumX = sum(x);
        if (sumX == n)
            res.push_back(vector<int>(x.begin(), x.begin() + i + 1));
        else if (sumX < n)
            Attempt(i+1, n, arr, j+1, x, res);
        x[i] = 0;
        if (sumX > n) break;
    }
}

std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num) {
    vector<vector<int>> res;
    if (num == 0) return {{}};

    vector<int> x(num);
    Attempt(0, num, arr, 0, x, res);
    set<vector<int>> s(res.begin(), res.end());
    res = vector<vector<int>>(s.begin(), s.end());
    return res;
}

// ---------------------------- wordsBoggle

vector<pair<int, int>> getAround(int J, int K, int m, int n) {
    vector<pair<int, int>> ret;

    if (J > 0) ret.push_back({J-1, K});
    if (J < m-1) ret.push_back({J+1, K});
    if (K > 0) ret.push_back({J, K-1});
    if (K < n-1) ret.push_back({J, K+1});

    if (J > 0 && K > 0) ret.push_back({J-1, K-1});
    if (J > 0 & K < n-1) ret.push_back({J-1, K+1});
    if (J < m-1 && K > 0) ret.push_back({J+1, K-1});
    if (J < m-1 && K < n-1) ret.push_back({J+1, K+1});

    return ret;
}

void Attempt(int i, pair<int, int> prevJK, const string& word, const vector<vector<char>>& board, const int& m, const int& n, vector<vector<bool>> &check, bool& res) {
    vector<pair<int, int>> vPairJK = getAround(prevJK.first, prevJK.second, m, n);
    for (const auto& p : vPairJK) {
        if (board[p.first][p.second] == word[i] && check[p.first][p.second] == false) {
            check[p.first][p.second] = true;
            if (i == word.size() - 1) {
                res = true;
                return;
            }
            else {
                Attempt(i + 1, p, word, board, m, n, check, res);
            }
            check[p.first][p.second] = false;
        }
    }
}

vector<pair<int, int>> chooseFirstJK(const vector<vector<char>>& board, const string& word, const int& m, const int& n) {
    vector<pair<int, int>> ret;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (word[0] == board[i][j]) ret.push_back({i, j});
    return ret;
}

void initCheck(vector<vector<bool>>& check, const int& m, const int& n) {
    check.resize(m);
    for (int i = 0; i < m; ++i) {
        check[i].resize(n);
        for (int j = 0; j < n; ++j) check[i][j] = false;
    }
}

bool wordBoggle(const vector<vector<char>>& board, string word, const int& m, const int& n) {
    vector<pair<int, int>> firstJKs = chooseFirstJK(board, word, m, n);

    // Init check array
    vector<vector<bool>> check;

    // Iterate through firstJKs and check
    bool ret = false;
    for (int i = 0; i < firstJKs.size(); ++i) {
        initCheck(check, m, n);
        check[firstJKs[i].first][firstJKs[i].second] = true;
        Attempt(1, firstJKs[i], word, board, m, n, check, ret);
        if (ret == true) return true;
    }
    return false;
}

std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
    int m = board.size(), n = board[0].size();
    vector<string> ret;

    if (words.size() == 0) return ret;

    for (int i = 0; i < words.size(); ++i) {
        if (wordBoggle(board, words[i], m, n))
            ret.push_back(words[i]);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

// ------------------ combinationSum

string to_string(int i) {
    char buffer[20];
    sprintf(buffer, "%d", i);
    return string(buffer);
}

string toString(vector<int> v) {
    string ret("(");
    int i = 0;
    for (; i < v.size()-1; ++i) ret += to_string(v[i]) + " ";
    ret += to_string(v[i]) + ")";
    return ret;
}

void Attempt(int i, const int& n, const vector<int>& arr, int firstJ, vector<int>& x, string& res) {
    int k = arr.size();
    for (int j = firstJ; j < k; ++j) {
        x[i] = arr[j];
        int sumX = sum(x);
        if (sumX == n) {
            res += toString(vector<int>(x.begin(), x.begin() + i + 1));
        }
        else if (sumX < n) {
            Attempt(i + 1, n, arr, j, x, res);
        }
        x[i] = 0;
        if (sumX > n) break;
    }
}

void preprocessRemoveDuplicateAndSort(vector<int>& a) {
    sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

std::string combinationSum(std::vector<int> a, int sum) {
    string ret = "";
    vector<int> x(sum);

    preprocessRemoveDuplicateAndSort(a);
    Attempt(0, sum, a, 0, x, ret);
    return ret != "" ? ret : "Empty";
}

int main() {
    string s = combinationSum(
            {5, 2, 2, 6},
            3);
    return 0;
}