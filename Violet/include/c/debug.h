#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "types.h"
#include <stdarg.h>
#include "mgba/mgba.h"
    
    #define NONE 0
    #define MGBA 1

    #define DEBUG_TYPE MGBA

    #if DEBUG_TYPE != MGBA
        #define LOG(...) while (0) { mgba_printf(__VA_ARGS__); }
    #else
        #define LOG(...) (mgba_printf(__VA_ARGS__))
    #endif

    #define DEBUG(...) LOG(MGBA_LOG_DEBUG, __VA_ARGS__)
    #define WARN(...) LOG(MGBA_LOG_WARN, __VA_ARGS__)
    #define ERROR(...) LOG(MGBA_LOG_ERROR, __VA_ARGS__)

    // void debug1(int a);
    // void debug2(int a, int b);
    // void debug3(int a, int b, int c);
    // void debug4(int a, int b, int c, int d);
    // void debugn(int *n);
    // void err(int e);
    // void err2(int e, int p);

    // void dprintf(const char * str, ...);
    // void derrf(const char *str, ...);
    
    /**
     * Starts benchmarking, i.e. starts a timer
     **/
    void benchmark_start(void);

    /**
     * Ends benchmarking, i.e. ends the timer and returns the time elapsed (in cycles)
     * @return the cycles that have elapsed
     **/
    u32 benchmark_end(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

