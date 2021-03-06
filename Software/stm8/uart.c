
// #include "nrf24l01.h"
#include "stm8s.h"
#include "uart.h"

#define DISABLE_INTERRUPT UART1_CR2 &= ~(1 << UART1_CR2_RIEN)
#define ENABLE_INTERRUPT UART1_CR2 |= (1 << UART1_CR2_RIEN)


volatile unsigned char uart_rx_buffer_size = 0;
volatile unsigned char uart_rx_buffer[32];




void uart_init(void)
{
  // stm8s003 has 1 byte uart buffer
  // at main file do this for interrupt buffering
  // volatile unsigned char uart_buffer[32];
  // volatile unsigned char uart_buffer_size = 0;
  
  // ROUND TO NEAREST INTEGER
  // uint16_t div = (F_CPU + (BAUDRATE / 2 ) ) / BAUDRATE;
  // UART1_BRR2 = ( (div >> 8) & 0xF0) + (div & 0x0F);
  // UART1_BRR1 = (div >> 4);
  
  // no need calculating look at user manual for other bauds
  // UART_DIV    = 0x008B // F_MASTER = 16MHZ
  UART1_BRR2 = 0x0B;
  UART1_BRR1 = 0x08;
  // ENABLE TRANSMITTER AND RECEIVER
  UART1_CR2 = ( (1 << UART1_CR2_TEN) | (1 << UART1_CR2_REN) );
  // UART1_CR2 |= (1 << UART1_CR2_RIEN); // if you need rx interrupt enable this
}

void uart_send(unsigned char data)
{
  UART1_DR = data;
  while( ! (UART1_SR & (1 << UART1_SR_TC) ) );
}

unsigned char uart_get(void)
{
  while( ! (UART1_SR & (1 << UART1_SR_RXNE) ) );
  return UART1_DR;
}

void Char_To_Bit(unsigned char bit)
{
	unsigned int turn;
	uart_send('\r');uart_send('\n');
	for(turn = 8;turn > 0;turn--)
	{
		if((bit & (1 << (turn - 1))) == 0)uart_send('0');
		else uart_send('1');
	}
	uart_send('\r');uart_send('\n');
}

/*
void uart_isr() __interrupt(UART1_RXC_ISR) // uart rx interrupt function
{
  uart_rx_buffer[uart_rx_buffer_size] = UART1_DR;
  if(uart_rx_buffer_size < 32) // nrf max buffer size = 32 
  {
    uart_rx_buffer_size++;
  }
  else
  {
    uart_rx_buffer_size = 0;
  }
}
*/
/*
void comminicating_sender(void)
{
  unsigned char x;
  while(1)
  {
    make_tx();
    while( ! (UART1_SR & (1 << UART1_SR_TC) ) ); // WAIT HERE IF U NEED
    if(UART1_SR & (1 << UART1_SR_RXNE) )
    {
      x = UART1_DR;
    }
    else
    {
      x = 0;
    }
    NRF_write_buf(&x,1);
    NRF_send();
    make_rx();                            // receiver mode enable
    NRF_get();                            // get data from air
    NRF_read_buf(&x,1);                   // get data from device
    UART1_DR = x;                         // put data to peripheral "DONT WAIT"
  }
}


void comminicating_receiver(void)
{
  unsigned char x,y;
  while(1)
  {
    make_rx();
    NRF_get();
    NRF_read_buf(&y,1);
    if(UART1_SR & (1 << UART1_SR_RXNE) )
    {
      x = UART1_DR;
    }
    else
    {
      x = 0;
    }
    UART1_DR = y;
    make_tx();
    NRF_write_buf(&x,1);
    NRF_send();
    while( ! (UART1_SR & (1 << UART1_SR_TC) ) );
  }
}

void payload(void)
{
  unsigned char nrf_tx_buffer_size = 0;
  unsigned char nrf_tx_buffer[32];

  unsigned char f;

  if( (uart_rx_buffer_size > 0) )
  {
    DISABLE_INTERRUPT;
    for(f = 0 ; f <= uart_rx_buffer_size ; f++)
    {
      nrf_tx_buffer[f] = uart_rx_buffer[f];
    }
    nrf_tx_buffer_size = uart_rx_buffer_size;

    uart_rx_buffer_size = 0;
    ENABLE_INTERRUPT;

    if(UART1_SR & (1 << UART1_SR_RXNE) )
    {
      nrf_tx_buffer[uart_rx_buffer_size + 1]
      nrf_tx_buffer_size = uart_rx_buffer_size + 1;
    }
 
    nrf_load(nrf_tx_buffer[f],nrf_tx_buffer_size);
    //nrf_request();
  }
  else
  {
    nrf_request();
  }
}
  */
  
  
