#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node in a linked list
typedef struct Node {
    char *line;
    struct Node *next;
} Node;

// Function to create a new node with the given line
Node* createNode(char *line) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "malloc failed.\n");
        exit(1);
    }
    new_node->line = line;
    new_node->next = NULL;
    return new_node;
}

// Function to reverse the lines by reading them into a linked list
Node* read_lines(FILE *input) {
    Node *head = NULL;
    Node *current = NULL;
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t line_length;

    while ((line_length = getline(&buffer, &buffer_size, input)) != -1) {
        // Create a copy of the line
        char *line = strdup(buffer);
        if (line == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }

        // Create a new node and append it to the list
        Node *new_node = createNode(line);
        if (head == NULL) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    free(buffer);
    return head;
}

// Function to print the lines in reverse order from the linked list
void print_lines(Node *head, FILE *output) {
    Node *current = head;
    while (current != NULL) {
        fprintf(output, "%s", current->line);
        Node *temp = current;
        current = current->next;
        free(temp->line);
        free(temp);
    }
}


int main(int argc, char *argv[]) {
    FILE *input = stdin;
    FILE *output = stdout;

    if (argc > 3) {
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }

    // Open input file if specified, otherwise use stdin
    if (argc >= 2) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    }

    // Open output file if specified, otherwise use stdout
    if (argc == 3) {
        if (strcmp(argv[1], argv[2]) == 0) {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }

        output = fopen(argv[2], "w");
        if (output == NULL) {
            fprintf(stderr, "Error: cannot open file '%s'\n", argv[2]);
            exit(1);
        }
    }

    // Read and reverse the lines
    Node *head = read_lines(input);
    print_lines(head, output);

    // Clean up and close files if necessary
    if (input != stdin) fclose(input);
    if (output != stdout) fclose(output);

    return 0;
}