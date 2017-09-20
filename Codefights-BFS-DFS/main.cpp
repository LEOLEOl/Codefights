#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
//
// Definition for binary tree:
template<typename T>
struct Tree {
    Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
    T value;
    Tree *left;
    Tree *right;
};

typedef Tree<int> Node;

std::vector<int> traverseTree(Tree<int> * t) {
    vector<int> ret;
    queue<Node*> q;

    if (t) q.push(t);
    while (!q.empty()) {
        Node* qq = q.front();
        q.pop();

        ret.push_back(qq->value);
        if (qq->left) q.push(qq->left);
        if (qq->right) q.push(qq->right);
    }
    return ret;
}

//std::vector<int> largestValuesInTreeRows(Tree<int> * t) {
//	vector<int> ret;
//	vector<pair<int, int>> elementsWithRank;
//	queue<pair<Node*, int>> q;
//
//	if (t) q.push({ t, 0 });
//	while (!q.empty()) {
//		pair<Node*, int> qq = q.front();
//		q.pop();
//
//		elementsWithRank.push_back({ qq.first->value, qq.second });
//
//		if (qq.first->left) q.push({ qq.first->left, qq.second + 1 });
//		if (qq.first->right) q.push({ qq.first->right, qq.second + 1 });
//	}
//
//	if (elementsWithRank.size() > 0) {
//		int k = 0; // Rank of current element
//		for (int i = 0; i < elementsWithRank.size();) {
//			int largest = elementsWithRank[i].first;
//			int j = i + 1;
//			while (k == elementsWithRank[j].second) {
//				if (largest < elementsWithRank[j].first) {
//					largest = elementsWithRank[j].first;
//				}
//				++j;
//			}
//			ret.push_back(largest);
//			i = j;
//			++k;
//		}
//	}
//
//	return ret;
//}

vector<int> largestValuesInTreeRows(Tree<int> * t) {
    vector<int> ret;

    if (t) {
        queue<Node*> q;
        q.push(t);
        while (!q.empty()){
            int n = q.size();
            int largest = INT_MIN;
            for (int i = 0; i < n; i++){
                t = q.front();
                q.pop();
                largest = max(largest, t->value);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ret.push_back(largest);
        }
    }

    return ret;
}

// ---------------------------------------------

void traverse(Node* root, vector<Node*> path, vector<vector<Node*>>& listPath) {
    if (root) path.push_back(root);
    else return;

    if (!root->left && !root->right)
        listPath.push_back(path);
    else {
        if (root->left) traverse(root->left, path, listPath);
        if (root->right) traverse(root->right, path, listPath);

//        if (root->left) traverse(root->left, vector<Node*>(path), listPath);
//        if (root->right) traverse(root->right, vector<Node*>(path), listPath);
    }
}

long long convertVectorNodeToInt(vector<Node*> nodes) {
    int n = nodes.size();
    long long ret = 0;

    for (int i = 0; i < n; ++i)
        ret += nodes[i]->value * pow(10, n - 1 - i);
    return ret;
}

long long digitTreeSum(Tree<int> * t) {
    vector<Node*> path;
    vector<vector<Node*>> listPath;
    traverse(t, path, listPath);

    long long ret = 0;
    for (int i = 0; i < listPath.size(); ++i)
        ret += convertVectorNodeToInt(listPath[i]);
    return ret;
}

 // ---- longestPath
void replaceAllOccurrences(string& s, string a, string b) {
    int found, startPos = 0;
    while ((found = s.find(a, startPos)) != string::npos) {
        s.replace(found, 4, b);
        startPos = found + 1;
    }
}

string longestPath(std::string fileSystem) {
    int found, startPos = 0;

    // Replace all 4 spaces with a tab
    replaceAllOccurrences(fileSystem, "    ", "\t");

    // Find the deepest
    string p = "\r";
    int i = 0;
    while (fileSystem.find(p) != string::npos && ++i)
        p += "\t";
    p.resize(p.size() - 1);
    --i;

    vector<int> vPos;
    startPos = 0;
    while ((startPos = fileSystem.find(".", startPos)) != string::npos) {
        vPos.push_back(startPos);
        startPos++;
    }


    startPos = fileSystem.rfind("\t", vPos[0]);
    int x;
    i = 0;
    while ((x = fileSystem.rfind("\t", startPos - 1)) != string::npos && ++i) {
        if (startPos - x != 1) break;
        startPos = x;
    }

    p = "\r";
    for (int j = 0; j < i - 1; ++j) p += "\t";

    x = fileSystem.rfind(p, startPos - 2);
    string str = fileSystem.substr(x, p.length() + 1);
    if (str[str.length() - 1] == '\t')
        return p;

    return p;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}