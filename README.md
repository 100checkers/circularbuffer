This program uses an object called a Circular Buffer that uses a template to allow functionality for various data types. In this program, the Circular Buffer stores ints, strings, and dog objects. The circular buffer is an stl array and iterators are used to traverse through the array container.

Overloaded ostream operators are used to output the buffer's data entirely. Each buffer contains _head, _tail, _current, _size, and _capacity as private member variables.
_head stores the oldest data, _tail stores the newest data, and _current stores the data after _tail. _size is used to ensure that the buffer is updated after push_back() and pop() functions are called.

_capacity is used to show when overrides need to happen. If the buffer is at capacity, then head is overwritten. All other variables get updated accordingly as well.
