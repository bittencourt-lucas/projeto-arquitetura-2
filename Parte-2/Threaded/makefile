CFILES=$(shell find src -name '*.cpp')
OFILES=$(patsubst %.cpp,%.o,$(CFILES))
TARGET=Threaded-Optimized
FLAGS=-Wall -Wextra -Wpedantic -fopenmp
-CC_FLAGS=-std=c++11

$(TARGET): $(OFILES)
		g++ -o $(TARGET) $(OFILES) $(FLAGS)

%.o: %.cpp
		g++ $(CC_FLAGS) -o $@ -c $< -fopenmp

clean:
		rm -rf $(TARGET) $(OFILES)