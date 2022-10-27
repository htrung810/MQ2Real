#include <simcom.h>
// Declare your global variables here
unsigned int i;
unsigned char cmd_1[] = {"AT"};                              // trang thai sim
unsigned char cmd_baud[] = {"AT+IPR=9600"};
unsigned char cmd_setup[] = {"AT&W"};
unsigned char cmd_2[] = {"AT+CMGF=1"};                       // tin nhan text
unsigned char cmd_3[] = {"AT+CMGS=\"+84936230861\""};        // sdt gui tin nhan
unsigned char cmd_8[] = {"Warning move"};
// Standard Input/Output functions
void sim_status()
{
    //send AT
    for(i=0;cmd_1[i]!='';i++)
    {
        UDR = cmd_1[i];
        delay_ms(100);
    }
    UDR = ('\r');
    delay_ms(300); 
    // baud
    for(i=0;cmd_baud[i]!='';i++)
    {
        UDR = cmd_baud[i];
        delay_ms(100);
    }
    UDR = ('\r');
    delay_ms(300);
    //setup
    for(i=0;cmd_setup[i]!='';i++)
    {
        UDR = cmd_setup[i];
        delay_ms(100);
    }
    UDR = ('\r');
    delay_ms(300);
}
void sim_sendmess()
{
    // send messenger
    for(i=0;cmd_2[i]!='';i++)
    {
        UDR = cmd_2[i];
        delay_ms(100);
    }
    UDR = ('\r');
    delay_ms(500);
    // phone number                 
    for(i=0;cmd_3[i]!='';i++)
    {
        UDR = cmd_3[i];
        delay_ms(100);
    }
    UDR = ('\r');
    delay_ms(500);
    // canh bao chay
    for(i=0;cmd_8[i]!='';i++)
    {
        UDR = cmd_8[i];
        delay_ms(100);
    }
    UDR = ('\r');
    UDR = (26);
    delay_ms(1000);
}
