# SCS213-OOP-Assignment3

## Classes:

- [ ] FloatArray
- [ ] SortedArray
- [ ] FrontArray
- [ ] PositiveArray
- [ ] NegativeArray

---

## 1] Class FloatArray

Private :

- [x] dynamic array of floats
- [x] size of the array of floats

Public :

- [x] parameterized constructor [takes the arraySize]
- [x] add method [adds a float at the end of the array]
- [x] destructor [deallocates the array of floats]

Overloading:

- [ ] > > stream extraction operator to read array elements from file[ifstream]
      > > and then adds them to the array

---

## 2] Class SortedArray [child of FloatArray]

Public :

- [ ] parameterized constructor [arraySize] [Will call the FloatArray Constructor instead of setting it inside]
- [ ] add method [adds a float at the right place [the place that makes the array sorted]]
- Note: In the add method,_don't_ add the float and then sort the array

---

## 3] Class FrontArray [child of FloatArray]

Public :

- [ ] parameterized constructor [arraySize] [Will call the FloatArray Constructor instead of setting it inside]
- [ ] add method [adds a float at the front of the array]

---

## 4] Class PositiveArray [child of SortedArray]

Public :

- [ ] parameterized constructor [arraySize] [Will call the FloatArray Constructor instead of setting it inside]
- [ ] add method
- [adds a float only if it is a positive number
- _Then_ uses the add method of SortedArray]

---

## 5] Class NegativeArray [child of SortedArray]

Public :

- [ ] parameterized constructor [arraySize] [Will call the FloatArray Constructor instead of setting it inside]
- [ ] add method
- [adds a float only if it is a negative number
- _Then_ uses the add method of SortedArray]

---

Notes:

- You should use polymorphism in your code by creating an array of FloatArray\* in main.
- The output file: each line begins with the number of elements followed by the character ‘|’, a tab, then the array elements separated by tabs.
- Don’t forgot to deallocate by deleting your objects in main after finishing.
- The only input to your program is the names of the input txt file and output txt file name. The input text file will have exactly 10 lines.

---

My Notes (from the example):

- Front reverses the array
- Positive omits the negative and the zeros
- Negative omits the positive and the zeros
- may need to overload the insertion operator to write to another text file

---

Sequence:

- The input text file should exist with values in it
- ![image](https://user-images.githubusercontent.com/78238174/146653402-a82e7155-0a66-452d-a3ce-6e4ef64f4981.png)
- User Input : ![image](https://user-images.githubusercontent.com/78238174/146653332-13b8f801-15cc-4d48-8e8d-a65e35e4b6b8.png)
- Read from the txt file and allocate your objects according to the type of array and fill the arrays using the extraction operator >>
- After finishing reading the file, you should write your arrays to another text file using the insertion operator<<
- ![image](https://user-images.githubusercontent.com/78238174/146653424-ed2b5fbc-13bf-478c-aba1-de04154b53a4.png)
