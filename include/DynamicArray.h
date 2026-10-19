#pragma once
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <typeinfo>
#include<type_traits>

using namespace std;

template <typename T>
class DynamicArray{
private:
    T* data;
    size_t size;
    size_t capacity;

    class Proxy{
        private:
            DynamicArray& arr;
            size_t index;

        public:
        Proxy(DynamicArray& a, size_t i) : arr(a), index(i) {}

        Proxy& operator = (const T& value){
            arr.set(index, value);
            return *this;
        }

        operator T() const{
            return arr.get(index);
        }
    };

public:
    DynamicArray(size_t n) : size(n), capacity(n){ 
    data = new T[capacity]();
    }

    ~DynamicArray(){
        delete[] data;
        cout << "67.";
    }

    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity){
        data = new T[capacity]();
        for(size_t i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other){

        if(this == &other) return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;
        data = new T[capacity]();
        for(size_t i = 0; i < size; i++){
            data[i] = other.data[i];
        }
        return *this;
    }

     void set(size_t index, T value){
        if(index >= size){
            throw out_of_range("Index Error!");
        }
        if constexpr (is_integral_v<T>){
            if(value < -100 || value > 100){
                throw invalid_argument("Value Error!");
            }
        }
        data[index] = value;
    }

    T get(size_t index) const {
        if(index >= size){
            throw out_of_range("Index Error!");
        }
        return data[index];
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity){

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept{
        if(this == &other) return *this;

        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }


    void push_back(T value){
        if constexpr(is_integral_v<T>){
            if(value < -100 || value > 100){
                throw invalid_argument("Value Error!");
            }
        }

        if(size == capacity){
            capacity *= 2;
            if(capacity == 0){
                capacity++;
            }
            T* new_data = new T[capacity]();
            for(size_t i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size] = value;
        size++;
    }

    void add(const DynamicArray& other){
        size_t limit;
        if(size <= other.size){
            limit = size;
        }else{
            limit = other.size;
        }

        for(size_t i = 0; i < limit; i++){
            data[i] += other.data[i];
            }
    }
    
    void sub(const DynamicArray& other){
        size_t limit;
        if(size <= other.size){
            limit = size;
        }else{
            limit = other.size;
        }

        for(size_t i = 0; i < limit; i++){
            data[i] -= other.data[i];
        }
    }

    double distance(const DynamicArray& other) const {
        if(size != other.size){
            throw invalid_argument("Size Error!");
        }

        if constexpr(is_arithmetic_v<T>){
            double sum = 0.0;
            for(size_t i = 0; i < size; i++){
                double diff = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
                sum += diff*diff;
            }
            return sqrt(sum);
        }else{
            throw bad_typeid();
        }
    }
    
    friend ostream& operator<<(ostream& os, DynamicArray& arr){
        for(size_t i = 0; i < arr.size; i++){
            os << arr.data[i] << " ";
        }
        return os;
    }

    Proxy operator[](size_t index){
        return Proxy(*this, index);
    }

    const T& operator[](size_t index) const {
        return get(index);
    }

    bool operator==(const DynamicArray& other) const{
        if(size != other.size) return false;
        for(size_t i = 0; i < size; i++){
            if(data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=(const DynamicArray& other) const{
        return !(*this == other);
    }

    DynamicArray& operator+=(const DynamicArray& other){
        size_t limit;
        if(size <= other.size){
            limit = size;
        }else{
            limit = other.size;
        }
        for(size_t i = 0; i < limit; i++){
            set(i, data[i] + other.data[i]);
        }
        return *this;
    }
    
    DynamicArray& operator-=(const DynamicArray& other){
        size_t limit;
        if(size <= other.size){
            limit = size;
        }else{
            limit = other.size;
        }
        for(size_t i = 0; i < limit; i++){
            set(i, data[i] - other.data[i]);
        }
        return *this;
    }

    DynamicArray& operator+=(const T& scalar){
        for(size_t i = 0; i < size; i++){
            set(i, data[i] + scalar);
        }
        return *this;
    }

    DynamicArray& operator-=(const T& scalar){
        for(size_t i = 0; i < size; i++){
            set(i, data[i] - scalar);
        }
        return *this;
    }

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin(){return data;}
    iterator end(){return data + size;}
    const_iterator begin() const { return data;}
    const_iterator end() const {return data + size;}

    size_t getSize() const {return size;}
};
