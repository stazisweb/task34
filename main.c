#include <stdlib.h>

#define true 1

int main() {
	int marks[] = {1, 2, 3, 4};
	add_student("data.bin", "Ivanov", "Ivan", "Il'ich", 1998, true, marks);
	show_all_students("data.bin");
	return 0;
}
