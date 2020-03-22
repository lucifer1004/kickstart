#include <iostream>
#include <map>

using namespace std;

struct TrieNode {
  int depth;
  int cnt = 0;
  int used = 0;
  TrieNode *parent = nullptr;
  map<char, TrieNode *> adj;

  TrieNode(int depth, TrieNode *parent) {
    this->depth = depth;
    this->parent = parent;
  }
};

class Trie {
  TrieNode *root;
  int ans = 0;

public:
  Trie() { root = new TrieNode(0, nullptr); };

  void add(const string &s) {
    TrieNode *curr = root;
    curr->cnt++;
    for (char c : s) {
      if (curr->adj.find(c) == curr->adj.end())
        curr->adj[c] = new TrieNode(curr->depth + 1, curr);
      curr = curr->adj[c];
      curr->cnt++;
    }
  }

  void dfs(TrieNode *u, int k) {
    int delta = u->cnt - u->used;
    if (delta >= k)
      for (auto p : u->adj)
        dfs(p.second, k);
    delta = u->cnt - u->used;
    if (delta >= k) {
      ans += delta / k * u->depth;
      u->used += delta / k * k;
    }
    if (u->parent != nullptr)
      u->parent->used += u->used;
  }

  int solve(int k) {
    dfs(root, k);
    return ans;
  }
};

class Solution {
public:
  static void solve(int t) {
    int n, k;
    cin >> n >> k;
    Trie trie = Trie();
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      trie.add(s);
    }
    cout << "Case #" << t << ": " << trie.solve(k) << endl;
  }
};

int main() {
  int t;
  cin >> t;
  int i = 1;
  while (i <= t)
    Solution::solve(i++);
}