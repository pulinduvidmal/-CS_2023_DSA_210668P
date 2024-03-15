#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sum_of_numbers(int a, int b, int c){
    cout<<a+b+c<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num1,num2,num3;
    cin>>num1>>num2>>num3;
    sum_of_numbers(num1,num2,num3);
    return 0;
}
