#ifndef ASCENDING_ITERATOR_HPP
#define ASCENDING_ITERATOR

#include <vector>
#include "Itrator.hpp"

namespace ariel
{
    using namespace std;

    class AscendingIterator : public iterator
    {
    private:
        std::vector<int>::iterator current;
        std::vector<int>::iterator end;

    public:
        AscendingIterator();

        Iterator operator=(const Iterator &other);
        Iterator operator!=(const Iterator &other);
        Iterator operator==(const Iterator &other);
        Iterator operator>(const Iterator &other);
        Ite operator<(const Iterator &other);
        Iterator operator*();
        Iterator operator++(int);

        Iterator& *begin();
        Iterator& *end();
    }
}

#endif // !ASCENDING_ITERATOR_HPP