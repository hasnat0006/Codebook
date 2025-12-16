vector<ll> next_smallest(vector<ll> v) {
  ll n = v.size();
  vector<ll> nextS(n, n);
  stack<ll> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() and v[i] < v[st.top()]) {
      nextS[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  return nextS;
}

vector<ll> prev_smallest(vector<ll> v) {
  ll n = v.size();
  vector<ll> prevS(n, -1);
  stack<ll> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && v[i] < v[st.top()])
      st.pop();
    if (!st.empty())
      prevS[i] = st.top();
    st.push(i);
  }
  return prevS;
}