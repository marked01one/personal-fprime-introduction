// ======================================================================
// \title  MathSender.hpp
// \author marked01one
// \brief  hpp file for MathSender component implementation class
// ======================================================================

#ifndef MathModule_MathSender_HPP
#define MathModule_MathSender_HPP

#include "Components/MathSender/MathSenderComponentAc.hpp"

namespace MathModule {

  class MathSender :
    public MathSenderComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct MathSender object
      MathSender(
          const char* const compName //!< The component name
      );

      //! Destroy MathSender object
      ~MathSender();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for mathResultIn
      //!
      //! Port for receiving result
      void mathResultIn_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          F32 result //!< result of the operation
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command DO_MATH
      //!
      //! Do a math operation
      void DO_MATH_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          F32 val1,
          MathModule::MathOp op,
          F32 val2
      );

  };

}

#endif
