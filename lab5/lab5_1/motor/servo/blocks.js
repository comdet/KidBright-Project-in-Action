Blockly.Blocks['servo_attach'] = {
    init: function() {
      this.appendDummyInput()
          .appendField("ตั้งค่า Servo พิน")
          .appendField(new Blockly.FieldNumber(26, 0, 50), "servo_pin");
      this.setPreviousStatement(true, null);
      this.setNextStatement(true, null);
      this.setColour(230);
   this.setTooltip("");
   this.setHelpUrl("");
    }
  };

  Blockly.Blocks['servo_write'] = {
    init: function() {
      this.appendDummyInput()
          .appendField("หมุน Servo พิน")
          .appendField(new Blockly.FieldNumber(26, 0, 50), "servo_pin");
      this.appendValueInput("angle")
          .setCheck("Number")
          .appendField("ไปที่");
      this.appendDummyInput()
          .appendField("องศา");
      this.setInputsInline(true);
      this.setPreviousStatement(true, null);
      this.setNextStatement(true, null);
      this.setColour(230);
   this.setTooltip("");
   this.setHelpUrl("");
    }
  };

