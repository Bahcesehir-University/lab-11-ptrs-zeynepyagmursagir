# =============================================================================
# Makefile — CMP1001 Lab: Introduction to Pointers
# =============================================================================
#
# TARGETS
#   make          →  build the student lab executable
#   make run      →  build + run the lab
#   make test_1   →  Pointer basics            (Section 1 & 2)
#   make test_2   →  swapInts                  (Section 3A)
#   make test_3   →  fillArray + sumArray      (Section 3C)
#   make test_4   →  findMinMax + reverse      (Challenge)
#   make test_all →  all four test groups
#   make clean    →  remove all build artifacts
#
# =============================================================================

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Student source compiled as a library (no main) for testing
STUDENT_SRC  = MainProgram.cpp
STUDENT_OBJ  = student.o

# Catch2 amalgamated sources
CATCH_SRC    = catch_amalgamated.cpp
CATCH_OBJ    = catch_amalgamated.o

TEST_SRC     = test_pointers.cpp

# ── Default target: build the interactive lab ──────────────────────────────
all: lab

lab: $(STUDENT_SRC)
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Build OK → run with: ./lab"

run: lab
	./lab

# ── Shared object files ─────────────────────────────────────────────────────

# Compile student code without its main()
$(STUDENT_OBJ): $(STUDENT_SRC)
	$(CXX) $(CXXFLAGS) -DNO_MAIN -c $< -o $@

# Compile Catch2 once (slow first time, then cached)
$(CATCH_OBJ): $(CATCH_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ── Individual test targets ─────────────────────────────────────────────────

# test_1 — pointer basics: dereference, address, nullptr, arithmetic
test_1: $(STUDENT_OBJ) $(CATCH_OBJ) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) \
	    -DCATCH_CONFIG_MAIN \
	    $(TEST_SRC) $(STUDENT_OBJ) $(CATCH_OBJ) \
	    -o test_1_bin
	./test_1_bin "[test_1]" --reporter compact
	@echo ""
	@echo "── test_1 done ──"

# test_2 — swapInts pass-by-pointer
test_2: $(STUDENT_OBJ) $(CATCH_OBJ) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) \
	    -DCATCH_CONFIG_MAIN \
	    $(TEST_SRC) $(STUDENT_OBJ) $(CATCH_OBJ) \
	    -o test_2_bin
	./test_2_bin "[test_2]" --reporter compact
	@echo ""
	@echo "── test_2 done ──"

# test_3 — fillArray + sumArray
test_3: $(STUDENT_OBJ) $(CATCH_OBJ) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) \
	    -DCATCH_CONFIG_MAIN \
	    $(TEST_SRC) $(STUDENT_OBJ) $(CATCH_OBJ) \
	    -o test_3_bin
	./test_3_bin "[test_3]" --reporter compact
	@echo ""
	@echo "── test_3 done ──"

# test_4 — findMinMax + reverseArray (challenge)
test_4: $(STUDENT_OBJ) $(CATCH_OBJ) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) \
	    -DCATCH_CONFIG_MAIN \
	    $(TEST_SRC) $(STUDENT_OBJ) $(CATCH_OBJ) \
	    -o test_4_bin
	./test_4_bin "[test_4]" --reporter compact
	@echo ""
	@echo "── test_4 done ──"

# test_all — run every group in sequence
test_all: $(STUDENT_OBJ) $(CATCH_OBJ) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) \
	    -DCATCH_CONFIG_MAIN \
	    $(TEST_SRC) $(STUDENT_OBJ) $(CATCH_OBJ) \
	    -o test_all_bin
	@echo "════════════════════════════════════"
	@echo "   Running ALL test groups"
	@echo "════════════════════════════════════"
	./test_all_bin --reporter compact
	@echo ""
	@echo "── test_all done ──"

# ── Cleanup ─────────────────────────────────────────────────────────────────
clean:
	rm -f lab *.o test_1_bin test_2_bin test_3_bin test_4_bin test_all_bin

.PHONY: all run test_1 test_2 test_3 test_4 test_all clean
