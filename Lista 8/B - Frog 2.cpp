#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector <int> height(N + 1, 0);
    for(int i = 1; i <= N; i++){
        cin >> height[i];
    }

    vector <int> minCost(N + 1, 1000000000);
    minCost[1] = 0;

    for(int i = 2; i <= N; i++)
    {
        for(int j = i - 1; j >= max(1, i - K); j--)
        {
            minCost[i] = min(minCost[i], minCost[j] + abs(height[i] - height[j]));
        }
    }

    cout << minCost[N];
    return 0;
}