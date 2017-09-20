#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

#define         SIGMA           256     // alphabet's size

struct TrieNode {
	bool                    _isLeaf;
	vector <TrieNode*>      _children;

	TrieNode() :
		_isLeaf(false),
		_children(vector <TrieNode*>(SIGMA, NULL))
	{}


	TrieNode(bool isLeaf) :
		_isLeaf(isLeaf),
		_children(vector <TrieNode*>(SIGMA, NULL))
	{}

	bool isLeaf()
	{
		return _isLeaf;
	}
};

struct Trie {
	TrieNode* _root;

	void add_string(const string &str)
	{
		TrieNode *p = _root;
		for (size_t i = 0; i < str.size(); ++i) {
			int c = str[i];
			if (p->_children[c] == NULL)
				p->_children[c] = new TrieNode();
			p = p->_children[c];
		}
		p->_isLeaf = true;
	}

	void build(const vector <string> &sstr)
	{
		for (size_t i = 0; i < sstr.size(); ++i)
			add_string(sstr[i]);
	}

	pair <int, int> query(const string &str)
	{
		pair <int, int> res(-1, -1);
		int len = 0;
		for (int i = 0; i < (int)str.size(); ++i) {
			TrieNode *p = _root;
			for (int j = i; j < (int)str.size(); ++j) {
				if (p->_children[(int)str[j]] == NULL)
					break;
				p = p->_children[(int)str[j]];

				if (p->isLeaf() && j - i + 1 > len) {
					len = j - i + 1;
					res.first = i;
					res.second = j + 1;
				}
			}
		}
		return res;
	}

	Trie() :
		_root(new TrieNode())
	{}

	Trie(const vector <string> &sstr)
	{
		_root = new TrieNode();
		build(sstr);
	}
};

std::vector<std::string> findSubstrings_Trie(std::vector<std::string> words, std::vector<std::string> parts) {
	vector<string> ret;
	Trie *tree = new Trie(parts);

	for (size_t i = 0; i < words.size(); ++i) {
		pair <int, int> ans = tree->query(words[i]);
		if (ans.first == -1)
			ret.push_back(words[i]);
		else {
            words[i] = words[i].insert(ans.first, 1, '[').insert(ans.second + 1, 1, ']');
            ret.push_back(words[i]);
            // ret.push_back(words[i].insert(ans.first, 1, '[').insert(ans.second + 1, 1, ']')); // Clion cannot build it, I don't know why.
        }
	}
	return ret;
}

int main()
{
	/*vector <string> texts = { "Apple", "Melon", "Orange", "Watermelon" };
	vector <string> parts = { "a", "mel", "lon", "el", "An" };

	Trie *tree = new Trie(parts);

	for (size_t i = 0; i < texts.size(); ++i) {
	pair <int, int> ans = tree->query(texts[i]);
	if (ans.first == -1)
	cout << texts[i] << "\n";
	else
	cout << texts[i].substr(0, ans.first)
	<< '['
	<< texts[i].substr(ans.first, ans.second - ans.first)
	<< ']'
	<< texts[i].substr(ans.second)
	<< "\n";
	}
	return 0;*/

	vector<string> a = { "Apple", "Melon", "Orange", "Watermelon" };
	vector<string> b = { "a", "mel", "lon", "el", "An", "le" };

	vector<string> words = findSubstrings_Trie(a, b);
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << endl;


	return 0;
}

