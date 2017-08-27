#include "semaphore.h"
#include "time.h"
#include <exlib/include/fiber.h>

namespace v8 {
namespace base {

    Semaphore::Semaphore(int count)
    {
        native_handle_ = new exlib::Semaphore(count);
    }

    Semaphore::~Semaphore()
    {
        delete native_handle_;
    }

    void Semaphore::Signal()
    {
        native_handle_->post();
    }

    void Semaphore::Wait()
    {
        native_handle_->wait();
    }

    bool Semaphore::WaitFor(const TimeDelta& rel_time)
    {
        if (rel_time.InMicroseconds() == 0)
            return native_handle_->trywait();

        native_handle_->wait();
        return true;
    }
}
} // namespace v8::base
