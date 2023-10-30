CC = g++
CFLAGS = -g -Wall
TARGET = myprogram

# This detects all .cpp files in the current directory
SRCS = $(wildcard *.cpp) 
OBJS = $(SRCS:.cpp=.o)

# default target
all: $(TARGET)

# depends on the object files ($(OBJS)) and links them to create the executable.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)


# A pattern rule that compiles .cpp files to .o files.
# Any target file ending with .o can be built from a source file ending with .cpp. 
# The % symbol is a wildcard that matches any characters
# $<: This is an automatic variable that represents the first prerequisite of the rule
# $@: The $@ automatic variable represents the target file name.
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
