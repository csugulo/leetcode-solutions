#include "leetcode_solutions.h"

class Solution {
public:

	bool dfs(vector<vector<char>> & board, vector<vector<bool>> & unuseMap,
		string word, int begin, int i, int j) {
		if (begin == word.size()) return true;
		int rows(board.size()), cols(board[0].size());
		
		// left
		if (j > 0 && unuseMap[i][j - 1] && board[i][j - 1] == word[begin]) {
			unuseMap[i][j - 1] = false;
			if (dfs(board, unuseMap, word, begin + 1, i, j - 1)) return true;
			unuseMap[i][j - 1] = true;
		}

		// right
		if (j < cols - 1 && unuseMap[i][j + 1] && board[i][j + 1] == word[begin]) {
			unuseMap[i][j + 1] = false;
			if (dfs(board, unuseMap, word, begin + 1, i, j + 1)) return true;
			unuseMap[i][j + 1] = true;
		}

		// up
		if (i > 0 && unuseMap[i - 1][j] && board[i - 1][j] == word[begin]) {
			unuseMap[i - 1][j] = false;
			if (dfs(board, unuseMap, word, begin + 1, i - 1, j)) return true;
			unuseMap[i - 1][j] = true;
		}

		// down
		if (i < rows - 1 && unuseMap[i + 1][j] && board[i + 1][j] == word[begin]) {
			unuseMap[i + 1][j] = false;
			if (dfs(board, unuseMap, word, begin + 1, i + 1, j)) return true;
			unuseMap[i + 1][j] = true;
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0) return false;
		if (board[0].size() == 0) return false;
		int rows(board.size()), cols(board[0].size());
		if (word.size() == 0) return true;
		vector<vector<bool>> unuseMap(rows, vector<bool>(cols, true));
		
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (board[i][j] == word[0]) {
					unuseMap[i][j] = false;
					if (dfs(board, unuseMap, word, 1, i, j)) return true;
					unuseMap[i][j] = true;
				}
			}
		}

		return false;
		
	}
};

int main() {
	Solution s;
	vector<vector<char>> board;
	board.push_back({ 'A','B','C','E' });
	board.push_back({ 'S','F','C','S' });
	board.push_back({ 'A','D','E','E' });
	cout << s.exist(board, "BCB") << endl;
	cout << s.exist(board, "BC") << endl;
	cout << s.exist(board, "ABCCED") << endl;
	cout << s.exist(board, "SEE") << endl;
	cout << s.exist(board, "ABCB") << endl;
}