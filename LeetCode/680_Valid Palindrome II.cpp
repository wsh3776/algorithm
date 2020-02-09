// 680_Valid Palindrome II
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();

        int i = 0, j = n - 1;
        while (i < j) {
        	if (s[i] != s[j]) return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        	i ++, j --;
        }
    }

    bool isPalindrome(string s, int i, int j) {
    	int n = s.size();

    	while (i < j) {
    		if (s[i] != s[j]) return false;
    		i ++, j --;
    	}
    }
};