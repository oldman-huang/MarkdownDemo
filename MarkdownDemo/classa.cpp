#include "ClassA.h"

namespace name {
ClassA::ClassA()
{

}

void ClassA::setCallback(callbackFunc func)
{
    m_callback = func;
}

void ClassA::testCallback()
{
    m_callback(QString("ClassA::useCallback():"));
}

}

