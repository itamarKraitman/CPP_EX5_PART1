#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel
{
    MagicalContainer::MagicalContainer()
    {
        elements = vector<int>();
        iterators = vector<Iterator *>();
    }

    MagicalContainer::~MagicalContainer()
    {
    }

    bool MagicalContainer::addElement(int newElement)
    {
        elements.push_back(newElement);
        return true;
    }

    bool MagicalContainer::removeElement(int element)
    {
        for (auto currElement : elements)
        {
            if (currElement == element)
            {
                elements.erase(std::find(elements.begin(), elements.end(), element));
                return true;
            }
        }
        return false;
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    MagicalContainer::AscendingIterator::AscendingIterator() {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(&container), sortedElements(container.elements)
    {
        this->currElement = &sortedElements[0];
        container.iterators.push_back(this);
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), sortedElements(other.sortedElements), currElement(other.currElement)
    {
        other.container->iterators.push_back(this);
    }

    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        sortedElements = other.sortedElements;
        container = other.container;
        return *this;
    }

    int &MagicalContainer::AscendingIterator::operator*()
    {
        return *currElement;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        ++currElement;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return false;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator();
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return AscendingIterator();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    {
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        return *this;
    }

    int &MagicalContainer::SideCrossIterator::operator*()
    {
        return *currElement;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return false;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator();
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return SideCrossIterator();
    }

    MagicalContainer::PrimeIterator::PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    {
    }

    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        return *this;
    }

    int &MagicalContainer::PrimeIterator::operator*()
    {
        return *currElement;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return false;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return PrimeIterator();
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator();
    }
}