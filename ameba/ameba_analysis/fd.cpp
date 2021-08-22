#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    //amebaTxt：num = 982
    //amebaTxt2, 4：num = 1000
    //amebaTxt3：num = 89
    const int num = 1000;
    int H, W, b = 0;
    for(int i = 0; i < num; i++){
        int eps = 1;
        double xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
        //ファイル読み込み
        char fileName[] = "../amebaTxt4/ameba0000.txt";
        fileName[18] = i / 1000 + '0';
        fileName[19] = (i / 100) % 10 + '0';
        fileName[20] = (i / 10) % 10 + '0';
        fileName[21] = i % 10 + '0';
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
        //時刻とフラクタル次元を空白区切りで出力
        printf("%f %f\n", i / 29.97, -(b * xySum - xSum * ySum) / (b * xSqSum - xSum * xSum));
    }
    return 0;
}