/*
 * C++ Program To Implement BST
 */
#include <iostream>
#include <cstdlib>
#include "BSTree.h"
//#include "printPretty.h"

using namespace std;

/*
 * Main Contains Menu
 */
int main()
{
    int choice, num;
    BST bst;
    node *temp;

  string arr[256];
  string rem[256];
  //Some random test data, use as you like

	// Get list of keys to insert
	int i = 0;
	cout << "Tree insert\n";
	do
	{
	  cin >> arr[i++];
  }	while (arr[i-1] != "NULL");
	int arrlen = i-1;

	// Get list of keys to remove
 	i = 0;
	cout << "Tree remove\n";
	do
	{
	  cin >> rem[i];
  }	while (rem[i++] != "NULL" );
	int remlen = i-1;

  cout << "Search\n";
  string search;
  cin >> search;

	// cout << "Array size: " << arrlen << endl;

			for (int i=0; i<arrlen; i++)
			{
				temp = new node;
				temp->name = arr[i];
				bst.insert(bst.root, temp);
        // cout << "STARTING "<<arrlen<< endl;
			}
			//bst.display(bst.root,1);
      for (int i=0; i<remlen; i++)
			{
				bst.remove(rem[i]);
			}

      cout << "Found: ";
      bst.printSearch(bst.root, search);
      cout << endl;
      cout<<"Display BST:"<<endl;
      bst.display(bst.root,1);
      cout << endl;

      cout<<endl;

}
