


#define E2PROM_TRUE                                       0x01              // TRUE FOR E2PROM
#define E2PROM_FALSE                                      0x00              // FALSE FOR E2PROM
#define E2PROM_DEVICE_ADDR                                0xA2              // DEVICE ADDR FOR I2C
#define E2PROM_24C32_ADDR_SIZE                            2                 // 2 BYTE ADDR SIZE,ADDR BYTE LEN
#define E2PROM_24C32_END_ADDR                             0xFFF             // MAX ADDR
#define VERSION_ADDR                                      0x000             // FIRSTLY READ THIS BYTE FOR VERSION

////////////////////////////////////////////////////////////////////////////////

#define ARE_THERE_ALARM                                   0x001              // 1 or 0 EXTRA ALARM VARMI

#define ALARM_COUNT_ADDR                                  0x00A              // BIRTDAY AND LIKE THAT DATES COUNT MAX 255
                                                                             // MAYBE AT SCHOOL OR REST TIME
#define ALARM_START_ADDR                                  0x030              // 1 BYTE MINUTE             MAX 59 MIN 0
                                                                             // 1 BYTE WATCH OR CLOCK     MAX 23 MIN 0
                                                                             // 1 BYTE DAY IN MOUNT       MAX 31 MIN 1
                                                                             // 1 BYTE MOUNT IN YEAR      MAX 12 MIN 1
#define EXTRA_ALARM_TOTAL_BYTE_PER_DATA                   4                  // 4 BYTE TOTAL PER 1 SPECIAL DATE
                                                                             // 0x030 FIRST DATA TO 0X111 (NAMAZ START ADDR)

////////////////////////////////////////////////////////////////////////////////

#define DOES_ALERT_AT_NAMAZ_CLOCK                         0x002             // 1 or 0 NAMAZ SAATLERINDE CALSINMI

#define E2PROM_ALL_NAMAZ_ALERT_SETTING_ADDR               0x020             // 1 or 0 BUTUN NAMAZ SAATLERINDE CALSINMI
                                                                            // BAZI NAMAZ SAATLERINDE CALACKSA HANGISI 
                                                                            // ASAGIDAKILERDEN SEC
#define E2PROM_SABAH_NAMAZI_ALERT_SETTING_ADDR            0x021             // 1 or 0 SABAH NAMAZI CALSIN VEYA CALMASIN
#define E2PROM_GUNES_NAMAZI_ALERT_SETTING_ADDR            0x022             // 1 or 0 GUNES DOGUSU CALSIN VEYA CALMASIN
#define E2PROM_OGLE_NAMAZI_ALERT_SETTING_ADDR             0x023             // 1 or 0 OGLE NAMAZI CALSIN VEYA CALMASIN
#define E2PROM_IKINDI_NAMAZI_ALERT_SETTING_ADDR           0x024             // 1 or 0 IKINDI NAMAZI CALSIN VEYA CALMASIN
#define E2PROM_AKSAM_NAMAZI_ALERT_SETTING_ADDR            0x025             // 1 or 0 AKSAM NAMAZI CALSIN VEYA CALMASIN
#define E2PROM_YATSI_NAMAZI_ALERT_SETTING_ADDR            0x026             // 1 or 0 YATSI NAMAZI CALSIN VEYA CALMASIN

#define BEFORE_NAMAZ_SETTING_ADDR                         0x027             // 1 or 0 NAMAZ SAATINDEMI YOKSA ONCEMI CALSIN
                                                                            // NE KADAR SURE ONCE CALSIN DAKIKA OLARAK
#define MINUTE_FOR_BEFORE_NAMAZ_SETTING_ADDR              0x028             // EN FAZLA 255 DAKIKA ONCEDEN CALABILIR

#define ALL_NAMAZ_ADDR                                    0x111             // ALL NAMAZ CLOCK HERE STARTING
                                                                            // 8 BYTE PER DAY
                                                                            // 366 X 8 = 2928 BYTE TOTAL
                                                                            // 4095 MAX VALUE
                                                                            // 4095 - 2928 = 1167 = 0X48F = MAX START ADDR

////////////////////////////////////////////////////////////////////////////////

#define DOES_ALERT_AT_HOURLY                              0x003             // 1 or 0 HER SAAT BASI CALMA AYARI

#define HOURLY_ALERT_SETTING_ADDR                         0x00B             // 1 or 0 HER SAAT BASI CALMA AYARI
#define TWO_HOURLY_ALERT_SETTING_ADDR                     0x00C             // 1 or 0 HER IKI SAAT BASI CALMA AYARI
#define THREE_HOURLY_ALERT_SETTING_ADDR                   0x00D             // 1 or 0 HER UC SAAT BASI CALMA AYARI
#define FOUR_HOURLY_ALERT_SETTING_ADDR                    0x00E             // 1 or 0 HER DORT SAAT BASI CALMA AYARI
#define FIVE_HOURLY_ALERT_SETTING_ADDR                    0x00F             // 1 or 0 HER BES SAAT BASI CALMA AYARI
#define SIX_HOURLY_ALERT_SETTING_ADDR                     0x010             // 1 or 0 HER ALTI SAAT BASI CALMA AYARI
#define TWEVE_HOURLY_ALERT_SETTING_ADDR                   0x011             // 1 or 0 HER ONIKI SAAT BASI CALMA AYARI
#define HOURLY_ALERT_START_SETTING_ADDR                   0x012             // SAAT BASI CALMA AYARI BASLANGIC SAATI

////////////////////////////////////////////////////////////////////////////////



#define DOES_REPEAT_THE_ALARM                             0x004             // 1 or 0 KOLAY UYANAMAYANLAR ICIN ALARM UZATMA

#define INTERVAL_REPEATED_ALERT_SETTING_ADDR              0x005             // DAKIKA OLARAK KAC DAKIKADA BIR
#define NUMBER_REPEATED_ALERT_SETTING_ADDR                0x006             // 1 or 2 or 3 or 4 or 6 or 12 or 24 KAC DEFA

////////////////////////////////////////////////////////////////////////////////

                                                                            // MSB+LSB = DUTY = 16 BIT TIMER FOR PWM
#define LED_LIGHT_SETTING_DUTY_LSB_ADDR                   0x007             // MAX 0xFF 
#define LED_LIGHT_SETTING_DUTY_MSB_ADDR                   0x008             // MAX 0xFF 
#define LED_LIGHT_SETTING_PERCENT_ADDR                    0x009             // DEFAULT %50 IF EMPTY MAX 99 MIN 1

////////////////////////////////////////////////////////////////////////////////

unsigned char e2prom_write(unsigned int addr,unsigned char * data,unsigned int size);
unsigned char e2prom_read(unsigned int addr,unsigned char * data,unsigned int size);


