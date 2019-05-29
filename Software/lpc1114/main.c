#include "LPC11xx.h"

#define setting_alarm_button_pressed (LPC_GPIO1->DATA & (1 << 5))
#define setting_clk_button_pressed (LPC_GPIO1->DATA & (1 << 11))

volatile unsigned char tick_interrupt_count = 0;
volatile unsigned char tick_second = 10;


int main(void)
{
  // DS3231 HAS 19 REGISTER ADDRESS
  unsigned char saat[19];
  // FOR CONVERTING DS REGISTERS TO REASONABLE DATA
  ds_t ds3231;
  //  INIT ALL NECESSARY FUNCTIONS
  main_init();
  i2c_init();
  spi_init();
  systick_init();
  
  //READ ALL REGISTER AND SAVE TO RAW ARRAY  
  i2c_read_multi_char(0xD0,0xD1,0x00,saat[19]);
  // CONVERT RAW REGISTER DATA TO REASONABLE DATA
  raw_to_ds_t(ds3231,saat[19]);
  //  CHECK ALL ALARMS
  check_alarm(ds3231);  
  
//WRITE MINUTE AND HOUR
led_write(ds3231.hour__am_pm,ds3231.minute,0);
  
//START SYSTICK AND 10 SECOND DEADLINE FOR POWERDOWN MODE
systick_second_sleep(10);

while(1){
  
//WAIT FOR SETTING BUTTON PRESSED
//EACH BUTTON PRESSED RESTART SYSTICK
  if(setting_clk_button_pressed == 0)
  {
    setting_clk_on();
  }
  if(setting_alarm_button_pressed == 0)
  {
  setting_alarm_on();
  }
}
return 0;
}
