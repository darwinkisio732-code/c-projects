#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 10
#define NAME_LEN 50
#define DEPT_LEN 30

typedef struct {
    char name[NAME_LEN];
    float salary;
    int yearsWorked;
    char department[DEPT_LEN];
} Employee;

// Input handler for reading string lines safely
void readString(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void inputEmployeeDetails(Employee emp[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\n===== Employee %d =====\n", i + 1);
        
        printf("Enter Name: ");
        readString(emp[i].name, sizeof(emp[i].name));

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        getchar(); // Clear buffer newline

        printf("Years Worked: ");
        scanf("%d", &emp[i].yearsWorked);
        getchar(); // Clear buffer newline

        printf("Department: ");
        readString(emp[i].department, sizeof(emp[i].department));
    }
}

void displayEmployees(const Employee emp[], int count) {
    printf("\n================================ EMPLOYEES DATA ================================\n");
    printf("%-20s %-12s %-12s %-20s\n", "Name", "Salary ($)", "Years", "Department");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-12.2f %-12d %-20s\n", 
               emp[i].name, emp[i].salary, emp[i].yearsWorked, emp[i].department);
    }
}

float calculateTotalSalary(const Employee emp[], int count) {
    float totalSalary = 0.0f; // Fixed: int to float
    for (int i = 0; i < count; i++) {
        totalSalary += emp[i].salary;
    }
    return totalSalary;
}

int findHighestPaidEmployee(const Employee emp[], int count) {
    int highestIdx = 0;
    for (int i = 1; i < count; i++) {
        if (emp[i].salary > emp[highestIdx].salary) {
            highestIdx = i;
        }
    }
    return highestIdx;
}

int findMostExperienced(const Employee emp[], int count) {
    int expIdx = 0;
    for (int i = 1; i < count; i++) {
        if (emp[i].yearsWorked > emp[expIdx].yearsWorked) {
            expIdx = i;
        }
    }
    return expIdx;
}

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    int num_of_employee;

    printf("How many Employees? (Max %d): ", MAX_EMPLOYEES);
    if (scanf("%d", &num_of_employee) != 1 || num_of_employee <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    getchar();

    if (num_of_employee > MAX_EMPLOYEES) {
        printf("Capping input to maximum allowed (%d).\n", MAX_EMPLOYEES);
        num_of_employee = MAX_EMPLOYEES;
    }

    inputEmployeeDetails(employees, num_of_employee);
    displayEmployees(employees, num_of_employee);

    float total_salary = calculateTotalSalary(employees, num_of_employee);
    int highestPaid = findHighestPaidEmployee(employees, num_of_employee);
    int mostExperienced = findMostExperienced(employees, num_of_employee);

    printf("\n-------------------------------- SUMMARY --------------------------------\n");
    printf("Total Payroll:            $%.2f\n", total_salary);
    printf("Highest Paid Employee:    %s ($%.2f)\n", employees[highestPaid].name, employees[highestPaid].salary);
    printf("Most Experienced:         %s (%d years)\n", employees[mostExperienced].name, employees[mostExperienced].yearsWorked);
    printf("=========================================================================\n\n");

    return 0;
}
