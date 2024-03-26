#include <stdio.h>

#include "debug.h"




Debug::Debug(void)
{
  me_MinDebugLevel = Error;
  mp_ActionInterface = nullptr;
}



void Debug::init(DebugActionInterface *p_ActionInterface, const ELevel e_MinDebugLevel)
{
  mp_ActionInterface = p_ActionInterface;
  me_MinDebugLevel = e_MinDebugLevel;
}


void Debug::finish(void)
{
  me_MinDebugLevel = None;
  mp_ActionInterface = nullptr;
}



void Debug::msg(const ELevel e_DebugLevel, const char* pc_Message)
{
  if((e_DebugLevel>=me_MinDebugLevel) && (mp_ActionInterface!=nullptr))
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
    mp_ActionInterface->Callback(ac_Message);
  }
}

