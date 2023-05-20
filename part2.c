#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// define the binary search tree node structure
typedef struct bst_node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct bst_node *left;
    struct bst_node *right;
} bst_node_t;

// recursively traverse the binary search tree and print the word frequencies
void print_bst(bst_node_t *root) {
    if (root != NULL) {
        print_bst(root->left);
        printf("%s %s %d\n", root->word, strrev(root->word), root->count);
        print_bst(root->right);
    }
}

// example usage
int main() {
    // create a sample binary search tree
    bst_node_t *root = NULL;
    root = insert_bst(root, "test");
    root = insert_bst(root, "tset");
    root = insert_bst(root, "the");
    root = insert_bst(root, "eht");
    root = insert_bst(root, "this");
    root = insert_bst(root, "siht");
    root = insert_bst(root, "a");
    root = insert_bst(root, "and");
    root = insert_bst(root, "dna");
    root = insert_bst(root, "appears");
    root = insert_bst(root, "sraeppa");
    root = insert_bst(root, "as");
    root = insert_bst(root, "containing");
    root = insert_bst(root, "gniniatnoc");
    root = insert_bst(root, "file");
    root = insert_bst(root, "eilf");
    root = insert_bst(root, "is");
    root = insert_bst(root, "si");
    root = insert_bst(root, "Level");
    root = insert_bst(root, "level");
    root = insert_bst(root, "Madam");
    root = insert_bst(root, "madam");
    root = insert_bst(root, "Mom");
    root = insert_bst(root, "mom");
    root = insert_bst(root, "palindromes");
    root = insert_bst(root, "semordnilap");
    root = insert_bst(root, "such");
    root = insert_bst(root, "hcus");
    root = insert_bst(root, "twice");
    root = insert_bst(root, "ecitw");
    root = insert_bst(root, "word");
    root = insert_bst(root, "drow");

    // print the word frequencies
    print_bst(root);

    return 0;
}
