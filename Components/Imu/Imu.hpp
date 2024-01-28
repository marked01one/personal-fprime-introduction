// ======================================================================
// \title  Imu.hpp
// \author marked01one
// \brief  hpp file for Imu component implementation class
// ======================================================================

#ifndef Components_Imu_HPP
#define Components_Imu_HPP

#include "Components/Imu/ImuComponentAc.hpp"

namespace Components {

  class Imu :
    public ImuComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Imu object
      Imu(
          const char* const compName //!< The component name
      );

      //! Destroy Imu object
      ~Imu();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      );

  };

}

#endif
