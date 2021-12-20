/*
    Assignment 3 OOP
    Group: SG1
    Team Members:
    [ Mostafa Ibrahim Abdellatif, ID: 20205006] [ Youssef Magdi Salah Eldin, ID: 20205033]
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//-------------------------------------------------------
/*Class FloatArray*/
class FloatArray {
protected:
    float *floats_;
    int arraySize_;
    int indexCursor_=0;
public:
    FloatArray(int);
    virtual void add(float);

    friend void operator >>(ifstream&, FloatArray** );
    friend ofstream& operator<<(ofstream&, FloatArray**);

    ~FloatArray();
};

FloatArray::FloatArray(int arraySize){      //Definition of constructor
    arraySize_ = arraySize;
    floats_ = new float[arraySize_];
}
void FloatArray::add(float floatElement){   //Definition of add member function
    if(indexCursor_ < arraySize_){
        floats_[indexCursor_]=floatElement;
        indexCursor_++;
    }
}

FloatArray::~FloatArray(){      //Definition of destructor
    delete [] floats_;
    floats_ = 0;
}


//-------------------------------------------------------
/*Class SortedArray : adds float at the right place , the place that makes the array sorted*/
class SortedArray : public FloatArray {
public:
    SortedArray(int);
    void add(float);
};

SortedArray::SortedArray(int arraySize):FloatArray(arraySize){};

void SortedArray::add(float floatElement) {
    int insertPos = indexCursor_;
    for (int i = indexCursor_; i >= 0; i--) {       //Loop to find out the position where the number should be inserted
        if (floatElement < floats_[i]) {
            insertPos = i;
        }
    }
    if ((indexCursor_ == 0) || (indexCursor_ == insertPos)) {       //Conditional statement to check if the float should be inserted at the beginning or end
        FloatArray::add(floatElement);
    }
    else if (indexCursor_ < arraySize_){
        for (int i = indexCursor_; i > insertPos; i--) {        //Loop to shift elements one position to allow for insertion of float in the correct position
            floats_[i] = floats_[i-1];
        }
        floats_[insertPos] = floatElement;
        indexCursor_++;
    }
}
//-------------------------------------------------------
/*Class PositiveArray : adds float at the front of the array*/
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
        for (int i = indexCursor_; i > shifter; i--) {      //Loop to bring elements to the front
            floats_[i] = floats_[i-1];
        }
        floats_[shifter] = floatElement;
        shifter++;
        indexCursor_++;
    }
}
//-------------------------------------------------------
/*Class PositiveArray : adds only positive floats */
class PositiveArray : public SortedArray {
public:
    PositiveArray(int);
    void add(float);
};

PositiveArray::PositiveArray(int arraySize):SortedArray(arraySize){}

void PositiveArray::add(float floatElement) {
    if (floatElement <= 0) {        //Conditional statement to deduct the count of negative values or zeros
        arraySize_--;
    }
    else                            //Conditional statement to add the positive values to the array
        SortedArray::add(floatElement);
}
//-------------------------------------------------------
/*Class NegativeArray : adds only negative floats */
class NegativeArray : public SortedArray {
public:
    NegativeArray(int);
    void add(float);
};

NegativeArray::NegativeArray(int arraySize):SortedArray(arraySize){}

void NegativeArray::add(float floatElement) {
    if (floatElement >= 0) {        //Conditional statement to deduct the count of positive values or zeros
        arraySize_--;
    }
    else                            //Conditional statement to add the negative values to the array
        SortedArray::add(floatElement);
}
//-------------------------------------------------------
/*Overloading stream extraction operator [friend of floatArray] to read the arrays from a file and perform the required operation on them*/

void operator>>(ifstream& inFile,FloatArray** ArrayOfPointers){

    int size;
    string type;
    float element;
    FloatArray* pointerToObject;
    while(!inFile.eof()){
        for(int i=0;i<10;i++){

            inFile >> type;
            inFile >> size;
            if(type == "Array"){
                pointerToObject = new FloatArray(size);
            }
            else if(type == "Sorted"){
                pointerToObject = new SortedArray(size);
            }
            else if(type == "Front"){
                pointerToObject = new FrontArray(size);
            }
            else if(type == "Positive"){
                pointerToObject = new PositiveArray(size);
            }
            else if(type == "Negative"){
                pointerToObject = new NegativeArray(size);
            }
            for(int j = 0; j < size; j++){

                inFile >> element;
                pointerToObject->add(element);
            }
            ArrayOfPointers[i] = pointerToObject;




        pointerToObject = 0;
        }
    }

}

/*Overloading stream insertion operator [friend of floatArray] to write the arrays to a file*/

ofstream& operator<<(ofstream& outFile, FloatArray** ArrayOfPointers){

    for(int i = 0; i < 10; i++){
        outFile << ArrayOfPointers[i]->arraySize_ << "|   ";
        for(int j = 0; j < ArrayOfPointers[i]->arraySize_; j++){
                outFile << ArrayOfPointers[i]->floats_[j] << "   ";
        }
        outFile << "\n";
    }
    return outFile;
}
int main() {

    string inputFileName,outputFileName;
    cout << "Enter the name of the input file:" << endl;
    cin >> inputFileName;
    cout << "Enter the name of the output file:" << endl;
    cin >> outputFileName;
//---------------------------------------------------------------
    ifstream inFile;
    inFile.open(inputFileName);
    if(inFile.fail()){
        cerr << "Error Opening File!" << endl;
        exit(1);
    }
    FloatArray* ArrayOfPointers[10];
    inFile >> ArrayOfPointers;
    inFile.close();
    cout << "\n\n\n";
//---------------------------------------------------------------
    ofstream outFile;
    outFile.open(outputFileName);
    if(outFile.fail()){
        cerr << "Error Opening File!" << endl;
        exit(1);
    }
    outFile << ArrayOfPointers;
    outFile.close();
//---------------------------------------------------------------
/*Deallocation and deletion of objects*/
    for(int i = 0; i < 10 ; i++){
        delete ArrayOfPointers[i];
    }
    delete [] ArrayOfPointers;
    return 0;
}
