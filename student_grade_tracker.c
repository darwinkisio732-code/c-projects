#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LEN 50
#define NUM_SUBJECTS 3

// Clear remaining characters from stdin buffer
void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Safely read text input
void read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// Safely read integer input
int read_int(const char *prompt) {
    int val;
    printf("%s", prompt);
    while (scanf("%d", &val) != 1) {
        clear_buffer();
        printf("Invalid input. Try again: ");
    }
    clear_buffer();
    return val;
}

// Safely read valid marks between 0 and 100
int read_mark(const char *prompt) {
    int mark;
    while (1) {
        mark = read_int(prompt);
        if (mark >= 0 && mark <= 100) {
            return mark;
        }
        printf("Invalid mark! Must be between 0 and 100.\n");
    }
}

int main(void) {
    int num_students;
    char students_names[MAX_STUDENTS][NAME_LEN];
    int student_marks[MAX_STUDENTS][NUM_SUBJECTS];
    int total_marks[MAX_STUDENTS] = {0};
    float average_marks[MAX_STUDENTS];
    float class_average = 0.0f;
    int class_total = 0;
    int count = 0;
    int highest_index = 0;

    printf("\n====== STUDENT GRADE TRACKER ======\n");

    // Validate number of students
    do {
        num_students = read_int("How many students? (1 - 10): ");
        if (num_students < 1 || num_students > MAX_STUDENTS) {
            printf("Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        }
    } while (num_students < 1 || num_students > MAX_STUDENTS);

    // Input details
    for (int i = 0; i < num_students; i++) {
        printf("\n---- Student %d ----\n", i + 1);
        read_string("Name: ", students_names[i], NAME_LEN);

        student_marks[i][0] = read_mark("Mathematics: ");
        student_marks[i][1] = read_mark("English: ");
        student_marks[i][2] = read_mark("Science: ");

        total_marks[i] = student_marks[i][0] + student_marks[i][1] + student_marks[i][2];
        average_marks[i] = total_marks[i] / (float)NUM_SUBJECTS;
        class_total += total_marks[i];

        if (total_marks[i] > total_marks[highest_index]) {
            highest_index = i;
        }
    }

    class_average = (float)class_total / (num_students * NUM_SUBJECTS);

    // Output individual results
    for (int i = 0; i < num_students; i++) {
        printf("\n====== RESULTS FOR %s ======\n", students_names[i]);
        printf("Mathematics: %d\n", student_marks[i][0]);
        printf("English:     %d\n", student_marks[i][1]);
        printf("Science:     %d\n", student_marks[i][2]);
        printf("Total: %d | Average: %.2f | ", total_marks[i], average_marks[i]);

        // Grade calculation
        if (average_marks[i] >= 80) {
            printf("Grade A\n");
        } else if (average_marks[i] >= 60) {
            printf("Grade B\n");
        } else if (average_marks[i] >= 50) {
            printf("Grade C\n");
        } else if (average_marks[i] >= 40) {
            printf("Grade D\n");
        } else {
            printf("Grade E\n");
        }
    }

    // Class statistics
    printf("\n====== CLASS SUMMARY ======\n");
    printf("Class Average: %.2f\n", class_average);
    printf("Highest Scorer: %s with %d marks\n",
           students_names[highest_index], total_marks[highest_index]);

    // Count passed students
    for (int i = 0; i < num_students; i++) {
        if (average_marks[i] >= 50.0f) {
            count++;
        }
    }
    printf("Students Passed: %d out of %d\n", count, num_students);

    return 0;
}
