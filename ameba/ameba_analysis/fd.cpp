#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    //amebaTxt：num = 982, 234 * 235
    //amebaTxt2：num = 1001, 344 * 345
    const int num = 982, H = 234, W = 235, boxNum = 7;
    ifstream readingFile;
    for(int i = 0; i < num; i++){
        vector<vector<int>> isAmeba(H, vector<int>(W));
        int two = 1;
        double xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
        readingFile.open("../amebaTxt/ameba" + to_string (i / 1000) + to_string((i / 100) % 10) + to_string((i / 10) % 10) + to_string(i % 10) + ".txt", ios::in);
        for(int j = 0; j < H; j++){
            for(int k = 0; k < W; k++)readingFile >> isAmeba[j][k];
        }
        readingFile.close();
        for(int j = 0; j < boxNum; j++){
            int cnt = 0;
            for(int k = 0; k < W - two; k += two){
                for(int l = 0; l < H - two; l += two){
                    bool exist = false;
                    for(int m = k; m < k + two; m++){
                        for(int n = l; n < l + two; n++){
                            if(isAmeba[m][n]){
                                exist = true;
                                break;
                            }
                        }
                        if(exist)break;
                    }
                    if(exist)cnt++;
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