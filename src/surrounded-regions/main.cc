class Solution {
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
            
            
        int _dx[4] = {-1, 0, 1, 0},
            _dy[4] = {0, -1, 0, 1};
        dx.assign(_dx, _dx + 4);
        dy.assign(_dy, _dy + 4);
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push(make_pair(i, 0));
            }
            if (m > 1 && board[i][m - 1] == 'O') {
                q.push(make_pair(i, m - 1));
            }
        }
        
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push(make_pair(0, j));
            }
            if (n > 1 && board[n - 1][j] == 'O') {
                q.push(make_pair(n - 1, j));
            }
        }
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            
            board[x][y] = 'E';
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    vector<int> dx, dy;
    int n, m;

};
