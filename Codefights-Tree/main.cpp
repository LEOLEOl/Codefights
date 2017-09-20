#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

template<typename T>
struct Tree {
    Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
    T value;
    Tree *left;
    Tree *right;
};

typedef Tree<int> Node;
typedef Tree<int>* TREE;


bool helper(Tree<int>* t, int s) {
    if (t == NULL)
        return s == 0;

    if (t->left && t->right)
        return helper(t->left, s - t->value) ||
               helper(t->right, s - t->value);
    else if (t->left)
        return helper(t->left, s - t->value);
    else
        return helper(t->right, s - t->value);
}

bool hasPathWithGivenSum(Tree<int> * t, int s) {
    return helper(t, s);
}

void input() {
    Tree<int>* node3 = new Tree<int>(3);
    Node* node8 = new Node(8);
    node8->left = node3;

    cout << hasPathWithGivenSum(node8, 8);
}

// ---------------------------------

bool checkLR(Node* l, Node* r) {
    if (!l && !r) return true;
    else if ((!l && r) || (l && !r)) return false;
    else {
        if (l->value != r->value) return false;
        else {
            if ((!l->left && r->right) || (l->left && !r->right)) return false;
            if ((!l->right && r->left) || (l->right && !r->left)) return false;
            bool b1 = checkLR(l->left, r->right);
            bool b2 = checkLR(l->right, r->left);
            return b1 && b2;
        }
    }
}

bool checkEqual(Node* t1, Node* t2) {
    if (!t1 && !t2) return true;
    else if ((!t1 && t2) || (t1 && !t2)) return false;
    else {
        if (t1->value != t2->value) return false;
        else {
            if ((!t1->left && t2->left) || (t1->left && !t2->left)) return false;
            if ((!t1->right && t2->right) || (t1->right && !t2->right)) return false;
            bool b1 = checkEqual(t1->left, t2->left);
            bool b2 = checkEqual(t1->right, t2->right);
            return b1 && b2;
        }
    }
}

bool isSubtree(Tree<int> * t1, Tree<int> * t2) {
    if (t1 == NULL) return t2 == NULL;

    if (checkEqual(t1, t2)) return true;

    bool b1 = isSubtree(t1->left, t2);
    bool b2 = isSubtree(t1->right, t2);
    return b1 || b2;
}



//std::string findProfession(int level, int pos) {
//	if (level == 1 && pos == 1) return "Engineer";
//	else {
//		string x = findProfession(level - 1, (pos - 1) / 2 + 1);
//		if (x == "Engineer") {
//			if (pos % 2 == 0) return "Doctor";
//			else return "Engineer";
//		}
//		else {
//			if (pos % 2 == 0) return "Engineer";
//			else return "Doctor";
//		}
//	}
//}

//std::string findProfession(int level, int pos) {
//	if (level == 1 & pos == 1) return "Engineer";
//	else {
//		string x = findProfession(level - 1, (pos - 1 >> 1) + 1);
//
//		if (x == "Engineer") return pos & 1 ? "Engineer" : "Doctor";
//		else return pos & 1 ? "Doctor" : "Engineer";
//	}
//}

std::string findProfession(int level, int pos) {
    if (level == 1 & pos == 1) return "Engineer";
    else return findProfession(level - 1, (pos - 1 >> 1) + 1) == "Engineer" ? (pos & 1 ? "Engineer" : "Doctor") : (pos & 1 ? "Doctor" : "Engineer");
}

int kthLargestInBST(Tree<int>* t, int k, int& pos) {
    // t cannot be NULL
    if (t == NULL) return -1;

    kthLargestInBST(t->left, k, pos);
    ++pos;
    cout << t->value;
    kthLargestInBST(t->right, k, pos);
}

Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    if (inorder.size() == 0) return nullptr;
    else {
        vector<int>::iterator it = std::find(inorder.begin(), inorder.end(), preorder[0]);
        Tree<int>* root = new Tree<int>(preorder[0]);

        int dis = distance(inorder.begin(), it);
        root->left = restoreBinaryTree(vector<int>(inorder.begin(), it), vector<int>(preorder.begin() + 1, preorder.begin() + dis + 1));
        root->right = restoreBinaryTree(vector<int>(it + 1, inorder.end()), vector<int>(preorder.begin() + dis + 1, preorder.end()));
        return root;
    }
}


// ---------------------

pair<int, int> findStringInString(string a, string b) {
    return pair<int, int>(a.find(b), b.length());
}

bool decreaseCompare(pair<int, int> a, pair<int, int> b) {
    if (a.first == -1 && b.first == -1) {
        return a.second > b.second;
    }
    else if (a.first == -1 && b.first != -1) {
        return false;
    }
    else if (a.first != -1 && b.first == -1) {
        return true;
    }
    else {
        if (a.second > b.second) return true;
        else if (a.second < b.second) return false;
        else {
            return a.first < b.first;
        }
    }
}

pair<int, int> findStringsInString(string a, vector<string> b) {
    vector<pair<int, int>> ret;
    int n = b.size();
    pair<int, int> current = findStringInString(a, b[0]);
    for (int i = 1; i < n; ++i) {
        pair<int, int> x = findStringInString(a, b[i]);
        if (decreaseCompare(current, x) == false)
            current = x;
    }
    return current;
}

string findSubstring(string word, vector<string> parts) {
    pair<int, int> p = findStringsInString(word, parts);

    if (p.first != -1) {
        word.insert(p.first, 1, '[');
        word.insert(p.first + p.second + 1, 1, ']');
    }
    return word;
}

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    if (parts.size() > 0) {
        int n = words.size();
        for (int i = 0; i < n; ++i)
            words[i] = findSubstring(words[i], parts);
    }
    return words;
}

// -- deleteBST

void getRightMost(Node *&r, Node *parentR, Node *&q) {
    if (r->right)
        getRightMost(r->right, r, q);
    else {
        q->value = r->value;
        q = r;
        parentR->value < r->value ? parentR->right = r->left : parentR->left = r->left;
    }
}

void deleteRecursive(Node*& r, Node* parentR, int k) {
    if (r == NULL)
        return;
    if (k < r->value)
        deleteRecursive(r->left, r, k);
    else if (k > r->value)
        deleteRecursive(r->right, r, k);
    else {
        Node* q = r;
        if (r->left) // remove the rightmost node from r, put it at the root of r.
            getRightMost(r->left, r, q);
        else { // remove the root r and its right subtree becomes the new r's root.
            if (parentR) parentR->value < r->value ? parentR->right = r->right : parentR->left = r->right;
            else r = r->right;
        }
        delete q;
    }
}

void deleteKey(Node *&root, int k)
{
    deleteRecursive(root, NULL, k);
}

TREE deleteFromBST(TREE t, std::vector<int> queries) {
    for (int i = 0; i < queries.size(); ++i) deleteKey(t, queries[i]);
    return t;
}

void addKey(TREE t, int key) {
    if (key < t->value) {
        if (t->left)
            addKey(t->left, key);
        else
            t->left = new Node(key);
    }
    else if (key > t->value) {
        if (t->right)
            addKey(t->right, key);
        else
            t->right = new Node(key);
    }
}

Node* makeRoot(int key) {
    return new Node(key);
}

int phoneCall(int min1, int min2_10, int min11, int s) {
    int ret = 0;
    if (s < min1) return 0;
    else {
        s -= min1;
        ret += 1;
        int countLoop = 0;
        while (s > min2_10 && countLoop++ < 9) {
            s -= min2_10;
            ret += 1;
        }

        if (s > 0 && countLoop == 10)
            ret += (s / min11);
    }
    return ret;
}

//int main() {
//    phoneCall(1, 2, 1, 6);
//    return 0;
//}