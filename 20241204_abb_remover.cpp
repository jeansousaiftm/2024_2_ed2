#include<stdio.h>

struct Node {
    int value;
    Node *left, *right;
    Node() {
        left = NULL;
        right = NULL;
    }
    Node(int _value) {
        value = _value;
        left = NULL;
        right = NULL;
    }
    int g() {
        int g = 0;
        if (left != NULL) g++;
        if (right != NULL) g++;
        return g;
    }
};

struct Tree {
    Node *root;
    Tree() {
        root = NULL;
    }
    bool empty() {
        return root == NULL;
    }


    void insert(int value) {
        if (empty()) {
            root = new Node(value);
            return;
        }
        insert(root, value);
    }

    void insert(Node *aux, int value) {
        if (value < aux->value) {
            if (aux->left == NULL) {
                aux->left = new Node(value);
                return;
            }
            insert(aux->left, value);
        } else if (value > aux->value) {
            if (aux->right == NULL) {
                aux->right = new Node(value);
                return;
            }
            insert(aux->right, value);
        }
    }

    bool search(int value) {
        Node *aux = root;
        while (aux != NULL) {
            if (value == aux->value) {
                return true;
            } else if (value < aux->value) {
                aux = aux->left;
            } else if (value > aux->value) {
                aux = aux->right;
            }
        }
        return false;
    }

    void inOrder() {
        inOrder(root);
        printf("\n");
    }

    void inOrder(Node *aux) {
        if (aux == NULL) return;
        inOrder(aux->left);
        printf("%d ", aux->value);
        inOrder(aux->right);
    }

    void remove(int value) {

        if (!empty() && root->value == value) {

            if (root->g() == 0) {
                delete(root);
                root = NULL;
            } else if (root->g() == 1) {
                Node *toDel = root;
                if (root->left != NULL) {
                    root = root->left;
                } else {
                    root = root->right;
                }
                delete(toDel);
            } else {
                Node *toDel = root;
                Node* aux2 = root->left;
                while (aux2->right != NULL) {
                    aux2 = aux2->right;
                }
                aux2->right = root->right;
                root = root->left;
                delete(toDel);
            }

            return;
        }

        Node* aux = root;
        Node* toDel = root;

        while (toDel != NULL) {

            if (toDel->value == value) {

                if (toDel->g() == 0) {

                    if (value > aux->value) {
                        aux->right = NULL;
                    } else {
                        aux->left = NULL;
                    }

                    delete(toDel);

                } else if (toDel->g() == 1) {

                    Node* toMove;
                    if (toDel->left != NULL) {
                        toMove = toDel->left;
                    } else {
                        toMove = toDel->right;
                    }

                    if (value > aux->value) {
                        aux->right = toMove;
                    } else {
                        aux->left = toMove;
                    }

                    delete(toDel);

                } else {

                    Node* aux2 = toDel->left;

                    while (aux2->right != NULL) {
                        aux2 = aux2->right;
                    }

                    aux2->right = toDel->right;

                    if (value > aux->value) {
                        aux->right = toDel->left;
                    } else {
                        aux->left = toDel->left;
                    }

                    delete(toDel);

                }

                return;

            } else if (value < toDel->value) {
                aux = toDel;
                toDel = toDel->left;
            } else {
                aux = toDel;
                toDel = toDel->right;
            }
        }
    }

};

int main() {
    Tree t;
    t.insert(3);
    t.insert(8);
    t.insert(10);
    t.insert(5);
    t.insert(6);
    t.inOrder();
    t.remove(3);
    t.inOrder();
    return 0;
}
