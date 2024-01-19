module MathModule {
    @ Active component used for sending math operands & operations to MathReceiver
    active component MathSender {
        # -----------------------------------------------------------------------------
        # Commands
        # -----------------------------------------------------------------------------

        @ Do a math operation
        async command DO_MATH(
            val1: F32
            op: MathOp
            val2: F32
        )

        # -----------------------------------------------------------------------------
        # Events
        # -----------------------------------------------------------------------------

        @ Math command received
        event COMMAND_RECV(
            val1: F32
            op: MathOp
            val2: F32
        ) severity activity low format "Math command received: {f} {} {f}"

        @ Received math result
        event RESULT(
            result: F32
        ) severity activity high format "Result: {f}"

        # -----------------------------------------------------------------------------
        # Telemetry
        # -----------------------------------------------------------------------------

        @ The 1st value
        telemetry VAL1: F32
        @ The operation
        telemetry OP: MathOp
        @ The 2nd value
        telemetry VAL2: F32
        @ The result
        telemetry RESULT: F32

        # -----------------------------------------------------------------------------
        # General ports
        # -----------------------------------------------------------------------------

        @ Port for sending the operation request
        output port mathOpOutput: OpRequest

        @ Port for receiving result
        async input port mathResultIn: MathResult

        # -----------------------------------------------------------------------------
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  
        # -----------------------------------------------------------------------------

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Event port
        event port eventOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Text event port
        text event port textEventOut

        @ Time get port
        time get port timeGetOut

    }
}