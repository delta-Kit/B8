#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int num, H, W, boxNum = 0;
    for(int i = 0; i < num; i++){
        int two = 1;
        double xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
        char fileName[] = "koch.txt";
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
                sum[j + 1][k + 1] = sum[j][k + 1] + sum[j + 1][k] - sum[j][k] + isAmeba[j][k];
            }
        }
        fclose(fp);
        for(int j = 0; j < boxNum; j++){
            int cnt = 0;
            for(int k = 0; k < H - two; k += two){
                for(int l = 0; l < W - two; l += two){
                    if(sum[k + two][l + two] - sum[k][l + two] - sum[k + two][l] + sum[k][l])cnt++;
                }
            }
            double x = log(two), y = log(cnt);
            xySum += x * y;
            xSum += x;
            ySum += y;
            xSqSum += x * x;
            two *= 2;
        }
        printf("%f %f\n", (double)i / 30, -(boxNum * xySum - xSum * ySum) / (boxNum * xSqSum - xSum * xSum));
    }
    return 0;
}