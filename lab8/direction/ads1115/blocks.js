Blockly.Blocks['ads1115_init'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("ตั้งค่า ads1115 address")
        .appendField(new Blockly.FieldNumber(72, 0, 255), "address");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};
Blockly.Blocks['ads1115_read'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("อ่าน ads1115 address")
        .appendField(new Blockly.FieldNumber(72, 0, 255), "address");
    this.appendValueInput("NAME")
        .setCheck("Number")
        .appendField("ขาที่");
    this.setInputsInline(true);
    this.setOutput(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};