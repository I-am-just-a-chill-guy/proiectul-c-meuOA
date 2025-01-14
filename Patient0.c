#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}


void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}

int main() {
    struct Node* root = NULL;


    srand(time(NULL));
    
    int n = 10;
    printf("Se insereaza %d elemente aleatorii in arbore:\n", n);
    for (int i = 0; i < n; i++) {
        int randomValue = rand() % 100;
        printf("%d ", randomValue);
        root = insert(root, randomValue);
    }
    printf("\n\n");

    printf("Traversare Pre-ordine: ");
    preOrder(root);
    printf("\n");

    printf("Traversare In-ordine: ");
    inOrder(root);
    printf("\n");

    printf("Traversare Post-ordine: ");
    postOrder(root);
    printf("\n");

    printf("Traversare Pe Nivel: ");
    levelOrder(root);
    printf("\n");

printf("aia e!");
    return 0;
}
