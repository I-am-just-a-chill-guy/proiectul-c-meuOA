#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structura unui nod al arborelui
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Funcție pentru a crea un nod nou
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Funcție pentru inserarea unui element într-un arbore binar ordonat
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

// Traversare pre-ordine
void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Traversare in-ordine
void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Traversare post-ordine
void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Traversare pe nivel (level-order traversal) folosind o coadă
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100]; // Coada pentru niveluri
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

    // Inițializăm generatorul de numere aleatorii
    srand(time(NULL));
    
    int n = 10; // Numărul de noduri generate
    printf("Se insereaza %d elemente aleatorii in arbore:\n", n);
    for (int i = 0; i < n; i++) {
        int randomValue = rand() % 100; // Generăm valori între 0 și 99
        printf("%d ", randomValue);
        root = insert(root, randomValue);
    }
    printf("\n\n");

    // Afișăm rezultatele traversărilor
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

    return 0;
}
