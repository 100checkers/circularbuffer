/*
This program uses an object called a Circular Buffer that uses a template to allow functionality for various data types
In this program, the Circular Buffer stores ints, strings, and dog objects
The circular buffer is an stl array and iterators are used to traverse through the array container
*
*
Overloaded ostream operators are used to output the buffer's data entirely
Each buffer contains _head, _tail, _current, _size, and _capacity as private member variables
_head stores the oldest data, _tail stores the newest data, and _current stores the data after _tail
_size is used to ensure that the buffer is updated after push_back() and pop() functions are called
*
*
_capacity is used to show when overrides need to happen. If the buffer is at capacity, then head is overwritten
All other variables get updated accordingly as well
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n\n\n";

    // creating a circular buffer object that holds five ints
    CircularBuffer<int, 5> buffInt;

    cout << "Initial state" << endl;
    cout << buffInt << endl;

    cout << "\nPushing 0" << endl;
    buffInt.push_back(0);
    cout << buffInt << endl;

    cout << "\nPushing 10" << endl;
    buffInt.push_back(10);
    cout << buffInt << endl;

    cout << "\nPushing 20" << endl;
    buffInt.push_back(20);
    cout << buffInt << endl;

    cout << "\nPushing 30" << endl;
    buffInt.push_back(30);
    cout << buffInt << endl;

    cout << "\nPushing 40" << endl;
    buffInt.push_back(40);
    cout << buffInt << endl;

    cout << "\nPushing 50" << endl;
    buffInt.push_back(50);
    cout << buffInt << endl;

    cout << "\nPushing 60" << endl;
    buffInt.push_back(60);
    cout << buffInt << endl;

    cout << "\nPushing 70" << endl;
    buffInt.push_back(70);
    cout << buffInt << endl;

    cout << "\nPopping 30" << endl;
    buffInt.pop();
    cout << buffInt << endl;

    cout << "\nPopping 40" << endl;
    buffInt.pop();
    cout << buffInt << endl;

    cout << "\nPopping 50" << endl;
    buffInt.pop();
    cout << buffInt << endl;

    cout << "\nPopping 60" << endl;
    buffInt.pop();
    cout << buffInt << endl;

    cout << "\nPopping 70" << endl;
    buffInt.pop();
    cout << buffInt << endl;




    cout << "\n\n*************** <string> Circular Buffer Demo ******************\n\n\n";

    // creating a circular buffer object that holds five strings
    CircularBuffer<string, 5> buffString;
    cout << "Initial state" << endl;
    cout << buffString << endl;
    cout << endl;

    vector<string> words{ "this", "is", "the", "wonderful", "world", "of", "oz" };

    copy(words.begin(), words.end(), back_inserter(buffString));

    cout << "After using back_inserter_iterator" << endl;
    cout << buffString;
    cout << endl;

    cout << "\nPopping: the" << endl;
    buffString.pop();
    cout << buffString << endl;

    cout << "\nPopping: wonderful " << endl;
    buffString.pop();
    cout << buffString << endl;

    cout << "\nPopping: world" << endl;
    buffString.pop();
    cout << buffString << endl;

    cout << "\nPopping: of" << endl;
    buffString.pop();
    cout << buffString << endl;

    cout << "\nPopping: oz" << endl;
    buffString.pop();
    cout << buffString << endl;

    cout << "\n\n*************** <Dog> Circular Buffer Demo ******************\n\n\n";

    // Creating dog objects to put into the circular buffer
    dog dog1("Guinness", "Wheaton", 9);
    dog dog2("Grimlock", "Lab", 2);
    dog dog3("Optimus", "Bulldog", 5);
    dog dog4("Murphy", "Lab", 14);
    dog dog5("Floyd", "Beagle", 12);
    dog dog6("Snoopy", "Beagle", 100);
    dog dog7("Archie", "Brittany", 1);
    dog dog8("Penny", "Beagle", 2);

    // creating a circular buffer object that holds five dog objects
    CircularBuffer<dog, 5> buffDog;

    buffDog.push_back(dog1);
    buffDog.push_back(dog2);
    buffDog.push_back(dog3);
    buffDog.push_back(dog4);
    buffDog.push_back(dog5);
    cout << buffDog << endl;

    // This if statement checks if the circular buffer is full
    cout << "\ndogs Full?:";
    if (buffDog.full()) {
        cout << "true" << endl;
    }
    cout << endl;

    buffDog.push_back(dog6);
    cout << buffDog << endl;
    cout << endl;

    buffDog.push_back(dog7);
    cout << buffDog << endl;
    cout << endl;

    buffDog.push_back(dog8);
    cout << buffDog << endl;

    cout << "\nPopping" << endl;
    cout << "   Murphy, Lab, 14\n" << endl;
    buffDog.pop();
    cout << buffDog << endl;

    cout << "\nPopping" << endl;
    cout << "   Floyd, Beagle, 12\n" << endl;
    buffDog.pop();
    cout << buffDog << endl;

    cout << "\nPopping" << endl;
    cout << "   Snoopy, Beagle, 100\n" << endl;
    buffDog.pop();
    cout << buffDog << endl;

    cout << "\nPopping" << endl;
    cout << "   Archie, Brittany, 1\n" << endl;
    buffDog.pop();
    cout << buffDog << endl;

    cout << "\nPopping" << endl;
    cout << "   Penny, Beagle, 1\n" << endl;
    buffDog.pop();
    cout << buffDog << endl;
}

