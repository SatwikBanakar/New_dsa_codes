#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);
    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && data < node->left->data)
        return rightRotate(node);
    if (balanceFactor < -1 && data > node->right->data)
        return leftRotate(node);
    if (balanceFactor > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balanceFactor < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void countNodesAtEachLevel(struct Node* node, int level, int* count) {
    if (node == NULL)
        return;

    count[level]++;
    countNodesAtEachLevel(node->left, level + 1, count);
    countNodesAtEachLevel(node->right, level + 1, count);
}
struct Node* searchNode(struct Node* node, int data) {
    if (node == NULL || node->data == data)
        return node;

    if (data < node->data)
        return searchNode(node->left, data);
    else
        return searchNode(node->right, data);
}
void displayTree(struct Node* root, int space) {
    if (root == NULL)
        return;

    space += 10;

    displayTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    displayTree(root->left, space);
}

// Function to free memory allocated for the AVL tree
void freeTree(struct Node* node) {
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    struct Node* root = NULL;
    int data, choice;

    do {
        printf("1. Insert\n");
        printf("2. Pre-order Traversal\n");
        printf("3. In-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Display Tree\n");

        printf("7. Count Nodes at Each Level\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                freeTree(root);
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("In-order traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("AVL tree:\n");
                displayTree(root, 0);
                printf("\n");
                break;
            case 6:
                printf("Enter the node to search for: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL)
                    printf("Node %d found in the AVL tree.\n", data);
                else
                    printf("Node %d not found in the AVL tree.\n", data);
                break;
            case 7:
                {
                    int height = getHeight(root);
                    int* count = (int*)calloc(height, sizeof(int));
                    countNodesAtEachLevel(root, 0, count);

                    printf("Number of nodes at each level:\n");
                    for (int i = 0; i < height; i++) {
                        printf("Level %d: %d\n", i, count[i]);
                    }
                    printf("\n");

                    free(count);
                }
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}
