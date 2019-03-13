Blockly.JavaScript['ads1115_init'] = function(block) {
  var number_address = block.getFieldValue('address');
  var code = 'DEV_IO.ADS1115().begin('+number_address+');\n';
  return code;
};
Blockly.JavaScript['ads1115_read'] = function(block) {
  var number_address = block.getFieldValue('address');
  var value_name = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC);
  var code = 'DEV_IO.ADS1115().read('+number_address+','+value_name+')';
  return [code, Blockly.JavaScript.ORDER_NONE];
};