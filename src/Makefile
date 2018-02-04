FLAGS=-std=c++17 -Wall -Werror -g
LIBS=-lsqlite3 -lcurl

all: main.o DB.o Result.o SMTP.o
	g++ $(FLAGS) main.o DB.o Result.o SMTP.o -o cppmaillist $(LIBS)

main.o: main.cpp DB.hpp Result.hpp
	g++ -c $(FLAGS) main.cpp -o main.o

DB.o: DB.cpp DB.hpp Result.hpp
	g++ -c $(FLAGS) DB.cpp -o DB.o

Result.o: Result.cpp Result.hpp
	g++ -c $(FLAGS) Result.cpp -o Result.o

SMTP.o: SMTP.cpp SMTP.hpp
	g++ -c $(FLAGS) SMTP.cpp -o SMTP.o
