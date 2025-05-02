class Solution {
    public:
        string pushDominoes(string dominoes) {
            int N = dominoes.size();
            vector<int> indexes = {-1};  // Start with virtual 'L'
            vector<char> symbols = {'L'};
            
            for (int i = 0; i < N; ++i) {
                if (dominoes[i] != '.') {
                    indexes.push_back(i);
                    symbols.push_back(dominoes[i]);
                }
            }
    
            indexes.push_back(N);  // End with virtual 'R'
            symbols.push_back('R');
    
            string ans = dominoes;
    
            for (int index = 0; index < (int)indexes.size() - 1; ++index) {
                int i = indexes[index], j = indexes[index + 1];
                char x = symbols[index], y = symbols[index + 1];
    
                if (x == y) {
                    for (int k = i + 1; k < j; ++k) {
                        ans[k] = x;
                    }
                } else if (x == 'R' && y == 'L') {
                    for (int k = i + 1; k < j; ++k) {
                        if (k - i == j - k) ans[k] = '.';
                        else if (k - i < j - k) ans[k] = 'R';
                        else ans[k] = 'L';
                    }
                }
                // If x == 'L' and y == 'R', leave them as '.'
            }
    
            return ans;
        }
    };
    