#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
    elements_ = nullptr;
	size_ = 0;
	capasity_= 0;
}

vector_t::vector_t(vector_t const & other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new int [capacity_];
    for (unsigned i = 0; i < size_; ++i){
        elements_[i] = other.elements_[i];
    }
    
}

vector_t & vector_t::operator =(vector_t const & other)
{
    if (elements_ == other.elements_) 
    return *this;
    else{
    delete[] elements_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new int [capacity_];
    for (unsigned i = 0; i < size_; ++i)
        elements_[i] = other.elements_[i];
 	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{  
    for (unsigned i = 0; i < size_; ++i){
        if (elements_[i] != other.elements_[i])
        return false;
    }
    return true;
}

vector_t::~vector_t()
{
    if (elements_ != nullptr)
        delete[] elements_;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{   
    if (size_ == 0) {
        size_ = 1;
        capacity_ = 1;
        elements_= new int [1];
        elements_[0] = value;
        return;
    }
    if (size_ == capacity_){
        ++size_;
        capacity_ = capacity_*2;
            int* elements_curr = new int [capacity_]
            for (unsigned i = 0; i < size_-1; ++i)
            elements_curr[i] = elements_[i];
            delete[] elements_;
            elements_ = new int [capacity_];
            for (unsigned i = 0; i < size_-1; ++i)
                elements_[i] = elements_curr[i];
                elements_[size-1] = value;
                delete[] elements_curr;
                return;
    }
    ++size_;
    elements_[size_-1] = value;
}

void vector_t::pop_back()
{
    if(size_ == 0) return;
    if(size_ == 1) {
        size_ = 0;
        capacity_ = 1;
        return;
    }
    --size_;
    if ( capacity_ = 4*size_){
        capacity_= capacity_/2;
        int * elements_curr = new int [capacity_];
        for( unsigned i = 0; i < size_; ++i)
        elements_curr[i] = elements_[i];
        delete[] elements_;
        elements_ = new int [capacity_];
        for( unsigned i = 0; i < size_; ++i)
        elements_[i] = elements_curr[i];
        delete[] elements_curr;
        return;
    }
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
    if(lhs.size() != rhs.size())
    return true;
    else{
        for(unsigned i = 0; i < lhs.size(); ++i)
        if(lhs[i] != rhs[i])
        return true;
    }
	return false;
}
