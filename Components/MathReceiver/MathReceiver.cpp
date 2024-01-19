// ======================================================================
// \title  MathReceiver.cpp
// \author marked01one
// \brief  cpp file for MathReceiver component implementation class
// ======================================================================

#include "Components/MathReceiver/MathReceiver.hpp"
#include "FpConfig.hpp"

namespace MathModule {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  MathReceiver ::
    MathReceiver(const char* const compName) :
      MathReceiverComponentBase(compName)
  {

  }

  MathReceiver ::
    ~MathReceiver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void MathReceiver ::
    TODO_1_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

  void MathReceiver ::
    TODO_2_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
