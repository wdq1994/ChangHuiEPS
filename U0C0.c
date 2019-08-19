//****************************************************************************
// @Module        Universal Serial Interface Channel (USIC) U0C0
// @Filename      U0C0.c
// @Project       EPS_TestBench_20190620.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      Keil
//
// @Codegenerator 0.2
//
// @Description   This file contains functions that use the U0C0 module.
//
//----------------------------------------------------------------------------
// @Date          2019/7/19 13:56:57
//
//****************************************************************************

// USER CODE BEGIN (U0C0_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (U0C0_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (U0C0_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (U0C0_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (U0C0_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (U0C0_General,8)
extern vehicelCommand;
// USER CODE END




//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (U0C0_General,9)

// USER CODE END


//****************************************************************************
// @Function      void U0C0_ASC_vInit(void)
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the U0C0 function
//                library. It is assumed that the SFRs used by this library
//                are in reset state.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/7/19
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void U0C0_ASC_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  U0C0 ASC is configured for Full-Duplex Operation Mode:
  ///  -----------------------------------------------------------------------

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Fractional Divider:
  ///  -----------------------------------------------------------------------
  ///  - The Fractional divider is selected
  ///  - The step value STEP = 613

  U0C0_FDRL      =  0x8265;      // load U0C0 fractional divider register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Baudrate Generator:
  ///  -----------------------------------------------------------------------
  ///  - The selected BaudRate is 57.600 kbaud
  ///  - The PreDivider for CTQ, PCTQ = 1
  ///  - The Denominator for CTQ, DCTQ = 15
  ///  - The Divider factor PDIV = 25

  U0C0_BRGL      =  0x3D00;      // load U0C0 load baud rate generator 
                                 // register L

  U0C0_BRGH      =  0x0019;      // load U0C0 load baud rate generator 
                                 // register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Input Control Register 0:
  ///  -----------------------------------------------------------------------
  ///  - The data input DX0F is selected for pin - P2.4

  U0C0_DX0CR     =  0x0005;      // load U0C0 input control register(Data)

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Interrupt Node Pointer Register:
  ///  -----------------------------------------------------------------------
  ///  - RINP pointer points to Interrupt node U0C0_0IC

  U0C0_INPRL     =  0x0000;      // load U0C0 Interrupt Node Pointer register 
                                 // L
  U0C0_INPRH     =  0x0000;      // load U0C0 Interrupt Node Pointer register 
                                 // H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Shift Control:
  ///  -----------------------------------------------------------------------
  ///  - Transmit/Receive LSB first is selected
  ///  - Transmission Mode (TRM) = 1
  ///  - Passive Data Level (PDL) = 1

  U0C0_SCTRL     =  0x0102;      // load U0C0 shift control register L

  ///  - Word Length (WLE) = 7
  ///  - Frame Length (FLE) = 7

  U0C0_SCTRH     =  0x0707;      // load U0C0 shift control register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Transmit Control/Status Register:
  ///  -----------------------------------------------------------------------
  ///  - TBUF Data Enable (TDEN) = 1
  ///  - TBUF Data Single Shot Mode (TDSSM) = 1

  U0C0_TCSRL     =  0x0500;      // load U0C0 transmit control/status 
                                 // register L
  U0C0_TCSRH     =  0x0000;      // load U0C0 transmit control/status 
                                 // register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Protocol Control Register:
  ///  -----------------------------------------------------------------------
  ///  - Sample Mode (SMD) = 1
  ///  - 1 Stop bit is selected
  ///  - Sample Point (SP) = 7
  ///  - Pulse Length (PL) = 0

  U0C0_PCRL      =  0x0701;      // load U0C0 protocol control register L
  U0C0_PCRH      =  0x0000;      // load U0C0 protocol control register H

  ///  -----------------------------------------------------------------------
  ///  Configuration of the U0C0 Protocol Status Register:
  ///  -----------------------------------------------------------------------
  ///  - TBIF is set to simplify polling

  U0C0_PSR      |=  0x2000;      // load U0C0 protocol status register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used U0C0 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  U0C00IC service request node configuration:
  ///  - U0C00IC interrupt priority level (ILVL) = 5
  ///  - U0C00IC interrupt group level (GLVL) = 0
  ///  - U0C00IC group priority extension (GPX) = 0

  U0C0_0IC       =  0x0054;     

  ///  -----------------------------------------------------------------------
  ///  Configuration of U0C0 FIFO:
  ///  -----------------------------------------------------------------------
  ///  -----------------------------------------------------------------------
  ///  Configuration of U0C0 Transmitter Buffer Conrol Register:
  ///  -----------------------------------------------------------------------
  ///  - Transmit FIFO buffer is disabled
  ///  -----------------------------------------------------------------------
  ///  Configuration of U0C0 Receiver Buffer Conrol Register:
  ///  -----------------------------------------------------------------------
  ///  - Receive FIFO buffer is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used U0C0 Port Pins:
  ///  -----------------------------------------------------------------------
  P2_IOCR04      =  0x0020;      // load port register for data input

  ///  - P2.3 is used for USIC0 Channel0 Shift Data Output(DOUT)

  P2_IOCR03 = 0x0090;    //set direction register



  // USER CODE BEGIN (U0C0_Function,3)

  // USER CODE END



} //  End of function U0C0_ASC_vInit


//****************************************************************************
// @Function      void U0C0_ASC_vSendData(uword uwData) 
//
//----------------------------------------------------------------------------
// @Description   This function clears the transmit buffer Indication flag 
//                first  & then writes the send data initialization word into 
//                the transmit buffer register.
//                
//                Note: 
//                In a multiprocessor system the master with this function 
//                has the possibility to send data to the selected slave.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    uwData: 
//                Data to be send
//
//----------------------------------------------------------------------------
// @Date          2019/7/19
//
//****************************************************************************

// USER CODE BEGIN (ASCSendData,1)

// USER CODE END

void U0C0_ASC_vSendData(uword uwData)
{

  while(!(U0C0_PSR & 0x2000));   //  wait until tx buffer indication flag is set

  U0C0_PSCR     |= 0x2000;   //  clear transmit buffer indication flag
  U0C0_TBUF00    = uwData;   //  load transmit buffer register

} //  End of function U0C0_ASC_vSendData


//****************************************************************************
// @Function      uword U0C0_ASC_uwGetData(void) 
//
//----------------------------------------------------------------------------
// @Description   This function reads out the content of the receive buffer 
//                register which contains the received data.
//
//----------------------------------------------------------------------------
// @Returnvalue   Data that has been received
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/7/19
//
//****************************************************************************

// USER CODE BEGIN (ASCGetData,1)

// USER CODE END

uword U0C0_ASC_uwGetData(void)
{

  return(U0C0_RBUF);         // return receive buffer register


} //  End of function U0C0_ASC_uwGetData


//****************************************************************************
// @Function      void U0C0_ASC_vi0IC(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the Service 
//                Request Node U0C0_0IC.
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2019/7/19
//
//****************************************************************************

// USER CODE BEGIN (ASC0IC,1)

// USER CODE END

void U0C0_ASC_vi0IC(void) interrupt U0C0_0INT
{

  // USER CODE BEGIN (ASC0IC,2)

  // USER CODE END

  if (U0C0_PSR & 0x4000)         // Receive interrupt flag
  {

  // USER CODE BEGIN (ASC0IC,4)
		
	CAN_T_MO3();
  // USER CODE END

  U0C0_PSCR   |= 0x4000;         // clear PSR_RIF
  }

  // USER CODE BEGIN (ASC0IC,15)

  // USER CODE END

} //  End of function U0C0_ASC_vi0IC




// USER CODE BEGIN (U0C0_General,10)

// USER CODE END

