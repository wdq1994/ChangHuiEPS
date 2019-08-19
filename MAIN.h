//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.h
// @Project       EPS_TestBench_20190620.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      Keil
//
// @Codegenerator 0.2
//
// @Description   This file contains all function prototypes and macros for 
//                the MAIN module.
//
//----------------------------------------------------------------------------
// @Date          2019/8/7 14:58:25
//
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,1)

// USER CODE END



#ifndef _MAIN_H_
#define _MAIN_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************
#define KEIL

#define SEG(func) (unsigned int)(((unsigned long)((void (far*)(void))func) >> 16))
#define SOF(func) (unsigned int)(((void (far *) (void))func))

// USER CODE BEGIN (MAIN_Header,4)
//  定义延时时间
#define  DELAYTIME		100			//单位：秒


// 	Engine Signal
#define EMS_ENGINESPEEDRPM_PHY				1000														//Physical Engine Rotate Speed			RPM
#define EMS_ENGINESPEEDRPM						((uword)(4*EMS_ENGINESPEEDRPM_PHY))
#define EMS_ENGINERUNNINGSTATUS				1																		//Engine Rotate Speed Valid Bit


//	Vehicle Speed	Signal
#define	VEHICLESPEEDVSOSIG_PHY  5
#define VEHICLESPEEDVSOSIG						((uword)(VEHICLESPEEDVSOSIG_PHY / 0.05625))	//Vehicle Speed						Km/h
#define VEHICLESPEEDSOSIGVALIDDATA		7																		//Vehicle Speed Signal Valid Bit(Include FR FL)
// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************


void MAIN_vUnlockProtecReg(void);

void MAIN_vLockProtecReg(void);

void MAIN_vChangeFreq(void);


// USER CODE BEGIN (MAIN_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

// USER CODE BEGIN (MAIN_Header,9)

// USER CODE END


//****************************************************************************
// @Project Includes
//****************************************************************************

#include <Intrins.h>

#include  "XC23xxBREGS.H"
#include  "SCS.h"

#include  "IO.h"
#include  "GPT1.h"
#include  "GPT2.h"
#include  "CAN.h"

// USER CODE BEGIN (MAIN_Header,10)

// USER CODE END


#endif  // ifndef _MAIN_H_
