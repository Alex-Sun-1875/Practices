#ifndef MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class MessageQueue {
  public:
    MessageQueue();

    virtual ~MessageQueue();

    void Push(T record);
    bool Pop(T& record, bool is_blocked = true);
    int Size();
    bool Empty();

  private:
    MessageQueue(const MessageQueue&) = delete;
    MessageQueue& operator=(const MessageQueue&) = delete;

  private:
    std::queue<T> que_;
    mutable std::mutex mutex_;
    std::condition_variable condition_;
};

template <typename T>
MessageQueue<T>::MessageQueue()
  : que_(),
    mutex_(),
    condition_() {
  // init message queue
}

template <typename T>
MessageQueue<T>::~MessageQueue() { }

template <typename T>
void MessageQueue<T>::Push(T record) {
  std::lock_guard<std::mutex> lock(mutex_);
  que_.push(record);
  condition_.notify_one();
}

template <typename T>
bool MessageQueue<T>::Pop(T& record, bool is_blocked) {
  if (is_blocked) {
    std::unique_lock<std::mutex> lock(mutex_);
    while (que_.empty()) {
      condition_.wait(lock);
    }
  } else { // if user wants to retrieve data in non-blocking mode
    std::lock_guard<std::mutex> lock(mutex_);
    if (que_.empty())
      return false;
  }

  record = std::move(que_.front());
  que_.pop();
  return true;
}

template <typename T>
int MessageQueue<T>::Size() {
  std::lock_guard<std::mutex> lock(mutex_);
  return que_.size();
}

template <typename T>
bool MessageQueue<T>::Empty() {
  std::lock_guard<std::mutex> lock(mutex_);
  return que_.empty();
}

#endif  // MESSAGE_QUEUE_H_
