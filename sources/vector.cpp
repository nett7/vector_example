#include "vector.hpp"
#include <algorithm>
#include <cassert>
#include <memory>


vector_t::vector_t() {
    elements_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

vector_t::vector_t(vector_t const &other) {
}

vector_t &vector_t::operator=(vector_t const &other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    if (elements_ != nullptr) {
        delete[] elements_;
    }
    elements_ = new int[other.capacity_];
    std::copy(&other.elements_[0], &other.elements_[other.size_], elements_);

    return *this;
}

bool vector_t::operator==(vector_t const &other) const {
    for (int i = 0; i < other.size_; i++) {
        if (elements_[i] != other[i]) {
            return false;
        }
    }

    return true;
}

vector_t::~vector_t() {
    delete []elements_;
}

std::size_t vector_t::size() const {
    return size_;
}

std::size_t vector_t::capacity() const {
    return capacity_;
}

void vector_t::push_back(int value) {
    if (size_ == capacity_) {
        extend_capacity_();
    }
    elements_[size_] = value;
    size_++;
}

void vector_t::pop_back() {
    size_--;
    if(size_< (capacity_/2)) {
        decrease_capacity();
    }
        int *temp = elements_;
        elements_ = new int[capacity_];
        std::copy(temp, &temp[size_-1], elements_);
        delete[]temp;
    
}

int &vector_t::operator[](std::size_t index) {
    return elements_[index];
}

int vector_t::operator[](std::size_t index) const {
    return elements_[index];
}

void vector_t::extend_capacity_() {
    if (elements_ == nullptr) {
        elements_ = new int[1];
        capacity_ = 1;
    } else {
        int *temp = elements_;
        capacity_ *= 2;
        elements_ = new int[capacity_];
        std::copy(temp, &temp[size_], elements_);
        delete[]temp;


    }
}

void vector_t::decrease_capacity() {
    if (capacity_ > 1) {
        int *temp = elements_;
        capacity_ /= 2;
        elements_ = new int[capacity_];
        std::copy(temp, &temp[size_], elements_);
        delete[]temp;
    }

}

bool operator!=(vector_t const &lhs, vector_t const &rhs) {
    if(lhs.size_!=rhs.size_){
        return true;
    }
    else {
    for (int i = 0; i < lhs.size_; i++) {
        if (lhs[i] != lhs[i]) {
            return true;
        }}
    }

    return false;
}
