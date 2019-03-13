Blockly.JavaScript['servo_attach'] = function(block) {
    var number_servo_pin = block.getFieldValue('servo_pin');
    var code = 'DEV_IO.Servo().attach('+number_servo_pin+');\n';
    return code;
};

Blockly.JavaScript['servo_write'] = function(block) {
    var number_servo_pin = block.getFieldValue('servo_pin');
    var value_angle = Blockly.JavaScript.valueToCode(block, 'angle', Blockly.JavaScript.ORDER_ATOMIC);
    // TODO: Assemble JavaScript into code variable.
    var code = 'DEV_IO.Servo().write('+value_angle+');\n';
    return code;
};