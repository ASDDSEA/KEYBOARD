#include "keyboard.h"
#include "string.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
uint8_t hidbuffer[17];


void keyboard()
{
    memset(hidbuffer,0,17);
    hidbuffer[0] = 1;
    if((HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5))==0)
    {
        DelayUs(100);
       if((HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5))==0)
       {
         hidbuffer[3] = 0x01;
       }
    }
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS,hidbuffer,17);
}


void DelayUs(uint32_t _us)
{
    for (int i = 0; i < _us; i++)
        for (int j = 0; j < 8; j++)  // ToDo: tune this for different chips
            __NOP();
}






