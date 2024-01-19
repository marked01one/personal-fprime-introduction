module Components {
    @ Simple Hello World greeting counter!
    active component HelloWorld {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        @ Command to issue greeting with maximum length of 20 chars
        async command SAY_HELLO(
            greeting: string size 20 @< Greeting to repeat in the Hello
        )

        @ Greeting event with maximum greet length of 20 chars
        event Hello(
            greeting: string size 20 @< Greeting suuplied from the SAY_HELLO command
        ) severity activity high format "[User]: {}"

        @ A count of the number of greetings issued
        telemetry GreetingCount: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
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