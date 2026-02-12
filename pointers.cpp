// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iomanip>
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(Student *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    student.f_name = new char[128];
    student.l_name = new char[128];

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;

    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);

    std::cout << "" << std::endl;
    student.grades = new double[student.n_assignments];
    for (int i = 0; i < student.n_assignments; i++) {
      std::string prompt = "Please enter grade for assigment " + std::to_string(i) + ": ";
      student.grades[i] = promptDouble(prompt, 0, 1000);
    }

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);

    // Output `average`
    std::cout << "" << std::endl;
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    std::cout << "  Average grade: " << std::fixed << std::setprecision(1) << average << std::endl;

    delete[] student.f_name;
    delete[] student.l_name;
    delete[] student.grades;

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    int response;
    while (true) {
      std::cout << message;

      if (!(std::cin >> response)) {
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        continue;
      }

      if (std::cin.peek() != '\n') {
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cin.ignore(10000, '\n');
        continue;
      }

      if (response < min || response > max) {
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        continue;
      }

      break;
    }
    return response;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double response;
    while (true) {
      std::cout << message;

      if (!(std::cin >> response)) {
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        continue;
      }

      if (std::cin.peek() != '\n') {
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        std::cin.ignore(10000, '\n');
        continue;
      }

      if (response < min || response > max) {
        std::cout << "Sorry, I cannot understand your answer" << std::endl;
        continue;
      }

      break;
    }
    return response;
}


/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(Student *object, double *avg)
{
    // Code to calculate and store average grade
    double sum = 0.0;
    for (int i = 0; i < object->n_assignments; i++) {
      sum += object->grades[i];
    }
    *avg = sum / object->n_assignments;
}
