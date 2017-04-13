/*
	Layne Earnheart & Adam Rucker
	4/13/2017
	Lab 12/ Minimum height binary search tree
*/	
#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int numItems = cds->size();
   cout << numItems << endl;
   cout << endl;

   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->getKey()->displayString();
	  cout<<endl;
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)
   cout<<"The height of the binary search tree (not minimum height is) ::"<<bst->getHeight()<<endl;
   bool balanced = bst->isBalanced();
   if(balanced)
	cout<<"The binary search tree is balanced."<<endl;
	else
		cout<<"The binary search tree is not balanced" <<endl;








   //create a minimum height binary search tree
//   cout<<"Made it to the minimum height tree"<<endl;
   BinarySearchTree<CD>* min_bst = bst->minimize();
   bst_iter = min_bst->iterator();

   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->getKey()->displayString();
	  cout<<endl;
   }
   delete bst_iter;

   cout<<"Made it through the minimum height tree"<<endl;
   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	cout<<"The height of the minimum binary tree is ::"<<min_bst->getHeight()<<endl;
	balanced = min_bst->isBalanced();
	if(balanced)
		cout<<"The minimum height binary search tree is balanced"<<endl;
	else
		cout<<"The minimum height binary search tree is not balanced"<<endl;







   //create a complete binary search tree
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
   delete bst;
	delete min_bst;
   //make sure that an inorder traversal gives sorted order
   bst_iter = complete_bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->getKey()->displayString();
	  cout<<endl;
   }
   delete bst_iter;

   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)
   cout<<"The height of the complete binary search tree is ::"<<complete_bst->getHeight()<<endl;
   
   balanced = complete_bst->isBalanced();
   if(balanced)
	   cout<<"The complete binary search tree is balanced"<<endl;
   else
	   cout<<"The complete binary search tree is not balanced" <<endl;









   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
