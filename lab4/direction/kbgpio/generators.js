Blockly.JavaScript['gpio_set_output'] = function(block) {
    var number_pin = block.getFieldValue('pin');
    var code = 'DEV_IO.KBGPIO().setOutput('+number_pin+');\n';
    return code;
};

Blockly.JavaScript['gpio_digital_write'] = function(block) {
    var number_pin = block.getFieldValue('pin');
    var value_value = Blockly.JavaScript.valueToCode(block, 'value', Blockly.JavaScript.ORDER_ATOMIC);
    var code = 'DEV_IO.KBGPIO().digitalWrite('+number_pin+','+value_value+');\n';
    return code;
};