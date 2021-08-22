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
        char fileName[] = "koch.txt";
        FILE *fp = NULL;
        fp = fopen(fileName, "r");
        if(!i){
            fscanf(fp, "%d %d", &H, &W);
            b = log2(min(H, W));
        }
        vector<vector<int>> black(H, vector<int>(W)), sum(H + 5, vector<int>(W + 5));
        for(int j = 0; j < H; j++){
            for(int k = 0; k < W; k++){
                fscanf(fp, "%d", &black[j][k]);
                black[j][k] = min(1, black[j][k]);
                //2次元累積和の計算
                sum[j + 1][k + 1] = sum[j][k + 1] + sum[j + 1][k] - sum[j][k] + black[j][k];
            }
        }
        fclose(fp);
        //ボックスカウント法
        for(int j = 0; j < b; j++){
            int cnt = 0;
            for(int k = 0; k < H; k += eps){
                for(int l = 0; l < W; l += eps){
                    if(sum[min(k + eps, H)][min(l + eps, W)] - sum[k][min(l + eps, W)] - sum[min(k + eps, H)][l] + sum[k][l])cnt++;
                }
            }
            //最小二乗法
            double x = log(eps), y = log(cnt);
            xySum += x * y;
            xSum += x;
            ySum += y;
            xSqSum += x * x;
            eps *= 2;
        }
        printf("%f %f\n", (double)i / 30, -(b * xySum - xSum * ySum) / (b * xSqSum - xSum * xSum));
    }
    return 0;
}