#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

// -------------------- Common Techniques

int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
	const int mod = 1000000007;
	int n = nums.size();

	vector<int> list(n), sums(n);

	for (auto& q : queries) {
		if (q[0] != 0)
			list[q[0] - 1]--;
		list[q[1]]++;
	}

	sums[0] = nums[0] % mod;
	for (int i = 1; i < n; ++i)
		sums[i] = (sums[i - 1] + nums[i]) % mod;

	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum = (sum + sums[i] * list[i]) % mod;

	return sum + (sum < 0) * mod;
}

int arrayMaxConsecutiveSum2(std::vector<int> a) {
	int n = a.size();
	int max, MAX, idx1, idx2;

	max = MAX = a[0];
	idx1 = 0, idx2 = 0;
	for (int i = 1; i < a.size(); ++i) {
		if (max + a[i] > a[i]) {
			max = max + a[i];
			if (max > MAX) {
				MAX = max;
				idx2 = i;
			}
		}
		else {
			max = a[i];
			if (max > MAX) {
				MAX = max;
				idx1 = idx2 = i;
			}
		}
	}
	return MAX;
}


// -------------------------------------------------------

int compare(vector<int> a, vector<int> b) {
	if (a[1] - a[0] != b[1] - b[0]) return (a[1] - a[0]) > (b[1] - b[0]);
	else return a[0] < b[0];
}

std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
	int l = 0, r = -1, n = arr.size();
	int sum = 0;
	vector<vector<int>> rets;

	while (r < n) {
		if (sum == s && (r + 1 >= n || (arr[r + 1] != 0)))
			rets.push_back({ l + 1, r + 1 });

		if (sum <= s && ++r < n)
			sum += arr[r];
		else
			sum -= arr[l++];
	}

	n = rets.size();
	if (n > 0) {
		vector<int> ret = rets[0];
		for (int i = 1; i < n; ++i) {
			if (compare(rets[i], ret))
				ret = rets[i];
		}
		return ret;
	}
	else return vector<int>({ -1 });
}

// ------------------------------------------

void InsertToMap(map<char, int>& m, set<char> s, char c) {
	if (s.count(c) > 0) m[c]++;
}

void EraseFromMap(map<char, int>& m, set<char> s, char c) {
	if (s.count(c) > 0 && m.count(c) > 0) {
		m[c]--;
		if (m[c] == 0) m.erase(c);
	}
}

int compare(pair<int, int> a, pair<int, int> b) {
	if ((a.second - a.first) != (b.second - b.first)) return (a.second - a.first) < (b.second - b.first);
	else return a.first < b.first;
}

std::string minSubstringWithAllChars(std::string s, std::string t) {
	if (s == "" || t == "") return "";
	pair<int, int> ret = {0, 1000};

	int n = s.size();
	set<char> setChar(t.begin(), t.end());

	map<char, int> m;
	int l = 0, r = -1;
	while (r < n) {
		if (m.size() < setChar.size() && ++r < n)
			InsertToMap(m, setChar, s[r]);
		else if (m.size() == setChar.size()) {
			EraseFromMap(m, setChar, s[l++]);
			if (m.size() < setChar.size() && compare({ l - 1, r + 1 }, ret) > 0)
				ret = { l - 1, r + 1 };
		}
	}
	return s.substr(ret.first, ret.second - ret.first);
}

int main() {
    cout << minSubstringWithAllChars("zxyvzbfeiee", "zxe");

    return 0;
}