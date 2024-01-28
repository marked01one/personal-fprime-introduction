module Components {
    @ Component to blink an LED driven by a rate group
    active component Led {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        async command BLINKING_ON_OFF(
            on_off: Fw.On @< Indicates whether the blinking should be on or off
        )


        # Events ---------------------------------------------------------------------
        @ Indicates we received an invalid argument
        event InvalidBlinkArgument(badArg: Fw.On) \
            severity warning low \
            format "Invalid Blinking Argument: {}"

        @ Reports the state we set to blinking
        event SetBlinkingState(state: Fw.On) \
            severity activity high \
            format "Set blinking state to {}"

        @ Sets the interval between blinks
        event BlinkIntervalSet(interval: U32) \
            severity activity high \
            format "LED blink interval set to {}"
        
        @ Emit the current state - on/off - of the LED 
        event LedState(on_off: Fw.On) \
            severity activity low \
            format "LED is {}"


        # Telemetry ------------------------------------------------------------------
        @ Telemetry channel to report blinking state 
        telemetry BlinkingState: Fw.On

        @ Telemetry channel to report LED state transitions
        telemetry LedTransitions: U64


        # Parameters -----------------------------------------------------------------
        @ Blinking interval in rate group ticks
        param BLINK_INTERVAL: U32


        # Ports ----------------------------------------------------------------------
        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Port sending calls to the GPIO driver
        output port gpioSet: Drv.GpioWrite


        # Standard ports -------------------------------------------------------------
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}