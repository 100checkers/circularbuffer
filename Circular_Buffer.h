#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T, int cap, typename Container = std::array<T, cap> >
class CircularBuffer {
public:
	//type T will be the data type in the Container declared in the template
	using value_type = T;

	// Constructor for Circular Buffer objects
	CircularBuffer() : _head(0), _tail(0), _current(0), _size(0), _capacity(cap) {};
	//CircularBuffer() { _head = 0; _tail = 0; _current = 0; _size = 0; _capacity = cap; };

	// T& head() {};
	// T& tail() {};

	// in-line getter functions:
	// "c" is the name of the circular buffer array
	// member functions technically can access private variables
	T const& head() const { return c[_head]; };
	T const& tail() const { return c[_tail]; };

	// head, tail, current, and capacity are our iterators
	// increment current
	// override happens over oldest data

	// This function adds values to the array, also updates _size, _head, and _tail
	void push_back(T val) noexcept {
		// val is stored in _current because this is where new elements go
		c[_current] = val;

		// _tail is set equal to _current because _tail points to the newest element
		_tail = _current;

		// _current is updated to point to the next guy again by increasing it's size by 1
		_current++;

		// if current reaches capacity, we need to reset it to 0
		// this helps us achieve proper wrap-around behavior because after an element gets pushed into the last slot,
		// our current will be at index position 5 (which is outside the buffer)
		if (_current >= _capacity) {
			_current = 0;
		}

		// If the buffer is full, we need to overwrite head (the oldest data)
		// After we override head at 0, the new head is the new oldest (previously second-oldest)
		if (full()) {
			_head++;

			// if head reaches 5, we have to start over again and put head back to 0
			if (_head >= capacity()) {
				_head = 0;
			}
		}
		else // _size gets incremented after pushing new element into the array
			 // increasing size is the last thing that should happen... 
			 // because we don't want full() to be called too early
		{
			_size++;
		}
	}

	void pop() {
		if (empty()) {
			throw std::underflow_error("pop(): empty buffer");
		}
		// head needs to move to the next oldest data, so it is incremented
		_head++;
		if (_head == _capacity) {
			_head = 0;
			_size--;
		}
		// if head isn't being overridden, we still have to decrease size by 1 after popping
		else if (_size >= 1) {
			_size--;
		}
	}

	// in-line functions to get size, capacity, and current
	int size() const noexcept { return _size; }
	int capacity() noexcept { return _capacity; }
	int current() noexcept { return _current; }

	//returns true if buffer is empty
	bool empty() const noexcept {
		return _size == 0;
	}

	//returns true if buffer is full
	bool full() const noexcept {
		return _size >= _capacity;
	}

	typename Container::iterator begin() { return c.begin(); }

	typename Container::iterator end() { return c.end(); }

	// buf works similar to c
	friend std::ostream& operator<<(std::ostream& os, CircularBuffer& buf) {
		// This outputs each of our private variables that are held within a CircularBuffer object
		os << "Buffer info: head: " << buf._head << ", " << "tail: " << buf._tail << ", ";
		os << "current: " << buf._current << ", " << "capacity: " << buf._capacity << ", ";
		os << "size: " << buf._size << endl;

		// this part uses an iterator to go through each element in the array
		// dereferencing our iterator lets us output the value
		cout << " Container: ";
		for (auto it = buf.begin(); it != buf.end(); it++) {
			cout << *it << " ";
		}
		return os;
	}

	// use an stl array, has extra stuff
	// we use five member variables
private:
	Container c;	// will be std::array<T, cap>
	int _head;		//oldest item in buffer
	int _tail;		//newest item in buffer, last one pushed in
	int _size;		//# of elem in buffer, how many cells are full
	int _current;	//next write position in buffer
	int _capacity;  // the amount of elements we can store in buffer, set to 5 according to specs
};

// the guy we were just at will be set to tail
// head will be one after current
// size is a counter 
// capacity of an array, this won't for the duration of each run
#endif

