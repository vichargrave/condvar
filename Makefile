CC		= g++
CFLAGS		= -c -Wall -g
LDFLAGS		= -lpthread
SOURCES		= main.cpp ../threads/thread.cpp
INCLUDES	= -I../threads -I../mutex
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= condv

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
