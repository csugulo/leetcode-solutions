#include "leetcode_solutions.h"

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1);
        G[0] = G[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j)  G[i] += G[j-1] * G[i-j];
        } 
        return G[n];   
    }
};

int main(){
    Solution s;
    cout << s.numTrees(0) << endl; 
    cout << s.numTrees(1) << endl; 
    cout << s.numTrees(2) << endl; 
    cout << s.numTrees(3) << endl; 
    cout << s.numTrees(4) << endl; 
    cout << s.numTrees(5) << endl; 
    cout << s.numTrees(6) << endl; 
    cout << s.numTrees(7) << endl; 
    cout << s.numTrees(8) << endl; 
}