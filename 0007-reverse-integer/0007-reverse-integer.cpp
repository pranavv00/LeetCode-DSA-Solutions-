class Solution {
public:
    int reverse(int x) {
        int count = 0;
        while (x != 0) {
            int lastdigit = x % 10;
            
            // Check for overflow before updating count
            if (count > INT_MAX / 10 || (count == INT_MAX / 10 && lastdigit > 7)) 
                return 0;
            if (count < INT_MIN / 10 || (count == INT_MIN / 10 && lastdigit <-8)) 
                return 0;

            count = count * 10 + lastdigit;
            x = x / 10;
        }
        return count;
    }
};
