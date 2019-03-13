Blockly.JavaScript['pcf8574_init'] = function(block) {
  var number_address = block.getFieldValue('address');
  var code = 'DEV_IO.KBPCF8574().begin('+number_address+');\n';
  return code;
};

Blockly.JavaScript['pcf8574_write'] = function(block) {
  var number_address = block.getFieldValue('address');
  var value_pin = Blockly.JavaScript.valueToCode(block, 'pin', Blockly.JavaScript.ORDER_ATOMIC);
  var value_value = Blockly.JavaScript.valueToCode(block, 'value', Blockly.JavaScript.ORDER_ATOMIC);
  var code = 'DEV_IO.KBPCF8574().write('+number_address+','+value_pin+','+value_value+');\n';
  return code;
};

Blockly.JavaScript['pcf8574_read'] = function(block) {
  var number_address = block.getFieldValue('address');
  var value_pin = Blockly.JavaScript.valueToCode(block, 'pin', Blockly.JavaScript.ORDER_ATOMIC);
  var code = 'DEV_IO.KBPCF8574().read('+number_address+','+value_pin+')';
  return [code, Blockly.JavaScript.ORDER_NONE];
};