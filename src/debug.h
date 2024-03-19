#ifndef _LIB_DEBUG_H_
#define _LIB_DEBUG_H_

#include <inttypes.h>


#define MAX_DEBUG_MSG_LENGTH 80


typedef enum 
{
  Trace,
  Info, 
  Warning, 
  Error, 
  FatalError,
  None
} EDebugLevel;

typedef void (*TCallback)(const char* pc_Message);


void debug_init(const TCallback p_Callback, const EDebugLevel e_MinDebugLevel = Error);
void debug_finish(void);

void debug(const EDebugLevel e_LogLevel, const char* pc_Message);


#endif
