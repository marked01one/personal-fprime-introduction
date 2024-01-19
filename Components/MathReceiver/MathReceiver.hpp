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
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO_1
      //!
      //! TODO
      void TODO_1_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      );

      //! Handler implementation for command TODO_2
      //!
      //! TODO
      void TODO_2_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      );

  };

}

#endif
