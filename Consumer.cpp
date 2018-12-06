#include "Consumer.h"
#include"stdio.h"
#include<QMutex>
#include<QWaitCondition>
#include<QDebug>
extern const int BufferSize ;
extern const int  DataSize ;

extern QWaitCondition bufferNotEmpty;
extern QWaitCondition bufferNotFull;
extern QMutex mutex;
extern char buffer[8192];
extern int numUsedBytes;

Consumer::Consumer()
{

}

Consumer::~Consumer()
{

}

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i)
    {
        mutex.lock();
        if (numUsedBytes == 0)
        {
            bufferNotEmpty.wait(&mutex);
        }

        mutex.unlock();

        qDebug() << "\nI am consumer, and I use a project! -------" << i;
        fprintf(stderr, "%c\n", buffer[i % BufferSize]);


        mutex.lock();

        --numUsedBytes;
        bufferNotFull.wakeAll();

        mutex.unlock();
    }
    fprintf(stderr, "\n");

}
