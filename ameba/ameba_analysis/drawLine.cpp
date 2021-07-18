#include <iostream>

using namespace std;

int main(){
    const int H = 800, W = 800;
    printf("%d %d\n", H, W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i == H / 2){
                cout << "1 ";
            }else{
                cout << "0 ";
            }
        }
        puts("");
    }
    return 0;
}