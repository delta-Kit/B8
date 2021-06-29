#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    const int num = 3636;
    vector<double> x(num), y(num), msd(num + 5);
    for(int i = 0; i < num; i++){
        cin >> x[i] >> y[i];
        for(int j = 0; j < i; j++)msd[i - j] += (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
    for(int i = 1; i < num; i++){
        msd[i] /= num - i;
        printf("%f %f %f %f\n", (double)i / 30, msd[i], log((double)i / 30), log(msd[i]));
    }
    return 0;
}