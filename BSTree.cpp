/*
 * Binary Search Tree class
 * Do not alter the display() function, this will break the Repl.it
 * tests
 */


#include <iostream>
#include <cstdlib>
#include "BSTree.h"

using namespace std;



/*
 * Find Element in the Tree
 * find a node by item_key and provide an updated parent node
 *   pointer and location node pointer
 */


void BST::find(string item_name, node **prnt, node **loc)
{
    node *ptr, *ptrsave;
    if (root == nullptr)
    {
        *loc = nullptr;
        *prnt = nullptr;
        return;
    }
    if (item_name == root->name)
    {
        *loc = root;
        *prnt = nullptr;
        return;
    }
    // cout << "HERE"<<endl;
    if (item_name.compare(root->name) < 0)
        ptr = root->p_left;
    else
        ptr = root->p_right;
    ptrsave = root;
    while (ptr != nullptr)
    {
        if (item_name == ptr->name)
        {
            *loc = ptr;
            *prnt = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item_name.compare(ptr->name) < 0)
            ptr = ptr->p_left;
	else
	    ptr = ptr->p_right;
    }
    *loc = nullptr;
    *prnt = ptrsave;
}

/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode)
{


    // if (we are at root)
    if(root == nullptr)
    {
        // Just create a single node for root to point to,
        //    with all the data in it.
        root = newnode;

        return;
    }
    // if (there is already a node with our key value)
    else{
    node* temp = new node;
    node* parent = temp;
    node* location = temp;
    //node *parent, *location;
    find(newnode->name, &parent, &location);
    if(location != nullptr)
    {
        //Just return
        return;
    }
    //if (the new node is less than the current node)
    node* current = tree;
    if(newnode->name.compare(current->name) < 0)
    {
        //if (see if something is already a child on the left)
        if(current->p_left != nullptr)
        {
            // if so, the recurse insert at this subtree
            insert(current->p_left, newnode);
      	}
      	else
      	{
            // otherwise the new node goes here as a leaf (ie no children)
            current->p_left = newnode;
            return;
        }
    }
    else  // it must be to the right
    {
        // cout << "HERE"<<endl;
        //if (is there already a child on right?)
        if(current->p_right != nullptr)
        {
             // if so, the recurse insert at this subtree
             insert(current->p_right, newnode);
        }
        else
        {
            // otherwise the new node goes here as a leaf (ie no children)
            current->p_right = newnode;
            // cout << "DONE"<<endl;
            return;
        }
    }
    }
}

/*
 * Delete Element from the tree
 */
void BST::remove(string item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    //if (there is no child on left or right)
    if(location->p_left == nullptr && location->p_right == nullptr){
        case_0(parent, location);
    }
    //if (there is one child on left only)
    else if(location->p_left != nullptr && location->p_right == nullptr){
        case_1(parent, location);
    }
    else if(location->p_left == nullptr && location->p_right != nullptr){
    //if (there is one child on right only)
        case_1(parent, location);
    }
    else if(location->p_left != nullptr && location->p_right != nullptr){
   // if (there are childred on left and right)
        case_2(parent, location);
    }
    //free(location);
}

/*
 * Case 0
 * the node is simply removed no other updates necessary.
 */
void BST::case_0(node *prnt, node *loc )
{
    //if (we are at the root)
    if(root == loc)
    {
        //update the root
        root = nullptr;
    }
    else
    {
      // otherwise simply remove node
      if(loc->name.compare(prnt->name) > 0)
        prnt->p_right = nullptr;
      else
        prnt->p_left = nullptr;
      delete loc;
      return;
    }
}

/*
 * Case 1
 * We have only one child so promote the child and replace the target
 * node
 */
void BST::case_1(node *prnt, node *loc)
{
    node *child;

    //if (the child is on the left?)
      if(loc->p_left != nullptr)
        //point left
        child = loc->p_left;
      // else  // must be the right side has child
      else
        // point right
        child = loc->p_right;
         //if (we are at the root handle specialy)
    if(root == loc)
    {
      // update the root
      root = child;

    }
    else{
      //if (the node is left child of parent)
      if(child->name.compare(prnt->name) < 0)
        //promote the left
        prnt->p_left = child;
      //else // the node is right of parent
      else
        //    promote right
        prnt->p_right = child;
    }
}

/*
 * Case case_2
 * We have to find and promote a successor or predecessor
 */
void BST::case_2(node *prnt, node *loc)
{
    // temporary pointers for node we are manipulating
    node* temp;

    // Find successor: Step to the right child
    node* successor = loc->p_right;
    // Find the min of the subtree on parent's right
    while(successor->p_left != nullptr){
      successor = successor->p_left;
    }
    //if (found node has no children)
    if(true){
        // Temporarily remove the successor node by replacing it with
        // its right child, we will replace the node we are removing
        // with the successor we just removed.

      temp = successor;
      loc->p_right = successor->p_right;
    //if (we are at root)
    if(loc == root)
    {
        //then update root
        root->name = temp->name;
    }
    else
    {
        // Insert the successor node where the target node we
        //   are removing is located
        loc->name = temp->name;
    }
    // then update the successor child pointers to reflect the old
    //     target's child pointers.
    }
    //display(root, 1);
}


/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->p_right, level+1);
        cout << endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	      }
        cout<<ptr->name;
        display(ptr->p_left, level+1);
    }
}

void BST::printSearch(node* n, string search)
{
    if (n == NULL)
        return;

    //check if file exists
    node* temp = new node;
    node* parent = temp;
    node* location = temp;
    find(search, &parent, &location);
    if (location == nullptr){
      cout << "The file " << search << " does not exist" <<endl;
      return;
    }
    /* first recur on left child */
    printSearch(n->p_left, search);
    /* then print the data of node */    
    if (n->name.substr(0, search.length()) == search)
        cout << n->name << " ";
    /* now recur on right child */
    printSearch(n->p_right, search);
}
