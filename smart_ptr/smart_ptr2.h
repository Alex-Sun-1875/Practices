#include <iostream>

template <typename>
class SmartPtr;

template <typename T>
class RefPtr {
  public:
    friend class SmartPtr<T>;

  protected:
    void ref();
    bool deref();

  private:
    T* ptr_;
    int count_;
    RefPtr(T* ptr);
    virtual ~RefPtr();
};

template <typename T>
RefPtr<T>::RefPtr(T* ptr) : ptr_(ptr), count_(1) { }

template <typename T>
RefPtr<T>::~RefPtr() {
  if (ptr_) {
    std::cout << "call destructor!" << std::endl;
    delete ptr_;
    count_ = 0;
  }

  ptr_ = nullptr;
}

template <typename T>
void RefPtr<T>::ref() {
  ++count_;
}

template <typename T>
bool RefPtr<T>::deref() {
  if (--count_) {
    return false;
  }

  return true;
}

// Smart Pointer
template <typename T>
class SmartPtr {
  private:
    RefPtr<T>* ref_ptr_;

  public:
    SmartPtr();
    SmartPtr(T* ptr);
    SmartPtr(const SmartPtr& other);

    ~SmartPtr();

    SmartPtr<T>& operator=(const SmartPtr& rhs);

    T& operator*();
    T* operator->();
};

template <typename T>
SmartPtr<T>::SmartPtr() {
  ref_ptr_ = nullptr;
}

template <typename T>
SmartPtr<T>::SmartPtr(T* ptr) {
  std::cout << "call constructor!" << std::endl;
  ref_ptr_ = new RefPtr<T>(ptr);
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr& other) {
  std::cout << "call copy constructor!" << std::endl;
  ref_ptr_ = other.ref_ptr_;
  ref_ptr_->ref();
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& rhs) {
  rhs.ref();

  if (ref_ptr_)
    ref_ptr_->deref();

  ref_ptr_ = rhs.ref_ptr_;

  std::cout << "call operator =, current count = " << ref_ptr_->count_ << std::endl;

  return *this;
}

template <typename T>
T& SmartPtr<T>::operator*() {
  return *(ref_ptr_->ptr_);
}

template <typename T>
T* SmartPtr<T>::operator->() {
  return ref_ptr_->ptr_;
}

template <typename T>
SmartPtr<T>::~SmartPtr() {
  std::cout << "call SmartPtr destructor!" << std::endl;

  if (ref_ptr_->deref()) {
    delete ref_ptr_;
    ref_ptr_ = nullptr;
  }

  if (ref_ptr_)
    std::cout << "current_count = " << ref_ptr_->count_ << std::endl;
}
