#include <iostream>

using namespace std;

int main(){
    int age;
    again:
    cout<<"enter your age: ";
    cin>>age;
    if(age<=0){
        cout<<"invalid input try again."<< endl;
        goto again;
    }
    else if(age>0 && age <=12){
        cout<<"you are a child"<< endl;
    }
    else if(age>=13 &&age<=19){
        cout<<"you are a teenager"<<endl;
    }
    else if(age>= 20 && age<=64){
        cout<<"you are an adult"<<endl;
    }
    else if(age>=65){
        cout<<"you are a senior"<<endl;
    }
    return 0;
}
