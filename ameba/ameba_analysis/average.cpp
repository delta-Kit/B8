#include <iostream>
#include <vector>

using namespace std;

int main(){
    const int n = 89;
    double box, fd, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> box >> fd;
        sum += fd;
    }
    printf("%.10f", sum / n);
    return 0;
}