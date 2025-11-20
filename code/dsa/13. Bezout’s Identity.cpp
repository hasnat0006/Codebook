/*
Bezout's Identity (formatted notes)

Let gcd(a, b) = g. Then:
- There exist integers x, y such that a*x + b*y = g.
- All integers of the form a*x + b*y are exactly the multiples of g.

Properties:
- Adding or subtracting multiples doesn't change gcd:
    a ≡ b (mod g)  ⟺  g | (a − b)
- If gcd(a, b) = 1, then any integer can be expressed as a*x + b*y.
- If gcd(a, b) = g, then any multiple of g can be expressed as a*x + b*y.
- gcd(a, b) = gcd(a − b, b) = gcd(a, b − a)
- If gcd(a, b) = g then gcd(a / g, b / g) = 1
- gcd(k*a, k*b) = k * gcd(a, b)

Application (modular inverse):
- If gcd(a, m) = 1, Bézout's identity gives a*x + m*y = 1,
  so a*x ≡ 1 (mod m) and x is the modular inverse of a modulo m.
  (Useful when modulus m is not prime.)
*/
