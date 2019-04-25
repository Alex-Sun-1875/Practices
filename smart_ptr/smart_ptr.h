#include <iostream>

template <typename T>
class SmartPtr {
  public:
    SmartPtr(T* ptr);
    ~SmartPtr();

    SmartPtr(const SmartPtr<T>& ptr);
    SmartPtr<T>& operator=(const SmartPtr<T>& rhs);

    T& operator*();
    T* operator->();

    void addRef() {
      (*count_)++;
    }

    int* ref() const {
      return count_;
    }

    void deRef() {
      --(*count_);

      if (0 == (*count_)) {
        std::cout << "called destructor!!!" << std::endl;
        delete ptr_;
        delete count_;
      }
    }

    T* rawPtr() const { return ptr_; }

  private:
    T* ptr_;
    int* count_;
};

template <typename T>
SmartPtr<T>::SmartPtr(T* ptr)
  : ptr_(ptr) {
    count_ = new int(1);
}

template <typename T>
SmartPtr<T>::~SmartPtr() {
  this->deRef();
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& p) {
  std::cout << "call copy constructor!" << std::endl;
  this->ptr_ = p.rawPtr();
  this->count_ = p.ref();
  this->addRef();
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& rhs) {
  this->ptr_ = rhs.rawPtr();
  this->count_ = rhs.ref();
  this->addRef();

  return *this;
}

template <typename T>
T& SmartPtr<T>::operator*() {
  return *ptr_;
}

template <typename T>
T* SmartPtr<T>::operator->() {
  return ptr_;
}
