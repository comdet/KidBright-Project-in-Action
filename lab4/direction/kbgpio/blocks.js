Blockly.Blocks['gpio_set_output'] = {
    init: function() {
      this.appendDummyInput()
          .appendField("ใช้งานเอาต์พุต GPIO")
          .appendField(new Blockly.FieldNumber(2, 0, 99), "pin");
      this.setInputsInline(true);
      this.setPreviousStatement(true, null);
      this.setNextStatement(true, null);
      this.setColour(135);
   this.setTooltip("เปิดการใช้งานเอาต์พุต");
   this.setHelpUrl("");
    }
  };

Blockly.Blocks['gpio_digital_write'] = {
    init: function() {
      this.appendDummyInput()
          .appendField("กำหนด GPIO")
          .appendField(new Blockly.FieldNumber(2, 0, 99), "pin");
      this.appendValueInput("value")
          .setCheck("Boolean")
          .appendField(" ค่า ");
      this.setInputsInline(true);
      this.setPreviousStatement(true, null);
      this.setNextStatement(true, null);
      this.setColour(135);
   this.setTooltip("เปิดการใช้งานเอาต์พุต");
   this.setHelpUrl("");
    }
  };