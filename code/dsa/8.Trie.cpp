const ll N = 26;
class Node {
public:
  ll EoW;
  Node *child[N];
  Node() {
    EoW = 0;
    for (ll i = 0; i < N; i++)
      child[i] = NULL;
  }
};

void insert(Node *node, string s) {
  for (size_t i = 0; i < s.size(); i++) {
    ll r = s[i] - 'A';
    if (node->child[r] == NULL)
      node->child[r] = new Node();
    node = node->child[r];
  }
  node->EoW += 1;
}
ll search(Node *node, string s) {
  for (size_t i = 0; i < s.size(); i++) {
    ll r = s[i] - 'A';
    if (node->child[r] == NULL)
      return 0;
  }
  return node->EoW;
}

void prll(Node *node, string s = "") {
  if (node->EoW)
    cout << s << "\n";
  for (ll i = 0; i < N; i++) {
    if (node->child[i] != NULL) {
      char c = i + 'A';
      prll(node->child[i], s + c);
    }
  }
}

bool isChild(Node *node) {
  for (ll i = 0; i < N; i++)
    if (node->child[i] != NULL)
      return true;
  return false;
}

bool isJunc(Node *node) {
  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    if (node->child[i] != NULL)
      cnt++;
  }
  if (cnt > 1)
    return true;
  return false;
}

ll trie_delete(Node *node, string s, ll k = 0) {
  if (node == NULL)
    return 0;
  if (k == (ll)s.size()) {
    if (node->EoW == 0)
      return 0;
    if (isChild(node)) {
      node->EoW = 0;
      return 0;
    }
    return 1;
  }
  ll r = s[k] - 'A';
  ll d = trie_delete(node->child[r], s, k + 1);
  ll j = isJunc(node);
  if (d)
    delete node->child[r];
  if (j)
    return 0;
  return d;
}
void delete_trie(Node *node) {
  for (ll i = 0; i < 15; i++) {
    if (node->child[i] != NULL)
      delete_trie(node->child[i]);
  }
  delete node;
}
