#include <iostream>      
using namespace std;

// 题目中给出的最大宽度和高度
#define MAX_W 20
#define MAX_H 20

// 待输入的宽度和高度以及已走的步数
int W, H;
int step = 0;
int minStep;
int sRow, sCol;

// 待写入的二维数组
int room[MAX_W][MAX_H];
// 顺时针的可走方向
const int direc[4][2] = {
    { 0, -1 },
    { 1,0 },
    { 0, 1 },
    { -1 ,0 },
};

void dfs(const int& row, const int& col, int step) {
    if (step >= 10 || step > minStep) {
        return;
    }
    for (int d = 0; d < 4; ++d) {
        int cRow = row;
        int cCol = col;
        while (cRow >= 0 && cRow < H && cCol >= 0 && cCol < W) {
            switch (room[cRow][cCol]) {
            case 0: {
                cRow += direc[d][1];
                cCol += direc[d][0];
                break;
            }
            case 3: {
                if (step + 1 < minStep) {
                    minStep = step + 1;
                }
                cRow = -1;
                break;
            }
            case 1: {
                if (!(cRow - direc[d][1] == row && cCol - direc[d][0] == col)) {
                    room[cRow][cCol] = 0;
                    dfs(cRow - direc[d][1], cCol - direc[d][0], step + 1);
                    room[cRow][cCol] = 1;
                }
                cRow = -1;
                break;
            }
            default: {
                break;
            }
            }
        }
    }
}

int main()
{
    while (cin >> W >> H, W > 0) {
        // 输入
        for (int row = 0; row < H; ++row) {
            for (int col = 0; col < W; ++col) {
                cin >> room[row][col];
            }
        }
        // 为2的点为起始点
        for (int row = 0; row < H; ++row) {
            for (int col = 0; col < W; ++col) {
                if (room[row][col] == 2) {
                    sRow = row;
                    sCol = col;
                    break;
                }
            }
        }
        room[sRow][sCol] = 0;
        minStep = 11;
        dfs(sRow, sCol, 0);
        if (minStep > 10) {
            minStep = -1;
        }
        // 输出结果
        cout << minStep << endl;
    }
}
