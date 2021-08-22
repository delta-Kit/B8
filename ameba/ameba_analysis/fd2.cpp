#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    const int num = 1;
    int H, W, b = 0;
    for(int i = 0; i < num; i++){
        int eps = 1;
        double xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
        char fileName[] = "line.txt";
        FILE *fp = NULL;
        fp = fopen(fileName, "r");
        if(!i){
            fscanf(fp, "%d %d", &H, &W);
            b = log2(min(H, W));
        }
        vector<int> sum(b);
        vector<vector<vector<int>>> black(b, vector<vector<int>>(H, vector<int>(W)));
        for(int j = 0; j < H; j++){
            for(int k = 0; k < W; k++){
                fscanf(fp, "%d", &black[0][j][k]);
                if(black[0][j][k])sum[0]++;
                int x = j, y = k;
                for(int l = 0; l < b - 1; l++){
                    if(black[l][x][y] && !black[l + 1][x / 2][y / 2]){
                        sum[l + 1]++;
                        black[l + 1][x / 2][y / 2]++;
                    }else{
                        break;
                    }
                    x /= 2;
                    y /= 2;
                }
            }
        }
        fclose(fp);
        for(int j = 0; j < b; j++){
            //最小二乗法
            double x = log(pow(2, j)), y = log(sum[j]);
            //printf("%f %f\n", x, y);
            xySum += x * y;
            xSum += x;
            ySum += y;
            xSqSum += x * x;
        }
        printf("%f %f\n", (double)i / 30, -(b * xySum - xSum * ySum) / (b * xSqSum - xSum * xSum));
    }
    return 0;
}