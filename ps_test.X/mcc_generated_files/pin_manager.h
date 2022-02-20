/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set channel_ANA1 aliases
#define channel_ANA1_TRIS                 TRISAbits.TRISA1
#define channel_ANA1_LAT                  LATAbits.LATA1
#define channel_ANA1_PORT                 PORTAbits.RA1
#define channel_ANA1_WPU                  WPUAbits.WPUA1
#define channel_ANA1_OD                   ODCONAbits.ODCA1
#define channel_ANA1_ANS                  ANSELAbits.ANSELA1
#define channel_ANA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_ANA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_ANA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_ANA1_GetValue()           PORTAbits.RA1
#define channel_ANA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_ANA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_ANA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_ANA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_ANA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define channel_ANA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define channel_ANA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define channel_ANA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set HVON_IN_RA4 aliases
#define HVON_IN_RA4_TRIS                 TRISAbits.TRISA4
#define HVON_IN_RA4_LAT                  LATAbits.LATA4
#define HVON_IN_RA4_PORT                 PORTAbits.RA4
#define HVON_IN_RA4_WPU                  WPUAbits.WPUA4
#define HVON_IN_RA4_OD                   ODCONAbits.ODCA4
#define HVON_IN_RA4_ANS                  ANSELAbits.ANSELA4
#define HVON_IN_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define HVON_IN_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define HVON_IN_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define HVON_IN_RA4_GetValue()           PORTAbits.RA4
#define HVON_IN_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define HVON_IN_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define HVON_IN_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define HVON_IN_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define HVON_IN_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define HVON_IN_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define HVON_IN_RA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define HVON_IN_RA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set HVON_OUT_RA5 aliases
#define HVON_OUT_RA5_TRIS                 TRISAbits.TRISA5
#define HVON_OUT_RA5_LAT                  LATAbits.LATA5
#define HVON_OUT_RA5_PORT                 PORTAbits.RA5
#define HVON_OUT_RA5_WPU                  WPUAbits.WPUA5
#define HVON_OUT_RA5_OD                   ODCONAbits.ODCA5
#define HVON_OUT_RA5_ANS                  ANSELAbits.ANSELA5
#define HVON_OUT_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define HVON_OUT_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define HVON_OUT_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define HVON_OUT_RA5_GetValue()           PORTAbits.RA5
#define HVON_OUT_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define HVON_OUT_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define HVON_OUT_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define HVON_OUT_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define HVON_OUT_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define HVON_OUT_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define HVON_OUT_RA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define HVON_OUT_RA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set OVERLOAD aliases
#define OVERLOAD_TRIS                 TRISAbits.TRISA6
#define OVERLOAD_LAT                  LATAbits.LATA6
#define OVERLOAD_PORT                 PORTAbits.RA6
#define OVERLOAD_WPU                  WPUAbits.WPUA6
#define OVERLOAD_OD                   ODCONAbits.ODCA6
#define OVERLOAD_ANS                  ANSELAbits.ANSELA6
#define OVERLOAD_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define OVERLOAD_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define OVERLOAD_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define OVERLOAD_GetValue()           PORTAbits.RA6
#define OVERLOAD_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define OVERLOAD_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define OVERLOAD_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define OVERLOAD_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define OVERLOAD_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define OVERLOAD_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define OVERLOAD_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define OVERLOAD_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set MODESW_RB0 aliases
#define MODESW_RB0_TRIS                 TRISBbits.TRISB0
#define MODESW_RB0_LAT                  LATBbits.LATB0
#define MODESW_RB0_PORT                 PORTBbits.RB0
#define MODESW_RB0_WPU                  WPUBbits.WPUB0
#define MODESW_RB0_OD                   ODCONBbits.ODCB0
#define MODESW_RB0_ANS                  ANSELBbits.ANSELB0
#define MODESW_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define MODESW_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define MODESW_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define MODESW_RB0_GetValue()           PORTBbits.RB0
#define MODESW_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define MODESW_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define MODESW_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define MODESW_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define MODESW_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define MODESW_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define MODESW_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define MODESW_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set channel_ANB2 aliases
#define channel_ANB2_TRIS                 TRISBbits.TRISB2
#define channel_ANB2_LAT                  LATBbits.LATB2
#define channel_ANB2_PORT                 PORTBbits.RB2
#define channel_ANB2_WPU                  WPUBbits.WPUB2
#define channel_ANB2_OD                   ODCONBbits.ODCB2
#define channel_ANB2_ANS                  ANSELBbits.ANSELB2
#define channel_ANB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define channel_ANB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define channel_ANB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define channel_ANB2_GetValue()           PORTBbits.RB2
#define channel_ANB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define channel_ANB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define channel_ANB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define channel_ANB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define channel_ANB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define channel_ANB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define channel_ANB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define channel_ANB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set channel_ANB3 aliases
#define channel_ANB3_TRIS                 TRISBbits.TRISB3
#define channel_ANB3_LAT                  LATBbits.LATB3
#define channel_ANB3_PORT                 PORTBbits.RB3
#define channel_ANB3_WPU                  WPUBbits.WPUB3
#define channel_ANB3_OD                   ODCONBbits.ODCB3
#define channel_ANB3_ANS                  ANSELBbits.ANSELB3
#define channel_ANB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define channel_ANB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define channel_ANB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define channel_ANB3_GetValue()           PORTBbits.RB3
#define channel_ANB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define channel_ANB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define channel_ANB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define channel_ANB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define channel_ANB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define channel_ANB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define channel_ANB3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define channel_ANB3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set channel_ANB4 aliases
#define channel_ANB4_TRIS                 TRISBbits.TRISB4
#define channel_ANB4_LAT                  LATBbits.LATB4
#define channel_ANB4_PORT                 PORTBbits.RB4
#define channel_ANB4_WPU                  WPUBbits.WPUB4
#define channel_ANB4_OD                   ODCONBbits.ODCB4
#define channel_ANB4_ANS                  ANSELBbits.ANSELB4
#define channel_ANB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define channel_ANB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define channel_ANB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define channel_ANB4_GetValue()           PORTBbits.RB4
#define channel_ANB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define channel_ANB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define channel_ANB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define channel_ANB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define channel_ANB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define channel_ANB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define channel_ANB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define channel_ANB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set channel_ANB5 aliases
#define channel_ANB5_TRIS                 TRISBbits.TRISB5
#define channel_ANB5_LAT                  LATBbits.LATB5
#define channel_ANB5_PORT                 PORTBbits.RB5
#define channel_ANB5_WPU                  WPUBbits.WPUB5
#define channel_ANB5_OD                   ODCONBbits.ODCB5
#define channel_ANB5_ANS                  ANSELBbits.ANSELB5
#define channel_ANB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define channel_ANB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define channel_ANB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define channel_ANB5_GetValue()           PORTBbits.RB5
#define channel_ANB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define channel_ANB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define channel_ANB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define channel_ANB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define channel_ANB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define channel_ANB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define channel_ANB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define channel_ANB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set CSB aliases
#define CSB_TRIS                 TRISCbits.TRISC0
#define CSB_LAT                  LATCbits.LATC0
#define CSB_PORT                 PORTCbits.RC0
#define CSB_WPU                  WPUCbits.WPUC0
#define CSB_OD                   ODCONCbits.ODCC0
#define CSB_ANS                  ANSELCbits.ANSELC0
#define CSB_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define CSB_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define CSB_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define CSB_GetValue()           PORTCbits.RC0
#define CSB_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define CSB_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define CSB_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define CSB_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define CSB_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define CSB_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define CSB_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define CSB_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISCbits.TRISC1
#define RS_LAT                  LATCbits.LATC1
#define RS_PORT                 PORTCbits.RC1
#define RS_WPU                  WPUCbits.WPUC1
#define RS_OD                   ODCONCbits.ODCC1
#define RS_ANS                  ANSELCbits.ANSELC1
#define RS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RS_GetValue()           PORTCbits.RC1
#define RS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RS_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RS_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set CSSD aliases
#define CSSD_TRIS                 TRISCbits.TRISC2
#define CSSD_LAT                  LATCbits.LATC2
#define CSSD_PORT                 PORTCbits.RC2
#define CSSD_WPU                  WPUCbits.WPUC2
#define CSSD_OD                   ODCONCbits.ODCC2
#define CSSD_ANS                  ANSELCbits.ANSELC2
#define CSSD_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define CSSD_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define CSSD_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define CSSD_GetValue()           PORTCbits.RC2
#define CSSD_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define CSSD_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define CSSD_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define CSSD_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define CSSD_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define CSSD_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define CSSD_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define CSSD_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RELAY_RD0 aliases
#define RELAY_RD0_TRIS                 TRISDbits.TRISD0
#define RELAY_RD0_LAT                  LATDbits.LATD0
#define RELAY_RD0_PORT                 PORTDbits.RD0
#define RELAY_RD0_WPU                  WPUDbits.WPUD0
#define RELAY_RD0_OD                   ODCONDbits.ODCD0
#define RELAY_RD0_ANS                  ANSELDbits.ANSELD0
#define RELAY_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RELAY_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RELAY_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RELAY_RD0_GetValue()           PORTDbits.RD0
#define RELAY_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RELAY_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RELAY_RD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define RELAY_RD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define RELAY_RD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define RELAY_RD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define RELAY_RD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RELAY_RD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LED_MODE aliases
#define LED_MODE_TRIS                 TRISDbits.TRISD1
#define LED_MODE_LAT                  LATDbits.LATD1
#define LED_MODE_PORT                 PORTDbits.RD1
#define LED_MODE_WPU                  WPUDbits.WPUD1
#define LED_MODE_OD                   ODCONDbits.ODCD1
#define LED_MODE_ANS                  ANSELDbits.ANSELD1
#define LED_MODE_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED_MODE_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED_MODE_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED_MODE_GetValue()           PORTDbits.RD1
#define LED_MODE_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED_MODE_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED_MODE_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LED_MODE_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LED_MODE_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LED_MODE_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LED_MODE_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define LED_MODE_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set IO_00 aliases
#define IO_00_TRIS                 TRISDbits.TRISD4
#define IO_00_LAT                  LATDbits.LATD4
#define IO_00_PORT                 PORTDbits.RD4
#define IO_00_WPU                  WPUDbits.WPUD4
#define IO_00_OD                   ODCONDbits.ODCD4
#define IO_00_ANS                  ANSELDbits.ANSELD4
#define IO_00_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_00_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_00_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_00_GetValue()           PORTDbits.RD4
#define IO_00_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_00_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_00_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define IO_00_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define IO_00_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define IO_00_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define IO_00_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define IO_00_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set IO_01 aliases
#define IO_01_TRIS                 TRISDbits.TRISD5
#define IO_01_LAT                  LATDbits.LATD5
#define IO_01_PORT                 PORTDbits.RD5
#define IO_01_WPU                  WPUDbits.WPUD5
#define IO_01_OD                   ODCONDbits.ODCD5
#define IO_01_ANS                  ANSELDbits.ANSELD5
#define IO_01_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_01_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_01_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_01_GetValue()           PORTDbits.RD5
#define IO_01_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_01_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_01_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define IO_01_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define IO_01_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define IO_01_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define IO_01_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define IO_01_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set IO_10 aliases
#define IO_10_TRIS                 TRISDbits.TRISD6
#define IO_10_LAT                  LATDbits.LATD6
#define IO_10_PORT                 PORTDbits.RD6
#define IO_10_WPU                  WPUDbits.WPUD6
#define IO_10_OD                   ODCONDbits.ODCD6
#define IO_10_ANS                  ANSELDbits.ANSELD6
#define IO_10_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_10_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_10_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_10_GetValue()           PORTDbits.RD6
#define IO_10_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_10_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_10_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define IO_10_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define IO_10_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define IO_10_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define IO_10_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define IO_10_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set IO_11 aliases
#define IO_11_TRIS                 TRISDbits.TRISD7
#define IO_11_LAT                  LATDbits.LATD7
#define IO_11_PORT                 PORTDbits.RD7
#define IO_11_WPU                  WPUDbits.WPUD7
#define IO_11_OD                   ODCONDbits.ODCD7
#define IO_11_ANS                  ANSELDbits.ANSELD7
#define IO_11_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_11_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_11_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_11_GetValue()           PORTDbits.RD7
#define IO_11_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_11_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_11_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_11_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_11_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_11_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_11_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define IO_11_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set LED_RESET aliases
#define LED_RESET_TRIS                 TRISEbits.TRISE0
#define LED_RESET_LAT                  LATEbits.LATE0
#define LED_RESET_PORT                 PORTEbits.RE0
#define LED_RESET_WPU                  WPUEbits.WPUE0
#define LED_RESET_OD                   ODCONEbits.ODCE0
#define LED_RESET_ANS                  ANSELEbits.ANSELE0
#define LED_RESET_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED_RESET_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED_RESET_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED_RESET_GetValue()           PORTEbits.RE0
#define LED_RESET_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED_RESET_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED_RESET_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED_RESET_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED_RESET_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED_RESET_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED_RESET_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LED_RESET_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set LED_DB aliases
#define LED_DB_TRIS                 TRISEbits.TRISE2
#define LED_DB_LAT                  LATEbits.LATE2
#define LED_DB_PORT                 PORTEbits.RE2
#define LED_DB_WPU                  WPUEbits.WPUE2
#define LED_DB_OD                   ODCONEbits.ODCE2
#define LED_DB_ANS                  ANSELEbits.ANSELE2
#define LED_DB_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LED_DB_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LED_DB_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LED_DB_GetValue()           PORTEbits.RE2
#define LED_DB_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LED_DB_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LED_DB_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define LED_DB_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define LED_DB_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define LED_DB_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define LED_DB_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define LED_DB_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

// get/set IO_20 aliases
#define IO_20_TRIS                 TRISFbits.TRISF4
#define IO_20_LAT                  LATFbits.LATF4
#define IO_20_PORT                 PORTFbits.RF4
#define IO_20_WPU                  WPUFbits.WPUF4
#define IO_20_OD                   ODCONFbits.ODCF4
#define IO_20_ANS                  ANSELFbits.ANSELF4
#define IO_20_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define IO_20_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define IO_20_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define IO_20_GetValue()           PORTFbits.RF4
#define IO_20_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define IO_20_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define IO_20_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define IO_20_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define IO_20_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define IO_20_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define IO_20_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define IO_20_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set IO_21 aliases
#define IO_21_TRIS                 TRISFbits.TRISF5
#define IO_21_LAT                  LATFbits.LATF5
#define IO_21_PORT                 PORTFbits.RF5
#define IO_21_WPU                  WPUFbits.WPUF5
#define IO_21_OD                   ODCONFbits.ODCF5
#define IO_21_ANS                  ANSELFbits.ANSELF5
#define IO_21_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define IO_21_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define IO_21_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define IO_21_GetValue()           PORTFbits.RF5
#define IO_21_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define IO_21_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define IO_21_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define IO_21_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define IO_21_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define IO_21_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define IO_21_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define IO_21_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set IO_30 aliases
#define IO_30_TRIS                 TRISFbits.TRISF6
#define IO_30_LAT                  LATFbits.LATF6
#define IO_30_PORT                 PORTFbits.RF6
#define IO_30_WPU                  WPUFbits.WPUF6
#define IO_30_OD                   ODCONFbits.ODCF6
#define IO_30_ANS                  ANSELFbits.ANSELF6
#define IO_30_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define IO_30_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define IO_30_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define IO_30_GetValue()           PORTFbits.RF6
#define IO_30_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define IO_30_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define IO_30_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define IO_30_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define IO_30_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define IO_30_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define IO_30_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define IO_30_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)

// get/set IO_31 aliases
#define IO_31_TRIS                 TRISFbits.TRISF7
#define IO_31_LAT                  LATFbits.LATF7
#define IO_31_PORT                 PORTFbits.RF7
#define IO_31_WPU                  WPUFbits.WPUF7
#define IO_31_OD                   ODCONFbits.ODCF7
#define IO_31_ANS                  ANSELFbits.ANSELF7
#define IO_31_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define IO_31_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define IO_31_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define IO_31_GetValue()           PORTFbits.RF7
#define IO_31_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define IO_31_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define IO_31_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define IO_31_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define IO_31_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define IO_31_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define IO_31_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define IO_31_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);




#endif // PIN_MANAGER_H
/**
 End of File
*/