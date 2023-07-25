#include <iostream>
using namespace std;

int w[2006], v[2006], F[2004][2004];

int knapSack(int S, int N){
    for(int i= 0; i<=N; i++){
        for(int j= 0; j<=S; j++){
            
            if(i == 0 || j== 0)
                F[i][j]= 0;
            else if(w[i-1] <= j)
                F[i][j]= max(v[i-1] + F[i-1][j-w[i-1]], F[i-1][j]);
            else
                F[i][j]= F[i-1][j];
        }
    }
    return F[N][S];
}

int main(){
    int S, N;
    cin >> S >> N;

    for (int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }

    cout << knapSack(S, N);

    return 0;
}