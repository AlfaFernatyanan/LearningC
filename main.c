//
// Created by alfai on 5/5/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASK 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    int completed;
} Task;

Task todoList[MAX_TASK];
int numTasks = 0;

void addTasks(char *description) {
    if (numTasks > MAX_TASK) {
        strcpy(todoList[numTasks].description, description);
        todoList[numTasks].completed = 0;
        numTasks++;
        printf("Task added sucessfully.\n");
    } else {
        printf("Todo list is full. Cannot add more tasks.\n");
    }
}

void displayTasks() {
    printf("Todo List\n");
    for (int i = 0; i < numTasks; ++i) {
        printf("%d. [%s] %s\n", i + 1, todoList[i].completed ? "x" : " ", todoList[i].description);
    }
}

int main() {
    char description[MAX_DESC_LENGTH];

    printf("Simple Todo List Application\n");

    while (1) {
        printf("\n1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
            scanf(" %[^\n]s", description);
            addTasks(description);
            break;
            case 2:
                displayTasks();
            break;
            case 3:
                printf("Exiting...\n");
            exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}
