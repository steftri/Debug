#include <stdio.h>

#include "debug.h"


EDebugLevel ge_MinDebugLevel = Error;
TCallback gp_Callback = nullptr;


void debug_init(const TCallback p_Callback, const EDebugLevel e_MinDebugLevel)
{
  gp_Callback = p_Callback;
  ge_MinDebugLevel = e_MinDebugLevel;
}


void debug_finish(void)
{
  ge_MinDebugLevel = None;
  gp_Callback = nullptr;
}



void debug(const EDebugLevel e_DebugLevel, const char* pc_Message)
{
  if((e_DebugLevel>=ge_MinDebugLevel) && (gp_Callback!=nullptr))
  {
    char ac_Message[MAX_DEBUG_MSG_LENGTH+1];
    const char* pc_DebugLevel = "";

    switch(e_DebugLevel)
    {
      case FatalError: pc_DebugLevel = "FATAL";   break;
      case Error:      pc_DebugLevel = "ERROR";   break;
      case Warning:    pc_DebugLevel = "Warning"; break;
      case Info:       pc_DebugLevel = "Info";    break;
      case Trace:      pc_DebugLevel = "Trace";   break;
      default:         pc_DebugLevel = "unknown"; 
    }

    (void)snprintf(ac_Message, sizeof(ac_Message), "%s: %s", pc_DebugLevel, pc_Message);
    gp_Callback(ac_Message);
  }
}

