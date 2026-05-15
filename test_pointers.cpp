// =============================================================================
// Test File  : test_pointers.cpp
// Course     : CMP1001 -- Introduction to Programming (C++)
// Framework  : Catch2 (amalgamated)
// =============================================================================
//
//   make test_1   ->  Section 1: getAddress + readValue
//   make test_2   ->  Section 2: writeValue + isNullptr + addThroughPointer
//   make test_3   ->  Section 3: swapInts + getElementByOffset + fillArray + sumArray
//   make test_4   ->  Section 4 (challenge): findMinMax + reverseArray
//   make test_all ->  All groups at once
//
// =============================================================================

#include "catch_amalgamated.hpp"
#include <cmath>
using namespace std;

// Forward declarations -- resolved from student's compiled MainProgram.o
int*  getAddress          (int* p);
int   readValue           (const int* p);
void  writeValue          (int* p, int newVal);
bool  isNullptr           (int* p);
void  addThroughPointer   (double* p, double amount);
void  swapInts            (int* a, int* b);
int   getElementByOffset  (const int* ptr, int offset);
void  fillArray           (int* arr, int size);
int   sumArray            (const int* arr, int size);
void  findMinMax          (const int* arr, int size, int* minVal, int* maxVal);
void  reverseArray        (int* arr, int size);


// =============================================================================
// TEST GROUP 1 -- getAddress + readValue
// make test_1
// =============================================================================

TEST_CASE("T1: getAddress returns the address of the passed variable", "[test_1]")
{
    int x = 10;
    REQUIRE(getAddress(&x) == &x);
}

TEST_CASE("T1: getAddress on different variables returns different addresses", "[test_1]")
{
    int a = 1, b = 2;
    REQUIRE(getAddress(&a) != getAddress(&b));
}

TEST_CASE("T1: getAddress does not return nullptr for a valid variable", "[test_1]")
{
    int x = 5;
    REQUIRE(getAddress(&x) != nullptr);
}

TEST_CASE("T1: readValue returns the correct integer value", "[test_1]")
{
    int x = 42;
    REQUIRE(readValue(&x) == 42);
}

TEST_CASE("T1: readValue returns correct value for zero", "[test_1]")
{
    int x = 0;
    REQUIRE(readValue(&x) == 0);
}

TEST_CASE("T1: readValue returns correct value for negative number", "[test_1]")
{
    int x = -7;
    REQUIRE(readValue(&x) == -7);
}

TEST_CASE("T1: readValue reflects a changed variable", "[test_1]")
{
    int x = 10;
    REQUIRE(readValue(&x) == 10);
    x = 99;
    REQUIRE(readValue(&x) == 99);
}


// =============================================================================
// TEST GROUP 2 -- writeValue + isNullptr + addThroughPointer
// make test_2
// =============================================================================

TEST_CASE("T2: writeValue changes the variable through the pointer", "[test_2]")
{
    int x = 0;
    writeValue(&x, 77);
    REQUIRE(x == 77);
}

TEST_CASE("T2: writeValue overwrites an existing non-zero value", "[test_2]")
{
    int x = 100;
    writeValue(&x, 5);
    REQUIRE(x == 5);
}

TEST_CASE("T2: writeValue with negative value", "[test_2]")
{
    int x = 50;
    writeValue(&x, -3);
    REQUIRE(x == -3);
}

TEST_CASE("T2: writeValue called twice keeps the last value", "[test_2]")
{
    int x = 0;
    writeValue(&x, 10);
    writeValue(&x, 20);
    REQUIRE(x == 20);
}

TEST_CASE("T2: isNullptr returns true for nullptr", "[test_2]")
{
    int* p = nullptr;
    REQUIRE(isNullptr(p) == true);
}

TEST_CASE("T2: isNullptr returns false for a valid pointer", "[test_2]")
{
    int x = 5;
    REQUIRE(isNullptr(&x) == false);
}

TEST_CASE("T2: addThroughPointer adds the correct amount", "[test_2]")
{
    double price = 9.99;
    addThroughPointer(&price, 5.0);
    REQUIRE(fabs(price - 14.99) < 0.001);
}

TEST_CASE("T2: addThroughPointer adding zero leaves value unchanged", "[test_2]")
{
    double val = 3.14;
    addThroughPointer(&val, 0.0);
    REQUIRE(fabs(val - 3.14) < 0.001);
}

TEST_CASE("T2: addThroughPointer adding negative value decreases it", "[test_2]")
{
    double val = 10.0;
    addThroughPointer(&val, -4.0);
    REQUIRE(fabs(val - 6.0) < 0.001);
}


// =============================================================================
// TEST GROUP 3 -- swapInts + getElementByOffset + fillArray + sumArray
// make test_3
// =============================================================================

TEST_CASE("T3: swapInts exchanges two distinct values", "[test_3]")
{
    int a = 3, b = 7;
    swapInts(&a, &b);
    REQUIRE(a == 7);
    REQUIRE(b == 3);
}

TEST_CASE("T3: swapInts with equal values leaves them equal", "[test_3]")
{
    int a = 5, b = 5;
    swapInts(&a, &b);
    REQUIRE(a == 5);
    REQUIRE(b == 5);
}

TEST_CASE("T3: swapInts called twice returns to original values", "[test_3]")
{
    int a = 1, b = 2;
    swapInts(&a, &b);
    swapInts(&a, &b);
    REQUIRE(a == 1);
    REQUIRE(b == 2);
}

TEST_CASE("T3: swapInts with negative numbers", "[test_3]")
{
    int a = -10, b = 50;
    swapInts(&a, &b);
    REQUIRE(a == 50);
    REQUIRE(b == -10);
}

TEST_CASE("T3: getElementByOffset returns correct element at offset 0", "[test_3]")
{
    int arr[] = {10, 20, 30, 40, 50};
    REQUIRE(getElementByOffset(arr, 0) == 10);
}

TEST_CASE("T3: getElementByOffset returns correct element at offset 3", "[test_3]")
{
    int arr[] = {10, 20, 30, 40, 50};
    REQUIRE(getElementByOffset(arr, 3) == 40);
}

TEST_CASE("T3: getElementByOffset returns correct element at last position", "[test_3]")
{
    int arr[] = {10, 20, 30, 40, 50};
    REQUIRE(getElementByOffset(arr, 4) == 50);
}

TEST_CASE("T3: fillArray sets element i to i*10", "[test_3]")
{
    const int N = 6;
    int arr[N] = {};
    fillArray(arr, N);
    for (int i = 0; i < N; i++)
        REQUIRE(arr[i] == i * 10);
}

TEST_CASE("T3: fillArray with size 1 sets arr[0] to 0", "[test_3]")
{
    int arr[1] = {99};
    fillArray(arr, 1);
    REQUIRE(arr[0] == 0);
}

TEST_CASE("T3: sumArray returns correct sum", "[test_3]")
{
    int arr[] = {0, 10, 20, 30, 40, 50};
    REQUIRE(sumArray(arr, 6) == 150);
}

TEST_CASE("T3: sumArray returns 0 for all-zero array", "[test_3]")
{
    int arr[] = {0, 0, 0, 0};
    REQUIRE(sumArray(arr, 4) == 0);
}

TEST_CASE("T3: fillArray then sumArray gives expected total", "[test_3]")
{
    const int N = 5;   // 0+10+20+30+40 = 100
    int arr[N];
    fillArray(arr, N);
    REQUIRE(sumArray(arr, N) == 100);
}


// =============================================================================
// TEST GROUP 4 -- findMinMax + reverseArray  (Challenge)
// make test_4
// =============================================================================

TEST_CASE("T4: findMinMax finds correct min", "[test_4]")
{
    int scores[] = {42, 17, 98, 55, 3, 76};
    int lo, hi;
    findMinMax(scores, 6, &lo, &hi);
    REQUIRE(lo == 3);
}

TEST_CASE("T4: findMinMax finds correct max", "[test_4]")
{
    int scores[] = {42, 17, 98, 55, 3, 76};
    int lo, hi;
    findMinMax(scores, 6, &lo, &hi);
    REQUIRE(hi == 98);
}

TEST_CASE("T4: findMinMax on single-element array", "[test_4]")
{
    int arr[] = {7};
    int lo, hi;
    findMinMax(arr, 1, &lo, &hi);
    REQUIRE(lo == 7);
    REQUIRE(hi == 7);
}

TEST_CASE("T4: findMinMax with negative values", "[test_4]")
{
    int arr[] = {-10, 0, -5, 20, -1};
    int lo, hi;
    findMinMax(arr, 5, &lo, &hi);
    REQUIRE(lo == -10);
    REQUIRE(hi == 20);
}

TEST_CASE("T4: reverseArray reverses odd-length array", "[test_4]")
{
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 5);
    REQUIRE(arr[0] == 5);
    REQUIRE(arr[1] == 4);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr[3] == 2);
    REQUIRE(arr[4] == 1);
}

TEST_CASE("T4: reverseArray reverses even-length array", "[test_4]")
{
    int arr[] = {10, 20, 30, 40};
    reverseArray(arr, 4);
    REQUIRE(arr[0] == 40);
    REQUIRE(arr[1] == 30);
    REQUIRE(arr[2] == 20);
    REQUIRE(arr[3] == 10);
}

TEST_CASE("T4: reverseArray on single element leaves it unchanged", "[test_4]")
{
    int arr[] = {99};
    reverseArray(arr, 1);
    REQUIRE(arr[0] == 99);
}

TEST_CASE("T4: reverseArray twice returns original order", "[test_4]")
{
    int arr[]  = {3, 1, 4, 1, 5, 9};
    int copy[] = {3, 1, 4, 1, 5, 9};
    reverseArray(arr, 6);
    reverseArray(arr, 6);
    for (int i = 0; i < 6; i++) REQUIRE(arr[i] == copy[i]);
}