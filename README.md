# Student Management System

## Features

1. **Add a Student**
   - Input student details: ID, name, age, and GPA. Prevents duplicate IDs to maintain unique records.

2. **Display All Students**
   - Lists all students with their respective details (ID, name, age, GPA). Organizes records in the order they were added.

3. **Search by ID**
   - Find and display the details of a specific student using their unique ID.

4. **Update Student Information**
   - Modify the name, age, or GPA of an existing student by their ID.

5. **Delete a Student**
   - Remove a student record from the system using their ID. Handles both head and non-head node deletion seamlessly.

6. **Calculate Average GPA**
   - Computes and displays the average GPA of all students in the system.

7. **Find the Student with the Highest GPA**
   - Identifies and displays the details of the student with the highest GPA.

8. **Exit the Program**
   - Safely terminates the program.

## Implementation Details

### Dynamic Memory Allocation

- Each student is stored in a dynamically allocated node of a linked list. Ensures scalability for managing multiple student records.

### Modular Design

- Functions are written for each feature (e.g., `addStudent`, `updateStudent`, `deleteStudent`), making the code reusable and easy to maintain.

### Error Handling

- Prevents duplicate IDs during student addition.
- Handles edge cases like empty lists or invalid inputs gracefully.

## How to Use

1. Compile the program using a C compiler, e.g., `gcc student_management.c -o student_management`.
2. Run the program: `./student_management`.
3. Use the menu options to perform various operations:
   - Enter `1` to add a new student.
   - Enter `2` to display all students, and so on.
4. Follow prompts to input student details or IDs as required.
```` ▋
