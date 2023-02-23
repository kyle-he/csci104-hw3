#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T &item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const &top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  std::vector<T> data;

private:
  /// Add whatever helper functions and data members you need below
  PComparator comparator;

  size_t heap_size;
  size_t num_children;
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  heap_size = 0;
  num_children = m;
  comparator = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap_size;
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap_size == 0;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item)
{
  heap_size++;

  data.push_back(item);
  std::size_t index = data.size() - 1;
  while (index != 0)
  {
    std::size_t parent_index = (index - 1) / num_children;
    T &current = data[index];
    T &parent = data[parent_index];
    if (!comparator(current, parent))
    {
      break;
    }
    std::swap(current, parent);
    index = parent_index;
  }
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    throw std::out_of_range("heap is empty");
  }
  return data[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    throw std::out_of_range("heap is empty");
  }

  heap_size--;

  std::swap(data[0], data[data.size() - 1]);
  data.pop_back();

  std::size_t index = 0;
  while (index < data.size())
  {
    std::size_t smallest_child_index = num_children * index + 1;

    if (smallest_child_index >= data.size()) {
      break;
    }

    T smallest_child = data[smallest_child_index];

    for (std::size_t i = num_children * index + 1; i <= (num_children * index + 1 + num_children); i++)
    {
      if (i >= data.size()) {
        break;
      }

      if (comparator(data[i], smallest_child))
      {
        smallest_child = data[i];
        smallest_child_index = i;
      }
    }

    T &current = data[index];
    T &child = data[smallest_child_index];

    if (comparator(child, current))
    {
      std::swap(current, child);
      index = smallest_child_index;
    }
    else
    {
      break;
    }
  }
}

#endif
