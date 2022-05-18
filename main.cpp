#include<iostream>

#include"Node.h"
#include"LinkedList.h"

int main()
{
	int nums[100];
	int args[2];
	std::string func;

	int i=0;
	while(!std::cin.fail()) 
	{
        int input;
        std::cin >> input;
        nums[i] = input;
        i++;
    }
    i--;
    std::cin.clear();

    std::cin >> func;

    std::cin.clear();

    for(int k=0;k<2;k++)
    {
    	if(std::cin.fail()) break;
    	int input;
    	std::cin >> input;
    	args[k] = input;
    }

    int newNums[i];

    for(int j=0;j<i;j++)
    {
    	newNums[j] = nums[j];
    }

    LinkedList linkedList = LinkedList(newNums, i);

    if(func=="AF")
    {
    	linkedList.addFront(args[0]);
    }

    if(func=="AE")
    {
    	linkedList.addEnd(args[0]);
    }

    if(func=="AP")
    {
    	linkedList.addAtPosition(args[0], args[1]);
    }

    if(func=="S")
    {
    	linkedList.search(args[0]);
    }

    if(func=="DF")
    {
    	linkedList.deleteFront();
    }

    if(func=="DE")
    {
    	linkedList.deleteEnd();
    }

    if(func=="DP")
    {
    	linkedList.deletePosition(args[0]);
    }

    if(func=="GI")
    {
    	linkedList.getItem(args[0]);
    }

    linkedList.printItems();
   	
}