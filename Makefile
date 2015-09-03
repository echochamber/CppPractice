CXX=clang++
FLAGS=-std=c++11 -stdlib=libc++ -Wall
DEPS=src/IntegerToEnglish/
all:

clean:
	rm -fr build/*

test: integertoenglish.o
	$(CXX) $(FLAGS) src/test.cpp -Isrc/IntegerToEnglish/ -o build/$@ $^

run:
	make test > /dev/null
	build/test


#int_to_english.o: src/IntegerToEnglish/integertoenglish.cpp src/IntegerToEnglish/integertoenglish.h

integertoenglish.o: $(DEPS)/integertoenglish.cpp $(DEPS)/integertoenglish.h
	$(CXX) $(FLAGS) -c $<