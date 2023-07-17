#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value <= root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderTraversal(root->right, file);
    }
}

void preorderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

void postorderTraversal(Node* root, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, file);
        postorderTraversal(root->right, file);
        fprintf(file, "%d ", root->data);
    }
}

Node* binarySearch(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return binarySearch(root->left, value);
    }
    return binarySearch(root->right, value);
}

int main() {
    FILE* inputFile = fopen("numbers.txt", "w");
    if (inputFile == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        fprintf(inputFile, "%d ", num);
    }

    fclose(inputFile);

    clock_t start = clock();

    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    Node* root = NULL;
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    fclose(file);


    int searchValue;
    printf("Enter a value to search: ");
    scanf("%d", &searchValue);

    Node* searchResult = binarySearch(root, searchValue);

    if (searchResult != NULL) {
        printf("Value found: %d\n", searchResult->data);
    } else {
        printf("Value not found!\n");
    }

    FILE* inorderFile = fopen("inorder.txt", "w");
    FILE* preorderFile = fopen("preorder.txt", "w");
    FILE* postorderFile = fopen("postorder.txt", "w");

    if (inorderFile == NULL || preorderFile == NULL || postorderFile == NULL) {
        printf("Error opening files for writing traversal results!\n");
        return 1;
    }

    inorderTraversal(root, inorderFile);
    preorderTraversal(root, preorderFile);
    postorderTraversal(root, postorderFile);

    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);

    printf("Traversal results have been stored in files: inorder.txt, preorder.txt, postorder.txt\n");

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time Complexity: %f seconds\n", time_taken);

    return 0;
}
