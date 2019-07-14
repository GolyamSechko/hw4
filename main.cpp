#include <iostream>

using namespace std;

//first task

void setBit(int& value, size_t bitNumber, bool enabled){
    enabled ? value |= (1 << bitNumber) : value &=~ (1 << bitNumber);
}

//second task

int add(int a, int b){
    return a + b;
}
int subtract(int a, int b){
    return a - b;
}
int multiply(int a, int b){
    return a * b;
}
int divide(int a, int b){
    return a / b;
}

typedef int(*func_t)(int, int);

struct operation_t {
    char operation;
    func_t func;
};

operation_t operations[] {
    {'+', add},
    {'-', subtract}, 
    {'*', multiply},
    {'/', divide},
};

int main()
{

//first task example
    int val = 5;
    int& ref = val;
    setBit(ref, 2, false);
    cout << "res: " << ref << '\n';

//second task example
    int fstArg = 4;
    int sndArg = 2;
    for(operation_t opp: operations)
        cout << fstArg << opp.operation << sndArg << "->" << opp.func(fstArg,sndArg) << '\n';

    return 0;
}
