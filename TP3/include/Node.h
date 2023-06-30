#ifndef NODE_H
#define NODE_H

struct Node {
    public:
        Node();
        Node(char, int);
        ~Node();
    private:
        char data;            // Character
        int frequency;        // Frequency of the character
        Node* left;      // Pointer to the left child
        Node* right;     // Pointer to the right child
};

#endif