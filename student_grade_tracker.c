#include <stdio.h>

int main() {
    int num_students;
    char students_names[10][50];
    int student_marks[10][3];
    int i;
    int total_marks[10];
    float average_marks[10];
    float class_average;
    int class_total = 0;
    int count = 0;
    int highest_index = 0;

    printf("\n\n======STUDENT GRADE TRACKER======\n");
    printf("How many students? (Max 10): ");
    scanf("%d", &num_students);

    // Input
    for (i = 0; i < num_students; i++) {
        printf("\n----Student %d----\n", i + 1);
        printf("Name: ");
        scanf("%s", students_names[i]);
        printf("Mathematics: ");
        scanf("%d", &student_marks[i][0]);
        printf("English: ");
        scanf("%d", &student_marks[i][1]);
        printf("Science: ");
        scanf("%d", &student_marks[i][2]);

        total_marks[i] = student_marks[i][0] + student_marks[i][1] + student_marks[i][2];
        average_marks[i] = total_marks[i] / 3.0;
        class_total += total_marks[i];
        
        if(total_marks[i] > total_marks[highest_index]) {
            highest_index = i;
        }
    }
    
    class_average = (float)class_total / (num_students * 3);

    // Output individual results
    for (i = 0; i < num_students; i++) {
        printf("\n\n======RESULTS FOR %s======\n", students_names[i]);
        printf("Mathematics: %d\n", student_marks[i][0]);
        printf("English: %d\n", student_marks[i][1]);
        printf("Science: %d\n", student_marks[i][2]);
        printf("Total: %d | Average: %.2f | ", total_marks[i], average_marks[i]);

        // Grade
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
    printf("\n\n======CLASS SUMMARY======\n");
    printf("Class Average: %.2f\n", class_average);
    printf("Highest Scorer: %s with %d marks\n", 
           students_names[highest_index], total_marks[highest_index]);
    
    // Count passed (average >= 50)
    count = 0;
    for (i = 0; i < num_students; i++) {
        if (average_marks[i] >= 50) {
            count++;
        }
    }
    printf("Students Passed: %d out of %d\n", count, num_students);

    return 0;
}