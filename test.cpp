
#include"comprehend.hpp"

#include <iostream>
using std::cout;

void print(vector<int>& v){
    cout<<"{";
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<",";
    cout<<"\b}\n";
}

int main(){
    auto arr = range(10);
    auto modif = Comp(i + 1, i, arr);
    print(arr);
    print(modif);
}