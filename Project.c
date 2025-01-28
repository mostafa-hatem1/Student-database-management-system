/*
 ============================================================================
 Name        : C_project.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : C_project
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int id;
    char name[50];
    int age;
    float gpa;
} student;

typedef struct node {
    student data;
    struct node* next;
} node;

node* head = NULL;
node* current = NULL;

void addStudent(const struct student* const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);

student newStudent;
int id;

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    while (1) {
    	printf("----------------------------------------------\n");
        printf("Options:\n");
        printf("1: Add student\n");
        printf("2: Display all students\n");
        printf("3: Search by ID\n");
        printf("4: Update student information\n");
        printf("5: Delete student\n");
        printf("6: Calculate average GPA\n");
        printf("7: Find student with highest GPA\n");
        printf("8: Exit\n");
        printf("Enter your choice: ");

        int user_input;
        scanf("%d", &user_input);

        switch (user_input) {
            case 1:
            	printf("----------------------------------------------\n");
                printf("Add student information\n");
                printf("ID: ");
                scanf("%d", &id);
                current = head;
                int id_exists = 0;
                while(current != NULL){
                	if(current->data.id == id){
                		printf("Error: Student with ID %d already exists.\n", id);
                		id_exists = 1;
                		break;
                	}
                	current = current->next;
                }
                if(id_exists){
                	break;
                }
                newStudent.id = id;
                printf("Name: ");
                scanf("%s", &newStudent.name);
                printf("Age: ");
                scanf("%d", &newStudent.age);
                printf("GPA: ");
                scanf("%f", &newStudent.gpa);
                addStudent(&newStudent);
                break;

            case 2:
            	printf("----------------------------------------------\n");
                displayStudents();
                break;
            case 3:
            	printf("----------------------------------------------\n");
                printf("Enter the ID to search: ");
                scanf("%d", &id);
                searchStudentByID(id);
                break;
            case 4:
            	printf("----------------------------------------------\n");
            	printf("Enter an ID to update ");
            	scanf("%d",&id);
            	updateStudent(id);
            	break;
            case 5:
            	printf("----------------------------------------------\n");
            	printf("Enter the id to be deleted: ");
            	scanf("%d",&id);
            	deleteStudent(id);
            	break;
            case 6:
            	printf("----------------------------------------------\n");
            	printf("Average GPA is: %0.3f\n", calculateAverageGPA());
            	break;
            case 7:
            	printf("----------------------------------------------\n");
            	searchHighestGPA();
            	break;
            case 8:
            	printf("----------------------------------------------\n");
            	printf("Exiting...");
            	return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

void searchStudentByID(int id) {
     current = head;

    while (current != NULL) {
        if (current->data.id == id) {
        	printf("Student Found\n");
        	printf("ID: %d, Name: %s, Age: %d, GPA: %0.2f.\n",id, current->data.name,current->data.age,current->data.gpa);
            return;
        }
        current = current->next;
    }
    printf("Student not found\n");
    return;
}

void addStudent(const struct student* const ptr) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    newNode->data = *ptr;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayStudents(void) {
     current = head;
    if (current == NULL) {
        printf("No students in the system.\n");
        return;
    }

    int i = 1;
    while (current != NULL) {
        printf("Student %d information:\n", i);
        printf("ID: %d\n", current->data.id);
        printf("Name: %s\n", current->data.name);
        printf("Age: %d\n", current->data.age);
        printf("GPA: %.2f\n", current->data.gpa);

        current = current->next;
        i++;
    }
}

void updateStudent(int id){
	current = head;
	if(head == NULL){
		printf("There are no students to update\n");
		return;
	}
	while(current != NULL){
		if(current->data.id == id){
			printf("Enter new name: ");
			scanf("%s",&current->data.name);
			printf("Enter new age: ");
			scanf("%d",&current->data.age);
			printf("Enter new GPA: ");
			scanf("%f", &current->data.gpa);
			return;
		}
		current=current->next;
	}
	printf("Student not found\n");
	return;
}

float calculateAverageGPA(void){
	current = head;
	float avg=0;
	int count = 0;
	if(head == NULL){
		return 0;
	}
	while(current != NULL){
		avg += current->data.gpa;
		count++;
		current = current->next;
	}
	return avg /= (float)count;
}

void deleteStudent(int id){
	current = head;
	node* prev = NULL;
	if(head == NULL){
		printf("There are no students in the list\n");
		return;
	}
	while(current != NULL){
		if(current->data.id == id){
			if(current == head){
				head = current->next;
			} else{
				prev->next = current->next;
			}
			free(current);
			printf("Removal was successful\n");
			return;
		}
		prev = current;
		current = current->next;

	}
	printf("Student was not found\n");
	return;
}

void searchHighestGPA(void){
	current = head;
	if(head == NULL){
		printf("There are no students in the list\n");
		return;
	}
	node* maxptr = head;
	float max = head->data.gpa;
	while(current != NULL){
		if(current->data.gpa > max){
			maxptr = current;
			max = current->data.gpa;
		}
		current = current->next;
	}
	printf("Student with highest GPA details: \n");
	printf("Name: %s, ID: %d, Age: %d, GPA: %0.2f\n", maxptr->data.name, maxptr->data.id, maxptr->data.age, maxptr->data.gpa);
}
