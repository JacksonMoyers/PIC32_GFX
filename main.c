//*******************************************************************//
// File: main.c                                                      //
// Author: Thomas Mindenhall                                         //
// Project: Backpack Buddy                                           //
// MCU: PIC32MX270F256B                                              //
// Compiler: XC32 2.00                                               //
//                                                                   //
// Description: Main program                                         //
//                                                                   //
//*******************************************************************// 


///////////////////////////////////////////////////////////////////////////////
//*****************************Includes**************************************//
///////////////////////////////////////////////////////////////////////////////
#include <xc.h>
#include <sys/attribs.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Config.h"
#include "EUSART.h"
#include "I2C.h"
#include "ILI9341.h"
#include "SPI.h"
#include "FONT.h"
#include "BNO055.h"
#include "MT3339.h"

////////////////////////////////////////////////////////////////////////////////
//*****************************Prototypes*************************************//
////////////////////////////////////////////////////////////////////////////////
void Boot_Message(void);
void Done_Message(void);

////////////////////////////////////////////////////////////////////////////////
//*********************************GLOBALS************************************//
////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
char TFT_BUFF[50];
=======
uint8_t c;
uint8_t str_buffer_msg[] = "UART 1 Configured\r\n";
//NMEA Strings
uint16_t i;
uint32_t distance;
uint16_t delta_t;
>>>>>>> ddc3f5fc1af51ba063db23a2ed1e63ac9fb108d3

////////////////////////////////////////////////////////////////////////////////
//*******************************MAIN FUNCTION********************************//
////////////////////////////////////////////////////////////////////////////////
int main(void) {
    //Config Functions
    //Inits
    InitSystem();
    SPI1_Init();
//    UART_1_Init(9600);

    
    TFT_Init();
    TFT_SetDotSize(0);
    TFT_SetFont(Courier_New_Bold_20,1);
    
    
    //Begin Processing
<<<<<<< HEAD
   
    TFT_Line(0,160,240,160,WHITE);
    TFT_Line(120,0,120,320,WHITE);
    TFT_Circle(120,160,119,WHITE);
   // sprintf(TFT_BUFF, "Hello World!" );
   // TFT_Text(TFT_BUFF,0,40,WHITE,BLACK);
    TFT_Vector(120,160,40,45);
    TFT_Vector(148,132,40,90);
    TFT_Vector(148,92,40,180);
 //   TFT_Vector()
   


  
    
    while(1){
       
    }
=======
    BNO_Init();
    BNO_Cal_Routine();
    //TFT_FillScreen(BLACK);
    Timer_1_Init();
    int32_t c = 0;
    double test_heading;
    while (1) {
    /**************************************************************************/ 
        test_heading = Get_Tilt_Heading();
        sprintf(buffer_1, "Tilt Heading: %f\r\n", test_heading);
        Send_String_U1(buffer_1);
        Get_Orientation();
        sprintf(buffer_1, "H: %d\r\n",eul_heading);
        Send_String_U1(buffer_1);
        //sprintf(buffer_1, "R: %d\r\n",eul_roll);
        //Send_String_U1(buffer_1);
        //sprintf(buffer_1, "P: %d\r\n",eul_pitch);
        //Send_String_U1(buffer_1);
        Delay_ms(500);
        //BNO_Cal_Routine();
        if(NMEA_Flag){
            sprintf(buffer_1,"%c : %d\r",NMEA_Xfer_Buff[nmea_index],nmea_index);
            Send_String_U1(buffer_1);
            GPS_String_Handler(); //puts characters into Xfer Buffer
            rx_nmea = 0;
        }
>>>>>>> ddc3f5fc1af51ba063db23a2ed1e63ac9fb108d3
        
   /***************************************************************************/    
    
}


////////////////////////////////////////////////////////////////////////////////
//*******************************FUNCTIONS************************************//
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 * Description: Sends a booting message to TFT Screen.
 * 
 * Inputs: NULL (VOID).
 * 
 * Returns: NULL (VOID).
 ******************************************************************************/
void Boot_Message(void){
    sprintf(buffer_1,"Booting...");
    TFT_Text(buffer_1, 20, 20, WHITE, BLACK);
}

/******************************************************************************
 * Description: Sends a done message to TFT Screen.
 * 
 * Inputs: NULL (VOID).
 * 
 * Returns: NULL (VOID).
 ******************************************************************************/
void Done_Message(void){
    sprintf(buffer_1,"Done...");
    TFT_Text(buffer_1, 20, 20, BLACK, WHITE);
}


/*******************************************************************************
 End of File
 */
