/*
 * C++ Program To Implement BST
 */
#ifndef BSTREE_H
#define BSTREE_H


/*
 * Node Declaration
 */
struct node
{
    std::string name;
    struct node *p_left;
    struct node *p_right;
};

/*
 * Class Declaration
 */
class BST
{
public:
		node* root;
        void find(std::string, node **, node **);
        void insert(node *, node *);
        void remove(std::string);
        void case_0(node *,node *);
        void case_1(node *,node *);
        void case_2(node *,node *);
        void display(node *, int);
        void printSearch(node *, std::string);
        BST()
        {
            root = nullptr;
        }
};


#endif	//BSTREE_H
