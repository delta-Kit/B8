#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int num, H, W, boxNum = 0;
    for(int i = 0; i < num; i++){
        int two = 1;
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
            fscanf(fp, "%d %d %d", &num, &H, &W);
            boxNum = log2(min(H, W)) + 1;
        }
        vector<vector<int>> isAmeba(H, vector<int>(W)), sum(H + 5, vector<int>(W + 5));
        for(int j = 0; j < H; j++){
            for(int k = 0; k < W; k++){
                fscanf(fp, "%d", &isAmeba[j][k]);
                isAmeba[j][k] = min(1, isAmeba[j][k]);
                //2次元累積和の計算
                sum[j + 1][k + 1] = sum[j][k + 1] + sum[j + 1][k] - sum[j][k] + isAmeba[j][k];
            }
        }
        fclose(fp);
        //ボックスカウント法
        for(int j = 0; j < boxNum; j++){
            int cnt = 0;
            for(int k = 0; k < H - two; k += two){
                for(int l = 0; l < W - two; l += two){
                    if(sum[k + two][l + two] - sum[k][l + two] - sum[k + two][l] + sum[k][l])cnt++;
                }
            }
            //最小二乗法
            double x = log(two), y = log(cnt);
            xySum += x * y;
            xSum += x;
            ySum += y;
            xSqSum += x * x;
            two *= 2;
        }
        //時刻とフラクタル次元を空白区切りで出力
        printf("%f %f\n", (double)i / 30, -(boxNum * xySum - xSum * ySum) / (boxNum * xSqSum - xSum * xSum));
    }
    return 0;
}