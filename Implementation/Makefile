SRC =src/user.cpp\
main.cpp\

INC =inc/user.h\
inc/product.h\

all: $(SRC) $(INC)
	g++ $^ -o all.out

run:all
	./all.out

coverage:$(SRC) $(INC)
	g++ -fprofile-arcs -ftest-coverage $^ -lgtest -lgtest_main -lpthread -o all.out
	./all.out
	gcov -a $(SRC)

analyze:all $(SRC)
	cppcheck --enable=all $(SRC)
	valgrind ./all.out

clean:
	rm -rf *.o *.out *.gcd* *.gcno* *.gcov* 
