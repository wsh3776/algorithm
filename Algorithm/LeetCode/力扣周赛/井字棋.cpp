// 暴力模拟即可
class Solution {
public:
    int a[3][3];
    bool row(int i, int t) {
        for (int k = 0; k < 3; k++) {
            if (a[i][k] != t) {
                return false;
            }
        }
        return true;
    }

    bool col(int j, int t) {
        for (int k = 0; k < 3; k++) {
            if (a[k][j] != t) {
                return false;
            }
        }
        return true;
    }

    bool diag(int k) {
        if (a[0][0] == k && a[1][1] == k && a[2][2] == k) return true;
        if (a[2][0] == k && a[1][1] == k && a[0][2] == k) return true;
        return false;
    }


    string tictactoe(vector<vector<int>> &moves) {
        memset(a, 0, sizeof(a));
        int d = 1;
        for(auto x : moves) {
            if (d & 1) a[x[0]][x[1]] = 1;
            else a[x[0]][x[1]] = 2;
            d ++;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] == 1) {
                    if(row(i, 1) || col(j, 1) || diag(1)) {
                        return "A";
                    }
                } else if (a[i][j] == 2) {
                    if(row(i, 2) || col(j, 2) || diag(2)) {
                        return "B";
                    }
                }
            }
        }

        d--; // size of moves
        if (d == 9) return "Draw";
        return "Pending";

    }
};