#ifndef PRODUCER_H
#define PRODUCER_H
#include<QThread>

class Producer : public QThread
{
public:
    Producer();
    ~Producer();
    void run() Q_DECL_OVERRIDE;
};

#endif // PRODUCER_H
