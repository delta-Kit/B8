#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    const int num = 982, H = 256, W = 256;
    int h, w, b = 0;
    for(int i = 0; i < num; i++){
        int eps = 1;
        double xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
        //ファイル読み込み
        char fileName[] = "../amebaTxt/ameba0000.txt";
        fileName[17] = i / 1000 + '0';
        fileName[18] = (i / 100) % 10 + '0';
        fileName[19] = (i / 10) % 10 + '0';
        fileName[20] = i % 10 + '0';
        FILE *fp = NULL;
        fp = fopen(fileName, "r");
        if(!i){
            fscanf(fp, "%d %d", &h, &w);
            b = log2(min(h, w));
        }
        vector<vector<int>> black(H, vector<int>(W)), sum(H + 5, vector<int>(W + 5));
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
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
            for(int k = 0; k < H - eps; k += eps){
                for(int l = 0; l < W - eps; l += eps){
                    if(sum[k + eps][l + eps] - sum[k][l + eps] - sum[k + eps][l] + sum[k][l])cnt++;
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
        printf("%f %f\n", (double)i / 30, -(b * xySum - xSum * ySum) / (b * xSqSum - xSum * xSum));
    }
    return 0;
}