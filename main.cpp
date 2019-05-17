/*
 * C++ Program To Implement BST
 */
#include <iostream>
#include <cstdlib>
#include "BSTree.h"
//#include "printPretty.h"

using namespace std;

//Simple hashing method to convert a string to a unique number
int getID(string name){
  int id = 0;
  for(char a: name){
    id+=(int)a;
  }
  return id;
}

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


	cout << "Array size: " << arrlen << endl;

			for (int i=0; i<arrlen; i++)
			{
				temp = new node;
       				temp->name = arr[i];
				temp->priority = getID(arr[i]);
				bst.insert(bst.root, temp);
			}
			//bst.display(bst.root,1);
     			for (int i=0; i<remlen; i++)
			{
				bst.remove(getID(rem[i]));
			}
      cout<<"Display BST:"<<endl;
      bst.display(bst.root,1);

      cout<<endl;

}
