#include <iostream>
#include <stddef.h>

using namespace std;

typedef long long T;

class Vector{
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
public:
    Vector(){
        cout << "To ja, konstruktor Vector!" << endl;
    }

    Vector(const Vector& other){
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[other.size_];
        for(size_t i = 0; i<other.size(); i++){
            data_[i] = other.data_[i];
        }
    }

    Vector(Vector&& other){
        size_ = std::move(other.size_);
        capacity_ = std::move(other.capacity_);
        data_ = std::move(other.data_);

        other.size_ = 0;
        other.capacity_ = 0;

    }

    ~Vector(){
        cout << "To ja, destruktor Vector!" << endl;
        delete [] data_;
    }

    size_t size() const{
        return size_;
    }

    size_t capacity() const{
        return capacity_;
    }

    T& at(size_t index){
        return data_[index];
    }

    T at(size_t index) const{
        return data_[index];
    }

    void push_back(T newElement){
        makeSureCapacityIsEnough();
        data_[size_++] = newElement;
    }

    T pop_back(){
        if(size_ == 0){
            cout << "The vector is empty!" << endl;
        }
        size_--;
        T ReturnValue = data_[size_];
        return ReturnValue;
    }

    class iterator{
        T* position;
    public:
        explicit iterator(T* pos = nullptr) : position(pos){}
        T& operator*(){
            return *position;
        }
        iterator& operator++() {position = position + 1; return *this;}
        bool operator!=(const iterator& it) const{
            return position != it.position;
        }
    };

    iterator begin(){
        return iterator{data_};
    }

    iterator end(){
        return iterator{data_ + size()};
    }
private:
    void makeSureCapacityIsEnough(){
        if(!data_){
            data_ = new T;
            capacity_ = 1;
        }
        else{
            if(size() == capacity_ ){
                auto NewCapacity = size() + 1;
                T* newData = new T[NewCapacity];
                for(size_t i = 0; i<size(); i++){
                    newData[i] = data_[i];
                }
                delete [] data_;
                data_ = newData;
                capacity_ = NewCapacity;
            }
        }
    }
};
int main()
{
    /*
    Vector v;

    cout << "#1" << endl;
    cout << "Size of vector: " << v.size() << endl;
    cout << "Vector's capacity: " << v.capacity() << endl;

    v.push_back(23);

    cout << "#2" << endl;
    cout << "Size of vector: " << v.size() << endl;
    cout << "Vector's capacity: " << v.capacity() << endl;

    v.pop_back();

    cout << "#3" << endl;
    cout << "Size of vector: " << v.size() << endl;
    cout << "Vector's capacity: " << v.capacity() << endl;

    v.push_back(43);
    v.push_back(12);
    v.push_back(102);
    v.push_back(124);

    cout << "#4" << endl;
    cout << "Size of vector: " << v.size() << endl;
    cout << "Vector's capacity: " << v.capacity() << endl;

    for(auto it = begin(v); it != end(v); ++it)
    {
        cout<< (*it) <<endl;
    }

    v.push_back(633325);
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout<< (*it) <<endl;
    }

    for(auto it : v)
    {
        cout<< it <<endl;
    }
    */

    Vector v;
    v.push_back(12);
    v.push_back(354);
    v.push_back(1567);

    Vector kopia = move(v);

    cout << "Elementy kopii: " << endl;
    for(auto c : kopia){
        cout << c << endl;
    }
    cout << "Elementy oryginalu: " << endl;
    for(auto c : v){
        cout << c << endl;
    }



    return 0;
}
