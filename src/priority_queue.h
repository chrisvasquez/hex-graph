#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


//
//
//
//
//
//  Requirements:
//    1)  std::less<T> for the queue element or type T
template <class T,
          class Container = std::vector<T>,
          class Compare = std::less<typename Container::value_type> >
class PriorityQueue
{
public:
    //  Default constructor
    PriorityQueue();
    PriorityQueue(Compare priority_comparator): priority_comparator(priority_comparator) {};
    //  Constructor from input iterator
    template <class InputIterator>
    PriorityQueue(InputIterator first,
                  InputIterator last,
                  const Compare& priority_comparator = Compare()) : data(first, last), priority_comparator(priority_comparator) {
      //  There is a choice between priority_comparitor vs std::less<T>
      //  priority_comparator is optimized for top() and pop()
      //  and std::less<T> is optimized for insert() operation
      std::sort(begin(), end(), priority_comparator);
    }

    // Changes the priority (vertex value) of queue element.
    void ChangePriority(const T& queue_element, double priority) {
      //  Find the queue element in the data container
      auto it = find(queue_element);
      //  Set the priority of the found queue element to the target priority value
      it->set_value(priority);
      // if (priority_change_handler) {
      //     priority_change_handler(queue_element, priority);
      //   }
    }
    //  Insert the queue_element in the data priority_queue
    void insert(const T queue_element) {
      //  Sort the data container to prepare for std::lower_bound
      std::sort(begin(), end(), std::less<T>());
      //  Get the insertion point for the new element
      //  Returns an iterator that points to an element that is equal of greated than the element
      iterator i = std::lower_bound(begin(), end(), queue_element, std::less<T>());
      //  Inserts the new queue_element only if it is not found in data (i == end()) or the element is
      //  less than ( essentially, not equal, to the pointer element of iterator `i`
      if (i == end() || std::less<T>()(queue_element, *i)) {
          data.insert(i, queue_element);
      }
    }
    //  Return the top element of the queue with out removing it
    T top() {
      //  Sort the elements of the queue based on the priority comparison function
      //  priority_comparator should check priority or value
      std::sort(begin(), end(), priority_comparator);
      // Return the one with the highest priority
      return *(begin());
    }
    //  Erase the top element in the queue
    void pop() {
      // Erase the first most queue element if the vector is not empty
      if (data.size() != 0) {
          data.erase(begin());
        }
    }
    //  Returns whether the queue contain `queue_element`.
    bool contains(const T& queue_element) {
     return find(queue_element) != end();
    }
    //  Returns an iterator to a queue_element of the end() iterator if not found
    typename Container::iterator find(const T& queue_element) {
      std::sort(begin(), end(), std::less<T>());
      iterator i = std::lower_bound(begin(), end(), queue_element, std::less<T>());
      // typename Container::iterator i = std::lower_bound(data.begin(), data.end(), queue_element, std::less<T>());
      return (i == end() || std::less<T>()(queue_element, *i)) ? end() : i;
    }
    // Return the number of queue_elements.
    std::size_t size() const {
      return data.size();
    }
private:
    //  Main Data ADT
    Container data;
    //  Function
    Compare priority_comparator;

    // Convenience types and methods for iterators to the data of the priority queue
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    iterator begin() { return data.begin(); }
    iterator end() { return data.end(); }
    const_iterator begin() const { return data.begin(); }
    const_iterator end() const { return data.end(); }
};

#endif // PRIORITY_QUEUE_H
