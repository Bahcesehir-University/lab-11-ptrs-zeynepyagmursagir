# Lab: Introduction to Pointers in C++

**Course:** CMP1001 – Introduction to Programming (C++)  
**Duration:** 40 Minutes  
**Language:** C++17  
**Testing Framework:** [Catch2](https://github.com/catchorg/Catch2) (amalgamated, included)

---

## Objective

By the end of this lab you will be able to:

- Explain what a pointer is and why it exists
- Declare a pointer, assign it an address, and dereference it
- Use `nullptr` safely
- Modify a caller's variable through a pointer (pass-by-pointer)
- Apply pointer arithmetic to iterate over arrays
- Write functions that accept and return data via pointer parameters

---

## Prerequisites

Before attempting this lab you should be comfortable with:

- Declaring and using variables (`int`, `double`, etc.)
- Writing `cout` / `cin` statements
- Writing simple `if` conditions and `for`/`while` loops
- Declaring and indexing arrays (`int arr[5]`)
- Writing and calling functions

---

## What You Will Learn

| Topic | Covered in |
|---|---|
| Address-of operator `&` | Section 1 |
| Pointer declaration (`int* p`) | Section 2 |
| Dereferencing (`*p`) | Section 2 |
| Writing through a pointer | Section 2 |
| `nullptr` | Section 2 |
| Pass-by-pointer (modifying caller's data) | Section 3A |
| Pointer arithmetic (`p++`, `*(p+n)`) | Section 3B |
| Arrays passed as pointers | Section 3C |
| Multi-output functions via pointers | Challenge A |
| Two-pointer algorithmic pattern | Challenge B |

---

## Repository Contents

```
.
├── MainProgram.cpp          ← Student file (fill in the TODOs)
├── MainProgram_teacher.cpp  ← Reference solution (do not open until done!)
├── test_pointers.cpp        ← Automated tests for partial grading
├── catch_amalgamated.hpp    ← Catch2 testing framework (header)
├── catch_amalgamated.cpp    ← Catch2 testing framework (source)
├── Makefile                 ← Build rules
└── README.md                ← This file
```

> **Note:** `MainProgram_teacher.cpp` is for the instructor only.  
> Do **not** distribute it to students via GitHub Classroom's student repositories.

---

## Lab Structure

| Section | Topic | Time |
|---|---|---|
| Section 1 — Warm-Up | Variables, addresses, `&` operator | ~5 min |
| Section 2 — Core Concepts | Pointers: declare, assign, dereference, `nullptr` | ~10 min |
| Section 3A — Guided Exercise | `swapInts` via pass-by-pointer | ~5 min |
| Section 3B — Guided Exercise | Pointer arithmetic over arrays | ~5 min |
| Section 3C — Guided Exercise | `fillArray` + `sumArray` | ~5 min |
| Challenge A | `findMinMax` via output pointers | ~5 min |
| Challenge B | `reverseArray` with two pointer variables | ~5 min |

---

## How to Compile & Run

### Build the interactive lab

```bash
g++ MainProgram.cpp -o lab
./lab
```

Or using make:

```bash
make        # build
make run    # build + run immediately
```

### Run automated tests (partial grading)

Each `make test_N` target compiles and runs only that group of tests.  
This lets you earn partial credit even if not all sections are complete.

```bash
make test_1   # Pointer basics: dereference, address, nullptr, arithmetic
make test_2   # swapInts pass-by-pointer
make test_3   # fillArray + sumArray
make test_4   # findMinMax + reverseArray  (challenge)
make test_all # Run every group at once
```

**Expected output when all tests pass:**

```
All tests passed (56 assertions in 27 test cases)
```

### Clean build artifacts

```bash
make clean
```

---

## Submission Instructions

1. Complete all `// TODO:` markers in `MainProgram.cpp`.
2. Make sure your file compiles without errors:
   ```bash
   g++ MainProgram.cpp -o lab
   ```
3. Run the tests to check your work:
   ```bash
   make test_all
   ```
4. Commit **only** `MainProgram.cpp` to your GitHub Classroom repository:
   ```bash
   git add MainProgram.cpp
   git commit -m "Lab 05: Pointers – completed"
   git push
   ```
5. Do **not** modify `test_pointers.cpp`, `catch_amalgamated.*`, or the `Makefile`.

---

## Grading Criteria

| Component | Weight | How It Is Measured |
|---|---|---|
| **Correctness** | 50 % | Automated tests (`make test_all`); each test group is worth 12.5 % |
| **Code Quality** | 20 % | Clean, readable code; meaningful variable names; no unnecessary duplication |
| **Completion** | 20 % | All TODO markers addressed; code compiles without errors |
| **Challenge** | 10 % | `findMinMax` and `reverseArray` pass their test cases (`make test_4`) |

### Partial Credit by Test Group

| Target | Section | Points Available |
|---|---|---|
| `make test_1` | Pointer basics | 12.5 pts |
| `make test_2` | `swapInts` | 12.5 pts |
| `make test_3` | `fillArray` + `sumArray` | 12.5 pts |
| `make test_4` | Challenge (`findMinMax` + `reverseArray`) | 12.5 pts |

---

## Estimated Time Breakdown

| Activity | Time |
|---|---|
| Reading and understanding each section's comments | ~5 min total |
| Section 1 – Warm-Up | ~5 min |
| Section 2 – Core Concepts | ~10 min |
| Section 3 – Guided Exercises (3A, 3B, 3C) | ~15 min |
| Challenge (A + B) | ~10 min |
| Testing and fixing | ~5 min |
| **Total** | **~40 min** |

---

## Tips for Students

- **Read the comments first.** Each section has a short explanation before the TODOs. Don't skip it.
- **Compile early and often.** After each TODO, save and compile. Catching one error at a time is much easier than fixing ten.
- **`*` has two meanings.** `int* p` declares a pointer. `*p` (used later) dereferences it. Don't mix them up.
- **`&` has two meanings too.** `int& r` is a reference (not used here). `&x` is the address of `x`. In this lab it is always the address-of operator.
- **Never dereference `nullptr`.** If `p == nullptr`, doing `*p` crashes the program immediately.
- **Pointer arithmetic is typed.** `p++` on an `int*` moves 4 bytes forward (to the next `int`). On a `double*` it moves 8 bytes.
- **An array name IS a pointer.** `int arr[5]; int* p = arr;` is perfectly legal. `arr[i]` and `*(arr + i)` are identical.
- **Use `make test_N` after each section** to check your work before moving on.
- If a test group fails, read the Catch2 output carefully — it tells you exactly which assertion failed and what values it saw.

---

## Quick Pointer Reference Card

```cpp
int x = 42;

int* p = &x;    // p holds the ADDRESS of x
cout << p;      // prints address  e.g. 0x7ffd...
cout << *p;     // prints VALUE    → 42   (dereference)
*p = 99;        // WRITES 99 into x through the pointer

int* q = nullptr;   // q points to nothing — safe initial value
// NEVER do *q      — crash!

// Pointer arithmetic
int arr[] = {10, 20, 30};
int* r = arr;       // points to arr[0]
r++;                // now points to arr[1]
cout << *r;         // 20
cout << *(r + 1);   // 30  (offset without moving r)
```
