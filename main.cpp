#include <iostream>
#include <string>

using namespace std;

class FloatArray {
private:
    float *floats;
    int arraySize;
public:
    FloatArray(int);
    virtual void add(float);
    //ofstream overloading
    //ifstream overloading
    ~FloatArray();
};

class SortedArray : public FloatArray {
public:
    SortedArray(int);
    void add(float);
};

class FrontArray : public FloatArray {
public:
    FrontArray(int);
    void add(float);
};

class PositiveArray : public FrontArray {
public:
    PositiveArray(int);
    void add(float);
};

class NegativeArray : public FrontArray {
public:
    NegativeArray(int);
    void add(float);
};


int main() {
    cout << "Enter the name of the input file:" << endl;
    cout << "Enter the name of the output file:" << endl;
    return 0;
}
