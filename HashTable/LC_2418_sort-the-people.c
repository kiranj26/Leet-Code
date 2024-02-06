#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* First Try
*/
// Define a structure to hold a person's name and height
typedef struct {
    char *name;
    int height;
} Person;

// Comparator function for qsort
int comparePersons(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personB->height - personA->height; // Descending order
}

// Function to sort people by their heights in descending order
char** sortPeople(char **names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    *returnSize = namesSize;
    Person *people = malloc(sizeof(Person) * namesSize);
    char **sortedNames = malloc(sizeof(char*) * namesSize);

    // Populate the people array
    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // Sort the people array
    qsort(people, namesSize, sizeof(Person), comparePersons);

    // Populate the result array with sorted names
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = people[i].name;
    }

    free(people); // Don't forget to free dynamically allocated memory
    return sortedNames;
}

int main() {
    char *names[] = {"Mary", "John", "Emma"};
    int heights[] = {180, 165, 170};
    int returnSize;
    char **sortedNames = sortPeople(names, 3, heights, 3, &returnSize);

    // Print sorted names
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", sortedNames[i]);
    }

    free(sortedNames); // Free the allocated memory for sorted names
    return 0;
}
