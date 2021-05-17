#pragma once
#include <sstream>
#include <iostream>
#include <vector>

template<class Iterator, class Predicate>
bool allOf(Iterator first, Iterator last, Predicate predicate) {
    while (first != last) {
        if (!predicate(*first)) return false;
        ++first;
    }
    return true;
}

template<class Iterator, class Predicate>
bool anyOf(Iterator first, Iterator last, Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) return true;
        ++first;
    }
    return false;
}

template<class Iterator, class Predicate>
bool noneOf(Iterator first, Iterator last, Predicate predicate) {
    while (first != last) {
        if (predicate(*first)) return false;
        ++first;
    }
    return true;
}


template<class Iterator, class Predicate>
bool oneOf(Iterator first, Iterator last, Predicate predicate) {
    int count = 0;
    while (first != last) {
        if (predicate(*first)) {
            count++;
            if (count > 1) return false;
        }
        ++first;
    }
    return true;
}

template<class Iterator>
bool isSorted(Iterator first, Iterator last) {
    if (first != last) {
        Iterator next = first;
        while (++next != last) {
            if (*next < *first) return false;
            first = next;
        }
    }
    return true;
}

template<class Iterator, class Compare>
bool isSorted(Iterator first, Iterator last, Compare comp) {
    if (first != last) {
        Iterator next = first;
        while (++next != last) {
            if (!comp(*next, *first)) return false;
            first = next;
        }
    }
    return true;
}


template<class Iterator, class Predicate>
bool isPartitioned(Iterator first, Iterator last, Predicate predicate) {
    bool flag = false;
    while (first != last && predicate(*first)) {
        flag = true;
        ++first;
    }
    while (first != last) {
        if (flag and predicate(*first)) return false;

        ++first;
    }
    return true;
}

template<class Iterator, class T>
Iterator findNot(Iterator first, Iterator last, const T &value) {
    while (first != last) {
        if (*first != value) return first;
        ++first;
    }
    return first;
}


template<class Iterator, class T>
Iterator findBackward(Iterator first, Iterator last, const T &value) {
    Iterator temp = last;
    while (first != last) {
        if (*first == value) temp = first;
        ++first;
    }
    return temp;
}


template<class Iterator, class Compare>
bool isPalindrome(Iterator first, Iterator last, Compare comp) {

    while (last != first) {
        if (!comp(*first, *last)) return false;
        ++first;
        if (first == last) break;
        --last;
    }
    return true;
}
