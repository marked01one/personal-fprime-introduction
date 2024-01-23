// ======================================================================
// \title  MathReceiver.hpp
// \author marked01one
// \brief  hpp file for MathReceiver component implementation class
// ======================================================================

#ifndef MathModule_MathReceiver_HPP
#define MathModule_MathReceiver_HPP

#include "Components/MathReceiver/MathReceiverComponentAc.hpp"

namespace MathModule {

  class MathReceiver :
    public MathReceiverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct MathReceiver object
      MathReceiver(
          const char* const compName //!< The component name
      );

      //! Destroy MathReceiver object
      ~MathReceiver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for mathOpIn
      //!
      //! Port for receiving the math operation
      void mathOpIn_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          F32 val1, //!< 1st operand (float-32)
          const MathModule::MathOp& op, //!< operation enum
          F32 val2 //!< 2nd operand
      );

      //! Handler implementation for scheduleIn
      //!
      //! The rate group scheduler input
      void scheduleIn_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      );

      void parameterUpdated(FwPrmIdType id);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command CLEAR_EVENT_THROTTLE
      //!
      //! Clear the event throttle
      void CLEAR_EVENT_THROTTLE_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      );

  };

}

#endif
