// fractional knapsack

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float knapsack(int W, const vector<int>& weights, const vector<int>& values, int n){
    vector<float> ratio;
    for(int i = 0; i<n; i++){
        ratio.push_back((float)values[i]/weights[i]);
    }
    sort(ratio.begin(),ratio.end(),greater<float>());
    float total = 0;
    for(int i = 0;i<n;i++){
        if(W == 0 ) break;
        for(int j = 0; j<n; j++){
            if((float)values[j]/weights[j] == ratio[i]){
                if(weights[j] <= W){
                    total += values[j];
                    W -= weights[j];
                } else {
                    total += ratio[i] * W;
                    W = 0;
                }
                break;
            }
        }
    }
    return total;
}

int main(){
    vector<int> values = {60,100,120};
    vector<int> weights ={10,20,30};
    int W= 55;
    int n = values.size();
    cout<<"maximum value (fractional knapsack): "<< knapsack(W,weights,values,n)<<endl;
    return 0;
}