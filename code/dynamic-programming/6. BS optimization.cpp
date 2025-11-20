bitset<100005> bs = 1;
for (auto i : a) {
  bs |= (bs << i); 
  // if previous 1 value pos is possible now ith bit or ith sm is also possible
}
cout << bs.count() - 1 << endl;
for (ll i = 1; i <= 100003; i++)
  if (bs[i])
    cout << i << " ";
cout << endl;
