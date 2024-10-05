#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>
#include <cassert>
#include <sstream>
#include <iomanip>

class Term {
public:
    std::string query;
    long weight;

    // Constructor: Initializes a term with the given query string and weight.
    Term(std::string query, long weight) {
        if (query.empty()) throw std::invalid_argument("Empty Query");
        if (weight < 0) throw std::invalid_argument("Negative Weight");

        this->query = query;
        this->weight = weight; 
    }

    // Compare two terms in lexicographic order by query (natural order).
    bool operator<(const Term& other) const {
        return query < other.query;
    }

    // Compares the two terms in descending order by weight.
    // Return a comparator that compares two terms in descending order by weight.
    static std::function<bool(const Term&, const Term&)> byReverseWeightOrder() {
        return [](const Term& a, const Term& b) -> bool {
            return a.weight > b.weight;
        };
    }

    // Returns a comparator that compares two Term objects by the first r characters 
    // of their query strings in lexicographic order (i.e., dictionary order).
    static std::function<bool(const Term&, const Term&)> byPrefixOrder(int r) {
        return [r](const Term& a, const Term& b) -> bool {
            return a.query.substr(0, r) < b.query.substr(0, r); 
        };
    }

    // Returns a string representation of the term: "weight query".
    std::string toString() const {
        std::ostringstream oss;
        oss << std::setw(10) << weight << '\t' << query; // Set width for weight
        return oss.str();
    }

    // Unit testing (required)
    static void test() {
        Term t1("apple", 100);
        Term t2("application", 300);
        Term t3("app", 700);
        Term t4("banana", 200);

        // Test natural order
        assert((t3 < t1) == true);
        assert((t2 < t1) == false);

        // Test byReverseWeightOrder
        auto reverseWeightOrder = Term::byReverseWeightOrder();
        assert(reverseWeightOrder(t1, t2) == false);
        assert(reverseWeightOrder(t2, t1) == true);

        // Test byPrefixOrder
        auto prefixOrder = Term::byPrefixOrder(3);
        assert(prefixOrder(t1, t3) == false);
        assert(prefixOrder(t3, t1) == false);

        // Test toString
        assert(t1.toString() == "       100\tapple");
        assert(t4.toString() == "       200\tbanana");

        std::cout << "Term: All tests passed!" << std::endl;
    }
};
