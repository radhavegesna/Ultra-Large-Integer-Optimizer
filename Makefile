CC = gcc  # Change this if you use a different compiler
CFLAGS = -Wall -shared -fPIC  # Flags for warnings, shared library, PIC
 
# Target to create the shared library
all: file_reader.so
 
# Rule to compile and link the shared library
count_pairs.so: ultralarge_int.o
    $(CC) $(CFLAGS) -o file_reader.so ultralarge_int.o
 
# Rule to compile the C source code
ultralarge_int.o: ultralarge_int.c
    $(CC) $(CFLAGS) -c ultralarge_int.c
 
# Rule to clean up (remove object file and shared library)
clean:
    rm -f file_reader.so *.o