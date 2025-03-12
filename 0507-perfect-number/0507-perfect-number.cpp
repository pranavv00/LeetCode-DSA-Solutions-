class Solution {
public:
    bool checkPerfectNumber(int n) {
        int sum = 0;
        
        // Loop from 1 to n
        for(int i=1; i < n; i++) {
            
            // Check if i is a proper divisor
            if(n % i == 0){
                // Update sum
                sum = sum + i;
            }
        }
        
        // Compare sum and n
        if(sum == n) return true;
        return false;
    }
};