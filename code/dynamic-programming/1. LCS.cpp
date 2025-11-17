/*
Fact about LCS:
1. Longest Increasing Substring
To solve this, we just care about when two char equals. Rest of the things should be neglected.
2. Longest Palindromic Subsequence(LPS)
To solve this, we just take a new string which is the reverse of the original string. Then just call the LCS function to find LPS. 
3. Minimum insertions to make a string palindrome To solve this, we just basically do string length - LPS. Why this? 
    Let's take an example: string s = aabca; Let's say aca is our LPS. Now we find how many char we need to insert to make the string palindrome while our LPS is fixed. 
    a ab c a now to make the string palindrome we just need to insert the reverse of ab after c. So the new string looks like a ab c ba a 
4. Minimum Number of Deletions and Insertions to make the string equals To solve this we just find the LCS of those string then just do: n + m - 2 * LCS.length() where n, m = strings length
*/
