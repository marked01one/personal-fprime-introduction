// ======================================================================
// \title  HelloWorld.cpp
// \author marked01one
// \brief  cpp file for HelloWorld component implementation class
// ======================================================================

#include "Components/HelloWorld/HelloWorld.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  HelloWorld :: HelloWorld(const char* const compName) :
      HelloWorldComponentBase(compName), m_greetingCount(0)
  {

  }

  HelloWorld ::
    ~HelloWorld()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void HelloWorld ::
    SAY_HELLO_cmdHandler(FwOpcodeType opCode,U32 cmdSeq, const Fw::CmdStringArg& greeting)
  {
    // TODO
    Fw::LogStringArg eventGreeting(greeting.toChar());

    this->log_ACTIVITY_HI_Hello(eventGreeting);

    this->tlmWrite_GreetingCount(++this->m_greetingCount);

    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
