#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    const int num = 1, H = 2048, W = 2048;
    int h, w, b = 0;
    for(int i = 0; i < num; i++){
        int eps = 1;
        double xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
        char fileName[] = "line.txt";
        FILE *fp = NULL;
        fp = fopen(fileName, "r");
        if(!i){
            fscanf(fp, "%d %d", &h, &w);
            b = log2(min(h, w));
        }
        vector<vector<int>> black(H, vector<int>(W)), sum(H + 5, vector<int>(W + 5));
        for(int j = 0; j < H; j++){
            for(int k = 0; k < W; k++){
                if(j < h && k < w){
                    fscanf(fp, "%d", &black[j][k]);
                    black[j][k] = min(1, black[j][k]);
                }
                sum[j + 1][k + 1] = sum[j][k + 1] + sum[j + 1][k] - sum[j][k] + black[j][k];
            }
        }
        fclose(fp);
        for(int j = 0; j < b; j++){
            int cnt = 0;
            for(int k = 0; k < H - eps; k += eps){
                for(int l = 0; l < W - eps; l += eps){
                    if(sum[k + eps][l + eps] - sum[k][l + eps] - sum[k + eps][l] + sum[k][l])cnt++;
                }
            }
            double x = log(eps), y = log(cnt);
            cout << cnt << endl;
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