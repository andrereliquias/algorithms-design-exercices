CXX = g++
CXXFLAGS = 

EX ?= ./
SRC = $(EX)/main.cpp
TARGET = $(EX)/exec
TEST_DIR = $(EX)/tests
TEST_CASES = $(shell ls $(TEST_DIR)/*.in | sed 's/\.in//')

.PHONY: all clean run tests

all: clean $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

tests: all
	@for test in $(TEST_CASES); do \
		{ TIME=$$( (time ./$(TARGET) < $$test.in > $$test.out.tmp) 2>&1 1>/dev/null ); } 2>/dev/null; \
		if diff -q $$test.out.tmp $$test.out > /dev/null; then \
			echo "✅ $$(basename $$test) - Pass - Time: $$TIME\n"; \
		else \
			echo "❌ $$(basename $$test) - Failed - Time: $$TIME\n"; \
		fi; \
		rm -f $$test.out.tmp; \
	done

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

debug: all
	@if [ ! -f "$(EX)/tests/$(IN).in" ]; then \
		echo "❌ Erro: Arquivo '$(EX)/tests/$(IN).in' não encontrado!"; \
		exit 1; \
	fi
	rm -f $(EX)/debug.out
	./$(TARGET) < $(EX)/tests/$(IN).in > $(EX)/debug.out
	code $(EX)/debug.out
	diff --color=auto $(EX)/debug.out $(EX)/tests/$(IN).out
