#ifndef CLASSA_H
#define CLASSA_H
#include <QString>
#include <QList>
#include <functional>

namespace name {
typedef std::function<void(const QString&)> callbackFunc;
class ClassA
{
public:
    ClassA();

    void setCallback(name::callbackFunc func);
    void testCallback();

private:
    callbackFunc m_callback;
};

bool static fun0(int a)
{
    if (a < 6) {
        return true;
    } else {
        return false;
    }
}

class Fun1
{
public:
    bool operator()(int a)
    {
        if (a < 60) {
            return true;
        } else {
            return false;
        }
    }
};

struct Fun2
{
public:
    bool operator()(int a)
    {
        if (a < 60) {
            return true;
        } else {
            return false;
        }
    }
};
}
#endif // CLASSA_H
