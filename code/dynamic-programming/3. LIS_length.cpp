vector<ll> v = {7, 3, 5, 3, 6, 2, 9, 8};
vector<ll> seq;
/*
here we basically check is the current element from v is greater than the last element of the sequence. if it is then push it to the seq array and if not then replace that index value. let's take an example: 
v = 7 3 5 3 6 2 9 8 
1st iteration seq = 7; 
2nd iteration seq = 3; 
3rd iteration seq = 3 5; 
4th iteration seq = 3 3; 
5th iteration seq = 3 3 6; 
6th iteration seq = 2 3 6; 
7th iteration seq = 2 3 6 9;
8th iteration seq = 2 3 6 8;
*/
for (auto i : v) {
  auto id = lower_bound(seq.begin(), seq.end(), i);
  if (id == seq.end())
    seq.push_back(i);
  else
    seq[id - seq.begin()] = i;
}
cout << seq.size() << endl;
