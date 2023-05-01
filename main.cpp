#include "Set.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Set ss;
    Set ss1;
    Set ss2;
  

    assert(ss.insert("roti"));
    assert(ss.insert("pita"));
    assert(ss.insert("pit"));
    assert(ss.insert("pi"));

    assert(ss1.insert("hi"));
    assert(ss1.insert("pita"));
    assert(ss1.insert("pit"));
    assert(ss1.insert("hello"));

    assert(ss1.insert("clyde"));
    assert(!ss1.insert("clyde")); //checks for duplicate; it will return false
    assert(ss1.insert("pranav")); 
    assert(ss1.insert("max"));
    assert(ss1.insert("lucy"));
    assert(ss1.insert("evan"));
    assert(ss1.insert("juni"));
    assert(ss1.size() == 10); //i inserted 10 things in ss1 insert, so this return true
    assert(ss1.erase("juni"));
    assert(!ss1.erase("juni")); //this should return false because i have already erased juni
    assert(ss1.erase("clyde"));
    assert(ss1.erase("pranav"));
    assert(ss1.size() != 10); //this should return false because size is no longer 10.
    assert(ss1.size() == 7); //i deleted 7 things in ss1 insert, so this return true
    assert(ss1.contains("max")); //contains max
    assert(!ss1.contains("juni")); //will return false because juni has been deleted
    //at this point the list of s1:
    //pita pit max lucy hi hello evan
    ItemType x = "cris";
    assert(ss1.get(5, x) && x == "hello"); //this should return true because cris is less than hello and is less than 5 elements in the set
    assert(ss1.get(6, x) && x == "evan"); //this should return true bcause cris is less than evan and is less than 6 elements in the set
    assert(!(ss1.get(2, x) && x == "hi")); //this returns false because cris is not less than max, however it is not less than 2 elements in the set
    (ss1.swap(ss)); //complete swap, so ss1 now have roti pita pit hello
    assert(!(ss1.get(5, x) && x == "hello")); //this should return false because it now has been swapped with ss
    assert(ss1.get(2, x) && x == "pit"); //this correctly uses the get function on the correctly swapped ss1 elements
   // unite(ss, ss1, ss2);
    //assert(ss2.size() == 9); //returns true because all of ss and ss1 is included in ss2 but not duplicates
    butNot(ss, ss, ss);
    //assert(ss2.size() == 5); 
    //ss: roti, pita, pit, pi
    //ss1: hi, pita, pit, hello
    
    //butNot(ss1, ss, ss1); //b,a,b
    ss2.dump();
    //cout << endl;
  


}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}