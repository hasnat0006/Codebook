ll calculateGrundy(ll n, vector<ll> &grundy, const vector<ll> &moves)
{
    if (grundy[n] != -1)
        return grundy[n];
    unordered_set<ll> s;
    for (ll move : moves)
    {
        if (n >= move)
        {
            s.insert(calculateGrundy(n - move, grundy, moves));
        }
    }
    ll g = 0;
    while (s.count(g))
        g++;
    return grundy[n] = g;
}
vector<ll> computeGrundy(ll maxN, const vector<ll> &moves)
{
    vector<ll> grundy(maxN + 1, -1);
    grundy[0] = 0;
    for (ll i = 1; i <= maxN; ++i)
    {
        calculateGrundy(i, grundy, moves);
    }
    return grundy;
}
