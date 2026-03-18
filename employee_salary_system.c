#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[50];
    float salary;
    int yearsWorked;
    char department[30];
};

void inputEmployeeDetails(struct Employee s[], int num_of_employee)
{
    for (int i = 0; i < num_of_employee; i++)
    {
        printf("\n=====Employee %d=====", i + 1);
        printf("\nEnter Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0;

        printf("\nSalary: ");
        scanf("%f", &s[i].salary);
        getchar();

        printf("\nYears Worked: ");
        scanf("%d", &s[i].yearsWorked);
        getchar();

        printf("\nDepartment: ");
        fgets(s[i].department, sizeof(s[i].department), stdin);
        s[i].department[strcspn(s[i].department, "\n")] = 0;
    }
}

void employeeDisplay(struct Employee s[], int num_of_employee)
{
    printf("\n==================EMPLOYEES DATA==================");
    printf("\n%-15s %-10s %-10s %-15s", "Name", "Salary", "Years", "Department");
    printf("\n--------------------------------------------------");
    for (int i = 0; i < num_of_employee; i++)
    {
        printf("\n%-15s %-10.2f %-10d %-15s", s[i].name, s[i].salary, s[i].yearsWorked, s[i].department);
    }
}

float calculateTotalSalary(struct Employee s[], int num_of_employee)
{
    int totalSalary = 0;

    for (int i = 0; i < num_of_employee; i++)
    {
        totalSalary += s[i].salary;
    }

    return totalSalary;
}

int findHighestPaidEmployee(struct Employee s[], int num_of_employee)
{
    int highestSalary = 0;

    for (int i = 0; i < num_of_employee; i++)
    {
        if (s[i].salary > s[highestSalary].salary)
        {
            highestSalary = i;
        }
    }

    return highestSalary;
}

int findMostExperienced(struct Employee s[], int num_of_employee)
{
    int mostExperienced = 0;

    for (int i = 0; i < num_of_employee; i++)
    {
        if (s[i].yearsWorked > s[mostExperienced].yearsWorked)
        {
            mostExperienced = i;
        }
    }

    return mostExperienced;
}

int main()
{
    struct Employee employees[10];
    int num_of_employee;

    printf("\nHow many Employees? ");
    scanf("%d", &num_of_employee);
    getchar();

    inputEmployeeDetails(employees, num_of_employee);

    employeeDisplay(employees, num_of_employee);

    float total_salary = calculateTotalSalary(employees, num_of_employee);
    printf("\nTotal Salary Paid: %.1f", total_salary);

    int highestPaid = findHighestPaidEmployee(employees, num_of_employee);
    printf("\nHighest Paid Employee: %s - %.1f", employees[highestPaid].name, employees[highestPaid].salary);

    int mostExperiencedEmployee = findMostExperienced(employees, num_of_employee);
    printf("\nMost Experienced Employee: %s", employees[mostExperiencedEmployee].name);

    return 0;
}