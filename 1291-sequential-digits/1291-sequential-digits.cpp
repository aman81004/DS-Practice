class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        std::string digits = "123456789";
        
        // Loop through all possible lengths of substrings (from 2 to 9 digits)
        for (int length = 2; length <= 9; ++length) {
            // Loop through all possible starting positions
            for (int start = 0; start <= 9 - length; ++start) {
                // Extract the sequential substring and convert it to an integer
                std::string sub = digits.substr(start, length);
                int num = std::stoi(sub);
                
                // If it fits our criteria, save it
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        // The generation naturally keeps them sorted by length, but sorting 
        // ensures strict ascending order across all generations.
        std::sort(result.begin(), result.end());
        return result;
        
    }
};