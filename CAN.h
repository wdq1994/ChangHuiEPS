//****************************************************************************
// @Module        MultiCAN Module (CAN)
// @Filename      CAN.h
// @Project       EPS_TestBench_20190620.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      Keil
//
// @Codegenerator 0.2
//
// @Description   This file contains all function prototypes and macros for 
//                the CAN module.
//
//----------------------------------------------------------------------------
// @Date          2019/8/7 14:58:27
//
//****************************************************************************

// USER CODE BEGIN (CAN_Header,1)

// USER CODE END

/*
******************************************************************************
@Note

MO2:发动机报文
MO3:车速报文

******************************************************************************
*/


#ifndef _CAN_H_
#define _CAN_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CAN_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

#define SetListCommand(ValueH, ValueL) CAN_PANCTRH = ValueH; CAN_PANCTRL = ValueL; while(CAN_PANCTRL & CAN_PANCTR_BUSY);

// USER CODE BEGIN (CAN_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

 // Panel Busy Flag
 #define CAN_PANCTR_BUSY       0x0100

 // Message Object Status Register
 #define MOSTAT_RXPND          0x0001
 #define MOSTAT_TXPND          0x0002
 #define MOSTAT_NEWDAT         0x0008
 #define MOSTAT_MSGLST         0x0010
 #define MOSTAT_RST_MNR        0x0019
 #define MOSTAT_RST_NT         0x000A



 // Structure for a single MultiCAN object
 // A total of 64 such object structures exists

 struct stCanObj
 {
   uword  uwMOFCRL;    // Function Control Register Low
   uword  uwMOFCRH;    // Function Control Register High
   uword  uwMOFGPRL;   // FIFO/Gateway Pointer Register Low
   uword  uwMOFGPRH;   // FIFO/Gateway Pointer Register High
   uword  uwMOIPRL;    // Interrupt Pointer Register Low
   uword  uwMOIPRH;    // Interrupt Pointer Register High
   uword  uwMOAMRL;    // Acceptance Mask Register Low
   uword  uwMOAMRH;    // Acceptance Mask Register High
   ubyte  ubData[8];   // Message Data 0..7
   uword  uwMOARL;     // Arbitration Register Low
   uword  uwMOARH;     // Arbitration Register High
   uword  uwMOCTRL;    // Control Register Low
   uword  uwMOCTRH;    // Control Register High
 };

 #define CAN_HWOBJ ((struct stCanObj volatile far*) 0x201000)

// USER CODE BEGIN (CAN_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

 ///  -------------------------------------------------------------------------
 ///  @Definition of a structure for the CAN data
 ///  -------------------------------------------------------------------------

 // The following data type serves as a software message object. Each access to
 // a hardware message object has to be made by forward a pointer to a software
 // message object (MCAN_SWObj). The data type has the following fields:
 //
 // ubMOCfg:
 // this byte contains the 'Data Lenght Code(DLC)', 
 // 'Identifier Extension bit(IDE) - if 0 standard frame, else 1 extended frame', 
 // 'Message Direction(DIR) - if 0 receive Object, else 1 transmit Object'
 // 'Acceptance Mask bit(MIDE) - if 0 receives both, else 1 receives matching IDE'
 //
 //
 //         7     6     5     4     3     2     1     0
 //      |-----------------------------------------------|
 //      |     | MIDE |IDE | DIR |          DLC          |
 //      |-----------------------------------------------|
 //
 // ulID:
 // this field is four bytes long and contains either the 11-bit identifier
 // or the 29-bit identifier
 //
 // ulMask:
 // this field is four bytes long and contains either the 11-bit mask
 // or the 29-bit mask
 //
 // ubData[8]:
 // 8 bytes containing the data of a frame
 //
 // uwCounter:
 // this field is two bytes long and contains the counter value
 //

 typedef struct
 {
     ubyte ubMOCfg;    // message object configuration
     ulong ulID;       // standard (11-bit)/extended (29-bit) identifier
     ulong ulMask;     // standard (11-bit)/extended (29-bit) mask
     ubyte ubData[8];  // 8-bit data bytes
     uword uwCounter;  // frame counter(MOIPRnH[15-0])
 }stCAN_SWObj;


// USER CODE BEGIN (CAN_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CAN_vInit(void);
void CAN_vGetMsgObj(ubyte ubObjNr, stCAN_SWObj *pstObj);
void CAN_vTransmit(ubyte ubObjNr);
void CAN_vConfigMsgObj(ubyte ubObjNr, stCAN_SWObj *pstObj);
void CAN_vLoadData(ubyte ubObjNr, ubyte *ubpubData);



// USER CODE BEGIN (CAN_Header,8)
void CAN_T_MO2(void);
void CAN_T_MO3(void);
// USER CODE END


//****************************************************************************
// @Macro         CAN_ubRequestMsgObj(ObjNr) 
//
//----------------------------------------------------------------------------
// @Description   If a TRANSMIT OBJECT is to be reconfigured it must first be 
//                accessed. The access to the transmit object is exclusive. 
//                This function checks whether the choosen message object is 
//                still executing a transmit request, or if the object can be 
//                accessed exclusively.
//                After the message object is reserved, it can be 
//                reconfigured by using the function CAN_vConfigMsgObj or 
//                CAN_vLoadData.
//                Both functions enable access to the object for the CAN 
//                controller. 
//                By calling the function CAN_vTransmit transfering of data 
//                is started.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 message object is busy (a transfer is active), else 1
//
//----------------------------------------------------------------------------
// @Parameters    ObjNr: 
//                Number of the message object (0-63)
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

#define CAN_ubRequestMsgObj(ObjNr) (((CAN_HWOBJ[ObjNr].uwMOCTRL & 0x0100) == 0x0000) \
   ? CAN_HWOBJ[ObjNr].uwMOCTRL = 0x0020, 1 : 0)


//****************************************************************************
// @Macro         CAN_ubNewData(ObjNr) 
//
//----------------------------------------------------------------------------
// @Description   This function checks whether the selected RECEIVE OBJECT 
//                has received a new message. If so the function returns the 
//                value '1'.
//
//----------------------------------------------------------------------------
// @Returnvalue   1 the message object has received a new message, else 0
//
//----------------------------------------------------------------------------
// @Parameters    ObjNr: 
//                Number of the message object (0-63)
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

#define CAN_ubNewData(ObjNr) (((CAN_HWOBJ[ObjNr].uwMOCTRL & 0x0008) == 0x0008) \
   ? 1 : 0)


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************


// USER CODE BEGIN (CAN_Header,9)

// USER CODE END


#endif  // ifndef _CAN_H_
