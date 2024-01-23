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
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void MathReceiver ::
    mathOpIn_handler(
        NATIVE_INT_TYPE portNum,
        F32 val1,
        const MathModule::MathOp& op,
        F32 val2
    )
  {
    F32 res = 0.0;

    // Get the initial value
    switch (op.e)
    {
    case MathOp::ADD:
      res = val1 + val2;
      break;
    
    case MathOp::SUB:
      res = val1 - val2;
      break;
    
    case MathOp::MUL:
      res = val1 * val2;
      break;
    
    case MathOp::DIV:
      res = val1 / val2;
      break;
    
    default:
      FW_ASSERT(0, op.e);
      break;
    }

    // Get the factor value
    Fw::ParamValid valid;
    F32 factor = paramGet_FACTOR(valid);
    FW_ASSERT(
      valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
      valid.e
    );

    // Multiply result by factor
    res *= factor;

    // Emit telemetry & events
    this->log_ACTIVITY_HI_OPERATION_PERFORMED(op);
    this->tlmWrite_OPERATION(op);

    // Emit result
    this->mathResultOut_out(0, res);
  }

  void MathReceiver ::
    scheduleIn_handler(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    U32 numMsgs = this->m_queue.getNumMsgs();

    for (U32 i = 0; i < numMsgs; ++i) {
      (void) this->doDispatch();
    }
  }

  void MathReceiver ::
    parameterUpdated(FwPrmIdType id)
  {
    switch (id)
    {
    case  PARAMID_FACTOR: {
      Fw::ParamValid valid;
      F32 val = this->paramGet_FACTOR(valid);
      FW_ASSERT(
        valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
        valid.e
      );
      this->log_ACTIVITY_HI_FACTOR_UPDATED(val);
      break;
    }
    
    default:
      FW_ASSERT(0, id);
      break;
    }
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void MathReceiver ::
    CLEAR_EVENT_THROTTLE_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // Clear throttle
    this->log_ACTIVITY_HI_FACTOR_UPDATED_ThrottleClear();
    // Send event that throttle is cleared
    this->log_ACTIVITY_HI_THROTTLE_CLEARED();
    // Reply with completion status
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
