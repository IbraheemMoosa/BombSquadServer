/*
 * C++ Program To Implement BST
 */
#include <iostream>
#include <cstdlib>
#include "BSTree.h"
//#include "printPretty.h"

using namespace std;

//Simple hashing method to convert a string to a number
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

<<<<<<< HEAD:main.cpp
  string arr[256];
  string rem[256];
=======
  int arr[256];
  int rem[256];
  //Some random test data, use as you like
  //int arr[] = {41, 70, 16, 68, 12, 20, 45, 100, 25, 48, 80, 21, 80, 50, 48, 72, 10, 2, 89, 93, 98, 98, 38, 11, 65, 79, 38, 40, 21, 66, 36, 2, 2, 80, 75, 13, 55, 59, 75, 23, 77, 50, 3, 28, 61, 84, 15, 78, 100, 81, 77, 58, 60, 64, 47, 94, 7, 41, 34, 18, 6, 21, 90, 37, 87, 96, 12, 10, 39, 60, 7, 17, 41, 70, 16, 68, 12, 20, 45, 100, 25, 48, 80, 10, 26, 11, 56, 80, 79, 29, 42, 69, 25, 26, 96, 52, 13, 66, 3, 92, 45, 52 };
>>>>>>> 884eb0e6426704c1b4be8afe2f41bd77f4dfe2e5:main.cpp

	// Get list of keys to insert
  string name;
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
<<<<<<< HEAD:main.cpp
        temp->name = arr[i];
				temp->priority = getID(arr[i]);
=======
				temp->key_value = arr[i];
>>>>>>> 884eb0e6426704c1b4be8afe2f41bd77f4dfe2e5:main.cpp
				bst.insert(bst.root, temp);
        cout << "STARTING "<<arrlen<< endl;
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
