#pragma once
#include <QFutureWatcher>
#include <QtConcurrent>
#include <concepts>
#include <type_traits>
#include <qobject.h>

namespace threaded::detail
{
    template<typename Work, typename WorkRet>
    concept ThreadFunction = std::same_as<std::invoke_result_t<Work>, WorkRet>;
}

template<typename WorkRet>
class Threaded
{
public:
    Threaded(QWidget* parent = nullptr){ watcher = new QFutureWatcher<WorkRet>(parent); }

protected:
    QFutureWatcher<WorkRet>* watcher;

    // Use lambda for worker and ret.
    // Possible to use reference in ret.
    template<
        typename Reciever,
        typename Work,
        typename Ret,
        typename Control,
        typename Signal
            >
    requires threaded::detail::ThreadFunction<Work, WorkRet>
    void connect_to_thread(Control sender,
                   Signal  signal, Reciever reciever,
                   Work   worker,  Ret      slot)
    {
        QObject::connect(watcher, &QFutureWatcher<WorkRet>::finished, reciever, slot);
        QObject::connect(sender, signal, reciever, [reciever, worker](){
                auto future = QtConcurrent::run(worker);
                reciever->watcher->setFuture(future);
                });
    }
};
