

// interrupt ları interrupt içinde tekrar kurmak gerekir 
// yeniden interrupt a girsin diye
// fakat systick interrupt unun tekrar girmesine gerek yoktur.
// biz çağırınca girmesi gerekir.
// o yüzden interrupt un tekrar içinde aktif edilmez.

#define SYSTEM_CLOCK_FREQUENCY 12 // 12MHZ

#define SYSTICK_CLKSOURCE_BIT 2
#define SYSTICK_TICKINT_BIT 1
#define SYSTICK_ENABLE_BIT 0

#define WAITING_FOR_ACTION 1
#define ONLY_DELAY 2

#define SEC_10 10
#define SEC_20 20
#define SEC_40 40
#define SEC_100 100
#define SEC_250 250

void relax_systick_sec(void);
void deadline_systick_sec(unsigned char wait_for_dead);
void delay_sys(unsigned int u_sec);
void SysTick_Handler(void);




