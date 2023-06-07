//
// Created by 15428 on 6/6/2023.
//
#include <iostream>
#include <vector>

#include <iostream>

class Range {
private:
    int start;
    int end;

public:
    Range(int start, int end) : start(start), end(end) {}

    class Iterator {
    private:
        int current;

    public:
        Iterator(int current) : current(current) {}

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        int operator*() const {
            return current;
        }

        void operator++() {
            ++current;
        }
    };

    std::vector<int> generate() const {
        std::vector<int> result;
        for (int i = start; i < end; ++i) {
            result.push_back(i);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Range& range) {
        std::vector<int> values = range.generate();
        for (int value : values) {
            os << value << " ";
        }
        return os;
    }

    Iterator begin() const {
        return Iterator(start);
    }

    Iterator ends() const {
        return Iterator(end);
    }
};

Range range(int start, int end) {
    return Range(start, end);
}
