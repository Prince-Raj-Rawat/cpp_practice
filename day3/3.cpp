#include <iostream>

int main(){
    std::cout<<"enter a number: ";
    int a;
    std::cin>>a;
    for(int i = 0; i< a; i++){
        for(int j = a;j>i;j--){
            std::cout<<j<<" ";
        }
        std::cout << std::endl;
    }
    return 0;

}