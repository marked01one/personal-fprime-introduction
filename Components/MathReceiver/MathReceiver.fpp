module MathModule {
    @ Queued component that process math operands & operations sent by MathSender
    queued component MathReceiver {

        # -----------------------------------------------------------------------------
        # General ports
        # -----------------------------------------------------------------------------
        
        @ Port for receiving the math operation
        async input port mathOp: OpRequest

        @ Port for returning the math result
        output port mathResultOut: MathResult

        @ The rate group scheduler input
        sync input port scheduleIn: Svc.Shed

        # -----------------------------------------------------------------------------
        # Special ports
        # -----------------------------------------------------------------------------

        @ Command receive
        command recv port cmdIn

        @ Command registration
        command reg port cmdRegOut

        @ Command response 
        command resp port cmdResponseOut

        @ Event
        event port eventOut

        @ Parameter get
        param get port prmGetOut

        @ Parameter set
        param set port prmSetOut

        @ Telemetry
        telemetry port tlmOut

        @ Text event
        text event port textEventOut

        @ Time get
        time get port timeGetOut
    }
}