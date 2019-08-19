//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.c
// @Project       EPS_TestBench_20190620.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      Keil
//
// @Codegenerator 0.2
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          2019/8/7 14:58:25
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (MAIN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)
uword GPT1_T2_FLAG = 0;
uword GPT1_T3_FLAG = 0;
ubyte t_200ms = 0;				//Times Parameter	 t_200ms
uword vehicleCommand = 0;
uword VehicleSpeedVSOSig= 0;
ubyte t_5ms = 0;
uword t_1000ms = 0;
ubyte btnTrigNow = 0;
ubyte btnTrigLast = 0;
ubyte btnTrigUp = 0;
// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)
// hardware initial 
//	LED:P7.1 -> RED			>30 km/h
//			P7.2 -> GREEN		<15 km/h
//			P7.3 -> BLUE		15~30 km/h
	void hwInit(void)
	{
		P7_OUT_P1 = 0;
		P7_OUT_P2 = 0;
		P7_OUT_P3 = 0;
	}

// software initial 
//	VehicleSpeedVSOSig = 0km/h
	void swInit(void)
	{
			VehicleSpeedVSOSig = 0;
	}
	
//	LED display
//	LED:P7.1 -> RED			>40 km/h
//			P7.2 -> GREEN		<15 km/h
//			P7.3 -> BLUE		15~40 km/h
	void ledDisplay(void)
	{
		
			if(VehicleSpeedVSOSig <= 15 && VehicleSpeedVSOSig > 0)
			{
				P7_OUT_P2 = 0;		P7_OUT_P2 = 1;		P7_OUT_P3 = 0;
			}
			
			else if(VehicleSpeedVSOSig > 15 && VehicleSpeedVSOSig <=40 )
			{
				P7_OUT_P2 = 0;		P7_OUT_P2 = 0;		P7_OUT_P3 = 1;
			}
			else if(VehicleSpeedVSOSig > 40 && VehicleSpeedVSOSig <=55 )
			{
				P7_OUT_P2 = 1;		P7_OUT_P2 = 0;		P7_OUT_P3 = 0;
			}
			else
			{;}
	}
// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //   globally disable interrupts
  PSW_IEN        =  0;          


  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8.00 MHz
  ///  - system clock is 80.00 MHz

  MAIN_vUnlockProtecReg();     // unlock write security

  MAIN_vChangeFreq();          // load PLL control register

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the MultiCAN Module (CAN)
  CAN_vInit();


  //   -----------------------------------------------------------------------
  //   Initialization of the Bank Select registers:
  //   -----------------------------------------------------------------------


  // USER CODE BEGIN (Init,3)

  // USER CODE END

  MAIN_vLockProtecReg();       // lock write security

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x0000;                   // command 3

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x1800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCU_SLC = 0x8E00 | uwPASSWORD;      // command 4

} //  End of function MAIN_vLockProtecReg


//****************************************************************************
// @Function      void MAIN_vChangeFreq(void) 
//
//----------------------------------------------------------------------------
// @Description   This function is used to select the external crystal and
//                configure the system frequency to 80Mhz/66Mhz.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

// USER CODE BEGIN (ChangeFreq,1)

// USER CODE END

void MAIN_vChangeFreq(void)
{
  Scs_ErrorType Error;

  Scs_EnableHighPrecOsc(1U);

  //For application and internal application resets, the complete PLL configuration could be avoided
  //The entry from application resets and internal application reset is covered in the following differentiation
  //in int/ext clock in lock/unlocked state.

  if  ((SCU_PLLSTAT & 0x0004) == 0x0004)       // fR derived from Internal clock
  {
    //Normal startup state during boot and the clock
    //has to be in the next step configured on the external crystal
    //use XTAL/VCO, count XTAL clock

    Scs_InitTimer();       // initialize CCU6 timer T13 for SCS driver

    // perform transition from base mode to normal mode, check for error
    Error = Scs_GoFromBaseModeToNormalMode();
    if(Error)
    {
      for(;;)      // this part of code should not be reached
      {
        NOP();
      }
    }

    if ((SCU_PLLSTAT & 0x1009) == 0x1009)      // fR derived from external crystal clock + VCO is locked
    {
      //usually after an application reset where clock need not be configured again.
      //check K2/P/N values and decide whether these values have to be adapted based on application needs.
      NOP();
      //usually the PLL losss of Lock TRAP schould be enabled here.
    }
    else       //fR derived from external crystal clock + VCO is not locked
    {
               //estimate the K1 value and the current frequency
               //reduce K2/P/N values in steps so that the frequency
               //jumps is limited to 20MHz or factor of 5 whichever is minimum
      NOP();
    }


  }

} //  End of function MAIN_vChangeFreq


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

// USER CODE BEGIN (Main,1)

// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)

  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,3)
//	hwInit();
//	swInit();
		P7_IN_P2 = 1;
		btnTrigLast = 1;
  // USER CODE END

  while(1)
  {

   // USER CODE BEGIN (Main,4)	

			if(GPT1_T3_FLAG == 1)
			{// 5ms
				GPT1_T3_FLAG = 0;
				t_5ms++;	
				
				if(t_5ms > 200)
				{
						t_1000ms++;
						t_5ms = 0;
				}
				
				if(t_5ms % 10 == 1)
				{
						//50ms扫描一次键盘
						btnTrigNow = P7_IN_P2;
						//按键按下
						if(btnTrigNow == 0 && btnTrigLast == 1)
						{
								
						}
						//按键松开	
						else if(btnTrigNow == 1 && btnTrigLast == 0)
						{
								btnTrigUp = 1;
								t_1000ms = 0;
								GPT1_vStartTmr_GPT1_TIMER_2();
						}
						//按键连续按下
						else if(btnTrigNow == 0 && btnTrigLast == 0)
						{}
						//按键连续松开
						else if(btnTrigNow == 1 && btnTrigLast == 1)
						{}						
						else{}
							
						btnTrigLast = btnTrigNow;
						
				}
				//按键按下且过100s后，停止报文发送
				if(btnTrigUp == 1 && (t_1000ms > DELAYTIME))
				{
						btnTrigUp = 0;
						GPT1_vStopTmr_GPT1_TIMER_2();
						t_1000ms = 0;
				}
				
			}
			else
			{
			
			}
   // USER CODE END

  }

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END


