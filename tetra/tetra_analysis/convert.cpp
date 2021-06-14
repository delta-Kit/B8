#include<iostream>

using namespace std;

int main(){
    const int num = 76;
    string str;
    int box;
    double xm, ym;
    for(int i = 0; i < 6; i++)cin >> str;
    for(int i = 0; i <num; i++){
        cin >> box >> str >> box >> xm >> ym >> box >> box;
        printf("%f %f\n", xm, ym);
    }
    return 0;
}