#include "doctest.h"

#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_SUITE("Testing MagicalContainer")
{
    TEST_CASE("Test adding elements")
    {
        MagicalContainer container;
        CHECK(container.addElement(5));
        CHECK(container.addElement(10));
        CHECK(container.addElement(5));
        CHECK(container.addElement(-3));
        CHECK(container.addElement(0));
    }

    TEST_CASE("Test getting elements")
    {
        MagicalContainer container;

        CHECK_THROWS_AS(container.getElements(), std::runtime_error);

        container.addElement(5);
        container.addElement(10);
        container.addElement(5);
        container.addElement(-3);
        container.addElement(0);

        std::vector<int> elements = container.getElements();
        CHECK(elements.size() == 5);
        CHECK(elements[0] == 5);
        CHECK(elements[1] == 10);
        CHECK(elements[2] == 5);
        CHECK(elements[3] == -3);
        CHECK(elements[4] == 0);

        CHECK_THROWS_AS(elements[5], std::out_of_range);
    }

    TEST_CASE("Test removing elements")
    {
        MagicalContainer container;

        SUBCASE("Empty Container")
        {
            CHECK_THROWS_AS(container.removeElement(8), std::invalid_argument);
        }
        container.addElement(5);
        container.addElement(10);
        container.addElement(5);
        container.addElement(-3);
        container.addElement(0);

        CHECK_FALSE(container.removeElement(7));

        CHECK(container.removeElement(5));
        CHECK(container.removeElement(-3));
        CHECK(container.removeElement(10));
        CHECK(container.removeElement(5));
        CHECK(container.removeElement(0));

        CHECK(container.elements.empty());
    }

    TEST_CASE("Test size")
    {
        MagicalContainer container;
        container.addElement(5);
        container.addElement(10);
        container.addElement(5);
        container.addElement(-3);
        container.addElement(0);

        CHECK(container.size() == 5);
    }
}

TEST_SUITE("Iterators")
{

    TEST_CASE("AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::AscendingIterator ascIter = container.getAscendingIterator();

        SUBCASE("Iterating over elements")
        {
            std::vector<int> expected = {1, 2, 4, 5, 14};
            std::vector<int> actual;

            for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
            {
                actual.push_back(*it);
            }

            CHECK_EQ(actual, expected);
        }

        SUBCASE("Copy constructor")
        {
            MagicalContainer::AscendingIterator other(ascIter);
            CHECK(other.begin() == ascIter.begin());
            CHECK(other.begin() + 1 == ascIter.begin() + 1);
            CHECK(other.begin() + 2 == ascIter.begin() + 2);
            CHECK(other.begin() + 3 == ascIter.begin() + 3);
            CHECK(other.end() == ascIter.end());

            // nullptr
            MagicalContainer::AscendingIterator nullIter;
            CHECK_THROWS_AS(MagicalContainer::AscendingIterator other2(nullIter), std::nullptr_t);
        }

        SUBCASE("> operator")
        {
            CHECK(ascIter.begin() + 3 > ascIter.begin() + 1);
            CHECK(ascIter.begin() + 4 > ascIter.begin());
            CHECK_FALSE(ascIter.begin() > ascIter.begin() + 1);
        }

        SUBCASE("< operator")
        {
            CHECK(ascIter.begin() + 1 > ascIter.begin() + 3);
            CHECK(ascIter.begin() > ascIter.begin() + 4);
            CHECK_FALSE(ascIter.begin() + 1 > ascIter.begin());
        }

        SUBCASE("=, ==, and != operators")
        {
            MagicalContainer::AscendingIterator otherAscIter = MagicalContainer::AscendingIterator(container);

            CHECK_NOTHROW(otherAscIter = ascIter);

            // self assignmnet
            CHECK_THROWS_AS(ascIter = ascIter, std::runtime_error);

            // ==
            CHECK(otherAscIter == ascIter);

            // !=
            CHECK_FALSE(otherAscIter != ascIter);
        }
    }

    TEST_CASE("SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        MagicalContainer::SideCrossIterator scIter = container.getSideCrossIterator();

        SUBCASE("Iterating over elements")
        {
            std::vector<int> expected = {1, 14, 2, 5, 4};
            std::vector<int> actual;

            for (auto it = scIter.begin(); it != scIter.end(); ++it)
            {
                actual.push_back(*it);
            }

            CHECK_EQ(actual, expected);
        }

        SUBCASE("Copy constructor")
        {
            MagicalContainer::SideCrossIterator other(scIter);
            CHECK(other.begin() == scIter.begin());
            CHECK(other.begin() + 1 == scIter.begin() + 1);
            CHECK(other.begin() + 2 == scIter.begin() + 2);
            CHECK(other.begin() + 3 == scIter.begin() + 3);
            CHECK(other.end() == scIter.end());

            // nullptr
            MagicalContainer::SideCrossIterator nullIter;
            CHECK_THROWS_AS(MagicalContainer::SideCrossIterator other2(nullIter), std::nullptr_t);

            SUBCASE("> operator")
            {
                CHECK(scIter.begin() + 3 > scIter.begin() + 1);
                CHECK(scIter.begin() + 2 > scIter.begin());
                CHECK(scIter.begin() + 4 > scIter.begin() + 1);
                CHECK_FALSE(scIter.begin() > scIter.begin() + 1);
            }

            SUBCASE("< operator")
            {
                CHECK(scIter.begin() + 1 > scIter.begin() + 3);
                CHECK(scIter.begin() > scIter.begin() + 2);
                CHECK(scIter.begin() + 1 > scIter.begin() + 4);
                CHECK_FALSE(scIter.begin() + 1 > scIter.begin());
            }

            SUBCASE("=, ==, and != operators")
            {
                MagicalContainer::SideCrossIterator otherScIter = MagicalContainer::SideCrossIterator(container);

                CHECK_NOTHROW(otherScIter = scIter);

                // self assignmnet
                CHECK_THROWS_AS(scIter = scIter, std::runtime_error);

                // ==
                CHECK(otherScIter == scIter);

                // !=
                CHECK_FALSE(otherScIter != scIter);
            }
        }
    }

    TEST_CASE("PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(10);
        container.addElement(5);
        container.addElement(15);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::PrimeIterator primeIter = container.getPrimeIterator();

        SUBCASE("Iterating over elements")
        {
            std::vector<int> expected = {2, 5, 7};
            std::vector<int> actual;

            for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
            {
                actual.push_back(*it);
            }

            CHECK_EQ(actual, expected);
        }

         SUBCASE("Copy constructor")
        {
            MagicalContainer::PrimeIterator other(primeIter);
            CHECK(other.begin() == primeIter.begin());
            CHECK(other.begin() + 1 == primeIter.begin() + 1);  
            CHECK(other.begin() + 2 == primeIter.begin() + 2);  
            CHECK(other.begin() + 3 == primeIter.begin() + 3);  
            CHECK(other.end() == primeIter.end());

            // nullptr
            MagicalContainer::PrimeIterator nullIter;
            CHECK_THROWS_AS(MagicalContainer::PrimeIterator other2(nullIter), std::nullptr_t);
        }

        SUBCASE("> operator")
        {
            CHECK(primeIter.begin() + 1 > primeIter.begin());
            CHECK_FALSE(primeIter.begin() > primeIter.begin() + 1);
        }

        SUBCASE("< operator")
        {
            CHECK(primeIter.begin() > primeIter.begin() + 1);
            CHECK_FALSE(primeIter.begin() + 1 > primeIter.begin());
        }

        SUBCASE("=, ==, and != operators")
        {
            MagicalContainer::PrimeIterator otherPrimeIter = MagicalContainer::PrimeIterator(container);

            CHECK_NOTHROW(otherPrimeIter = primeIter);

            // self assignmnet
            CHECK_THROWS_AS(primeIter = primeIter, std::runtime_error);

            // ==
            CHECK(otherPrimeIter == primeIter);

            // !=
            CHECK_FALSE(otherPrimeIter != primeIter);
        }
    }
}
