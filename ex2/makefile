
TARGET	=	prog
CC	= g++
CXXFLAGS= -ansi -std=c++11 -Wall  


default: $(TARGET)
all: clean default

OBJECTS	= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
		del -f *.o
		del -f *.exe
	