#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP
#include <iostream>
using namespace std;
#include <vector>

namespace ariel
{
    class MagicalContainer
    {
        class Iterator
        {
        public:
            int* currElement;
            virtual ~Iterator() = default;
            virtual int &operator*() = 0;
            virtual Iterator &operator++() = 0;
        };

        vector<int> elements;
        vector<Iterator*> iterators; 
    public:
        MagicalContainer();
        ~MagicalContainer();
        bool addElement(int element);
        bool removeElement(int element);
        int size() const;

        class AscendingIterator : public Iterator
        {
        private:
            MagicalContainer *container;
            vector<int> sortedElements;
            int *currElement;

        public:
            AscendingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int &operator*() override;
            AscendingIterator &operator++() override;

            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator : public Iterator
        {
        private:
            vector<int> sortedElements;
            MagicalContainer *container;
            int *currElement;

        public:
            SideCrossIterator();
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int &operator*() override;
            SideCrossIterator &operator++() override;
            
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator : public Iterator
        {
        private:
            vector<int> sortedElements;
            MagicalContainer *container;
            int *currElement;

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int &operator*() override;
            PrimeIterator &operator++() override;

            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}
#endif