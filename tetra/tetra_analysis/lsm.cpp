#include<iostream>
#include<vector>

using namespace std;

int main(){
    const int num = 500;
    double ignore, x, y, xySum = 0, xSum = 0, ySum = 0, xSqSum = 0;
    for(int i = 0; i < num; i++){
        cin >> ignore >> ignore >> x >> y;
        xySum += x * y;
        xSum += x;
        ySum += y;
        xSqSum += x * x;
    }
    cout << (num * xySum - xSum * ySum) / (num * xSqSum - xSum * xSum) << endl;
    return 0;
}