#include"global.h"
#include<QMutex>
#include<QWaitCondition>

extern const int DataSize = 10000 ;
extern const int BufferSize = 8192;
QWaitCondition bufferNotEmpty;
QWaitCondition bufferNotFull;
QMutex mutex;
char buffer[8192];
int numUsedBytes=0;
