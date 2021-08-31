TARGET	=	prog.exe
CC	= g++
CFLAGS	= -g 

default: $(TARGET)
all: default

OBJECTS	= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.hpp)

%.o: %.cpp $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
		$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
		del -f *.o
		del -f *.exe
	