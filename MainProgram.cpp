// =============================================================================
// Lab Title  : Introduction to Pointers in C++
// Course     : CMP1001 – Introduction to Programming (C++)
// Duration   : 40 Minutes
// File       : MainProgram.cpp
// =============================================================================
//
// DESCRIPTION:
//   This lab introduces you to one of the most powerful — and most misunderstood
//   features of C++: POINTERS. You will learn what a pointer is, how to declare
//   and use one, how to pass data by pointer to functions, and how to work with
//   pointers and arrays.
//
// INSTRUCTIONS:
//   1. Read every comment carefully before writing any code.
//   2. Search for every // TODO: marker — those are your tasks.
//   3. Do NOT delete the TODO comments; write your code right below them.
//   4. Work through sections in order — each one builds on the last.
//   5. Compile often: g++ MainProgram.cpp -o lab && ./lab
//
// =============================================================================

#include <iostream>
using namespace std;

// =============================================================================
// SECTION 1 — WARM-UP  (≈ 5 minutes)
// Goal: Use the address-of operator and confirm a pointer holds the right address
// =============================================================================
//
// Every variable lives somewhere in memory — it has an ADDRESS.
// The address-of operator  &  gives you that address.
//
//   int x = 10;
//   cout << &x;        // prints something like 0x7ffd3a2b
//
// A POINTER stores that address:
//   int* p = &x;       // p now holds the address of x
//   cout << (p == &x); // prints 1 (true) — they are the same address
//
// ------------------------------------------------------------
// TODO 1: Implement getAddress.
//   - Receives an int by pointer.
//   - Returns that same pointer (i.e. just return the argument).
//   - This confirms that a pointer really does hold the address of
//     the variable passed in.
//
//   Example: int n = 5;  getAddress(&n)  ->  returns &n
//
int* getAddress(int* p)
{
    // TODO 1: return p


    return nullptr; // placeholder -- replace this line
}

// ------------------------------------------------------------
// TODO 2: Implement readValue.
//   - Receives a const int pointer.
//   - Returns the integer VALUE stored at that address (dereference it).
//
//   Example: int n = 42;  readValue(&n)  ->  returns 42
//
int readValue(const int* p)
{
    // TODO 2: dereference p and return the value


    return -1; // placeholder -- replace this line
}

void section1_warmup()
{
    cout << "\n===== SECTION 1: Warm-Up =====\n";

    int age = 20;
    int* result = getAddress(&age);
    cout << "Address of age    : " << &age   << "\n";
    cout << "Returned by func  : " << result << "\n";
    cout << "Match? (1=yes)    : " << (result == &age) << "\n";

    int score = 99;
    cout << "Value via pointer : " << readValue(&score) << "\n";  // expect 99
}

// =============================================================================
// SECTION 2 — CORE CONCEPTS  (≈ 10 minutes)
// Goal: Write through a pointer, use nullptr safely
// =============================================================================
//
// Writing through a pointer changes the ORIGINAL variable:
//
//   int x = 5;
//   int* p = &x;
//   *p = 100;       // x is now 100
//
// nullptr is a pointer that points to NOTHING -- safe initial value:
//
//   int* p = nullptr;
//   // *p would CRASH -- never dereference nullptr
//
// ------------------------------------------------------------
// TODO 3: Implement writeValue.
//   - Receives an int pointer and a new integer value.
//   - Writes the new value through the pointer (modifies what p points to).
//   - No return value.
//
//   Example: int n = 0;  writeValue(&n, 77);  -> n is now 77
//
void writeValue(int* p, int newVal)
{
    // TODO 3: write newVal into the memory location p points to

}

// ------------------------------------------------------------
// TODO 4: Implement isNullptr.
//   - Receives an int pointer.
//   - Returns true  if the pointer is nullptr.
//   - Returns false otherwise.
//
//   Example: isNullptr(nullptr)  -> true
//            int n = 0;  isNullptr(&n)  -> false
//
bool isNullptr(int* p)
{
    // TODO 4: compare p to nullptr and return the result


    return false; // placeholder -- replace this line
}

// ------------------------------------------------------------
// TODO 5: Implement addThroughPointer.
//   - Receives a double pointer and a double amount.
//   - Adds 'amount' to the value at the pointer location.
//   - No return value.
//
//   Example: double price = 9.99;  addThroughPointer(&price, 5.0);
//            -> price is now 14.99
//
void addThroughPointer(double* p, double amount)
{
    // TODO 5: add 'amount' to *p

}

void section2_core_concepts()
{
    cout << "\n===== SECTION 2: Core Concepts =====\n";

    int temperature = 36;
    cout << "temperature before : " << temperature << "\n";
    writeValue(&temperature, 100);
    cout << "temperature after  : " << temperature << "\n";  // expect 100

    int* pNull = nullptr;
    int  val   = 5;
    cout << "isNullptr(nullptr) : " << isNullptr(pNull) << "\n";  // expect 1
    cout << "isNullptr(&val)    : " << isNullptr(&val)  << "\n";  // expect 0

    double price = 9.99;
    addThroughPointer(&price, 5.0);
    cout << "price after +5.0   : " << price << "\n";  // expect 14.99
}

// =============================================================================
// SECTION 3 -- GUIDED EXERCISES  (approx 15 minutes)
// Goal: Pass-by-pointer, pointer arithmetic, pointers & arrays
// =============================================================================

// ------------------------------------------------------------
// EXERCISE 3A -- Pass by Pointer (swap two values)
// ------------------------------------------------------------
//
// In C++, functions normally receive COPIES of arguments (pass-by-value).
// If you want a function to MODIFY the caller's variables, pass POINTERS.
//
// PATTERN:
//   void doubleIt(int* p) { *p = (*p) * 2; }
//   int n = 5;
//   doubleIt(&n);   // n is now 10
//
// Your task: implement swapInts so it swaps the values of two integers
//            through pointers. No return value needed.
//
//   Example: a=3, b=7  ->  after swap: a=7, b=3
//
void swapInts(int* a, int* b)
{
    // TODO 3a: Swap the values that a and b point to.
    //          HINT: you need a temporary variable.

}

void exercise3a_swap()
{
    cout << "\n--- Exercise 3A: Swap via Pointer ---\n";
    int x = 3, y = 7;
    cout << "Before swap: x=" << x << "  y=" << y << "\n";
    swapInts(&x, &y);
    cout << "After swap : x=" << x << "  y=" << y << "\n";
    // Expected: x=7  y=3
}

// ------------------------------------------------------------
// EXERCISE 3B -- Pointer Arithmetic
// ------------------------------------------------------------
//
// When you increment a pointer, it moves by sizeof(type) bytes -- not 1 byte.
//
//   int arr[] = {10, 20, 30, 40, 50};
//   int* p = arr;        // p points to arr[0]
//   p++;                 // p now points to arr[1]
//   cout << *p;          // prints 20
//
// TODO 3b: Implement getElementByOffset.
//   - Receives a const int pointer (base of an array) and an integer offset.
//   - Returns the value at position (ptr + offset) using pointer arithmetic.
//   - Do NOT use array index notation like ptr[offset].
//
//   Example: int arr[] = {10,20,30,40,50};
//            getElementByOffset(arr, 3)  ->  40
//
int getElementByOffset(const int* ptr, int offset)
{
    // TODO 3b: use *(ptr + offset) to return the element


    return -1; // placeholder -- replace this line
}

void exercise3b_pointer_arithmetic()
{
    cout << "\n--- Exercise 3B: Pointer Arithmetic ---\n";

    int numbers[] = {10, 20, 30, 40, 50};
    int* p = numbers;

    cout << "Array via pointer: ";
    for (int i = 0; i < 5; i++) { cout << *p << " "; p++; }
    cout << "\n";

    cout << "Element at offset 3 : " << getElementByOffset(numbers, 3) << "\n"; // 40
    cout << "Element at offset 0 : " << getElementByOffset(numbers, 0) << "\n"; // 10
}

// ------------------------------------------------------------
// EXERCISE 3C -- Pointers and Arrays (read + modify)
// ------------------------------------------------------------
//
// The name of an array IS a pointer to its first element.
//   int arr[5];
//   int* p = arr;    // same as  int* p = &arr[0];
//
// TODO 3c-i: Implement fillArray.
//   - Receives a pointer to an int array and a size.
//   - Fills every element with its index * 10.
//
void fillArray(int* arr, int size)
{
    // TODO 3c-i: Use a loop. Access elements via arr[i] OR *(arr+i).

}

// TODO 3c-ii: Implement sumArray.
//   - Receives a const int* and a size.
//   - Returns the sum of all elements.
//
int sumArray(const int* arr, int size)
{
    // TODO 3c-ii: accumulate and return the sum.
    return 0; // placeholder -- replace this
}

void exercise3c_array_pointer()
{
    cout << "\n--- Exercise 3C: Array via Pointer ---\n";
    const int SIZE = 6;
    int data[SIZE];
    fillArray(data, SIZE);
    cout << "Filled array: ";
    for (int i = 0; i < SIZE; i++) cout << data[i] << " ";
    cout << "\n";
    cout << "Sum of array: " << sumArray(data, SIZE) << "\n";
}

// =============================================================================
// SECTION 4 -- CHALLENGE  (approx 10 minutes)
// =============================================================================

void findMinMax(const int* arr, int size, int* minVal, int* maxVal)
{
    // TODO 4a: initialise *minVal and *maxVal with arr[0], then loop.

}

void challengeA_minMax()
{
    cout << "\n--- Challenge A: Min & Max via Pointer ---\n";
    int scores[] = {42, 17, 98, 55, 3, 76};
    int lo, hi;
    findMinMax(scores, 6, &lo, &hi);
    cout << "Min: " << lo << "\n";
    cout << "Max: " << hi << "\n";
}

void reverseArray(int* arr, int size)
{
    // TODO 4b: left = arr,  right = arr + size - 1
    //          while left < right: swap, then left++, right--

}

void challengeB_reverse()
{
    cout << "\n--- Challenge B: Reverse Array in Place ---\n";
    int vals[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Before: ";
    for (int i = 0; i < n; i++) cout << vals[i] << " ";
    cout << "\n";
    reverseArray(vals, n);
    cout << "After : ";
    for (int i = 0; i < n; i++) cout << vals[i] << " ";
    cout << "\n";
}

// =============================================================================
// MAIN
// =============================================================================
#ifndef NO_MAIN
int main()
{
    section1_warmup();
    section2_core_concepts();
    exercise3a_swap();
    exercise3b_pointer_arithmetic();
    exercise3c_array_pointer();
    challengeA_minMax();
    challengeB_reverse();
    cout << "\n===== Lab Complete =====\n";
    return 0;
}
#endif // NO_MAIN