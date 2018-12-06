#include "Producer.h"
#include<QTime>
#include<QMutex>
#include<QWaitCondition>
#include<QDebug>
extern const int BufferSize ;
extern const int  DataSize ;

extern QWaitCondition bufferNotEmpty;
extern QWaitCondition bufferNotFull;
extern QMutex mutex;
extern int numUsedBytes;

extern char buffer[8192];
Producer::Producer()
{

}

Producer::~Producer()
{

}

void Producer::run()Q_DECL_OVERRIDE
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i = 0; i < DataSize; ++i)
    {
        mutex.lock();
        if (numUsedBytes == BufferSize)
        {
            bufferNotFull.wait(&mutex);
        }

        mutex.unlock();

        buffer[i % BufferSize] = "ABCDEF"[(int)qrand() % 6];
        qDebug() << "I am producer, and I produce a project! -------" << "buffer["<<i<<"] is" << buffer[i % BufferSize];

        mutex.lock();

        ++numUsedBytes;
        bufferNotEmpty.wakeAll();

        mutex.unlock();

    }

}
