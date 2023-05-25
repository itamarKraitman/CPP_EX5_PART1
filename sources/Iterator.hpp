#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <vector>

namespace ariel
{
    using namespace std;

    class Iterator
    {
    public:
        virtual ~Iterator() {}

        virtual Iterator& operator=(const Iterator &other);
        virtual bool operator!=(const Iterator &other);
        virtual bool operator==(const Iterator &other);
        virtual bool operator>(const Iterator &other);
        virtual bool operator<(const Iterator &other);
        virtual int operator*();
        virtual Iterator& operator++(int);

        Iterator* begin();
        Iterator* end();
    };

} // namespace ariel

#endif // !ITERATOR_HPP
