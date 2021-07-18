#include <iostream>
#include <math.h>

using namespace std;

const int H = 800, W = 800;
int koch[H + 5][W + 5] = {};

void Koch(double xs, double ys, double xt, double yt){
    const double rad = acos(-1) / 3;
    double x1 = (2 * xs + xt) / 3, y1 = (2 * ys + yt) / 3, x3 = (2 * xt + xs) / 3, y3 = (2 * yt + ys) / 3;
    double r = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)), theta = atan2(y3 - y1, x3 - x1);
    double x2 = x1 + r * cos(theta + rad), y2 = y1 + r * sin(theta + rad);
    if(r < 1){
        koch[int(round(xs) + 0.1)][int(round(ys) + 0.1)] = 1;
        koch[int(round(x1) + 0.1)][int(round(y1) + 0.1)] = 1;
        koch[int(round(x2) + 0.1)][int(round(y2) + 0.1)] = 1;
        koch[int(round(x3) + 0.1)][int(round(y3) + 0.1)] = 1;
        koch[int(round(xt) + 0.1)][int(round(yt) + 0.1)] = 1;
        return;
    }
    Koch(xs, ys, x1, y1);
    Koch(x1, y1, x2, y2);
    Koch(x2, y2, x3, y3);
    Koch(x3, y3, xt, yt);
}

int main(){
    printf("%d %d\n", H, W);
    Koch(H / 2, 0, H / 2, W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++)cout << koch[i][j] << " ";
        puts("");
    }
    return 0;
}