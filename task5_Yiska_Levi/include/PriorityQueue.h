#pragma once

#include <iostream>
#include <list>
#include <exception>



template<typename T>
class PriorityQueue {
public:

    void push(const T& t) {
        typename std::list<T>::iterator it = data.begin();
        while (it != data.end() && MyComparator<T>()(*it, t)) {
            ++it;
        }
        data.insert(it, t);
    }

    T poll() {
        if (data.empty()) {
            throw std::runtime_error("PriorityQueue is empty!");
        }
        T front = data.front();
        data.pop_front();
        return front;
    }

private:
    std::list<T> data;
};

template<typename T>
struct MyComparator {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};
