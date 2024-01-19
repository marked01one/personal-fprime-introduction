module MathModule {
    @ Port for requesting an operation on two numbers
    port OpRequest(
        val1: F32 @< 1st operand (float-32)
        op: MathOp @< operation enum
        val2: F32 @< 2nd operand
    )

    port MathResult(
        result: F32 @< result of the operation
    )
}