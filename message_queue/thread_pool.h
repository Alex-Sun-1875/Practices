#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include "message_queue.h"

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

#define MIN_THREADS 10

template <typename T>
class ThreadPool {
  public:
    ThreadPool(int threads, std::function<void(T& record)> handler);
    virtual ~ThreadPool();
    void Submit(T record);

  private:
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

  private:
    bool shutdown_;
    int threads_;
    std::function<void(T& record)> handler_;
    std::vector<std::thread> workers_;
    MessageQueue<T> tasks_;
};

template <typename T>
ThreadPool<T>::ThreadPool(int threads, std::function<void(T& record)> handler)
  : shutdown_(false),
    threads_(threads),
    handler_(handler),
    workers_(),
    tasks_() {
  if (threads_ < MIN_THREADS)
    threads_ = MIN_THREADS;

  for (int i = 0; i < threads_; ++i) {
    workers_.emplace_back(
        [this] {
          while (!shutdown_) {
            T record;
            tasks_.Pop(record, true);
            handler_(record);
          }
        }
      );
  }
}

template <typename T>
ThreadPool<T>::~ThreadPool() {
  for (auto& worker : workers_) {
    worker.join();
  }
}

template <typename T>
void ThreadPool<T>::Submit(T record) {
  tasks_.Push(record);
}

#endif // THREAD_POOL_H_
