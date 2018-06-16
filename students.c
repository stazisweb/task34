#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define string_max_length 20
#define bool char
#define true 1
#define false 0

typedef struct student_
{
	char* surname;
	char* name;
	char* patronymic;
	int year_of_birth;
	bool is_male;
	int* marks;
} student, *p_student;

void add_student(char* file_name,
		char surname[string_max_length],
		char name[string_max_length],
		char patronymic[string_max_length],
		int year_of_birth,
		bool is_male,
		int marks[])
{
	FILE *f = fopen(file_name, "wb");
	student st;
	st.surname = surname;
	st.name = name;
	st.patronymic = patronymic;
	st.year_of_birth = year_of_birth;
	st.is_male = is_male;
	st.marks = marks;
	fwrite(&st, sizeof(st), 1, f);
	fclose(f);
}

void show_all_students(char* file_name)
{
	FILE *f = fopen(file_name, "rb");
	student st;
	fread(&st, sizeof(st), 1, f);
	printf("surname: %s \nname: %s \npatronymic: %s \nyear of birth: %d\nis_male: %c \nmarks: %d \n", st.surname, st.name, st.patronymic, st.year_of_birth, st.is_male, &st.marks);
	fclose(f);
}
