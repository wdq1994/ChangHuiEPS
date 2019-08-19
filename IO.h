//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.c
// @Project       EPS_TestBench_20190620.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      Keil
//
// @Codegenerator 0.2
//
// @Description   This file contains all function prototypes and macros for 
//                the IO module.
//
//----------------------------------------------------------------------------
// @Date          2019/8/7 14:58:27
//
//****************************************************************************

// USER CODE BEGIN (IO_Header,1)

// USER CODE END



#ifndef _IO_H_
#define _IO_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (IO_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

#define IO_NO_PULL    0x00
#define IO_PULL_DOWN  0x01
#define IO_PULL_UP    0x02
#define IO_LOOP_BACK  0x03
#define IO_INVERTED_NO_PULL     0x04
#define IO_INVERTED_PULL_DOWN   0x05
#define IO_INVERTED_PULL_UP     0x06
#define IO_INVERTED_LOOP_BACK   0x07
#define IO_PUSH_PULL   0x08
#define IO_OPEN_DRAIN  0x0C
//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------

#define IO_P0_0       P0_OUT_P0
#define IO_P0_1       P0_OUT_P1
#define IO_P0_2       P0_OUT_P2
#define IO_P0_3       P0_OUT_P3
#define IO_P0_4       P0_OUT_P4
#define IO_P0_5       P0_OUT_P5
#define IO_P0_6       P0_OUT_P6
#define IO_P0_7       P0_OUT_P7

#define IO_P1_0       P1_OUT_P0
#define IO_P1_1       P1_OUT_P1
#define IO_P1_2       P1_OUT_P2
#define IO_P1_3       P1_OUT_P3
#define IO_P1_4       P1_OUT_P4
#define IO_P1_5       P1_OUT_P5
#define IO_P1_6       P1_OUT_P6
#define IO_P1_7       P1_OUT_P7

#define IO_P2_0       P2_OUT_P0
#define IO_P2_1       P2_OUT_P1
#define IO_P2_2       P2_OUT_P2
#define IO_P2_3       P2_OUT_P3
#define IO_P2_4       P2_OUT_P4
#define IO_P2_5       P2_OUT_P5
#define IO_P2_6       P2_OUT_P6
#define IO_P2_7       P2_OUT_P7
#define IO_P2_8       P2_OUT_P8
#define IO_P2_9       P2_OUT_P9
#define IO_P2_10       P2_OUT_P10
#define IO_P2_11       P2_OUT_P11
#define IO_P2_12       P2_OUT_P12
#define IO_P2_13       P2_OUT_P13

#define IO_P4_0       P4_OUT_P0
#define IO_P4_1       P4_OUT_P1
#define IO_P4_2       P4_OUT_P2
#define IO_P4_3       P4_OUT_P3


#define IO_P6_0       P6_OUT_P0
#define IO_P6_1       P6_OUT_P1
#define IO_P6_2       P6_OUT_P2

#define IO_P7_0       P7_OUT_P0
#define IO_P7_1       P7_OUT_P1
#define IO_P7_2       P7_OUT_P2
#define IO_P7_3       P7_OUT_P3
#define IO_P7_4       P7_OUT_P4

#define IO_P10_0       P10_OUT_P0
#define IO_P10_1       P10_OUT_P1
#define IO_P10_2       P10_OUT_P2
#define IO_P10_3       P10_OUT_P3
#define IO_P10_4       P10_OUT_P4
#define IO_P10_5       P10_OUT_P5
#define IO_P10_6       P10_OUT_P6
#define IO_P10_7       P10_OUT_P7
#define IO_P10_8       P10_OUT_P8
#define IO_P10_9       P10_OUT_P9
#define IO_P10_10       P10_OUT_P10
#define IO_P10_11       P10_OUT_P11
#define IO_P10_12       P10_OUT_P12
#define IO_P10_13       P10_OUT_P13
#define IO_P10_14       P10_OUT_P14
#define IO_P10_15       P10_OUT_P15



//----------------------------------------------------------------------------
// Defines used by DAvE
//----------------------------------------------------------------------------

#define INIO_P0_0       P0_IN_P0
#define INIO_P0_1       P0_IN_P1
#define INIO_P0_2       P0_IN_P2
#define INIO_P0_3       P0_IN_P3
#define INIO_P0_4       P0_IN_P4
#define INIO_P0_5       P0_IN_P5
#define INIO_P0_6       P0_IN_P6
#define INIO_P0_7       P0_IN_P7

#define SETIO_P0_0       P0_OMRL = 0x0001
#define SETIO_P0_1       P0_OMRL = 0x0002
#define SETIO_P0_2       P0_OMRL = 0x0004
#define SETIO_P0_3       P0_OMRL = 0x0008
#define SETIO_P0_4       P0_OMRL = 0x0010
#define SETIO_P0_5       P0_OMRL = 0x0020
#define SETIO_P0_6       P0_OMRL = 0x0040
#define SETIO_P0_7       P0_OMRL = 0x0080


#define CLEARIO_P0_0       P0_OMRL = 0x0100
#define CLEARIO_P0_1       P0_OMRL = 0x0200
#define CLEARIO_P0_2       P0_OMRL = 0x0400
#define CLEARIO_P0_3       P0_OMRL = 0x0800
#define CLEARIO_P0_4       P0_OMRL = 0x1000
#define CLEARIO_P0_5       P0_OMRL = 0x2000
#define CLEARIO_P0_6       P0_OMRL = 0x4000
#define CLEARIO_P0_7       P0_OMRL = 0x8000


#define TOGGLEIO_P0_0       P0_OMRL = 0x0101
#define TOGGLEIO_P0_1       P0_OMRL = 0x0202
#define TOGGLEIO_P0_2       P0_OMRL = 0x0404
#define TOGGLEIO_P0_3       P0_OMRL = 0x0808
#define TOGGLEIO_P0_4       P0_OMRL = 0x1010
#define TOGGLEIO_P0_5       P0_OMRL = 0x2020
#define TOGGLEIO_P0_6       P0_OMRL = 0x4040
#define TOGGLEIO_P0_7       P0_OMRL = 0x8080


#define CONTROLIO_P0_0(Mode)       P0_IOCR00 = (P0_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_1(Mode)       P0_IOCR01 = (P0_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_2(Mode)       P0_IOCR02 = (P0_IOCR02 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_3(Mode)       P0_IOCR03 = (P0_IOCR03 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_4(Mode)       P0_IOCR04 = (P0_IOCR04 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_5(Mode)       P0_IOCR05 = (P0_IOCR05 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_6(Mode)       P0_IOCR06 = (P0_IOCR06 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P0_7(Mode)       P0_IOCR07 = (P0_IOCR07 & 0xFF0F) | (Mode << 4)

#define INIO_P1_0       P1_IN_P0
#define INIO_P1_1       P1_IN_P1
#define INIO_P1_2       P1_IN_P2
#define INIO_P1_3       P1_IN_P3
#define INIO_P1_4       P1_IN_P4
#define INIO_P1_5       P1_IN_P5
#define INIO_P1_6       P1_IN_P6
#define INIO_P1_7       P1_IN_P7

#define SETIO_P1_0       P1_OMRL = 0x0001
#define SETIO_P1_1       P1_OMRL = 0x0002
#define SETIO_P1_2       P1_OMRL = 0x0004
#define SETIO_P1_3       P1_OMRL = 0x0008
#define SETIO_P1_4       P1_OMRL = 0x0010
#define SETIO_P1_5       P1_OMRL = 0x0020
#define SETIO_P1_6       P1_OMRL = 0x0040
#define SETIO_P1_7       P1_OMRL = 0x0080


#define CLEARIO_P1_0       P1_OMRL = 0x0100
#define CLEARIO_P1_1       P1_OMRL = 0x0200
#define CLEARIO_P1_2       P1_OMRL = 0x0400
#define CLEARIO_P1_3       P1_OMRL = 0x0800
#define CLEARIO_P1_4       P1_OMRL = 0x1000
#define CLEARIO_P1_5       P1_OMRL = 0x2000
#define CLEARIO_P1_6       P1_OMRL = 0x4000
#define CLEARIO_P1_7       P1_OMRL = 0x8000


#define TOGGLEIO_P1_0       P1_OMRL = 0x0101
#define TOGGLEIO_P1_1       P1_OMRL = 0x0202
#define TOGGLEIO_P1_2       P1_OMRL = 0x0404
#define TOGGLEIO_P1_3       P1_OMRL = 0x0808
#define TOGGLEIO_P1_4       P1_OMRL = 0x1010
#define TOGGLEIO_P1_5       P1_OMRL = 0x2020
#define TOGGLEIO_P1_6       P1_OMRL = 0x4040
#define TOGGLEIO_P1_7       P1_OMRL = 0x8080


#define CONTROLIO_P1_0(Mode)       P1_IOCR00 = (P1_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_1(Mode)       P1_IOCR01 = (P1_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_2(Mode)       P1_IOCR02 = (P1_IOCR02 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_3(Mode)       P1_IOCR03 = (P1_IOCR03 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_4(Mode)       P1_IOCR04 = (P1_IOCR04 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_5(Mode)       P1_IOCR05 = (P1_IOCR05 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_6(Mode)       P1_IOCR06 = (P1_IOCR06 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P1_7(Mode)       P1_IOCR07 = (P1_IOCR07 & 0xFF0F) | (Mode << 4)

#define INIO_P2_0       P2_IN_P0
#define INIO_P2_1       P2_IN_P1
#define INIO_P2_2       P2_IN_P2
#define INIO_P2_3       P2_IN_P3
#define INIO_P2_4       P2_IN_P4
#define INIO_P2_5       P2_IN_P5
#define INIO_P2_6       P2_IN_P6
#define INIO_P2_7       P2_IN_P7
#define INIO_P2_8       P2_IN_P8
#define INIO_P2_9       P2_IN_P9
#define INIO_P2_10       P2_IN_P10
#define INIO_P2_11       P2_IN_P11
#define INIO_P2_12       P2_IN_P12
#define INIO_P2_13       P2_IN_P13

#define SETIO_P2_0       P2_OMRL = 0x0001
#define SETIO_P2_1       P2_OMRL = 0x0002
#define SETIO_P2_2       P2_OMRL = 0x0004
#define SETIO_P2_3       P2_OMRL = 0x0008
#define SETIO_P2_4       P2_OMRL = 0x0010
#define SETIO_P2_5       P2_OMRL = 0x0020
#define SETIO_P2_6       P2_OMRL = 0x0040
#define SETIO_P2_7       P2_OMRL = 0x0080

#define SETIO_P2_8       P2_OMRH = 0x0001
#define SETIO_P2_9       P2_OMRH = 0x0002
#define SETIO_P2_10       P2_OMRH = 0x0004
#define SETIO_P2_11       P2_OMRH = 0x0008
#define SETIO_P2_12       P2_OMRH = 0x0010
#define SETIO_P2_13       P2_OMRH = 0x0020

#define CLEARIO_P2_0       P2_OMRL = 0x0100
#define CLEARIO_P2_1       P2_OMRL = 0x0200
#define CLEARIO_P2_2       P2_OMRL = 0x0400
#define CLEARIO_P2_3       P2_OMRL = 0x0800
#define CLEARIO_P2_4       P2_OMRL = 0x1000
#define CLEARIO_P2_5       P2_OMRL = 0x2000
#define CLEARIO_P2_6       P2_OMRL = 0x4000
#define CLEARIO_P2_7       P2_OMRL = 0x8000

#define CLEARIO_P2_8       P2_OMRH = 0x0100
#define CLEARIO_P2_9       P2_OMRH = 0x0200
#define CLEARIO_P2_10       P2_OMRH = 0x0400
#define CLEARIO_P2_11       P2_OMRH = 0x0800
#define CLEARIO_P2_12       P2_OMRH = 0x1000
#define CLEARIO_P2_13       P2_OMRH = 0x2000

#define TOGGLEIO_P2_0       P2_OMRL = 0x0101
#define TOGGLEIO_P2_1       P2_OMRL = 0x0202
#define TOGGLEIO_P2_2       P2_OMRL = 0x0404
#define TOGGLEIO_P2_3       P2_OMRL = 0x0808
#define TOGGLEIO_P2_4       P2_OMRL = 0x1010
#define TOGGLEIO_P2_5       P2_OMRL = 0x2020
#define TOGGLEIO_P2_6       P2_OMRL = 0x4040
#define TOGGLEIO_P2_7       P2_OMRL = 0x8080

#define TOGGLEIO_P2_8       P2_OMRH = 0x0101
#define TOGGLEIO_P2_9       P2_OMRH = 0x0202
#define TOGGLEIO_P2_10       P2_OMRH = 0x0404
#define TOGGLEIO_P2_11       P2_OMRH = 0x0808
#define TOGGLEIO_P2_12       P2_OMRH = 0x1010
#define TOGGLEIO_P2_13       P2_OMRH = 0x2020

#define CONTROLIO_P2_0(Mode)       P2_IOCR00 = (P2_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_1(Mode)       P2_IOCR01 = (P2_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_2(Mode)       P2_IOCR02 = (P2_IOCR02 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_3(Mode)       P2_IOCR03 = (P2_IOCR03 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_4(Mode)       P2_IOCR04 = (P2_IOCR04 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_5(Mode)       P2_IOCR05 = (P2_IOCR05 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_6(Mode)       P2_IOCR06 = (P2_IOCR06 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_7(Mode)       P2_IOCR07 = (P2_IOCR07 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_8(Mode)       P2_IOCR08 = (P2_IOCR08 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_9(Mode)       P2_IOCR09 = (P2_IOCR09 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_10(Mode)       P2_IOCR10 = (P2_IOCR10 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_11(Mode)       P2_IOCR11 = (P2_IOCR11 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_12(Mode)       P2_IOCR12 = (P2_IOCR12 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P2_13(Mode)       P2_IOCR13 = (P2_IOCR13 & 0xFF0F) | (Mode << 4)

#define INIO_P4_0       P4_IN_P0
#define INIO_P4_1       P4_IN_P1
#define INIO_P4_2       P4_IN_P2
#define INIO_P4_3       P4_IN_P3

#define SETIO_P4_0       P4_OMRL = 0x0001
#define SETIO_P4_1       P4_OMRL = 0x0002
#define SETIO_P4_2       P4_OMRL = 0x0004
#define SETIO_P4_3       P4_OMRL = 0x0008


#define CLEARIO_P4_0       P4_OMRL = 0x0100
#define CLEARIO_P4_1       P4_OMRL = 0x0200
#define CLEARIO_P4_2       P4_OMRL = 0x0400
#define CLEARIO_P4_3       P4_OMRL = 0x0800


#define TOGGLEIO_P4_0       P4_OMRL = 0x0101
#define TOGGLEIO_P4_1       P4_OMRL = 0x0202
#define TOGGLEIO_P4_2       P4_OMRL = 0x0404
#define TOGGLEIO_P4_3       P4_OMRL = 0x0808


#define CONTROLIO_P4_0(Mode)       P4_IOCR00 = (P4_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P4_1(Mode)       P4_IOCR01 = (P4_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P4_2(Mode)       P4_IOCR02 = (P4_IOCR02 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P4_3(Mode)       P4_IOCR03 = (P4_IOCR03 & 0xFF0F) | (Mode << 4)

#define INIO_P5_0       P5_IN_P0
#define INIO_P5_2       P5_IN_P2
#define INIO_P5_3       P5_IN_P3
#define INIO_P5_4       P5_IN_P4
#define INIO_P5_5       P5_IN_P5
#define INIO_P5_8       P5_IN_P8
#define INIO_P5_9       P5_IN_P9
#define INIO_P5_10       P5_IN_P10
#define INIO_P5_11       P5_IN_P11
#define INIO_P5_13       P5_IN_P13
#define INIO_P5_15       P5_IN_P15








#define INIO_P6_0       P6_IN_P0
#define INIO_P6_1       P6_IN_P1
#define INIO_P6_2       P6_IN_P2

#define SETIO_P6_0       P6_OMRL = 0x0001
#define SETIO_P6_1       P6_OMRL = 0x0002
#define SETIO_P6_2       P6_OMRL = 0x0004


#define CLEARIO_P6_0       P6_OMRL = 0x0100
#define CLEARIO_P6_1       P6_OMRL = 0x0200
#define CLEARIO_P6_2       P6_OMRL = 0x0400


#define TOGGLEIO_P6_0       P6_OMRL = 0x0101
#define TOGGLEIO_P6_1       P6_OMRL = 0x0202
#define TOGGLEIO_P6_2       P6_OMRL = 0x0404


#define CONTROLIO_P6_0(Mode)       P6_IOCR00 = (P6_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P6_1(Mode)       P6_IOCR01 = (P6_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P6_2(Mode)       P6_IOCR02 = (P6_IOCR02 & 0xFF0F) | (Mode << 4)

#define INIO_P7_0       P7_IN_P0
#define INIO_P7_1       P7_IN_P1
#define INIO_P7_2       P7_IN_P2
#define INIO_P7_3       P7_IN_P3
#define INIO_P7_4       P7_IN_P4

#define SETIO_P7_0       P7_OMRL = 0x0001
#define SETIO_P7_1       P7_OMRL = 0x0002
#define SETIO_P7_2       P7_OMRL = 0x0004
#define SETIO_P7_3       P7_OMRL = 0x0008
#define SETIO_P7_4       P7_OMRL = 0x0010


#define CLEARIO_P7_0       P7_OMRL = 0x0100
#define CLEARIO_P7_1       P7_OMRL = 0x0200
#define CLEARIO_P7_2       P7_OMRL = 0x0400
#define CLEARIO_P7_3       P7_OMRL = 0x0800
#define CLEARIO_P7_4       P7_OMRL = 0x1000


#define TOGGLEIO_P7_0       P7_OMRL = 0x0101
#define TOGGLEIO_P7_1       P7_OMRL = 0x0202
#define TOGGLEIO_P7_2       P7_OMRL = 0x0404
#define TOGGLEIO_P7_3       P7_OMRL = 0x0808
#define TOGGLEIO_P7_4       P7_OMRL = 0x1010


#define CONTROLIO_P7_0(Mode)       P7_IOCR00 = (P7_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P7_1(Mode)       P7_IOCR01 = (P7_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P7_2(Mode)       P7_IOCR02 = (P7_IOCR02 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P7_3(Mode)       P7_IOCR03 = (P7_IOCR03 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P7_4(Mode)       P7_IOCR04 = (P7_IOCR04 & 0xFF0F) | (Mode << 4)

#define INIO_P10_0       P10_IN_P0
#define INIO_P10_1       P10_IN_P1
#define INIO_P10_2       P10_IN_P2
#define INIO_P10_3       P10_IN_P3
#define INIO_P10_4       P10_IN_P4
#define INIO_P10_5       P10_IN_P5
#define INIO_P10_6       P10_IN_P6
#define INIO_P10_7       P10_IN_P7
#define INIO_P10_8       P10_IN_P8
#define INIO_P10_9       P10_IN_P9
#define INIO_P10_10       P10_IN_P10
#define INIO_P10_11       P10_IN_P11
#define INIO_P10_12       P10_IN_P12
#define INIO_P10_13       P10_IN_P13
#define INIO_P10_14       P10_IN_P14
#define INIO_P10_15       P10_IN_P15

#define SETIO_P10_0       P10_OMRL = 0x0001
#define SETIO_P10_1       P10_OMRL = 0x0002
#define SETIO_P10_2       P10_OMRL = 0x0004
#define SETIO_P10_3       P10_OMRL = 0x0008
#define SETIO_P10_4       P10_OMRL = 0x0010
#define SETIO_P10_5       P10_OMRL = 0x0020
#define SETIO_P10_6       P10_OMRL = 0x0040
#define SETIO_P10_7       P10_OMRL = 0x0080

#define SETIO_P10_8       P10_OMRH = 0x0001
#define SETIO_P10_9       P10_OMRH = 0x0002
#define SETIO_P10_10       P10_OMRH = 0x0004
#define SETIO_P10_11       P10_OMRH = 0x0008
#define SETIO_P10_12       P10_OMRH = 0x0010
#define SETIO_P10_13       P10_OMRH = 0x0020
#define SETIO_P10_14       P10_OMRH = 0x0040
#define SETIO_P10_15       P10_OMRH = 0x0080

#define CLEARIO_P10_0       P10_OMRL = 0x0100
#define CLEARIO_P10_1       P10_OMRL = 0x0200
#define CLEARIO_P10_2       P10_OMRL = 0x0400
#define CLEARIO_P10_3       P10_OMRL = 0x0800
#define CLEARIO_P10_4       P10_OMRL = 0x1000
#define CLEARIO_P10_5       P10_OMRL = 0x2000
#define CLEARIO_P10_6       P10_OMRL = 0x4000
#define CLEARIO_P10_7       P10_OMRL = 0x8000

#define CLEARIO_P10_8       P10_OMRH = 0x0100
#define CLEARIO_P10_9       P10_OMRH = 0x0200
#define CLEARIO_P10_10       P10_OMRH = 0x0400
#define CLEARIO_P10_11       P10_OMRH = 0x0800
#define CLEARIO_P10_12       P10_OMRH = 0x1000
#define CLEARIO_P10_13       P10_OMRH = 0x2000
#define CLEARIO_P10_14       P10_OMRH = 0x4000
#define CLEARIO_P10_15       P10_OMRH = 0x8000

#define TOGGLEIO_P10_0       P10_OMRL = 0x0101
#define TOGGLEIO_P10_1       P10_OMRL = 0x0202
#define TOGGLEIO_P10_2       P10_OMRL = 0x0404
#define TOGGLEIO_P10_3       P10_OMRL = 0x0808
#define TOGGLEIO_P10_4       P10_OMRL = 0x1010
#define TOGGLEIO_P10_5       P10_OMRL = 0x2020
#define TOGGLEIO_P10_6       P10_OMRL = 0x4040
#define TOGGLEIO_P10_7       P10_OMRL = 0x8080

#define TOGGLEIO_P10_8       P10_OMRH = 0x0101
#define TOGGLEIO_P10_9       P10_OMRH = 0x0202
#define TOGGLEIO_P10_10       P10_OMRH = 0x0404
#define TOGGLEIO_P10_11       P10_OMRH = 0x0808
#define TOGGLEIO_P10_12       P10_OMRH = 0x1010
#define TOGGLEIO_P10_13       P10_OMRH = 0x2020
#define TOGGLEIO_P10_14       P10_OMRH = 0x4040
#define TOGGLEIO_P10_15       P10_OMRH = 0x8080

#define CONTROLIO_P10_0(Mode)       P10_IOCR00 = (P10_IOCR00 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_1(Mode)       P10_IOCR01 = (P10_IOCR01 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_2(Mode)       P10_IOCR02 = (P10_IOCR02 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_3(Mode)       P10_IOCR03 = (P10_IOCR03 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_4(Mode)       P10_IOCR04 = (P10_IOCR04 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_5(Mode)       P10_IOCR05 = (P10_IOCR05 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_6(Mode)       P10_IOCR06 = (P10_IOCR06 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_7(Mode)       P10_IOCR07 = (P10_IOCR07 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_8(Mode)       P10_IOCR08 = (P10_IOCR08 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_9(Mode)       P10_IOCR09 = (P10_IOCR09 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_10(Mode)       P10_IOCR10 = (P10_IOCR10 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_11(Mode)       P10_IOCR11 = (P10_IOCR11 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_12(Mode)       P10_IOCR12 = (P10_IOCR12 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_13(Mode)       P10_IOCR13 = (P10_IOCR13 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_14(Mode)       P10_IOCR14 = (P10_IOCR14 & 0xFF0F) | (Mode << 4)
#define CONTROLIO_P10_15(Mode)       P10_IOCR15 = (P10_IOCR15 & 0xFF0F) | (Mode << 4)

#define INIO_P15_0       P15_IN_P0
#define INIO_P15_2       P15_IN_P2
#define INIO_P15_4       P15_IN_P4
#define INIO_P15_5       P15_IN_P5
#define INIO_P15_6       P15_IN_P6








// USER CODE BEGIN (IO_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void IO_vInit(void);


// USER CODE BEGIN (IO_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         IO_vSetPin(PinName) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the chosen portpin to '1'.
//                Note:
//                See the 'Defines for the parameter PinName' section in this 
//                header file for the available definitions for the parameter 
//                PinName.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    PinName: 
//                Pin to be set to '1'
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

#define IO_vSetPin(PinName) SET##PinName


//****************************************************************************
// @Macro         IO_vResetPin(PinName) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the chosen portpin to '0'. 
//                Note: 
//                See the 'Defines for the parameter PinName' section in this 
//                header file for the available definitions for the parameter 
//                PinName.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    PinName: 
//                Pin to be set to '0'
//
//----------------------------------------------------------------------------
// @Date          2019/8/7
//
//****************************************************************************

#define IO_vResetPin(PinName) CLEAR##PinName


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

// USER CODE BEGIN (IO_Header,9)

// USER CODE END


#endif  // ifndef _IO_H_
