
#ifndef _LIB_DEBUG_H_
#define _LIB_DEBUG_H_

#include <inttypes.h>


#define MAX_DEBUG_MSG_LENGTH 80




// typedef void (*TCallback)(const char* pc_Message);


class DebugActionInterface
{
public:  
  virtual void Callback(const char* pc_Message) = 0;
};




class Debug
{
public:  
  typedef enum 
  {
    Trace,
    Info, 
    Warning, 
    Error, 
    FatalError,
    None
  } ELevel;

private:
  ELevel me_MinDebugLevel;
  DebugActionInterface *mp_ActionInterface;

public: 
  Debug(void);

  void init(DebugActionInterface *p_ActionInterface, const ELevel e_MinDebugLevel = Error);
  void finish(void);

  void msg(const ELevel e_LogLevel, const char* pc_Message);
};







#endif
