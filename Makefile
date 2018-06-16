TARGET = students
PREFIX = ~/tmp/pkg

.PHONY: all clean install uninstall

all: $(TARGET)

clean:
			rm -rf $(TARGET) *.o
main.o: main.c
			gcc -c -o main.o main.c
students.o: students.c
			gcc -c -o students.o students.c
$(TARGET): main.o students.o
			gcc -o $(TARGET) main.o students.o
install:
			install $(TARGET) $(PREFIX)
uninstall:
			rm -rf $(PREFIX)/$(TARGET)
