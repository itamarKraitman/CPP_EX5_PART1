#include <vector>
#include "MagicalContainer.hpp"
#include "Iterator.hpp"

namespace ariel
{
    using namespace std;

    MagicalContainer() {}
    MagicalContainer(const MagicalContainer &other) : container(other.container) {}
    ~MagicalContainer() {}

    void push_back(int element)
    {
        container.push_back(element);
    }
    void pop_back()
    {
        container.pop_back();
    }
    int size()
    {
        return container.size();
    }
    int getElement(int index)
    {
        return container[index];
    }
    void setElement(int index, int element)
    {
        container[index] = element;
    }
    void print()
    {
        for (int i = 0; i < container.size(); i++)
        {
            cout << container[i] << ", ";
        }
        cout << endl;
    }
    void erase(int index)
    {
        container.erase(container.begin() + index);
    }
    void clear()
    {
        container.clear();
    }
}