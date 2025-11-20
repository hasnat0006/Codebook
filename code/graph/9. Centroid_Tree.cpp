  const ll n = 1e5;
  vector<ll> sz(n + 5), dead(n + 5);
  function<void(ll, ll)> calculate_sz = [&](ll u, ll p) {
    sz[u] = 1;
    for (auto v : adj[u]) {
      if (v != p and !dead[v]) {
        calculate_sz(v, u);
        sz[u] += sz[v];
      }
    }
    return;
  };

  function<ll(ll, ll, ll)> find_centroid = [&](ll u, ll p, ll total) -> ll {
    for (auto v : adj[u]) {
      if (v != p and !dead[v] and 2 * sz[v] > total)
        return find_centroid(v, u, total);
    }
    return u;
  };


  function<void(ll)> decompose = [&] (ll u) -> void {
    // if needed change the parameter
    calculate_sz(u, -1);
    ll center = find_centroid(u, -1, sz[u]);
    // calculate the ans here
    dead[center] = 1;
    for(auto v : adj[center]) {
        if(!dead[v])
            decompose(v);
    }
  };    
  // call decompose only
  decompose(1);
