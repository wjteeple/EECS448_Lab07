/**
 * @author Will Teeple
 * @file test.cpp
 * @date 4/18/2016
 * 
 * Description: Gray Box testing for the LinkedList class. 
 */

#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

//function prototypes
bool testIsEmpty1();
bool testIsEmpty2();
bool testSize1();
bool testSize2();
bool testSearch1();
bool testSearch2();
bool testSearch3();
bool testAddBack1();
bool testAddBack2();
bool testAddBack3();
bool testAddFront1();
bool testAddFront2();
bool testAddFront3();
bool testRemoveBack1();
bool testRemoveBack2();
bool testRemoveBack3();
bool testRemoveFront1();
bool testRemoveFront2();
bool testRemoveFront3();
void runTests();

int main() 
{
    //run all tests
    runTests();
    
    return 0;
}

void runTests()
{
    cout << "\n\t\t--Test the 'isEmpty() method--" << endl << endl;
    cout << "Test 1 : Check results of isEmpty() upon initialization.\n\tResults: "
         << ((testIsEmpty1()) ? "PASS" : "FAIL") << endl;         
    cout << "Test 2 : Add and remove a single node and check result.\n\tResults: " 
         << ((testIsEmpty2()) ? "PASS" : "FAIL") << endl;
         
    cout << "\n\t\t--Test the 'size() method--" << endl << endl;
    cout << "Test 1 : Check list size right after initialization.\n\tResults: " 
         << ((testSize1()) ? "PASS" : "FAIL") << endl;
    cout << "Test 2 : Add two nodes and remove one. Check the difference in starting and ending list size.\n\tResults: "
         << ((testSize2()) ? "PASS" : "FAIL") << endl;
    
    cout << "\n\t\t--Test the 'search() method--" << endl << endl;
    cout << "Test 1 : Search an empty list.\n\tResults: "
         << ((testSearch1()) ? "PASS" : "FAIL") << endl;
    cout << "Test 2 : Search a list that does not contain the value using addFront().\n\tResults: "
         << ((testSearch2()) ? "PASS" : "FAIL") << endl;
    cout << "Test 3 : Search a list that does contain the value using addFront().\n\tResults: "
         << ((testSearch3()) ? "PASS" : "FAIL") << endl;
    
    cout << "\n\t\t--Test the 'addBack() method--" << endl << endl;
    cout << "Test 1 : Check to see if the method increments m_size properly.\n\tResults: "
         << ((testAddBack1()) ? "PASS" : "FAIL") << endl;
    cout << "Test 2 : Check to see if node was added to the back.\n\tResults: "
         << ((testAddBack2()) ? "PASS" : "FAIL") << endl;
    cout << "Test 3 : Check to see if the proper value was added to the node.\n\tResults: "
         << ((testAddBack3()) ? "PASS" : "FAIL") << endl;
    
    cout << "\n\t\t--Test the 'addFront() method--" << endl << endl;
    cout << "Test 1 : Check to see if the method increments m_size properly.\n\tResults: "
         << ((testAddFront1()) ? "PASS" : "FAIL") << endl;
    cout << "Test 2 : Check to see if node was added to the front.\n\tResults: "
         << ((testAddFront2()) ? "PASS" : "FAIL") << endl;
    cout << "Test 3 : Check to see if the proper value was added to the node.\n\tResults: "
         << ((testAddFront3()) ? "PASS" : "FAIL") << endl;
    
    cout << "\n\t\t--Test the 'removeBack() method--" << endl << endl;
    cout << "Test 1 : Check to see if the method decrements m_size properly.\n\tResults: "
         << ((testRemoveBack1()) ? "PASS" : "FAIL") << endl;
    cout << "Test 2 : Check to see if rear value is removed by adding using addBack()\n\tResults: "
         << ((testRemoveBack2()) ? "PASS" : "FAIL") << endl;
    cout << "Test 3 : Check to see if rear value is removed by adding using addFront()\n\tResults: "
         << ((testRemoveBack3()) ? "PASS" : "FAIL") << endl;
    
    cout << "\n\t\t--Test the 'removeFront() method--" << endl << endl;
    cout << "Test 1 : Check to see if the method decrements m_size properly.\n\tResults: "
         << ((testRemoveFront1()) ? "PASS" : "FAIL") << endl;
    cout << "Test 2 : Check to see if front value is removed by adding using addBack()\n\tResults: "
         << ((testRemoveFront2()) ? "PASS" : "FAIL") << endl;
    cout << "Test 3 : Check to see if front value is removed by adding using addFront()\n\tResults: "
         << ((testRemoveFront3()) ? "PASS" : "FAIL") << endl;
}

//testing functions

/**
 * @pre None
 * @post Checks the results of isEmpty() upon initialization
 * @return Returns true if the result isEmpty() is true, false otherwise
 */
bool testIsEmpty1() //check empty list
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    test = list->isEmpty();
    
    delete list;
    
    return test;
}

/**
 * @pre None
 * @post Add and remove and single node and check to see if isEmpty() result is properly returned
 * @return Returns true if the result of isEmpty() is true
 */
bool testIsEmpty2() //add and remove single node and check
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    list->addBack(5);
    list->removeBack();
    
    test = list->isEmpty();    
    
    delete list;
    
    return test;
}

/**
 * @pre None
 * @post Checks the size of the LinkedList right after initialization
 * @return Returns true if size() returns 0, false otherwise
 */
bool testSize1() //check size right after initialization
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    if (list->size() == 0)
        test = true;
    else
        test = false;    
    delete list;
    return test;
}

/**
 * @pre None
 * @post Add two nodes and remove one. Check the starting and ending size of the list
 * @return Returns true if the difference in the starting and ending size is correct, false otherwise
 */
bool testSize2() //add two, remove one, verify size
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    int start = list->size();
    
    list->addFront(5);
    list->addFront(5);
    list->removeBack();
    
    int end = list->size();
    
    if((end - start) == 1)
        test = true;
    else
        test = false;
    
    delete list;
    return test;    
}

/**
 * @pre None
 * @post Search an empty list
 * @return Returns true if the search yields false, false otherwise
 */
bool testSearch1() //search empty list
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    test = !list->search(1);
    
    delete list;
    return test;
}

/**
 * @pre None
 * @post Searches a list that does not contain the value
 * @return Returns true if the search yields false, false otherwise
 */
bool testSearch2() //search list without value
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for (int i = 0; i < 5; i++)
    {
        list->addFront(5);
    }
    
    test = !list->search(2);
    
    delete list;
    return test;
}

/**
 * @pre None
 * @post Searches a list the does contain the value
 * @return Returns true if the search yields true, false otherwise
 */
bool testSearch3() //search list with value
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for (int i = 0; i < 5; i++)
    {
        list->addFront(i);
    }
    
    test = list->search(2);
    
    delete list;
    return test;
}

/**
 * @pre None
 * @post Checks to see if the list increments m_size properly
 * @return Returns true if the size of the list properly increments, false otherwise
 */
bool testAddBack1() //check to see if list increments size properly
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    int start = list->size();
    
    list->addBack(5);
    list->addBack(5);
    
    int end = list->size();
    
    if((end - start) == 2)
        test = true;
    else
        test = false;
    
    delete list;
    return test;    
}

/**
 * @pre None
 * @post Checks to see if the node was properly added to the back (by checking value)
 * @return Returns true if the value is found at the back of the list, false otherwise
 */
bool testAddBack2() //check to see if value is added to back
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i = 0; i < 5; i++)
    {
        list->addBack(2);
    }
    
    list->addBack(5);
    
    std::vector<int> listVector = list->toVector();    
   
    if(listVector.back() == 5)
        test = true;
    else
        test = false;
    
    delete list;
    
    return test;
}

/**
 * @pre None
 * @post Checks to see if the value added to the node is correct
 * @return Returns true if the values were added to the nodes, false otherwise
 */
bool testAddBack3() //check to see if value added is correct
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    list->addBack(5);
    list->addBack(3);
    
    std::vector<int> listVector = list->toVector();
    
    if(listVector.back() == 3)
        test = true;
    else
        test = false;
    
    delete list;
    
    return test;
}

/**
 * @pre None
 * @post Checks to see if the list increments m_size properly
 * @return Returns true if the size of the list properly increments, false otherwise
 */
bool testAddFront1() //check to see if list increments size properly
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    int start = list->size();
    
    list->addFront(5);
    list->addFront(5);
    
    int end = list->size();
    
    if((end - start) == 2)
        test = true;
    else
        test = false;
    
    delete list;
    return test;    
}

/**
 * @pre None
 * @post Checks to see if the node was properly added to the front (by checking value)
 * @return Returns true if the value is found at the front of the list, false otherwise
 */
bool testAddFront2() //check to see if value is added to front
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i = 0; i < 5; i++)
    {
        list->addFront(2);
    }
    
    list->addFront(5);
    
    std::vector<int> listVector = list->toVector();
    
    if(listVector.front() == 5)
        test = true;
    else
        test = false;
    
    delete list;
    
    return test;    
    
}

/**
 * @pre None
 * @post Checks to see if the value added to the node is correct
 * @return Returns true if the values were added to the nodes, false otherwise
 */
bool testAddFront3() //check to see if value added is correct
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    list->addFront(5);
    list->addFront(3);
    
    std::vector<int> listVector = list->toVector();
    
    if(listVector.front() == 3)
        test = true;
    else
        test = false;
    
    delete list;
    
    return test;
}

/**
 * @pre None
 * @post Checks to see if the list decrements m_size properly
 * @return Returns true if the size of the list properly decrements, false otherwise
 */
bool testRemoveBack1() //check to see if list decrements size properly
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    int start = list->size();    
    
    list->addBack(5);
    list->addBack(5);
    list->removeBack();
    list->removeBack();
    
    int end = list->size();
    
    if(end == start)
        test = true;
    else
        test = false;
    
    delete list;
    return test;      
}

/**
 * @pre None
 * @post Checks to see if the node was properly removed from the back (by checking value) using addBack() 
 * @return Returns true if the value was removed from the back of the list, false otherwise
 */
bool testRemoveBack2() //check to see if rear value is removed by adding using addBack()
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i = 0; i < 5; i++)
        list->addBack(i);
    
    list->removeBack();
    std::vector <int> listVector = list->toVector();
    
    if(listVector.back() == 3)
        test = true;
    else
        test = false;
    
    return test;
}

/**
 * @pre None
 * @post Checks to see if the node was properly removed from the back (by checking value) using addFront() 
 * @return Returns true if the value was removed from the back of the list, false otherwise
 */
bool testRemoveBack3() //check to see if rear value is removed by adding using addFront()
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i = 0; i < 5; i++)
        list->addFront(i);
    
    list->removeBack();
    std::vector <int> listVector = list->toVector();
    
    if(listVector.back() == 1)
        test = true;
    else
        test = false;
    
    return test;
}

/**
 * @pre None
 * @post Checks to see if the list decrements m_size properly
 * @return Returns true if the size of the list properly decrements, false otherwise
 */
bool testRemoveFront1() //check to see if list decrements size properly
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    int start = list->size();    
    
    list->addFront(5);
    list->addFront(5);
    list->removeFront();
    list->removeFront();
    
    int end = list->size();
    
    if(end == start)
        test = true;
    else
        test = false;
    
    delete list;
    return test;  
}

/**
 * @pre None
 * @post Checks to see if the node was properly removed from the front (by checking value) using addFront() 
 * @return Returns true if the value was removed from the front of the list, false otherwise
 */
bool testRemoveFront2() //check to see if rear value is removed by adding using addFront()
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i = 0; i < 5; i++)
        list->addFront(i);
    
    list->removeFront();
    std::vector <int> listVector = list->toVector();
    
    if(listVector.front() == 3)
        test = true;
    else
        test = false;
    
    return test;
    return false;
}

/**
 * @pre None
 * @post Checks to see if the node was properly removed from the front (by checking value) using addBack() 
 * @return Returns true if the value was removed from the front of the list, false otherwise
 */
bool testRemoveFront3() //check to see if rear value is removed by adding using addBack()
{
    bool test = false;
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i = 0; i < 5; i++)
        list->addBack(i);
    
    list->removeFront();
    std::vector <int> listVector = list->toVector();
    
    if(listVector.front() == 1)
        test = true;
    else
        test = false;
    
    return test;
    return false;
}