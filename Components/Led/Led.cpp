// ======================================================================
// \title  Led.cpp
// \author marked01one
// \brief  cpp file for Led component implementation class
// ======================================================================

#include "Components/Led/Led.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  Led ::
    Led(const char* const compName) :
      LedComponentBase(compName)
  {

  }

  Led ::
    ~Led()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void Led ::BLINKING_ON_OFF_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On on_off
    )
  {
    auto cmdResp = Fw::CmdResponse::OK;

    if (!on_off.isValid())
    {
      cmdResp = Fw::CmdResponse::VALIDATION_ERROR;
    }
    else
    {
      this->count = 0; // Reset count on any successful command
      this->lock.lock();
      this->blinking = Fw::On::ON == on_off; // Update blinking state
      this->lock.unlock();

      this->log_WARNING_LO_InvalidBlinkArgument(on_off);

      this->log_ACTIVITY_HI_SetBlinkingState(on_off);

      
    }


    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

  void Led ::parameterUpdated(FwPrmIdType id) {
    // Read back the parameter value
    Fw::ParamValid isValid;
    U32 interval = this->paramGet_BLINK_INTERVAL(isValid);

    FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

    if (PARAMID_BLINK_INTERVAL == id) {
      // Emit the blink interval set event
      // TODO: Add an event with, severity activity high, named BlinkIntervalSet that takes in an argument of type U32 to report the blink interval.
      this->log_ACTIVITY_HI_BlinkIntervalSet(interval);
    }
  }

  void Led ::run_handler(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    Fw::ParamValid isValid;
    U32 interval = this->paramGet_BLINK_INTERVAL(isValid);

    // Force interval to be 0 when invalid or not set
    interval = \
      ((Fw::ParamValid::INVALID == isValid) || (Fw::ParamValid::UNINIT == isValid)) ? \
      0 : interval;

    // Only perform actions when set to blinking
    this->lock.lock();
    bool is_blinking = this->blinking;
    this->lock.unlock();

    if (is_blinking) 
    {
      Fw::On newState = this->state;
      // Check for transitions
      if ((0 == this->count) && (this->state == Fw::On::OFF))
        newState = Fw::On::ON;
      else if (((interval / 2) == this->count) && (this->state == Fw::On::ON))
        newState = Fw::On::OFF;
      
      // A transition state has occurred
      if (this->state != newState)
      {
        this->transitions = this->transitions + 1;
        // TODO: Add a channel to report the number of LED transitions (this->transitions)
        this->tlmWrite_LedTransitions(this->transitions);

        // Port may not be connected, so check before sending output
        if (this->isConnected_gpioSet_OutputPort(0))
          this->gpioSet_out(0, (Fw::On::ON == newState) ? Fw::Logic::HIGH : Fw::Logic::LOW);
      
        // TODO: Add an event to report the LED state (newState)
        this->state = newState;
        this->tlmWrite_BlinkingState(newState);
      }

      this->count = ((this->count + 1) >= interval) \
        ? 0 : (this->count + 1);
    }
    else
    {
      if (this->state == Fw::On::ON)
      {
        // Check port connection before sending output
        if (this->isConnected_gpioSet_OutputPort(0))
        {
          this->gpioSet_out(0, Fw::Logic::LOW);
        }

        this->state = Fw::On::OFF;
        // TODO: Add an event to report the LED state (this->state)
        this->tlmWrite_BlinkingState(this->state);
      }
    }
  }

}
