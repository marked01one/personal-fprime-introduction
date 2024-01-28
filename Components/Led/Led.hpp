// ======================================================================
// \title  Led.hpp
// \author marked01one
// \brief  hpp file for Led component implementation class
// ======================================================================

#ifndef Components_Led_HPP
#define Components_Led_HPP

#include "Components/Led/LedComponentAc.hpp"
#include <Os/Mutex.hpp>

namespace Components {

  class Led :
    public LedComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Led object
      Led(
          const char* const compName //!< The component name
      );

      //! Destroy Led object
      ~Led();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command BLINKING_ON_OFF
      //!
      //! TODO
      void BLINKING_ON_OFF_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On on_off //!< Indicates whether the blinking should be on or off
      );

      void parameterUpdated(FwPrmIdType id /*!< The parameter ID */);

      void run_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      );

      Os::Mutex lock;
      Fw::On state;
      U64 transitions;
      U32 count;
      bool blinking;

  };

}

#endif
