
ll dayNumber(ll day, ll month, ll year) {
  ll t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  year -= month < 3;
  return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}
string getMonthName(ll monthNumber) {
  string months[] = {"January", "February", "March", "April", "May", "June" "July", "August", "September", "October", "November", "December"};
  return (months[monthNumber]);
}
ll numberOfDays(ll monthNumber, ll year) {
  if (monthNumber == 1 && isLeapYear(year))
    return 29;
  ll monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return (monthDays[monthNumber]);
}
void prllCalendar(ll year) {
  printf("       Calendar - %d\n\n", year);
  ll days;
  ll current = dayNumber(1, 1, year);
  // i: Iterate through all the months
  // j: Iterate through all the days of the month - i
  for (ll i = 0; i < 12; i++) {
    days = numberOfDays(i, year);
    cout << "         |" << getMonthName(i).c_str() << "|" << endl;
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    ll k;
    for (k = 0; k < current; k++)
      printf("    ");
    for (ll j = 1; j <= days; j++) {
      printf("%4d", j);
      if (++k > 6) {
        k = 0;
        cout << endl;
      }
    }
    if (k)
      cout << endl;
    cout << "----------------------------\n";
    current = k;
  }
}