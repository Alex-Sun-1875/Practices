#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

class Singleton {
  public:
    static Singleton* GetInstance();

  private:
    Singleton();
    ~Singleton();

    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    static Singleton* instance_;
    static pthread_mutex_t mutex_;
};

// static
Singleton* Singleton::instance_ = nullptr;

pthread_mutex_t Singleton::mutex_ = PTHREAD_MUTEX_INITIALIZER;

Singleton* Singleton::GetInstance() {
  if (nullptr == instance_) {
    pthread_mutex_lock(&mutex_);
    if (nullptr == instance_) {
      instance_ = new Singleton();
    }
    pthread_mutex_unlock(&mutex_);
  }

  return instance_;
}

// non-static
Singleton::Singleton() {
  std::cout << "new a singleton instance!!!" << std::endl;
}

int main(int argc, char* argv[]) {
  Singleton* ins_1 = Singleton::GetInstance();

  return 0;
}
