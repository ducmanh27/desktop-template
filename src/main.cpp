#include <QCoreApplication>

// Add spdlog lib
// Add KDE Framework
// Add google test

#include <QDebug>
#include <ThreadWeaver/ThreadWeaver>
#include "spdlog/spdlog.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    using namespace ThreadWeaver;
    stream() << make_job([]() {
        spdlog::info("hello world");
    });
    return a.exec();
}
