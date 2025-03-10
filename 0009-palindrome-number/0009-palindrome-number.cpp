class Solution {
public:
    bool isPalindrome(int x) {
        int copy = x;
        
        /* After the code, revNum will
        contain the reversed number */
        long revNum = 0;

        /* Keep on iterating while there
        are digits left to extract */
        while(x > 0) {
            int lastDigit = x % 10;

            /* Pushing last digit at the
            back of reversed number */
            revNum = (revNum * 10) + lastDigit;
            x = x / 10;
        }
        
        /* Return true if the reversed and 
        copy of original number is same */
        if(revNum == copy) return true;
        return false;
    }
};