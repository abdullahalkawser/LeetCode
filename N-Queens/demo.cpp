class Solution {
    public:
        // Adding the result
        void addQueens(vector<vector<string>> &board, vector<vector<string>> &ans, int n){
            vector<string> temp;
    
            for(int i = 0; i < n; i++){
                string rowStr = "";
                for(int j = 0; j < n; j++){
                    rowStr += board[i][j];
                }
                temp.push_back(rowStr);
            }
    
            ans.push_back(temp);
        }
    
        // Recursive function to try placing queens column by column
        void solve(vector<vector<string>> &board, vector<vector<string>> &ans, int col, int n,
                   unordered_map<int, int> &rowMap,
                   unordered_map<int, int> &leftUpMap,
                   unordered_map<int, int> &leftDownMap){
    
            // Base case: All queens placed successfully
            if(col == n){
                addQueens(board, ans, n);
                return;
            }
    
            for(int row = 0; row < n; row++){
                // Check if placing queen at (row, col) is safe using maps
                if(rowMap[row] == 0 &&
                   leftDownMap[row + col] == 0 &&
                   leftUpMap[n - 1 + col - row] == 0){
    
                    // Place the queen
                    board[row][col] = "Q";
    
                    // Mark current row and diagonals as occupied
                    rowMap[row]++;
                    leftDownMap[row + col]++;
                    leftUpMap[n - 1 + col - row]++;
    
                    // Move to next column
                    solve(board, ans, col + 1, n, rowMap, leftUpMap, leftDownMap);
    
                    // Backtrack: Remove the queen and unmark
                    board[row][col] = ".";
                    rowMap[row]--;
                    leftDownMap[row + col]--;
                    leftUpMap[n - 1 + col - row]--;
                }
            }
        }
    
        // Main function to initialize board and maps
        vector<vector<string>> solveNQueens(int n) {
            // Create an n x n board filled with "."
            vector<vector<string>> board(n, vector<string>(n, "."));
            vector<vector<string>> ans;
    
            // Maps to track whether a row or diagonal is under attack
            unordered_map<int, int> rowMap;
            unordered_map<int, int> leftUpMap;
            unordered_map<int, int> leftDownMap;
    
            // Start backtracking from column 0
            solve(board, ans, 0, n, rowMap, leftUpMap, leftDownMap);
    
            return ans;
        }
    };