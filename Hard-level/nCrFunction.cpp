#include<bits/stdc++.h>

using namespace std;

int nCr(int n,int r){
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    
    return res;
}

int main(){
    int n = 5, r = 3;
    cout << nCr(n,r);
}