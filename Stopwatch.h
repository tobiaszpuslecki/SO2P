#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>

class Stopwatch
{
    public:
        Stopwatch();
        void start();
        double read();
    protected:
    private:
        clock_t tstart;
        clock_t tstop;
        double measurement;
};

#endif // STOPWATCH_H
