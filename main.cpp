#include <iostream>
#include <string>

using namespace std;

class FloatArray {
private:
    float *floats_;
    int arraySize_;
    int indexCursor_=0;
public:
    FloatArray(int);
    virtual void add(float);
    // (delete/comment it) V V
    void printIt();
    //ofstream overloading
    //ifstream overloading
    ~FloatArray();
};
FloatArray::FloatArray(int arraySize){
    arraySize_=arraySize;
    floats_ = new float[arraySize_];
}
void FloatArray::add(float floatElement){
    if(indexCursor_ < arraySize_){
        floats_[indexCursor_]=floatElement;
        indexCursor_++;
    }
}
////
// (delete/comment it) V
void FloatArray::printIt(){
    for(int i = 0 ; i < arraySize_ ; i++){
        cout<< floats_[i]<<endl;
    }
}
////
FloatArray::~FloatArray(){
    delete [] floats_;
    floats_=0;
}



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
    // cout << "Enter the name of the input file:" << endl;
    // cout << "Enter the name of the output file:" << endl;

    //Testing
    FloatArray fa1(2);
    fa1.add(3.3);
    fa1.add(4.55);
    fa1.add(6.2);//Won't be added as the size is only 2
    fa1.printIt();//Just a print function (delete/comment it)

    return 0;
}
