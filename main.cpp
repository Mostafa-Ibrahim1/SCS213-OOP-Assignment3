#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FloatArray {
protected:
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
    friend void operator >>(ifstream&,FloatArray**);
    friend ofstream& operator<<(ofstream& outFile,FloatArray** ArrayOfPointers);

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
        cout<< floats_[i]<<" ";
    }
    cout<<endl;
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

SortedArray::SortedArray(int arraySize):FloatArray(arraySize){};

void SortedArray::add(float floatElement) {
    int insertPos = indexCursor_;
    for (int i = indexCursor_; i >= 0; i--) {
        if (floatElement < floats_[i]) {
            insertPos = i;
        }
    }
    if ((indexCursor_ == 0) || (indexCursor_ == insertPos)) {
        FloatArray::add(floatElement);
    }
    else if (indexCursor_ < arraySize_){
        for (int i = indexCursor_; i > insertPos; i--) {
            floats_[i] = floats_[i-1];
        }
        floats_[insertPos] = floatElement;
        indexCursor_++;
    }
}

class FrontArray : public FloatArray {
public:
    FrontArray(int);
    void add(float);
};

FrontArray::FrontArray(int arraySize):FloatArray(arraySize){}


void FrontArray::add(float floatElement) {
    int shifter = 0;
    if (indexCursor_ == 0) {
        FloatArray::add(floatElement);
    }
    else {
        for (int i = indexCursor_; i > shifter; i--) {
            floats_[i] = floats_[i-1];
        }
        floats_[shifter] = floatElement;
        shifter++;
        indexCursor_++;
    }
}


class PositiveArray : public SortedArray {
public:
    PositiveArray(int);
    void add(float);
};

PositiveArray::PositiveArray(int arraySize):SortedArray(arraySize){}

void PositiveArray::add(float floatElement) {
    if (floatElement <= 0) {
        arraySize_--;
    }
    else
        SortedArray::add(floatElement);
}

class NegativeArray : public SortedArray {
public:
    NegativeArray(int);
    void add(float);
};

NegativeArray::NegativeArray(int arraySize):SortedArray(arraySize){}

void NegativeArray::add(float floatElement) {
    if (floatElement >= 0) {
        arraySize_--;
    }
    else
        SortedArray::add(floatElement);
}

void operator>>(ifstream& inFile,FloatArray** ArrayOfPointers){

    int size;
    string type;
    float element;
    FloatArray* pointerToObject;
    while(!inFile.eof()){
        for(int i=0;i<10;i++){

            inFile>>type;
            inFile>>size;
            if(type=="Array"){
                pointerToObject=new FloatArray(size);
            }
            else if(type=="Sorted"){
                pointerToObject=new SortedArray(size);
            }
            else if(type=="Front"){
                pointerToObject=new FrontArray(size);
            }
            else if(type=="Positive"){
                pointerToObject=new PositiveArray(size);
            }
            else if(type=="Negative"){
                pointerToObject=new NegativeArray(size);
            }
            for(int j=0;j<size;j++){

                inFile>>element;
                pointerToObject->add(element);
            }
            ArrayOfPointers[i]=pointerToObject;
            ArrayOfPointers[i]->printIt();




        pointerToObject=0;
        }
    }

}
ofstream& operator<<(ofstream& outFile,FloatArray** ArrayOfPointers){

    for(int i=0;i<10;i++){
        outFile<<ArrayOfPointers[i]->arraySize_<<"|   ";
        for(int j=0;j<ArrayOfPointers[i]->arraySize_;j++){
                outFile<<ArrayOfPointers[i]->floats_[j]<<"   ";
        }
        outFile<<"\n";
    }
    return outFile;
}
int main() {
    // cout << "Enter the name of the input file:" << endl;
    // cout << "Enter the name of the output file:" << endl;
    ifstream inFile;
    inFile.open("in.txt");
    FloatArray* ArrayOfPointers[10];
    inFile>>ArrayOfPointers;
    inFile.close();
    cout<<"\n\n"<<endl;

    ofstream outFile;
    outFile.open("MyOut.txt");
    outFile<<ArrayOfPointers;
    outFile.close();


    return 0;
}
