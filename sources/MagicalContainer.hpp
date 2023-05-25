#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <string>
#include "Iterators.hpp"


namespace ariel
{
    using namespace std;

    class MagicalContainer
    {
    private:
        vector<int> mysticalElements;

    public:
        MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        ~MagicalContainer();

        void push_back(int element);
        void pop_back();
        int size();
        int getElement(int index);
        void setElement(int index, int element);
        void print();
        void erase(int index);
        void clear();
    };
}
#endif // !MAGICAL_CONTAINER_HPP