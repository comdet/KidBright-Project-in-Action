Blockly.Blocks['pcf8574_init'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("ตั้งค่า pcf8574 address")
        .appendField(new Blockly.FieldNumber(39, 0, 255), "address");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['pcf8574_write'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("เขียนค่า pcf8574 address")
        .appendField(new Blockly.FieldNumber(39, 0, 255), "address");
    this.appendValueInput("pin")
        .setCheck("Number")
        .appendField("ขาที่");
    this.appendValueInput("value")
        .setCheck(null)
        .appendField("ค่า");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['pcf8574_read'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("อ่านค่า pcf8574 address")
        .appendField(new Blockly.FieldNumber(39, 0, 255), "address");
    this.appendValueInput("pin")
        .setCheck("Number")
        .appendField("ขาที่");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};