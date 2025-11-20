ll cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}
bool intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
  ll c1 = cross(x1, y1, x2, y2, x3, y3), c2 = cross(x1, y1, x2, y2, x4, y4),
     c3 = cross(x3, y3, x4, y4, x1, y1), c4 = cross(x3, y3, x4, y4, x2, y2);
  if ((!c1 && min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 &&
       y3 <= max(y1, y2)) |
      (!c2 && min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y1, y2) <= y4 &&
       y4 <= max(y1, y2)) |
      (!c3 && min(x3, x4) <= x1 && x1 <= max(x3, x4) && min(y3, y4) <= y1 &&
       y1 <= max(y3, y4)) |
      (!c4 && min(x3, x4) <= x2 && x2 <= max(x3, x4) && min(y3, y4) <= y2 &&
       y2 <= max(y3, y4)))
    return true;
  return (c1 > 0) != (c2 > 0) && (c3 > 0) != (c4 > 0);
}
