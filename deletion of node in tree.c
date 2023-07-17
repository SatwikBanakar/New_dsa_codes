#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node found, perform deletion
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    int i, data;
    for (i = 0; i < numNodes; i++) {
        printf("Enter node value: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    int numDeletes;
    printf("Enter the number of nodes to delete: ");
    scanf("%d", &numDeletes);

    for (i = 0; i < numDeletes; i++) {
        int dataToDelete;
        printf("Enter the value of the node to delete: ");
        scanf("%d", &dataToDelete);
        root = deleteNode(root, dataToDelete);
        printf("Deleted node: %d\n", dataToDelete);
    }

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
