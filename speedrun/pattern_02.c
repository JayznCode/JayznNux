char str[] = "hello";
int i = 0;
while (str[i] != '\0') {
    // Process each character: str[i]
    i++;
}





void update_value(int *ptr) {
    *ptr = 100; // Modifies the original variable
}




typedef struct {
    char name[20];
    int age;
} Person;

Person p = {"Brady", 46};
Person *ptr = &p;
printf("%s, %d\n", ptr->name, ptr->age);




int rows = 3, cols = 4;
int **matrix = malloc(sizeof(int *) * rows);
for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(sizeof(int) * cols);
}
// Freeing process is the reverse...





typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = malloc(sizeof(Node));
head->data = 10;
head->next = NULL;




