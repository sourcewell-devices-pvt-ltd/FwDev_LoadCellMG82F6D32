#ifndef __REG_MG82F6D32_H
#define __REG_MG82F6D32_H


// Avoid false-alarm syntax errors in Eclipse.
#ifdef __CDT_PARSER__
#define __sfr
#define __at(x)
#define __xdata
#define __interrupt(x)
#define __using(x)
#endif

#define SFRBIT(address, name, bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0) \
		SFR(address, name)    \
		SBIT((address+0, bit0) \
		SBIT((address+1, bit1) \
		SBIT((address+2, bit2) \
		SBIT((address+3, bit3) \
		SBIT((address+4, bit4) \
		SBIT((address+5, bit5) \
		SBIT((address+6, bit6) \
		SBIT((address+7, bit7)

#if defined SDCC || defined __CDT_PARSER__
// Syntax for the SDCC (Small Device C Compiler).
#define SFR(name, address ) static __sfr __at (address) name;
#define SBIT(name,  address) static __sbit __at (address) name;
#define SFR16(addressH, addressL, name) static __sfr16 __at (((addressH) << 8) + (addressL)) name;
#define SFRX(address, name)       static volatile unsigned char __xdata __at(address) name;

#define ISR(source, bank) void ISR_##source() __interrupt(source##_VECTOR) __using(bank)

#else
#error "Unknown compiler."
#endif


#define GF_7              0x80
#define GF_6              0x40
#define GF_5              0x20
#define GF_4              0x10
#define GF_3              0x08
#define GF_2              0x04
#define GF_1              0x02
#define GF_0              0x01

SFR(P0, 0x80)     //Port 0
#define P0_Page           0x00

SFR(SP, 0x81)     //Stack Pointer
#define SP_Page           0x00

SFR(DPL,  0x82)     //Data Pointer Low
#define DPL_Page          0x00

SFR(DPH,  0x83)     //Data Pointer High
#define DPH_Page          0x00

SFR(SPSTAT, 0x84)     //SPI Status Register
#define SPSTAT_Page       0x00
// (bits in SPSTAT)
#define SPIF              0x80
#define WCOL              0x40
#define THRF              0x20
#define SPIBSY            0x10
#define MODF              0x08
#define QPIEN             0x02
#define SPR2_QDOE         0x01

SFR(SPCON, 0x85)     //SPI Control Register
#define SPCON_Page        0x00
// (bits in SPCON)
#define SSIG              0x80
#define SPEN              0x40
#define DORD              0x20
#define MSTR              0x10
#define CPOL              0x08
#define CPHA              0x04
#define SPR1              0x02
#define SPR0              0x01

SFR(SPDAT, 0x86)     //SPI Data Register
#define SPDAT_Page        0x00

SFR(PCON0, 0x87)     //Power Control 0
#define PCON0_Page        0x00
// (bits in PCON0)
#define SMOD1             0x80
#define SMOD0             0x40
#define POF0              0x10
#define PD                0x02
#define IDL               0x01

SFR(TCON, 0x88)     //Timer Control
#define TCON_Page         0x00

SFR(TMOD, 0x89)     //Timer Mode
#define TMOD_Page         0x00
// (bits in TMOD)
#define T1GATE            0x80
#define T1C_T             0x40
#define T1M1              0x20
#define T1M0              0x10
#define T0GATE            0x08
#define T0C_T             0x04
#define T0M1              0x02
#define T0M0              0x01

SFR(TL0, 0x8A)     //Timer Low 0
#define TL0_Page          0x00

SFR(TL1, 0x8B)     //Timer Low 1
#define TL1_Page          0x00

SFR(TH0, 0x8C)     //Timer High 0
#define TH0_Page          0x00

SFR(TH1, 0x8D)     //Timer High 1
#define TH1_Page          0x00

SFR(SFIE, 0x8E)     //System Flag INT En.
#define SFIE_Page         0x00
// (bits in SFIE)
#define SIDFIE            0x80
#define MCDRE             0x40
#define MCDFIE            0x20
#define RTCFIE            0x10
#define SPWIE             0x08
#define BOF1IE            0x04
#define BOF0IE            0x02
#define WDTFIE            0x01

SFR(XRPS, 0x8F)     //XRAM Page Select
#define XRPS_Page         0x00

SFR(P1, 0x90)     //Port 1
#define P1_Page           0x00

SFR(P1M0, 0x91)     //P1 Mode Register 0
#define P1M0_Page         0x00
// (bits in P1M0)
#define P1M07             0x80
#define P1M06             0x40
#define P1M05             0x20
#define P1M04             0x10
#define P1M03             0x08
#define P1M02             0x04
#define P1M01             0x02
#define P1M00             0x01

SFR(P1M1, 0x92)     //P1 Mode Register 1
#define P1M1_Page         0x00
// (bits in P1M1)
#define P1M17             0x80
#define P1M16             0x40
#define P1M15             0x20
#define P1M14             0x10
#define P1M13             0x08
#define P1M12             0x04
#define P1M11             0x02
#define P1M10             0x01

SFR(P2M1, 0x92)     //P2 Mode Register 1
#define P2M1_Page         0x01
// (bits in P2M1)
#define P2M17             0x80
#define P2M16             0x40
#define P2M15             0x20
#define P2M14             0x10
#define P2M13             0x08
#define P2M12             0x04
#define P2M11             0x02
#define P2M10             0x01

SFR(P4M1, 0x92)     //P4 Mode Register 1
#define P4M1_Page         0x02
// (bits in P4M1)
#define P4M17             0x80
#define P4M16             0x40
#define P4M15             0x20
#define P4M14             0x10
#define P4M13             0x08
#define P4M12             0x04
#define P4M11             0x02
#define P4M10             0x01

SFR(P6M1, 0x92)     //P6 Mode Register 1
#define P6M1_Page         0x03
// (bits in P6M1)
#define P6M17             0x80
#define P6M16             0x40
#define P6M15             0x20
#define P6M14             0x10
#define P6M13             0x08
#define P6M12             0x04
#define P6M11             0x02
#define P6M10             0x01

SFR(P0M1, 0x92)     //P0 Mode Register 1
#define P0M1_Page         0x04
// (bits in P0M1)
#define P0M17             0x80
#define P0M16             0x40
#define P0M15             0x20
#define P0M14             0x10
#define P0M13             0x08
#define P0M12             0x04
#define P0M11             0x02
#define P0M10             0x01

SFR(P5M1, 0x92)     //P5 Mode Register 1
#define P5M1_Page         0x05
// (bits in P5M1)
#define P5M17             0x80
#define P5M16             0x40
#define P5M15             0x20
#define P5M14             0x10
#define P5M13             0x08
#define P5M12             0x04
#define P5M11             0x02
#define P5M10             0x01

SFR(P7M1, 0x92)     //P7 Mode Register 1
#define P7M1_Page         0x06
// (bits in P7M1)
#define P7M13             0x08
#define P7M12             0x04
#define P7M11             0x02
#define P7M10             0x01

SFR(P3FDC, 0x92)     //P3 Fast Drv. Ctrl.
#define P3FDC_Page        0x07
// (bits in P3FDC)
#define P3FDC7            0x80
#define P3FDC6            0x40
#define P3FDC5            0x20
#define P3FDC4            0x10
#define P3FDC3            0x08
#define P3FDC2            0x04
#define P3FDC1            0x02
#define P3FDC0            0x01

SFR(P1FDC, 0x92)     //P1 Fast Drv. Ctrl.
#define P1FDC_Page        0x08
// (bits in P1FDC)
#define P1FDC7            0x80
#define P1FDC6            0x40
#define P1FDC5            0x20
#define P1FDC4            0x10
#define P1FDC3            0x08
#define P1FDC2            0x04
#define P1FDC1            0x02
#define P1FDC0            0x01

SFR(P2FDC, 0x92)     //P2 Fast Drv. Ctrl.
#define P2FDC_Page        0x09
// (bits in P2FDC)
#define P2FDC7            0x80
#define P2FDC6            0x40
#define P2FDC5            0x20
#define P2FDC4            0x10
#define P2FDC3            0x08
#define P2FDC2            0x04
#define P2FDC1            0x02
#define P2FDC0            0x01

SFR(P4FDC, 0x92)     //P4 Fast Drv. Ctrl.
#define P4FDC_Page        0x0A
// (bits in P4FDC)
#define P4FDC6            0x40
#define P4FDC5            0x20
#define P4FDC4            0x10
#define P4FDC3            0x08
#define P4FDC2            0x04
#define P4FDC1            0x02
#define P4FDC0            0x01

SFR(P0FDC, 0x92)     //P0 Fast Drv. Ctrl.
#define P0FDC_Page        0x0B
// (bits in P0FDC)
#define P0FDC7            0x80
#define P0FDC6            0x40
#define P0FDC5            0x20
#define P0FDC4            0x10
#define P0FDC3            0x08
#define P0FDC2            0x04
#define P0FDC1            0x02
#define P0FDC0            0x01

SFR(P6FDC, 0x92)     //P6 Fast Drv. Ctrl.
#define P6FDC_Page        0x0C
// (bits in P6FDC)
#define P6FDC7            0x80
#define P6FDC6            0x40
#define P6FDC5            0x20
#define P6FDC4            0x10
#define P6FDC3            0x08
#define P6FDC2            0x04

SFR(P5FDC, 0x92)     //P5 Fast Drv. Ctrl.
#define P5FDC_Page        0x0D
// (bits in P5FDC)
#define P5FDC7            0x80
#define P5FDC6            0x40
#define P5FDC5            0x20
#define P5FDC4            0x10
#define P5FDC3            0x08
#define P5FDC2            0x04
#define P5FDC1            0x02
#define P5FDC0            0x01

SFR(P7FDC, 0x92)     //P7 Fast Drv. Ctrl.
#define P7FDC_Page        0x0E
// (bits in P7FDC)
#define P7FDC3            0x08
#define P7FDC2            0x04
#define P7FDC1            0x02
#define P7FDC0            0x01

SFR(P0M0, 0x93)     //P0 Mode Register 0
#define P0M0_Page         0x00
// (bits in P0M0)
#define P0M07             0x80
#define P0M06             0x40
#define P0M05             0x20
#define P0M04             0x10
#define P0M03             0x08
#define P0M02             0x04
#define P0M01             0x02
#define P0M00             0x01

SFR(T2MOD1, 0x93)     //Timer2 mode 1 Reg.
#define T2MOD1_Page       0x01
// (bits in T2MOD1)
#define TL2CS             0x80
#define TF2IG             0x40
#define TL2IS             0x20
#define T2CKS             0x10
#define T2MS1             0x08
#define CP2S2             0x04
#define CP2S1             0x02
#define CP2S0             0x01

SFR(T3MOD1, 0x93)     //Timer3 mode 1 Reg.
#define T3MOD1_Page       0x02
// (bits in T3MOD1)
#define TL3CS             0x80
#define TF3IG             0x40
#define TL3IS             0x20
#define T3CKS             0x10
#define T3MS1             0x08
#define CP3S2             0x04
#define CP3S1             0x02
#define CP3S0             0x01

SFR(T4MOD1, 0x93)     //Timer4 mode 1 Reg.
#define T4MOD1_Page       0x03
// (bits in T4MOD1)
#define TL4CS             0x80
#define TF4IG             0x40
#define TL4IS             0x20
#define T4CKS             0x10
#define T4MS1             0x08
#define CP4S2             0x04
#define CP4S1             0x02
#define CP4S0             0x01

SFR(DMACR0, 0x94)     //DMA Control Reg. 0
#define DMACR0_Page       0x00
// (bits in DMACR0)
#define DMAE0             0x08
#define DMAS0             0x04
#define DIE0              0x02
#define DCF0              0x01

SFR(DMACG0, 0x94)     //DMA Configured Reg. 0
#define DMACG0_Page       0x08
// (bits in DMACG0)
#define PDMAH             0x80
#define PDMAL             0x40
#define CRCW0             0x20
#define EXTS10            0x08
#define EXTS00            0x04
#define LOOP0             0x01

SFR(DMADS0, 0x94)     //DMA Data path Selection 0
#define DMADS0_Page       0x09
// (bits in DMADS0)
#define DSS30             0x80
#define DSS20             0x40
#define DSS10             0x20
#define DSS00             0x10
#define DDS30             0x08
#define DDS20             0x04
#define DDS10             0x02
#define DDS00             0x01

SFR(P2M0, 0x95)     //P2 Mode Register 0
#define P2M0_Page         0x00
// (bits in P2M0)
#define P2M07             0x80
#define P2M06             0x40
#define P2M05             0x20
#define P2M04             0x10
#define P2M03             0x08
#define P2M02             0x04
#define P2M01             0x02
#define P2M00             0x01

SFR(TREN0, 0x95)     //Timer Run Enable Register 0
#define TREN0_Page        0x01
// (bits in TREN0)
#define TR4LE             0x80
#define TR3LE             0x40
#define TR2LE             0x20
#define TR4E              0x10
#define TR3E              0x08
#define TR2E              0x04
#define TR1E              0x02
#define TR0E              0x01

SFR(TRLC0, 0x95)     //Timer Reload Control Register 0
#define TRLC0_Page        0x02
// (bits in TRLC0)
#define TL4RLC            0x80
#define TL3RLC            0x40
#define TL2RLC            0x20
#define T4RLC             0x10
#define T3RLC             0x08
#define T2RLC             0x04
#define T1RLC             0x02
#define T0RLC             0x01

SFR(TSPC0, 0x95)     //Timer Stop Control Register 0
#define TSPC0_Page        0x03
// (bits in TSPC0)
#define TL4SC             0x80
#define TL3SC             0x40
#define TL2SC             0x20
#define T4SC              0x10
#define T3SC              0x08
#define T2SC              0x04
#define T1SC              0x02
#define T0SC              0x01

SFR(BOREV, 0x96)     //Bit Order Reversed
#define BOREV_Page        0x00

SFR(PCON1, 0x97)     //Power Control 1
#define PCON1_Page        0x00
// (bits in PCON1)
#define SWRF              0x80
#define EXRF              0x40
#define MCDF              0x20
#define RTCF              0x10
#define SPWF              0x08
#define BOF1              0x04
#define BOF0              0x02
#define WDTF              0x01

SFR(S0CON, 0x98)     //Serial 0 Control
#define S0CON_Page        0x00


SFR(S1CON, 0x98)     //Serial 1 Control
#define S1CON_Page        0x01


SFR(S2CON, 0x98)     //Serial 2 Control
#define S2CON_Page        0x03


SFR(S3CON, 0x98)     //Serial 3 Control
#define S3CON_Page        0x04
// (bits in S3CON)

SFR(S0BUF, 0x99)     //Serial 0 Buffer
#define S0BUF_Page        0x00

SFR(S1BUF, 0x99)     //Serial 1 Buffer
#define S1BUF_Page        0x01

SFR(S2BUF, 0x99)     //Serial 2 Buffer
#define S2BUF_Page        0x03

SFR(S3BUF, 0x99)     //Serial 3 Buffer
#define S3BUF_Page        0x04

SFR(S0BRT, 0x9A)     //S0 Baud-Rate Timer
#define S0BRT_Page        0x00

SFR(S1BRT, 0x9A)     //S1 Baud-Rate Timer
#define S1BRT_Page        0x01

SFR(S2BRT, 0x9A)     //S2 Baud-Rate Timer
#define S2BRT_Page        0x03

SFR(S3BRT, 0x9A)     //S3 Baud-Rate Timer
#define S3BRT_Page        0x04

SFR(S0BRC, 0x9B)     //S0 Baud-Rate Counter
#define S0BRC_Page        0x00

SFR(S1BRC, 0x9B)     //S1 Baud-Rate Counter
#define S1BRC_Page        0x01

SFR(S2BRC, 0x9B)     //S2 Baud-Rate Counter
#define S2BRC_Page        0x03

SFR(S3BRC, 0x9B)     //S3 Baud-Rate Counter
#define S3BRC_Page        0x04

SFR(S0CFG, 0x9C)     //S0 Configuration
#define S0CFG_Page        0x00
// (bits in S0CFG)
#define URTS              0x80
#define SMOD2             0x40
#define URM0X3            0x20
#define SM30              0x10
#define S0DOR             0x08
#define BTI               0x04
#define UTIE              0x02
#define SMOD3             0x01

SFR(S1CFG, 0x9C)     //S1 Configuration
#define S1CFG_Page        0x01
// (bits in S1CFG)
#define SM31              0x80
#define S1M0X3            0x40
#define S1DOR             0x20
#define S1TR              0x10
#define S1MOD1            0x08
#define S1TX12            0x04
#define S1CKOE            0x02
#define S1TME             0x01

SFR(S2CFG, 0x9C)     //S2 Configuration
#define S2CFG_Page        0x03
// (bits in S2CFG)
#define SM32              0x80
#define S2M0X3            0x40
#define S2DOR             0x20
#define S2TR              0x10
#define S2MOD1            0x08
#define S2TX12            0x04
#define S2CKOE            0x02
#define S2TME             0x01

SFR(S3CFG, 0x9C)     //S3 Configuration
#define S3CFG_Page        0x04
// (bits in S3CFG)
#define SM33              0x80
#define S3M0X3            0x40
#define S3DOR             0x20
#define S3TR              0x10
#define S3MOD1            0x08
#define S3TX12            0x04
#define S3CKOE            0x02
#define S3TME             0x01

SFR(S0CFG1, 0x9D)     //S0 Configuration 1
#define S0CFG1_Page       0x00
// (bits in S0CFG1)
#define SBF0              0x80
#define TXER0             0x40
#define S0SB16            0x20
#define ATBR0             0x10
#define TXRX0             0x08
#define SYNC0             0x04

SFR(LINCFG, 0x9D)     //LIN Configuration
#define LINCFG_Page       0x00

SFR(AC0CON, 0x9E)     //AC0 Control Reg.
#define AC0CON_Page       0x00
// (bits in AC0CON)
#define AC0LP             0x80
#define AC0PDX            0x40
#define AC0OUT            0x20
#define AC0F              0x10
#define AC0EN             0x08
#define AC0INV            0x04
#define AC0M1             0x02
#define AC0M0             0x01

SFR(AC1CON, 0x9E)     //AC1 Control Reg.
#define AC1CON_Page       0x01
// (bits in AC1CON)
#define AC1LP             0x80
#define AC1PDX            0x40
#define AC1OUT            0x20
#define AC1F              0x10
#define AC1EN             0x08
#define AC1INV            0x04
#define AC1M1             0x02
#define AC1M0             0x01

SFR(AC2CON, 0x9E)     //AC2 Control Reg.
#define AC2CON_Page       0x02
// (bits in AC2CON)
#define AC2LP             0x80
#define AC2PDX            0x40
#define AC2OUT            0x20
#define AC2F              0x10
#define AC2EN             0x08
#define AC2INV            0x04
#define AC2M1             0x02
#define AC2M0             0x01

SFR(AC0MOD, 0x9F)     //AC0 Mode Reg.
#define AC0MOD_Page       0x00
// (bits in AC0MOD)
#define NVRS3             0x80
#define NVRS2             0x40
#define NVRS1             0x20
#define NVRS0             0x10
#define NVRL              0x08
#define AC0FLT            0x04
#define AC0PIS1           0x02
#define AC0PIS0           0x01

SFR(AC1MOD, 0x9F)     //AC1 Mode Reg.
#define AC1MOD_Page       0x01
// (bits in AC1MOD)
#define AC1NIS            0x10
#define NVRL1             0x08
#define AC1FLT            0x04

SFR(AC2MOD, 0x9F)     //AC2 Mode Reg.
#define AC2MOD_Page       0x02
// (bits in AC2MOD)
#define AC2NIS            0x10
#define NVRL2             0x08
#define AC2FLT            0x04

SFR(P2, 0xA0)     //Port 2
#define P2_Page           0x00
// (bits in P2)

SFR(AUXR0, 0xA1)     //Auxiliary Register 0
#define AUXR0_Page        0x00
// (bits in AUXR0)
#define P60OC1            0x80
#define P60OC0            0x40
#define P60FD             0x20
#define PBKF              0x10
#define BM1F              0x08
#define BM0F              0x04
#define INT1H             0x02
#define INT0H             0x01

SFR(AUXR1, 0xA2)     //Auxiliary Register 1
#define AUXR1_Page        0x00
// (bits in AUXR1)
#define CRCDS1            0x20
#define CRCDS0            0x10
#define DPS               0x01

SFR(AUXR2, 0xA3)     //Auxiliary Register 2
#define AUXR2_Page        0x00
// (bits in AUXR2)
#define STAF              0x80
#define STOF              0x40
#define T1X12             0x08
#define T0X12             0x04
#define T1CKOE            0x02
#define T0CKOE            0x01

SFR(AUXR3, 0xA4)     //Auxiliary Register 3
#define AUXR3_Page        0x00
// (bits in AUXR3)
#define T0PS1             0x80
#define T0PS0             0x40
#define BPOC1             0x20
#define BPOC0             0x10
#define S0PS0             0x08
#define TWIPS1            0x04
#define TWIPS0            0x02
#define T0XL              0x01

SFR(AUXR4, 0xA4)     //Auxiliary Register 4
#define AUXR4_Page        0x01
// (bits in AUXR4)
#define T2PS1             0x80
#define T2PS0             0x40
#define T1PS1             0x20
#define T1PS0             0x10
#define AC1OE             0x08
#define AC1FLT1           0x04
#define AC0OE             0x02
#define AC0FLT1           0x01

SFR(AUXR5, 0xA4)     //Auxiliary Register 5
#define AUXR5_Page        0x02
// (bits in AUXR5)
#define C0IC4S0           0x80
#define C0IC2S0           0x40
#define C0PPS1            0x20
#define C0PPS0            0x10
#define C0PS1             0x08
#define C0PS0             0x04
#define ECIPS0            0x02
#define C0COPS            0x01

SFR(AUXR6, 0xA4)     //Auxiliary Register 6
#define AUXR6_Page        0x03
// (bits in AUXR6)
#define KBIHPS1           0x80
#define KBIHPS0           0x40
#define KBILPS1           0x20
#define KBILPS0           0x10
#define T3FCS             0x08
#define T2FCS             0x04
#define SnMIPS            0x02
#define S0COPS            0x01

SFR(AUXR7, 0xA4)     //Auxiliary Register 7
#define AUXR7_Page        0x04
// (bits in AUXR7)
#define POE5              0x80
#define POE4              0x40
#define C0CKOE            0x20
#define SPI0M0            0x10
#define BM1OE1            0x08
#define BM1OE0            0x04
#define BM0OE1            0x02
#define BM0OE0            0x01

SFR(AUXR8, 0xA4)     //Auxiliary Register 8
#define AUXR8_Page        0x05
// (bits in AUXR8)
#define POE7              0x80
#define POE6              0x40
#define C0PPS2            0x20
#define S1COPS            0x04
#define T3PS1             0x02
#define T3PS0             0x01

SFR(AUXR9, 0xA4)     //Auxiliary Register 9
#define AUXR9_Page        0x06
// (bits in AUXR9)
#define SIDPS1            0x80
#define SIDPS0            0x40
#define T1G1              0x20
#define T0G1              0x10
#define C0FDC1            0x08
#define C0FDC0            0x04
#define S1PS1             0x02
#define S1PS0             0x01

SFR(AUXR10, 0xA4)     //Aux. Register 10
#define AUXR10_Page       0x07
// (bits in AUXR10)
#define AC1HC0            0x80
#define AC0HC0            0x40
#define SPIPS1            0x20
#define SPIPS0            0x10
#define S0PS1             0x08
#define SPFACE            0x04
#define TWICF             0x02
#define PAA               0x01

SFR(AUXR11, 0xA4)     //Aux. Register 11
#define AUXR11_Page       0x08
// (bits in AUXR11)
#define I2C1CF            0x80
#define PAA1              0x40
#define I2C1PS1           0x20
#define I2C1PS0           0x10
#define POEM0             0x04
#define C0M0              0x02
#define C0OFS             0x01

SFR(AUXR12, 0xA4)     //Aux. Register 12
#define AUXR12_Page       0x09
// (bits in AUXR12)
#define T0COBE            0x20
#define T0COAE            0x10

SFR(AUXR13, 0xA4)     //Aux. Register 13
#define AUXR13_Page       0x0A
// (bits in AUXR13)
#define S3PS0             0x40
#define S2PS0             0x10
#define T4FCS             0x04
#define T4PS1             0x02
#define T4PS0             0x01

SFR(AUXR14, 0xA4)     //Aux. Register 14
#define AUXR14_Page       0x0B
// (bits in AUXR14)
#define ADLPS1            0x80
#define ADLPS0            0x40
#define RWPS0             0x08
#define AC2HC0            0x04
#define AC2OE             0x02
#define AC2FLT1           0x01

SFR(EIE2, 0xA5)     //Extended INT Enable 2
#define EIE2_Page         0x00
// (bits in EIE2)
#define EAC2              0x80
#define ETWI1             0x40
#define ES3               0x10
#define ET4               0x08
#define ES2               0x04
#define EAC1              0x02
#define ET3               0x01

SFR(EIP2L, 0xA6)     //Ext. INT Priority 2 Low
#define EIP2L_Page        0x00
// (bits in EIP2L)
#define PAC2L             0x80
#define PTWI1L            0x40
#define PS3L              0x10
#define PT4L              0x08
#define PS2L              0x04
#define PAC1L             0x02
#define PT3L              0x01

SFR(EIP2H, 0xA7)     //Ext. INT Priority 2 High
#define EIP2H_Page        0x00
// (bits in EIP2H)
#define PAC2H             0x80
#define PTWI1H            0x40
#define PS3H              0x10
#define PT4H              0x08
#define PS2H              0x04
#define PAC1H             0x02
#define PT3H              0x01

SFR(IE, 0xA8)     //Interrupt Enable
#define IE_Page           0x00
// (bits in IE)

SFR(SADDR, 0xA9)     //Slave Address
#define SADDR_Page        0x00

SFR(SFRPI, 0xAC)     //SFR Page Index
#define SFRPI_Page        0x00
// (bits in SFRPI)
#define IDX3              0x08
#define IDX2              0x04
#define IDX1              0x02
#define IDX0              0x01

SFR(EIE1, 0xAD)     //Extended INT Enable 1
#define EIE1_Page         0x00
// (bits in EIE1)
#define EAC0              0x80
#define ETWI0             0x40
#define EKB               0x20
#define ES1               0x10
#define ESF               0x08
#define EPCA              0x04
#define EADC              0x02
#define ESPI              0x01

SFR(EIP1L, 0xAE)     //Ext. INT Priority 1 Low
#define EIP1L_Page        0x00
// (bits in EIP1L)
#define PAC0L             0x80
#define PTWI0L            0x40
#define PKBL              0x20
#define PS1L              0x10
#define PSFL              0x08
#define PPCAL             0x04
#define PADCL             0x02
#define PSPIL             0x01

SFR(EIP1H, 0xAF)     //Ext. INT Priority 1 High
#define EIP1H_Page        0x00
// (bits in EIP1H)
#define PAC0H             0x80
#define PTWI0H            0x40
#define PKBH              0x20
#define PS1H              0x10
#define PSFH              0x08
#define PPCAH             0x04
#define PADCH             0x02
#define PSPIH             0x01

SFR(P3, 0xB0)     //Port 3
#define P3_Page           0x00
// (bits in P3)

SFR(P3M0, 0xB1)     //P3 Mode Register 0
#define P3M0_Page         0x00
// (bits in P3M0)
#define P3M07             0x80
#define P3M06             0x40
#define P3M05             0x20
#define P3M04             0x10
#define P3M03             0x08
#define P3M02             0x04
#define P3M01             0x02
#define P3M00             0x01

SFR(P3M1, 0xB2)     //P3 Mode Register 1
#define P3M1_Page         0x00
// (bits in P3M1)
#define P3M17             0x80
#define P3M16             0x40
#define P3M15             0x20
#define P3M14             0x10
#define P3M13             0x08
#define P3M12             0x04
#define P3M11             0x02
#define P3M10             0x01

SFR(P4M0, 0xB3)     //P4 Mode Register 0
#define P4M0_Page         0x00
// (bits in P4M0)
#define P4M07             0x80
#define P4M06             0x40
#define P4M05             0x20
#define P4M04             0x10
#define P4M03             0x08
#define P4M02             0x04
#define P4M01             0x02
#define P4M00             0x01

SFR(PDRVC0, 0xB4)     //Port Driving Control 0
#define PDRVC0_Page       0x02
// (bits in PDRVC0)
#define P3DC1             0x80
#define P3DC0             0x40
#define P2DC1             0x20
#define P2DC0             0x10
#define P1DC1             0x08
#define P1DC0             0x04
#define P0DC1             0x02
#define P0DC0             0x01

SFR(PDRVC1, 0xB4)     //Port Driving Control 1
#define PDRVC1_Page       0x03
// (bits in PDRVC1)
#define P7DC0             0x40
#define P6DC1             0x20
#define P6DC0             0x10
#define P5DC1             0x08
#define P5DC0             0x04
#define P4DC1             0x02
#define P4DC0             0x01

SFR(P5M0, 0xB5)     //P5 Mode Register 0
#define P5M0_Page         0x00
// (bits in P5M0)
#define P5M07             0x80
#define P5M06             0x40
#define P5M05             0x20
#define P5M04             0x10
#define P5M03             0x08
#define P5M02             0x04
#define P5M01             0x02
#define P5M00             0x01

SFR(P6M0, 0xB5)     //P6 Mode Register 0
#define P6M0_Page         0x01
// (bits in P6M0)
#define P6M07             0x80
#define P6M06             0x40
#define P6M05             0x20
#define P6M04             0x10
#define P6M03             0x08
#define P6M02             0x04
#define P6M01             0x02
#define P6M00             0x01

SFR(P7M0, 0xB5)     //P7 Mode Register 0
#define P7M0_Page         0x02
// (bits in P7M0)
#define P7M03             0x08
#define P7M02             0x04
#define P7M01             0x02
#define P7M00             0x01

SFR(EMBTC, 0xB5)     //EMB Timing Control
#define EMBTC_Page        0x03
// (bits in EMBTC)
#define RWSH              0x08
#define RWS2              0x04
#define RWS1              0x02
#define RWS0              0x01

SFR(RTCTM, 0xB6)     //RTC Timer Register
#define RTCTM_Page        0x00
// (bits in RTCTM)
#define RTCCS1            0x80
#define RTCCS0            0x40
#define RTCCT5            0x20
#define RTCCT4            0x10
#define RTCCT3            0x08
#define RTCCT2            0x04
#define RTCCT1            0x02
#define RTCCT0            0x01

SFR(IP0H, 0xB7)     //Interrupt Priority 0 High
#define IP0H_Page         0x00
// (bits in IP0H)
#define PX3H              0x80
#define PX2H              0x40
#define PT2H              0x20
#define PSH               0x10
#define PT1H              0x08
#define PX1H              0x04
#define PT0H              0x02
#define PX0H              0x01

SFR(IP0L, 0xB8)     //Interrupt Priority Low
#define IP0L_Page         0x00
// (bits in IP0L)

SFR(SADEN, 0xB9)     //Slave Address Mask
#define SADEN_Page        0x00
// (bits in SADEN)
#define SADEN7            0x80
#define SADEN6            0x40
#define SADEN5            0x20
#define SADEN4            0x10
#define SADEN3            0x08
#define SADEN2            0x04
#define SADEN1            0x02
#define SADEN0            0x01

SFR(S0CR1, 0xB9)     //S0 Control 1
#define S0CR1_Page        0x00
// (bits in S0CR1)
#define S0TR              0x80
#define S0TX12            0x40
#define S0TCK             0x20
#define S0RCK             0x10
#define S0CKOE            0x08
#define ARTE              0x04

SFR(PWMCR, 0xBC)     //PWM Control Reg.
#define PWMCR_Page        0x00
// (bits in PWMCR)
#define PCAE              0x80
#define EXDT              0x40
#define PBKM              0x20
#define PBKE11            0x10
#define PBKE10            0x08
#define PBKE02            0x04
#define PBKE01            0x02
#define PBKE00            0x01

SFR(PDTCRA, 0xBC)     //PWM Dead-Time Control Reg. -A
#define PDTCRA_Page       0x01
// (bits in PDTCRA)
#define DTPS1             0x80
#define DTPS0             0x40
#define DT5               0x20
#define DT4               0x10
#define DT3               0x08
#define DT2               0x04
#define DT1               0x02
#define DT0               0x01

SFR(BM0CR, 0xBC)     //OBM0 Control Reg.
#define BM0CR_Page        0x02
// (bits in BM0CR)
#define BM0OUT            0x80
#define BM0SW             0x40
#define BM0IE             0x20
#define BM0POL            0x10
#define M0FLT1            0x08
#define M0FLT0            0x04
#define BM0M1             0x02
#define BM0M0             0x01

SFR(BM0SE, 0xBC)     //OBM0 Switch Enable Reg.
#define BM0SE_Page        0x03
// (bits in BM0SE)
#define BM0E13            0x80
#define BM0E12            0x40
#define BM0E11            0x20
#define BM0E10            0x10
#define BM0E03            0x08
#define BM0E02            0x04
#define BM0E01            0x02
#define BM0E00            0x01

SFR(BM0LCR, 0xBC)     //OBM0 Low channel Control Reg.
#define BM0LCR_Page       0x04
// (bits in BM0LCR)
#define BM0LCP            0x80
#define BM0LS3            0x08
#define BM0LS2            0x04
#define BM0LS1            0x02
#define BM0LS0            0x01

SFR(BM0HCR, 0xBC)     //OBM0 High channel Control Reg.
#define BM0HCR_Page       0x05
// (bits in BM0HCR)
#define BM0HCP            0x80
#define BM0HS3            0x08
#define BM0HS2            0x04
#define BM0HS1            0x02
#define BM0HS0            0x01

SFR(BM1CR, 0xBC)     //OBM1 Control Reg.
#define BM1CR_Page        0x06
// (bits in BM1CR)
#define BM1OUT            0x80
#define BM1SW             0x40
#define BM1IE             0x20
#define BM1POL            0x10
#define M1FLT1            0x08
#define M1FLT0            0x04
#define BM1M1             0x02
#define BM1M0             0x01

SFR(BM1SE, 0xBC)     //OBM1 Switch Enable Reg.
#define BM1SE_Page        0x07
// (bits in BM1SE)
#define BM1E13            0x80
#define BM1E12            0x40
#define BM1E11            0x20
#define BM1E10            0x10
#define BM1E03            0x08
#define BM1E02            0x04
#define BM1E01            0x02
#define BM1E00            0x01

SFR(BM1LCR, 0xBC)     //OBM1 Low channel Control Reg.
#define BM1LCR_Page       0x08
// (bits in BM1LCR)
#define BM1LCP            0x80
#define BM1LS3            0x08
#define BM1LS2            0x04
#define BM1LS1            0x02
#define BM1LS0            0x01

SFR(BM1HCR, 0xBC)     //OBM1 High channel Control Reg.
#define BM1HCR_Page       0x09
// (bits in BM1HCR)
#define BM1HCP            0x80
#define BM1HS3            0x08
#define BM1HS2            0x04
#define BM1HS1            0x02
#define BM1HS0            0x01

SFR(CRC0DA, 0xBD)     //CRC0 Data Port
#define CRC0DA_Page       0x00

SFR(RTCCR, 0xBE)     //RTC Control Reg.
#define RTCCR_Page        0x00
// (bits in RTCCR)
#define RTCE              0x80
#define RTCO              0x40
#define RTCRL5            0x20
#define RTCRL4            0x10
#define RTCRL3            0x08
#define RTCRL2            0x04
#define RTCRL1            0x02
#define RTCRL0            0x01

SFR(CKCON1, 0xBF)     //Clock Control 1
#define CKCON1_Page       0x00
// (bits in CKCON1)
#define XTOR              0x80
#define MCKSTA1           0x20
#define MCKSTA0           0x10
#define OSCSTA3           0x08
#define OSCSTA2           0x04
#define OSCSTA1           0x02
#define OSCSTA0           0x01

SFR(XICON, 0xC0)     //External INT Control
#define XICON_Page        0x00
// (bits in XICON)


SFR(XICFG, 0xC1)     //Ext. INT. Configured
#define XICFG_Page        0x00
// (bits in XICFG)
#define INT1IS1           0x80
#define INT1IS0           0x40
#define INT0IS1           0x20
#define INT0IS0           0x10
#define X3FLT             0x08
#define X2FLT             0x04
#define X1FLT             0x02
#define X0FLT             0x01

SFR(XICFG1, 0xC1)     //Ext. INT. Configured 1
#define XICFG1_Page       0x01
// (bits in XICFG1)
#define INT1IS2           0x80
#define INT0IS2           0x40
#define INT2IS1           0x20
#define INT2IS0           0x10
#define X3FLT1            0x08
#define X2FLT1            0x04
#define X1FLT1            0x02
#define X0FLT1            0x01

SFR(XICFG2, 0xC1)     //Ext. INT. Configured 2
#define XICFG2_Page       0x02
// (bits in XICFG2)
#define INT3IS2           0x08
#define INT3IS1           0x04
#define INT3IS0           0x02
#define INT2IS2           0x01

SFR(ADCFG0, 0xC3)     //ADC Configuration 0
#define ADCFG0_Page       0x00
// (bits in ADCFG0)
#define ADCKS2            0x80
#define ADCKS1            0x40
#define ADCKS0            0x20
#define ADRJ              0x10
#define ACHS              0x08
#define SMPF              0x04
#define ADTM1             0x02
#define ADTM0             0x01

SFR(ADCFG1, 0xC3)     //ADC Configuration 1
#define ADCFG1_Page       0x01
// (bits in ADCFG1)
#define IGADCI            0x80
#define EADCWI            0x40
#define SMPFIE            0x20
#define SIGN              0x10
#define AOS3              0x08
#define AOS2              0x04
#define AOS1              0x02
#define AOS0              0x01

SFR(ADCFG2, 0xC3)     //ADC Configuration 2
#define ADCFG2_Page       0x02
// (bits in ADCFG2)
#define SHT7              0x80
#define SHT6              0x40
#define SHT5              0x20
#define SHT4              0x10
#define SHT3              0x08
#define SHT2              0x04
#define SHT1              0x02
#define SHT0              0x01

SFR(ADCFG3, 0xC3)     //ADC Configuration 3
#define ADCFG3_Page       0x03
// (bits in ADCFG3)
#define ADPS1             0x80
#define ADPS0             0x40
#define ARES1             0x08
#define ARES0             0x04
#define ADES0             0x02

SFR(ADCFG4, 0xC3)     //ADC Configuration 4
#define ADCFG4_Page       0x04
// (bits in ADCFG4)
#define ADWM0             0x40
#define ADTM3             0x20
#define ADTM2             0x10
#define DBSD              0x02
#define DOSD              0x01

SFR(ADCFG5, 0xC3)     //ADC Configuration 5
#define ADCFG5_Page       0x05
// (bits in ADCFG5)
#define ASCE7             0x80
#define ASCE6             0x40
#define ASCE5             0x20
#define ASCE4             0x10
#define ASCE3             0x08
#define ASCE2             0x04
#define ASCE1             0x02
#define ASCE0             0x01

SFR(ADCFG6, 0xC3)     //ADC Configuration 6
#define ADCFG6_Page       0x06
// (bits in ADCFG6)
#define ASCE15            0x80
#define ASCE14            0x40
#define ASCE13            0x20
#define ASCE12            0x10
#define ASCE11            0x08
#define ASCE10            0x04
#define ASCE9             0x02
#define ASCE8             0x01

SFR(ADCFG11,0xC3)     //ADC Configuration 11
#define ADCFG11_Page      0x0B
// (bits in ADCFG11)
#define WHB3              0x80
#define WHB2              0x40
#define WHB1              0x20
#define WHB0              0x10

SFR(ADCFG12,0xC3)     //ADC Configuration 12
#define ADCFG12_Page      0x0C
// (bits in ADCFG12)
#define WHB11             0x80
#define WHB10             0x40
#define WHB9              0x20
#define WHB8              0x10
#define WHB7              0x08
#define WHB6              0x04
#define WHB5              0x02
#define WHB4              0x01

SFR(ADCFG13,0xC3)     //ADC Configuration 13
#define ADCFG13_Page      0x0D
// (bits in ADCFG13)
#define WLB3              0x80
#define WLB2              0x40
#define WLB1              0x20
#define WLB0              0x10

SFR(ADCFG14,0xC3)     //ADC Configuration 14
#define ADCFG14_Page      0x0E
// (bits in ADCFG14)
#define WLB11             0x80
#define WLB10             0x40
#define WLB9              0x20
#define WLB8              0x10
#define WLB7              0x08
#define WLB6              0x04
#define WLB5              0x02
#define WLB4              0x01

SFR(ADCON0, 0xC4)     //ADC Control 0
#define ADCON0_Page       0x00
// (bits in ADCON0)
#define ADCEN             0x80
#define ADCWI             0x40
#define CHS3              0x20
#define ADCI              0x10
#define ADCS              0x08
#define CHS2              0x04
#define CHS1              0x02
#define CHS0              0x01

SFR(ADCDL, 0xC5)     //ADC Data Low
#define ADCDL_Page        0x00
// (bits in ADCDL)
#define ADCV3             0x80
#define ADCV2             0x40
#define ADCV1             0x20
#define ADCV0             0x10

SFR(ADCDH, 0xC6)     //ADC Data High
#define ADCDH_Page        0x00
// (bits in ADCDH)
#define ADCV11            0x80
#define ADCV10            0x40
#define ADCV9             0x20
#define ADCV8             0x10
#define ADCV7             0x08
#define ADCV6             0x04
#define ADCV5             0x02
#define ADCV4             0x01

SFR(CKCON0, 0xC7)     //Clock Control 0
#define CKCON0_Page       0x00
// (bits in CKCON0)
#define AFS               0x80
#define ENCKM             0x40
#define CKMIS1            0x20
#define CKMIS0            0x10
#define CCKS              0x08
#define SCKS2             0x04
#define SCKS1             0x02
#define SCKS0             0x01

SFR(T2CON, 0xC8)     //Timer 2 Control Reg.
#define T2CON_Page        0x00
// (bits in T2CON)

SFR(T3CON, 0xC8)     //Timer 3 Control Reg.
#define T3CON_Page        0x01
// (bits in T3CON)

SFR(T4CON, 0xC8)     //Timer 4 Control Reg.
#define T4CON_Page        0x02
// (bits in T4CON)

SFR(T5CON, 0xC8)     //Timer 5 Control Reg.
#define T5CON_Page        0x03
// (bits in T5CON)

SFR(T6CON, 0xC8)     //Timer 6 Control Reg.
#define T6CON_Page        0x04
// (bits in T6CON)

SFR(T2MOD, 0xC9)     //Timer 2 mode Reg.
#define T2MOD_Page        0x00
// (bits in T2MOD)
#define T2SPL             0x80
#define TL2X12_T2EIP      0x40
#define T2EXH             0x20
#define T2X12             0x10
#define TR2L              0x08
#define TR2LC             0x04
#define T2OE              0x02
#define T2MS0             0x01

SFR(T3MOD, 0xC9)     //Timer 3 mode Reg.
#define T3MOD_Page        0x01
// (bits in T3MOD)
#define T3SPL             0x80
#define TL3X12_T3EIP      0x40
#define T3EXH             0x20
#define T3X12             0x10
#define TR3L              0x08
#define TR3LC             0x04
#define T3OE              0x02
#define T3MS0             0x01

SFR(T4MOD, 0xC9)     //Timer 4 mode Reg.
#define T4MOD_Page        0x02
// (bits in T4MOD)
#define T4SPL             0x80
#define TL4X12_T4EIP      0x40
#define T4EXH             0x20
#define T4X12             0x10
#define TR4L              0x08
#define TR4LC             0x04
#define T4OE              0x02
#define T4MS0             0x01

SFR(RCAP2L, 0xCA)     //Timer2 Capture Low
#define RCAP2L_Page       0x00

SFR(RCAP3L, 0xCA)     //Timer3 Capture Low
#define RCAP3L_Page       0x01

SFR(RCAP4L, 0xCA)     //Timer4 Capture Low
#define RCAP4L_Page       0x02

SFR(TLR5, 0xCA)     //TL5 reload Reg.
#define TLR5_Page         0x03

SFR(TLR6, 0xCA)     //TL6 reload Reg.
#define TLR6_Page         0x04

SFR(RCAP2H, 0xCB)     //Timer2 Capture High
#define RCAP2H_Page       0x00

SFR(RCAP3H, 0xCB)     //Timer3 Capture High
#define RCAP3H_Page       0x01

SFR(RCAP4H, 0xCB)     //Timer4 Capture High
#define RCAP4H_Page       0x02

SFR(THR5, 0xCB)     //TH5 reload Reg.
#define THR5_Page         0x03

SFR(THR6, 0xCB)     //TH6 reload Reg.
#define THR6_Page         0x04

SFR(TL2,  0xCC)     //Timer Low 2
#define TL2_Page          0x00

SFR(TL3,  0xCC)     //Timer Low 3
#define TL3_Page          0x01

SFR(TL4,  0xCC)     //Timer Low 4
#define TL4_Page          0x02

SFR(TL5,  0xCC)     //Timer Low 5
#define TL5_Page          0x03

SFR(TL6,  0xCC)     //Timer Low 6
#define TL6_Page          0x04

SFR(TH2,  0xCD)     //Timer High 2
#define TH2_Page          0x00

SFR(TH3,  0xCD)     //Timer High 3
#define TH3_Page          0x01

SFR(TH4,  0xCD)     //Timer High 4
#define TH4_Page          0x02

SFR(TH5,  0xCD)     //Timer High 5
#define TH5_Page          0x03

SFR(TH6,  0xCD)     //Timer High 6
#define TH6_Page          0x04

SFR(CLRL, 0xCE)     //CL Reload register
#define CLRL_Page         0x00

SFR(CHRL, 0xCF)     //CH Reload register
#define CHRL_Page         0x00

SFR(PSW,  0xD0)     //Program Status Word
#define PSW_Page          0x00
// (bits in PSW)

SFR(SIADR, 0xD1)     //TWI0 Address Reg.
#define SIADR_Page        0x00
// (bits in SIADR)
#define GC                0x01

SFR(SI1ADR, 0xD1)     //TWI1 Address Reg.
#define SI1ADR_Page       0x01
// (bits in SI1ADR)
#define GC1               0x01

SFR(SIA2, 0xD1)     //TWI0 2nd Addr Reg.
#define SIA2_Page         0x02
// (bits in SIA2)
#define A2E               0x01

SFR(SI1A2, 0xD1)     //TWI1 2nd Addr Reg.
#define SI1A2_Page        0x03
// (bits in SI1A2)
#define A2E1              0x01

SFR(SIDAT, 0xD2)     //TWI0 Data Reg.
#define SIDAT_Page        0x00

SFR(SI1DAT, 0xD2)     //TWI1 Data Reg.
#define SI1DAT_Page       0x01

SFR(SIA2M, 0xD2)     //SIA2 Mask Reg.
#define SIA2M_Page        0x02
// (bits in SIA2M)
#define SIA2M7            0x80
#define SIA2M6            0x40
#define SIA2M5            0x20
#define SIA2M4            0x10
#define SIA2M3            0x08
#define SIA2M2            0x04
#define SIA2M1            0x02

SFR(SI1A2M, 0xD2)     //SI1A2 Mask Reg.
#define SI1A2M_Page       0x03
// (bits in SI1A2M)
#define SI1A2M7           0x80
#define SI1A2M6           0x40
#define SI1A2M5           0x20
#define SI1A2M4           0x10
#define SI1A2M3           0x08
#define SI1A2M2           0x04
#define SI1A2M1           0x02

SFR(SISTA, 0xD3)     //TWI0 Status Reg.
#define SISTA_Page        0x00

SFR(SI1STA, 0xD3)     //TWI1 Status Reg.
#define SI1STA_Page       0x01

SFR(SICON, 0xD4)     //TWI0 Control Reg.
#define SICON_Page        0x00
// (bits in SICON)
#define CR2               0x80
#define ENSI              0x40
#define STA               0x20
#define STO               0x10
#define SI                0x08
#define AA                0x04
#define CR1               0x02
#define CR0               0x01

SFR(SI1CON, 0xD4)     //TWI1 Control Reg.
#define SI1CON_Page       0x01
// (bits in SI1CON)
#define CR21              0x80
#define ENSI1             0x40
#define STA1              0x20
#define STO1              0x10
#define SI1               0x08
#define AA1               0x04
#define CR11              0x02
#define CR01              0x01

SFR(KBPATN, 0xD5)     //Keypad Pattern
#define KBPATN_Page       0x00
// (bits in KBPATN)
#define KBPATN7           0x80
#define KBPATN6           0x40
#define KBPATN5           0x20
#define KBPATN4           0x10
#define KBPATN3           0x08
#define KBPATN2           0x04
#define KBPATN1           0x02
#define KBPATN0           0x01

SFR(KBCON, 0xD6)     //Keypad Control
#define KBCON_Page        0x00
// (bits in KBCON)
#define KBCS1             0x80
#define KBCS0             0x40
#define KBES              0x20
#define PATN_SEL          0x02
#define KBIF              0x01

SFR(KBMASK, 0xD7)     //Keypad Int. Mask
#define KBMASK_Page       0x00
// (bits in KBMASK)
#define KBMASK7           0x80
#define KBMASK6           0x40
#define KBMASK5           0x20
#define KBMASK4           0x10
#define KBMASK3           0x08
#define KBMASK2           0x04
#define KBMASK1           0x02
#define KBMASK0           0x01

SFR(CCON, 0xD8)     //PCA Control Reg.
#define CCON_Page         0x00
// (bits in CCON)

SFR(CMOD, 0xD9)     //PCA Mode Reg.
#define CMOD_Page         0x00
// (bits in CMOD)
#define CIDL              0x80
#define BME4              0x40
#define BME2              0x20
#define BME0              0x10
#define CPS2              0x08
#define CPS1              0x04
#define CPS0              0x02
#define ECF               0x01

SFR(CCAPM0, 0xDA)     //PCA Module0 Mode
#define CCAPM0_Page       0x00
// (bits in CCAPM0)
#define DTE0              0x80
#define ECOM0             0x40
#define CAPP0             0x20
#define CAPN0             0x10
#define MAT0              0x08
#define TOG0              0x04
#define PWM0              0x02
#define ECCF0             0x01

SFR(CCAPM6, 0xDA)     //PCA Module6 Mode
#define CCAPM6_Page       0x01
// (bits in CCAPM6)
#define BME6              0x80
#define ECOM6             0x40
#define CAPN6             0x10
#define MAT6              0x08
#define TOG6              0x04
#define PWM6              0x02
#define ECCF6             0x01

SFR(CCAPM1, 0xDB)     //PCA Module1 Mode
#define CCAPM1_Page       0x00
// (bits in CCAPM1)
#define ECOM1             0x40
#define CAPP1             0x20
#define CAPN1             0x10
#define MAT1              0x08
#define TOG1              0x04
#define PWM1              0x02
#define ECCF1             0x01

SFR(CCAPM7, 0xDB)     //PCA Module7 Mode
#define CCAPM7_Page       0x01
// (bits in CCAPM7)
#define ECOM7             0x40
#define CAPN7             0x10
#define MAT7              0x08
#define TOG7              0x04
#define PWM7              0x02
#define ECCF7             0x01

SFR(CCAPM2, 0xDC)     //PCA Module2 Mode
#define CCAPM2_Page       0x00
// (bits in CCAPM2)
#define DTE2              0x80
#define ECOM2             0x40
#define CAPP2             0x20
#define CAPN2             0x10
#define MAT2              0x08
#define TOG2              0x04
#define PWM2              0x02
#define ECCF2             0x01

SFR(CCAPM3, 0xDD)     //PCA Module3 Mode
#define CCAPM3_Page       0x00
// (bits in CCAPM3)
#define ECOM3             0x40
#define CAPP3             0x20
#define CAPN3             0x10
#define MAT3              0x08
#define TOG3              0x04
#define PWM3              0x02
#define ECCF3             0x01

SFR(CCAPM4, 0xDE)     //PCA Module4 Mode
#define CCAPM4_Page       0x00
// (bits in CCAPM4)
#define DTE4              0x80
#define ECOM4             0x40
#define CAPP4             0x20
#define CAPN4             0x10
#define MAT4              0x08
#define TOG4              0x04
#define PWM4              0x02
#define ECCF4             0x01

SFR(CCAPM5, 0xDF)     //PCA Module5 Mode
#define CCAPM5_Page       0x00
// (bits in CCAPM5)
#define ECOM5             0x40
#define CAPP5             0x20
#define CAPN5             0x10
#define MAT5              0x08
#define TOG5              0x04
#define PWM5              0x02
#define ECCF5             0x01

SFR(ACC,  0xE0)     //Accumulator
#define ACC_Page          0x00

SFR(WDTCR, 0xE1)     //WDT Control register
#define WDTCR_Page        0x00
// (bits in WDTCR)
#define WREN              0x80
#define NSW               0x40
#define ENW               0x20
#define CLRW              0x10
#define WIDL              0x08
#define PS2               0x04
#define PS1               0x02
#define PS0               0x01

SFR(IFD,  0xE2)     //ISP Flash data
#define IFD_Page          0x00

SFR(IFADRH, 0xE3)     //ISP Flash Addr. High
#define IFADRH_Page       0x00

SFR(IFADRL, 0xE4)     //ISP Flash Addr. Low
#define IFADRL_Page       0x00

SFR(IFMT, 0xE5)     //ISP Mode Table
#define IFMT_Page         0x00
// (bits in IFMT)
#define MS7               0x80
#define MS3               0x08
#define MS2               0x04
#define MS1               0x02
#define MS0               0x01

SFR(SCMD, 0xE6)     //ISP Serial Command
#define SCMD_Page         0x00

SFR(ISPCR, 0xE7)     //ISP Control Register
#define ISPCR_Page        0x00
// (bits in ISPCR)
#define ISPEN             0x80
#define SWBS              0x40
#define SRST              0x20
#define CFAIL             0x10

SFR(P4, 0xE8)     //Port 4
#define P4_Page           0x00
// (bits in P4)

SFR(CL, 0xE9)     //PCA base timer Low
#define CL_Page           0x00

SFR(CCAP0L, 0xEA)     //PCA module0 capture Low
#define CCAP0L_Page       0x00

SFR(CCAP6L, 0xEA)     //PCA module6 capture Low
#define CCAP6L_Page       0x01

SFR(CCAP1L, 0xEB)     //PCA module1 capture Low
#define CCAP1L_Page       0x00

SFR(CCAP7L, 0xEB)     //PCA module7 capture Low
#define CCAP7L_Page       0x01

SFR(CCAP2L, 0xEC)     //PCA module2 capture Low
#define CCAP2L_Page       0x00

SFR(CCAP3L, 0xED)     //PCA module3 capture Low
#define CCAP3L_Page       0x00

SFR(CCAP4L, 0xEE)     //PCA module4 capture Low
#define CCAP4L_Page       0x00

SFR(CCAP5L, 0xEF)     //PCA module5 capture Low
#define CCAP5L_Page       0x00

SFR(B, 0xF0)     //B Register
#define B_Page            0x00

SFR(PAOE, 0xF1)     //PWM Additional Output Enable
#define PAOE_Page         0x00
// (bits in PAOE)
#define POE3              0x80
#define POE2B             0x40
#define POE2A             0x20
#define POE2              0x10
#define POE1              0x08
#define POE0B             0x04
#define POE0A             0x02
#define POE0              0x01

SFR(PCAPWM0, 0xF2)     //PCA PWM0 Mode
#define PCAPWM0_Page      0x00
// (bits in PCAPWM0)
#define P0RS1             0x80
#define P0RS0             0x40
#define P0INV             0x04
#define ECAP0H            0x02
#define ECAP0L            0x01

SFR(PCAPWM6, 0xF2)     //PCA PWM6 Mode
#define PCAPWM6_Page      0x01
// (bits in PCAPWM6)
#define P6RS1             0x80
#define P6RS0             0x40
#define CCF6              0x08
#define P6INV             0x04
#define ECAP6H            0x02
#define ECAP6L            0x01

SFR(PCAPWM1, 0xF3)     //PCA PWM1 Mode
#define PCAPWM1_Page      0x00
// (bits in PCAPWM1)
#define P1RS1             0x80
#define P1RS0             0x40
#define P1INV             0x04
#define ECAP1H            0x02
#define ECAP1L            0x01

SFR(PCAPWM7, 0xF3)     //PCA PWM7 Mode
#define PCAPWM7_Page      0x01
// (bits in PCAPWM7)
#define P7RS1             0x80
#define P7RS0             0x40
#define CCF7              0x08
#define P7INV             0x04
#define ECAP7H            0x02
#define ECAP7L            0x01

SFR(PCAPWM2, 0xF4)     //PCA PWM2 Mode
#define PCAPWM2_Page      0x00
// (bits in PCAPWM2)
#define P2RS1             0x80
#define P2RS0             0x40
#define P2INV             0x04
#define ECAP2H            0x02
#define ECAP2L            0x01

SFR(PCAPWM3, 0xF5)     //PCA PWM3 Mode
#define PCAPWM3_Page      0x00
// (bits in PCAPWM3)
#define P3RS1             0x80
#define P3RS0             0x40
#define P3INV             0x04
#define ECAP3H            0x02
#define ECAP3L            0x01

SFR(PCAPWM4, 0xF6)     //PCA PWM4 Mode
#define PCAPWM4_Page      0x00
// (bits in PCAPWM4)
#define P4RS1             0x80
#define P4RS0             0x40
#define P4INV             0x04
#define ECAP4H            0x02
#define ECAP4L            0x01

SFR(PCAPWM5, 0xF7)     //PCA PWM5 Mode
#define PCAPWM5_Page      0x00
// (bits in PCAPWM5)
#define P5RS1             0x80
#define P5RS0             0x40
#define P5INV             0x04
#define ECAP5H            0x02
#define ECAP5L            0x01

SFR(P5, 0xF8)     //Port 5
#define P5_Page           0x00
// (bits in P5)

SFR(P6, 0xF8)     //Port 6
#define P6_Page           0x01
// (bits in P6)

SFR(P7, 0xF8)     //Port 7
#define P7_Page           0x02
// (bits in P7)

SFR(CH, 0xF9)     //PCA base timer High
#define CH_Page           0x00

SFR(CCAP0H, 0xFA)     //PCA Module0 capture High
#define CCAP0H_Page       0x00

SFR(CCAP6H, 0xFA)     //PCA Module6 capture High
#define CCAP6H_Page       0x01

SFR(CCAP1H, 0xFB)     //PCA Module1 capture High
#define CCAP1H_Page       0x00

SFR(CCAP7H, 0xFB)     //PCA Module7 capture High
#define CCAP7H_Page       0x01

SFR(CCAP2H, 0xFC)     //PCA Module2 capture High
#define CCAP2H_Page       0x00

SFR(CCAP3H, 0xFD)     //PCA Module3 capture High
#define CCAP3H_Page       0x00

SFR(CCAP4H, 0xFE)     //PCA Module4 capture High
#define CCAP4H_Page       0x00

SFR(CCAP5H, 0xFF)     //PCA Module5 capture High
#define CCAP5H_Page       0x00


//===== Page P =====//
#define IAPLB_P           0x03     //IAP Low Boundary
// (bits in IAPLB)
#define IAPLB6_P          0x80
#define IAPLB5_P          0x40
#define IAPLB4_P          0x20
#define IAPLB3_P          0x10
#define IAPLB2_P          0x08
#define IAPLB1_P          0x04
#define IAPLB0_P          0x02

#define CKCON2_P          0x40     //Clock Control 2
// (bits in CKCON2)
#define XTGS1_P           0x80
#define XTGS0_P           0x40
#define XTALE_P           0x20
#define IHRCOE_P          0x10
#define MCKS1_P           0x08
#define MCKS0_P           0x04
#define OSCS1_P           0x02
#define OSCS0_P           0x01

#define CKCON3_P          0x41     //Clock Control 3
// (bits in CKCON3)
#define WDTCS1_P          0x80
#define WDTCS0_P          0x40
#define FWKP_P            0x20
#define WDTFS_P           0x10
#define MCKD1_P           0x08
#define MCKD0_P           0x04
#define MCDS1_P           0x02
#define MCDS0_P           0x01

#define CKCON4_P          0x42     //Clock Control 4
// (bits in CKCON4)
#define RCSS2_P           0x80
#define RCSS1_P           0x40
#define RCSS0_P           0x20
#define RPSC2_P           0x10
#define RPSC1_P           0x08
#define RPSC0_P           0x04
#define RTCCS3_P          0x02
#define RTCCS2_P          0x01

#define CKCON5_P          0x43     //Clock Control 5
// (bits in CKCON5)
#define CKMS0_P           0x01

#define PCON2_P           0x44     //Power Control 2
// (bits in PCON2)
#define AWBOD1_P          0x80
#define BO1S1_P           0x20
#define BO1S0_P           0x10
#define BO1RE_P           0x08
#define EBOD1_P           0x04
#define BO0RE_P           0x02

#define PCON3_P           0x45     //Power Control 3
// (bits in PCON3)
#define IVREN_P           0x80
#define SPWRE_P           0x10

#define SPCON0_P          0x48     //SFR Page Control 0
// (bits in SPCON0)
#define P6CTL_P           0x40
#define P4CTL_P           0x20
#define WRCTL_P           0x10
#define CKCTL0_P          0x04
#define PWCTL1_P          0x02
#define PWCTL0_P          0x01

#define DCON0_P           0x4C     //Device Control 0
// (bits in DCON0)
#define HSE_P             0x80
#define IAPO_P            0x40
#define HSE1_P            0x20
#define IORCTL_P          0x04
#define RSTIO_P           0x02
#define OCDE_P            0x01

#define SPHB_P            0x53     //SP High Boundary
// (bits in SPHB)
#define SPHB3_P           0x08
#define SPHB2_P           0x04
#define SPHB1_P           0x02
#define SPHB0_P           0x01

#define RTCCR_P           0x54     //RTC Control Reg.
// (bits in RTCCR)
#define RTCE_P            0x80
#define RTCO_P            0x40
#define RTCRL5_P          0x20
#define RTCRL4_P          0x10
#define RTCRL3_P          0x08
#define RTCRL2_P          0x04
#define RTCRL1_P          0x02
#define RTCRL0_P          0x01

#define RTCTM_P           0x55     //RTC Timer Register
// (bits in RTCTM)
#define RTCCS1_P          0x80
#define RTCCS0_P          0x40
#define RTCCT5_P          0x20
#define RTCCT4_P          0x10
#define RTCCT3_P          0x08
#define RTCCT2_P          0x04
#define RTCCT1_P          0x02
#define RTCCT0_P          0x01

#define PCON0_P           0x87     //Power Control 0
// (bits in PCON0)
#define SMOD1_P           0x80
#define SMOD0_P           0x40
#define POF0_P            0x10
#define PD_P              0x02
#define IDL_P             0x01

#define PCON1_P           0x97     //Power Control 1
// (bits in PCON1)
#define SWRF_P            0x80
#define EXRF_P            0x40
#define MCDF_P            0x20
#define RTCF_P            0x10
#define SPWF_P            0x08
#define BOF1_P            0x04
#define BOF0_P            0x02
#define WDTF_P            0x01

#define CKCON0_P          0xC7     //Clock Control 0
// (bits in CKCON0)
#define AFS_P             0x80
#define ENCKM_P           0x40
#define CKMIS1_P          0x20
#define CKMIS0_P          0x10
#define CCKS_P            0x08
#define SCKS2_P           0x04
#define SCKS1_P           0x02
#define SCKS0_P           0x01

#define WDTCR_P           0xE1     //Watch-dog-timer Control register
// (bits in WDTCR)
#define WREN_P            0x80
#define NSW_P             0x40
#define ENW_P             0x20
#define CLRW_P            0x10
#define WIDL_P            0x08
#define PS2_P             0x04
#define PS1_P             0x02
#define PS0_P             0x01

#define P4_P              0xE8     //Port 4
// (bits in P4)
#define P47_P             0x80
#define P46_P             0x40
#define P45_P             0x20
#define P44_P             0x10
#define P43_P             0x08
#define P42_P             0x04
#define P41_P             0x02
#define P40_P             0x01

#define P6_P              0xF8     //Port 6
// (bits in P6)
#define P67_P             0x80
#define P66_P             0x40
#define P65_P             0x20
#define P64_P             0x10
#define P63_P             0x08
#define P62_P             0x04
#define P61_P             0x02
#define P60_P             0x01

#endif
