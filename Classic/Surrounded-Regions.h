#ifndef SURROUNDED_REGIONS_H_
#define SURROUNDED_REGIONS_H_

/*
 * Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	if (board.size() == 0 || board[0].size() == 0) {
    		return;
    	}
    	int rows = board.size();
    	int cols = board[0].size();
    	for (int i = 0; i < cols; ++i) {
    		if (board[0][i] == 'O') {
    			dfs(board, 0, i, rows, cols);
    		}
    		if (board[rows-1][i] == 'O') {
    			dfs(board, rows-1, i, rows, cols);
    		}
    	}
    	for (int i = 0; i < rows; ++i) {
    		if (board[i][0] == 'O') {
    			dfs(board, i, 0, rows, cols);
    		}
    		if (board[i][cols-1] == 'O') {
    			dfs(board, i, cols-1, rows, cols);
    		}
    	}
    	for (int i = 0; i < rows; ++i) {
    		for (int j = 0; j < cols; ++j) {
    			if (board[i][j] == 'O') {
    				board[i][j] = 'X';
    			}
    			if (board[i][j] == 'H') {
    				board[i][j] = 'O';
    			}
    		}
    	}
    }
    void dfs(vector<vector<char>> &board, int row, int col, int rows, int cols) {
    	if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == "X" || board[row][col] == 'H') {
    		return;
    	}
    	else {
    		board[row][col] = 'H';
    		dfs(board, row-1, col, rows, cols);
    		dfs(board, row+1, col, rows, cols);
    		dfs(board, row, col-1, rows, cols);
    		dfs(board, row, col+1, rows, cols);
    	}
    }
};



#endif /* SURROUNDED_REGIONS_H_ */
