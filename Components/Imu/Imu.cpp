// ======================================================================
// \title  Imu.cpp
// \author marked01one
// \brief  cpp file for Imu component implementation class
// ======================================================================

#include "Components/Imu/Imu.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Imu ::
    Imu(const char* const compName) :
      ImuComponentBase(compName)
  {

  }

  Imu ::
    ~Imu()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void Imu ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
