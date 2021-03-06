//****************************************************************************
// @Module        Universal Serial Interface Channel (USIC) U0C0
// @Filename      U0C0.h
// @Project       EPS_TestBench_20190620.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      Keil
//
// @Codegenerator 0.2
//
// @Description   This file contains all function prototypes and macros for 
//                the U0C0 module.
//
//----------------------------------------------------------------------------
// @Date          2019/7/19 13:56:57
//
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,1)

// USER CODE END



#ifndef _U0C0_H_
#define _U0C0_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (U0C0_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void U0C0_ASC_vInit(void);
void U0C0_ASC_vSendData(uword uwData);
uword U0C0_ASC_uwGetData(void);


// USER CODE BEGIN (U0C0_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define U0C0_0INT    0x50         // SR0 of U0C0


// USER CODE BEGIN (U0C0_Header,9)

// USER CODE END


#endif  // ifndef _U0C0_H_
