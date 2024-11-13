#pragma once

#include <map>

class Svector {
private:
    std::map<int, double> m_elements;

public:
    Svector() = default;

    void set(const int i, const double x) {
        if (x != 0.0) m_elements[i] = x;
        else m_elements.erase(i);
    };

    double get(const int i) const {
        if (m_elements.contains(i)) return m_elements.at(i);
        else return 0.0;
    }

    double dot(const Svector& that) const {
        double result = 0.0;
        for (const auto& [index, value] : m_elements)
            result += value * that.get(index);
        return result;
    }

    double norm() const {
        double sum = 0.0;
        for (const auto& [index, value] : m_elements)
            sum += value * value;
        return sum;
    }

    Svector add(const Svector& that) const {
        Svector result;
        for (const auto& [index, value] : m_elements) 
            result.set(index, value + that.get(index));
        
        for (const auto& [index, value] : that.m_elements) 
            if (!m_elements.contains(index)) 
                result.set(index, value);
        
        return result;
    }

    void scale(double alpha) {
        for (auto& [index, value] : m_elements)
            value += alpha;
    }
};