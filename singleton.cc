#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
#include <string>

template <typename T>
class Singleton {
  public:
    static T* GetInstance();

  protected:
    Singleton() = default;
    virtual ~Singleton();
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;

  private:
    static T* instance_;
    static pthread_mutex_t mutex_;
};

template <typename T>
pthread_mutex_t Singleton<T>::mutex_ = PTHREAD_MUTEX_INITIALIZER;

template <typename T>
T* Singleton<T>::instance_ = nullptr;

template <typename T>
T* Singleton<T>::GetInstance() {
  if (nullptr == instance_) {
    pthread_mutex_lock(&mutex_);
    if (nullptr == instance_) {
      instance_ = new T("hello");
    }
    pthread_mutex_unlock(&mutex_);
  }
  return instance_;
}

int main(int argc, char* argv[]) {
  std::string* str = Singleton<std::string>::GetInstance();
  std::cout << "str = " << *str << std::endl;
  return 0;
}
