/**
  * @file    cs32f0xx_dma.h
  * @brief   This file contains all the functions prototypes for the DMA firmware
  *          library.
  * @author  ChipSea MCU Group
  * @version V1.0.0
  * @date   2018.11.01         
  * @copyright CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
  * @note
  * <h2><center>&copy; COPYRIGHT 2018 ChipSea</center></h2>
  *
  */

#ifndef __CS32F0XX_DMA_H__
#define __CS32F0XX_DMA_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "cs32f0xx.h"


/** @addtogroup CS32F0xx_HAL_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/** 
  * @struct dma_config_t
  * @brief DMA channel config structures definition
  */
typedef struct
{
    uint32_t peri_base_addr;     //!<  DMA Channel the peripheral base address.             
    uint32_t mem_base_addr;      //!<  DMA Channel the memory base address.               
    uint32_t transfer_direct;    //!<  DMA transfer Direction                                        
    uint32_t buf_size;           //!<  DMA specifies the buffer size(data unit equal to peri_data_width (or mem_data_width)).    
    uint32_t peri_inc_flag;      //!<  DMA enable or disable the peripheral address increment.                                      
    uint32_t mem_inc_flag;       //!<  DMA enable or disable the memory address increment.                                        
    uint32_t peri_data_width;    //!<  DMA specifies the peripheral data width.                                     
    uint32_t mem_data_width;     //!<  DMA specifies the memory data width.                                        
    uint32_t operate_mode;       //!<  DMA Channel operation mode.                                                                                     
    uint32_t priority_level;     //!<  DMA set the Channel priority.                                                  
    uint32_t m2m_flag;           //!<  DMA enable or disable the Channel used in memory-to-memory transfer.                                       
}dma_config_t;


/** 
  * @ brief DMA data transfer direction 
  */
#define DMA_CHANNEL_CHECK(channel) (((channel) == DMA1_CHANNEL1) || ((channel) == DMA1_CHANNEL2) || \
                                    ((channel) == DMA1_CHANNEL3) || ((channel) == DMA1_CHANNEL4) || \
                                    ((channel) == DMA1_CHANNEL5) || ((channel) == DMA1_CHANNEL6) || \
                                    ((channel) == DMA1_CHANNEL7) || ((channel) == DMA2_CHANNEL1) || \
                                    ((channel) == DMA2_CHANNEL2) || ((channel) == DMA2_CHANNEL3) || \
                                    ((channel) == DMA2_CHANNEL4) || ((channel) == DMA2_CHANNEL5)) 

/** 
  * @ brief DMA data transfer direction 
  */
#define DMA_TRANS_DIR_FROM_PERI        ((uint32_t)0x00000000)  //!< DMA transfer data from peripheral 
#define DMA_TRANS_DIR_FROM_MEM          DMA_CHxCTR_DIR         //!< DMA transfer data from memory 
#define DMA_TRANS_DIR_CHECK(direct) (((direct) == DMA_TRANS_DIR_FROM_PERI) || ((direct) == DMA_TRANS_DIR_FROM_MEM))
                         


/**  
  * @ brief DMA peripheral increment enable defintion
  */
#define DMA_PERI_INC_DISABLE          ((uint32_t)0x00000000)  //!< DMA disable peripheral increment
#define DMA_PERI_INC_ENABLE           DMA_CHxCTR_PAGM         //!< DMA enable peripheral increment
#define DMA_PERI_INC_CHECK(flag) (((flag) == DMA_PERI_INC_DISABLE) || ((flag) == DMA_PERI_INC_ENABLE))
                                            


/**  
  * @ brief DMA memory increment enable defintion
  */
#define DMA_MEM_INC_DISABLE        ((uint32_t)0x00000000)     //!< DMA disable memory increment 
#define DMA_MEM_INC_ENABLE          DMA_CHxCTR_MAGM           //!< DMA enable memory increment 
#define DMA_MEM_INC_CHECK(flag)    (((flag) == DMA_MEM_INC_DISABLE) || ((flag) == DMA_MEM_INC_ENABLE))
                                        

/** 
  * @ brief DMA peripheral data width defintion
  */
#define DMA_PERI_DATA_WIDTH_BYTE        ((uint32_t)0x00000000)  //!< DMA peripheral width is BYTE 
#define DMA_PERI_DATA_WIDTH_HALFWORD      DMA_CHxCTR_PWDH_0     //!< DMA peripheral width is HALFWORD 
#define DMA_PERI_DATA_WIDTH_WORD          DMA_CHxCTR_PWDH_1     //!< DMA peripheral width is WORD 

#define DMA_PERI_DATA_WIDTH_CHECK(size) (((size) == DMA_PERI_DATA_WIDTH_BYTE) || \
                                         ((size) == DMA_PERI_DATA_WIDTH_HALFWORD) || \
                                         ((size) == DMA_PERI_DATA_WIDTH_WORD))
/** 
  * @ brief DMA memory data width defintion
  */
#define DMA_MEM_DATA_WIDTH_BYTE            ((uint32_t)0x00000000)  //!< DMA memory width is BYTE 
#define DMA_MEM_DATA_WIDTH_HALFWORD        DMA_CHxCTR_MWDH_0       //!< DMA mmeory width is HALFWORD 
#define DMA_MEM_DATA_WIDTH_WORD            DMA_CHxCTR_MWDH_1       //!< DMA memory width is WORD 

#define DMA_MEM_DATA_WIDTH_CHECK(SIZE) (((SIZE) == DMA_MEM_DATA_WIDTH_BYTE) || \
                                        ((SIZE) == DMA_MEM_DATA_WIDTH_HALFWORD) || \
                                        ((SIZE) == DMA_MEM_DATA_WIDTH_WORD))


/** 
  * @ brief DMA operation mode defintion
  */
#define DMA_OPERATE_MODE_NORMAL           ((uint32_t)0x00000000)   //!< DMA normal mode 
#define DMA_OPERATE_MODE_CIRCULAR          DMA_CHxCTR_CIRM         //!< DMA circular mode
#define DMA_OPERATE_MODE_CHECK(mode) (((mode) == DMA_OPERATE_MODE_NORMAL) || ((mode) == DMA_OPERATE_MODE_CIRCULAR))


/** 
  * @ brief DMA channel priority defintion
  */
#define DMA_CHANNEL_PRIORITY_HIGHEST       DMA_CHxCTR_PRIL         //!< DMA highest channel priority 
#define DMA_CHANNEL_PRIORITY_HIGH          DMA_CHxCTR_PRIL_1       //!< DMA high channel priority 
#define DMA_CHANNEL_PRIORITY_MEDIUM        DMA_CHxCTR_PRIL_0       //!< DMA medium channel priority 
#define DMA_CHANNEL_PRIORITY_LOW           ((uint32_t)0x00000000)  //!< DMA low channel priority 

#define DMA_CHANNEL_PRIORITY_CHECK(priority) (((priority) == DMA_CHANNEL_PRIORITY_HIGHEST) || \
                                              ((priority) == DMA_CHANNEL_PRIORITY_HIGH)    || \
                                              ((priority) == DMA_CHANNEL_PRIORITY_MEDIUM)  || \
                                              ((priority) == DMA_CHANNEL_PRIORITY_LOW))
                                                                
/** 
  * @ brief DMA memory_to_memory mode  defintion
  */
#define DMA_M2M_MODE_DISABLE       ((uint32_t)0x00000000)  //!< DMA disable M2MM (memory to memory mode)
#define DMA_M2M_MODE_ENABLE         DMA_CHxCTR_M2MM        //!< DMA enable M2MM (memory to memory mode)
#define DMA_M2M_MODE_CHECK(flag) (((flag) == DMA_M2M_MODE_DISABLE) || ((flag) == DMA_M2M_MODE_ENABLE))

/**  
  * @brief DMA buffer size check definition
  */
#define DMA_BUFFER_SIZE_CHECK(size) (((size) >= 0x1) && ((size) < 0x10000))

/**  
  * @brief DMA check definition
  */
#define DMA_BUS_CHECK(dma) (((dma) == DMA1) || ((dma) == DMA2))
                               
/** @defgroup DMA_interrupts_definition
  * @{
  */
#define DMA_INT_CONFIG_CMP              DMA_CHxCTR_CMPIE    //!< Enable Transfer complete interrupt
#define DMA_INT_CONFIG_HLF              DMA_CHxCTR_HLFIE    //!< Enable Half transfer interrupt
#define DMA_INT_CONFIG_ERR              DMA_CHxCTR_ERRIE    //!< Enable Transfer error interrupt 
#define DMA_INT_CONFIG_CHECK(flag) ((((flag) & 0xFFFFFFF1) == 0x00) && ((flag) != 0x00))

#define DMA1_INT_G1                     DMA_STS_GIF1    //!< Global interrupt flag of Channel 1   
#define DMA1_INT_CMP1                   DMA_STS_CMPIF1  //!< Transfer complete flag of Channel 1   
#define DMA1_INT_HLF1                   DMA_STS_HLFIF1  //!< Half transfer flag of Channel 1  
#define DMA1_INT_ERR1                   DMA_STS_ERRIF1  //!< Transfer error flag of Channel 1  

#define DMA1_INT_G2                     DMA_STS_GIF2    //!< Global interrupt flag of Channe 2   
#define DMA1_INT_CMP2                   DMA_STS_CMPIF2  //!< Transfer complete flag of Channel 2   
#define DMA1_INT_HLF2                   DMA_STS_HLFIF2  //!< Half transfer flag of Channel 2  
#define DMA1_INT_ERR2                   DMA_STS_ERRIF2  //!< Transfer error flag of Channel 2 

#define DMA1_INT_G3                     DMA_STS_GIF3    //!< Global interrupt flag of Channel 3  
#define DMA1_INT_CMP3                   DMA_STS_CMPIF3  //!< Transfer complete flag of Channel 3   
#define DMA1_INT_HLF3                   DMA_STS_HLFIF3  //!< Half transfer flag of Channel 3 
#define DMA1_INT_ERR3                   DMA_STS_ERRIF3  //!< Transfer error flag of Channel 3 

#define DMA1_INT_G4                     DMA_STS_GIF4    //!< Global interrupt flag of Channel 4   
#define DMA1_INT_CMP4                   DMA_STS_CMPIF4  //!< Transfer complete flag of Channel 4   
#define DMA1_INT_HLF4                   DMA_STS_HLFIF4  //!< Half transfer flag of Channel 4  
#define DMA1_INT_ERR4                   DMA_STS_ERRIF4  //!< Transfer error flag of Channel 4  

#define DMA1_INT_G5                     DMA_STS_GIF5    //!< Global interrupt flag of Channel 5   
#define DMA1_INT_CMP5                   DMA_STS_CMPIF5  //!< Transfer complete flag of Channel 5   
#define DMA1_INT_HLF5                   DMA_STS_HLFIF5  //!< Half transfer flag of Channel 5  
#define DMA1_INT_ERR5                   DMA_STS_ERRIF5  //!< Transfer error flag of Channel 5  

#define DMA1_INT_G6                     DMA_STS_GIF6    //!< Global interrupt flag of Channel 6
#define DMA1_INT_CMP6                   DMA_STS_CMPIF6  //!< Transfer complete flag of Channel 6
#define DMA1_INT_HLF6                   DMA_STS_HLFIF6  //!< Half transfer flag of Channel 6
#define DMA1_INT_ERR6                   DMA_STS_ERRIF6  //!< Transfer error flag of Channel 6

#define DMA1_INT_G7                     DMA_STS_GIF7    //!< Global interrupt flag of Channel 7
#define DMA1_INT_CMP7                   DMA_STS_CMPIF7  //!< Transfer complete flag of Channel 7 
#define DMA1_INT_HLF7                   DMA_STS_HLFIF7  //!< Half transfer flag of Channel 7 
#define DMA1_INT_ERR7                   DMA_STS_ERRIF7  //!< Transfer error flag of Channel 7

#define DMA2_INT_G1                    ((uint32_t)0x10000001)  //!< Global interrupt flag of Channel 1
#define DMA2_INT_CMP1                  ((uint32_t)0x10000002)  //!< Transfer complete flag of Channel 1 
#define DMA2_INT_HLF1                  ((uint32_t)0x10000004)  //!< Half transfer flag of Channel 1
#define DMA2_INT_ERR1                  ((uint32_t)0x10000008)  //!< Transfer error flag of Channel 1

#define DMA2_INT_G2                    ((uint32_t)0x10000010)  //!< Global interrupt flag of Channel 2
#define DMA2_INT_CMP2                  ((uint32_t)0x10000020)  //!< Transfer complete flag of Channel 2 
#define DMA2_INT_HLF2                  ((uint32_t)0x10000040)  //!< Half transfer flag of Channel 2
#define DMA2_INT_ERR2                  ((uint32_t)0x10000080)  //!< Transfer error flag of Channel 2 

#define DMA2_INT_G3                    ((uint32_t)0x10000100)  //!< Global interrupt flag of Channel 3 
#define DMA2_INT_CMP3                  ((uint32_t)0x10000200)  //!< Transfer complete flag of Channel 3 
#define DMA2_INT_HLF3                  ((uint32_t)0x10000400)  //!< Half transfer flag of Channel 3 
#define DMA2_INT_ERR3                  ((uint32_t)0x10000800)  //!< Transfer error flag of Channel 3 

#define DMA2_INT_G4                    ((uint32_t)0x10001000)  //!< Global interrupt flag of Channel 4 
#define DMA2_INT_CMP4                  ((uint32_t)0x10002000)  //!< Transfer complete flag of Channel 4 
#define DMA2_INT_HLF4                  ((uint32_t)0x10004000)  //!< Half transfer flag of Channel 4
#define DMA2_INT_ERR4                  ((uint32_t)0x10008000)  //!< Transfer error flag of Channel 4 

#define DMA2_INT_G5                    ((uint32_t)0x10010000)  //!< Global interrupt flag of Channel 5
#define DMA2_INT_CMP5                  ((uint32_t)0x10020000)  //!< Transfer complete flag of Channel 5
#define DMA2_INT_HLF5                  ((uint32_t)0x10040000)  //!< Half transfer flag of Channel 5 
#define DMA2_INT_ERR5                  ((uint32_t)0x10080000)  //!< Transfer error flag of Channel 5 

#define DMA_GET_INT_CHECK(flag) (((flag) == DMA1_INT_G1)   || ((flag) == DMA1_INT_CMP1) || \
                                 ((flag) == DMA1_INT_HLF1) || ((flag) == DMA1_INT_ERR1) || \
                                 ((flag) == DMA1_INT_G2)   || ((flag) == DMA1_INT_CMP2) || \
                                 ((flag) == DMA1_INT_HLF2) || ((flag) == DMA1_INT_ERR2) || \
                                 ((flag) == DMA1_INT_G3)   || ((flag) == DMA1_INT_CMP3) || \
                                 ((flag) == DMA1_INT_HLF3) || ((flag) == DMA1_INT_ERR3) || \
                                 ((flag) == DMA1_INT_G4)   || ((flag) == DMA1_INT_CMP4) || \
                                 ((flag) == DMA1_INT_HLF4) || ((flag) == DMA1_INT_ERR4) || \
                                 ((flag) == DMA1_INT_G5)   || ((flag) == DMA1_INT_CMP5) || \
                                 ((flag) == DMA1_INT_HLF5) || ((flag) == DMA1_INT_ERR5) || \
                                 ((flag) == DMA1_INT_G6)   || ((flag) == DMA1_INT_CMP6) || \
                                 ((flag) == DMA1_INT_HLF6) || ((flag) == DMA1_INT_ERR6) || \
                                 ((flag) == DMA1_INT_G7)   || ((flag) == DMA1_INT_CMP7) || \
                                 ((flag) == DMA1_INT_HLF7) || ((flag) == DMA1_INT_ERR7) || \
                                 ((flag) == DMA2_INT_G1)   || ((flag) == DMA2_INT_CMP1) || \
                                 ((flag) == DMA2_INT_HLF1) || ((flag) == DMA2_INT_ERR1) || \
                                 ((flag) == DMA2_INT_G2)   || ((flag) == DMA2_INT_CMP2) || \
                                 ((flag) == DMA2_INT_HLF2) || ((flag) == DMA2_INT_ERR2) || \
                                 ((flag) == DMA2_INT_G3)   || ((flag) == DMA2_INT_CMP3) || \
                                 ((flag) == DMA2_INT_HLF3) || ((flag) == DMA2_INT_ERR3) || \
                                 ((flag) == DMA2_INT_G4)   || ((flag) == DMA2_INT_CMP4) || \
                                 ((flag) == DMA2_INT_HLF4) || ((flag) == DMA2_INT_ERR4) || \
                                 ((flag) == DMA2_INT_G5)   || ((flag) == DMA2_INT_CMP5) || \
                                 ((flag) == DMA2_INT_HLF5) || ((flag) == DMA2_INT_ERR5))

#define DMA_CLEAR_INT_CHECK(flag) (((((flag) & 0xF0000000) == 0x00) || (((flag) & 0xEFF00000) == 0x00)) && ((flag) != 0x00))

/**
  * @}
  */

/** @defgroup DMA_flags_definition 
  * @{
  */
#define DMA1_FLAG_G1              DMA_STS_GIF1    //!< Global interrupt flag of Channel 1   
#define DMA1_FLAG_CMP1            DMA_STS_CMPIF1  //!< Transfer complete flag of Channel 1   
#define DMA1_FLAG_HLF1            DMA_STS_HLFIF1  //!< Half transfer flag of Channel 1 
#define DMA1_FLAG_ERR1            DMA_STS_ERRIF1  //!< Transfer error flag of Channel 1    

#define DMA1_FLAG_G2              DMA_STS_GIF2    //!< Global interrupt flag of Channel 2 
#define DMA1_FLAG_CMP2            DMA_STS_CMPIF2  //!< Transfer complete flag of Channel 2  
#define DMA1_FLAG_HLF2            DMA_STS_HLFIF2  //!< Half transfer flag of Channel 2
#define DMA1_FLAG_ERR2            DMA_STS_ERRIF2  //!< Transfer error flag of Channel 2    

#define DMA1_FLAG_G3              DMA_STS_GIF3    //!< Global interrupt flag of Channel 3  
#define DMA1_FLAG_CMP3            DMA_STS_CMPIF3  //!< Transfer complete flag of Channel 3  
#define DMA1_FLAG_HLF3            DMA_STS_HLFIF3  //!< Half transfer flag of Channel 3
#define DMA1_FLAG_ERR3            DMA_STS_ERRIF3  //!< Transfer error flag of Channel 3    

#define DMA1_FLAG_G4              DMA_STS_GIF4    //!< Global interrupt flag of Channel 4  
#define DMA1_FLAG_CMP4            DMA_STS_CMPIF4  //!< Transfer complete flag of Channel 4   
#define DMA1_FLAG_HLF4            DMA_STS_HLFIF4  //!< Half transfer flag of Channel 4 
#define DMA1_FLAG_ERR4            DMA_STS_ERRIF4  //!< Transfer error flag of Channel 4  

#define DMA1_FLAG_G5              DMA_STS_GIF5    //!< Global interrupt flag of Channel 5 
#define DMA1_FLAG_CMP5            DMA_STS_CMPIF5  //!< Transfer complete flag of Channel 5   
#define DMA1_FLAG_HLF5            DMA_STS_HLFIF5  //!< Half transfer flag of Channel 5
#define DMA1_FLAG_ERR5            DMA_STS_ERRIF5  //!< Transfer error flag of Channel 5    

#define DMA1_FLAG_G6              DMA_STS_GIF6    //!< Global interrupt flag of Channel 6
#define DMA1_FLAG_CMP6            DMA_STS_CMPIF6  //!< Transfer complete flag of Channel 6
#define DMA1_FLAG_HLF6            DMA_STS_HLFIF6  //!< Half transfer flag of Channel 6 
#define DMA1_FLAG_ERR6            DMA_STS_ERRIF6  //!< Transfer error flag of Channel 6 

#define DMA1_FLAG_G7              DMA_STS_GIF7    //!< Global interrupt flag of Channel 7 
#define DMA1_FLAG_CMP7            DMA_STS_CMPIF7  //!< Transfer complete flag of Channel 7 
#define DMA1_FLAG_HLF7            DMA_STS_HLFIF7  //!< Half transfer flag of Channel 7 
#define DMA1_FLAG_ERR7            DMA_STS_ERRIF7  //!< Transfer error flag of Channel 7

#define DMA2_FLAG_G1              ((uint32_t)0x10000001) //!< Global interrupt flag of Channel 1
#define DMA2_FLAG_CMP1            ((uint32_t)0x10000002) //!< Transfer complete flag of Channel 1
#define DMA2_FLAG_HLF1            ((uint32_t)0x10000004) //!< Half transfer flag of Channel 1
#define DMA2_FLAG_ERR1            ((uint32_t)0x10000008) //!< Transfer error flag of Channel 1

#define DMA2_FLAG_G2              ((uint32_t)0x10000010) //!< Global interrupt flag of Channel 2
#define DMA2_FLAG_CMP2            ((uint32_t)0x10000020) //!< Transfer complete flag of Channel 2
#define DMA2_FLAG_HLF2            ((uint32_t)0x10000040) //!< Half transfer flag of Channel 2 
#define DMA2_FLAG_ERR2            ((uint32_t)0x10000080) //!< Transfer error flag of Channel 2 

#define DMA2_FLAG_G3              ((uint32_t)0x10000100) //!< Global interrupt flag of Channel 3 
#define DMA2_FLAG_CMP3            ((uint32_t)0x10000200) //!< Transfer complete flag of Channel 3
#define DMA2_FLAG_HLF3            ((uint32_t)0x10000400) //!< Half transfer flag of Channel 3
#define DMA2_FLAG_ERR3            ((uint32_t)0x10000800) //!< Transfer error flag of Channel 3

#define DMA2_FLAG_G4              ((uint32_t)0x10001000) //!< Global interrupt flag of Channel 4
#define DMA2_FLAG_CMP4            ((uint32_t)0x10002000) //!< Transfer complete flag of Channel 4 
#define DMA2_FLAG_HLF4            ((uint32_t)0x10004000) //!< Half transfer flag of Channel 4
#define DMA2_FLAG_ERR4            ((uint32_t)0x10008000) //!< Transfer error flag of Channel 4 

#define DMA2_FLAG_G5              ((uint32_t)0x10010000) //!< Global interrupt flag of Channel 5 
#define DMA2_FLAG_CMP5            ((uint32_t)0x10020000) //!< Transfer complete flag of Channel 5 
#define DMA2_FLAG_HLF5            ((uint32_t)0x10040000) //!< Half transfer flag of Channel 5 
#define DMA2_FLAG_ERR5            ((uint32_t)0x10080000) //!< Transfer error flag of Channel 5 

#define DMA_GET_FLAG_CHECK(flag) (((flag) == DMA1_FLAG_G1)   || ((flag) == DMA1_FLAG_CMP1) || \
                                  ((flag) == DMA1_FLAG_HLF1) || ((flag) == DMA1_FLAG_ERR1) || \
                                  ((flag) == DMA1_FLAG_G2)   || ((flag) == DMA1_FLAG_CMP2) || \
                                  ((flag) == DMA1_FLAG_HLF2) || ((flag) == DMA1_FLAG_ERR2) || \
                                  ((flag) == DMA1_FLAG_G3)   || ((flag) == DMA1_FLAG_CMP3) || \
                                  ((flag) == DMA1_FLAG_HLF3) || ((flag) == DMA1_FLAG_ERR3) || \
                                  ((flag) == DMA1_FLAG_G4)   || ((flag) == DMA1_FLAG_CMP4) || \
                                  ((flag) == DMA1_FLAG_HLF4) || ((flag) == DMA1_FLAG_ERR4) || \
                                  ((flag) == DMA1_FLAG_G5)   || ((flag) == DMA1_FLAG_CMP5) || \
                                  ((flag) == DMA1_FLAG_HLF5) || ((flag) == DMA1_FLAG_ERR5) || \
                                  ((flag) == DMA1_FLAG_G6)   || ((flag) == DMA1_FLAG_CMP6) || \
                                  ((flag) == DMA1_FLAG_HLF6) || ((flag) == DMA1_FLAG_ERR6) || \
                                  ((flag) == DMA1_FLAG_G7)   || ((flag) == DMA1_FLAG_CMP7) || \
                                  ((flag) == DMA1_FLAG_HLF7) || ((flag) == DMA1_FLAG_ERR7) || \
                                  ((flag) == DMA2_FLAG_G1)   || ((flag) == DMA2_FLAG_CMP1) || \
                                  ((flag) == DMA2_FLAG_HLF1) || ((flag) == DMA2_FLAG_ERR1) || \
                                  ((flag) == DMA2_FLAG_G2)   || ((flag) == DMA2_FLAG_CMP2) || \
                                  ((flag) == DMA2_FLAG_HLF2) || ((flag) == DMA2_FLAG_ERR2) || \
                                  ((flag) == DMA2_FLAG_G3)   || ((flag) == DMA2_FLAG_CMP3) || \
                                  ((flag) == DMA2_FLAG_HLF3) || ((flag) == DMA2_FLAG_ERR3) || \
                                  ((flag) == DMA2_FLAG_G4)   || ((flag) == DMA2_FLAG_CMP4) || \
                                  ((flag) == DMA2_FLAG_HLF4) || ((flag) == DMA2_FLAG_ERR4) || \
                                  ((flag) == DMA2_FLAG_G5)   || ((flag) == DMA2_FLAG_CMP5) || \
                                  ((flag) == DMA2_FLAG_HLF5) || ((flag) == DMA2_FLAG_ERR5))
                               
#define DMA_CLEAR_FLAG_CHECK(flag) (((((flag) & 0xF0000000) == 0x00) || (((flag) & 0xEFF00000) == 0x00)) && ((flag) != 0x00))
                              
/**
  * @}
  */




/** @defgroup DMA_Remap_Set
  * @{
  */ 
  
/** 
  * @ brief DMA remap config definition
  */  
#define DMAx_CHANNEL1_REMAP                 0x00000000   //!< DMA1 or DMA2 channel 1 remap config
#define DMAx_CHANNEL2_REMAP                 0x10000000   //!< DMA1 or DMA2 channel 2 remap config
#define DMAx_CHANNEL3_REMAP                 0x20000000   //!< DMA1 or DMA2 channel 3 remap config
#define DMAx_CHANNEL4_REMAP                 0x30000000   //!< DMA1 or DMA2 channel 4 remap config
#define DMAx_CHANNEL5_REMAP                 0x40000000   //!< DMA1 or DMA2 channel 5 remap config
#define DMAx_CHANNEL6_REMAP                 0x50000000   //!< DMA1 or DMA2 channel 6 remap config
#define DMAx_CHANNEL7_REMAP                 0x60000000   //!< DMA1 or DMA2 channel 7 remap config

/** 
  * @ brief DMA1 Channel 1 remap bit field definition
  */
#define DMA1_CH1_DEFAULT      (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 1 default remap position
#define DMA1_CH1_ADC          (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_ADC)       //!< DMA1 channel 1 remap to ADC 
#define DMA1_CH1_TIM17_CH1    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_TIM17_CH1) //!< DMA1 channel 1 remap to TIM17 channel 1 
#define DMA1_CH1_TIM17_UP     (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_TIM17_UP)  //!< DMA1 channel 1 remap to TIM17 up 
#define DMA1_CH1_USART1_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART1_RX) //!< DMA1 channel 1 remap to USART1 Rx  
#define DMA1_CH1_USART2_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART2_RX) //!< DMA1 channel 1 remap to USART2 Rx 
#define DMA1_CH1_USART3_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART3_RX) //!< DMA1 channel 1 remap to USART3 Rx 
#define DMA1_CH1_USART4_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART4_RX) //!< DMA1 channel 1 remap to USART4 Rx 
#define DMA1_CH1_USART5_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART5_RX) //!< DMA1 channel 1 remap to USART5 Rx 
#define DMA1_CH1_USART6_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART6_RX) //!< DMA1 channel 1 remap to USART6 Rx 
#define DMA1_CH1_USART7_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART7_RX) //!< DMA1 channel 1 remap to USART7 Rx 
#define DMA1_CH1_USART8_RX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR1_CH1_USART8_RX) //!< DMA1 channel 1 remap to USART8 Rx 

/** 
  * @ brief DMA1 Channel 2 remap bit field definition
  */
#define DMA1_CH2_DEFAULT      (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 2 default remap position
#define DMA1_CH2_ADC          (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_ADC)       //!< DMA1 channel 2 remap to ADC 
#define DMA1_CH2_I2C1_TX      (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_I2C1_TX)   //!< DMA1 channel 2 remap to I2C1 Tx 
#define DMA1_CH2_SPI1_RX      (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_SPI_1RX)   //!< DMA1 channel 2 remap to SPI1 Rx 
#define DMA1_CH2_TIM1_CH1     (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_TIM1_CH1)  //!< DMA1 channel 2 remap to TIM1 channel 1 
#define DMA1_CH2_TIM17_CH1    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_TIM17_CH1) //!< DMA1 channel 2 remap to TIM17 channel 1 
#define DMA1_CH2_TIM17_UP     (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_TIM17_UP)  //!< DMA1 channel 2 remap to TIM17 up o
#define DMA1_CH2_USART1_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART1_TX) //!< DMA1 channel 2 remap to USART1 Tx 
#define DMA1_CH2_USART2_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART2_TX) //!< DMA1 channel 2 remap to USART2 Tx
#define DMA1_CH2_USART3_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART3_TX) //!< DMA1 channel 2 remap to USART3 Tx
#define DMA1_CH2_USART4_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART4_TX) //!< DMA1 channel 2 remap to USART4 Tx
#define DMA1_CH2_USART5_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART5_TX) //!< DMA1 channel 2 remap to USART5 Tx 
#define DMA1_CH2_USART6_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART6_TX) //!< DMA1 channel 2 remap to USART6 Tx 
#define DMA1_CH2_USART7_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART7_TX) //!< DMA1 channel 2 remap to USART7 Tx
#define DMA1_CH2_USART8_TX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR1_CH2_USART8_TX) //!< DMA1 channel 2 remap to USART8 Tx
/** 
  * @ brief DMA1 Channel 3 remap bit field definition
  */
#define DMA1_CH3_DEFAULT      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 3 default remap position
#define DMA1_CH3_TIM6_UP      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_TIM6_UP)   //!< DMA1 channel 3 remap to TIM6 up
#define DMA1_CH3_DAC_CH1      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_DAC_CH1)   //!< DMA1 channel 3 remap to DAC Channel 1
#define DMA1_CH3_I2C1_RX      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_I2C1_RX)   //!< DMA1 channel 3 remap to I2C1 Rx 
#define DMA1_CH3_SPI1_TX      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_SPI1_TX)   //!< DMA1 channel 3 remap to SPI1 Tx 
#define DMA1_CH3_TIM1_CH2     (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_TIM1_CH2)  //!< DMA1 channel 3 remap to TIM1 channel 2 
#define DMA1_CH3_TIM2_CH2     (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_TIM2_CH2)  //!< DMA1 channel 3 remap to TIM2 channel 2 
#define DMA1_CH3_TIM16_CH1    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_TIM16_CH1) //!< DMA1 channel 3 remap to TIM16 channel 1 
#define DMA1_CH3_TIM16_UP     (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_TIM16_UP)  //!< DMA1 channel 3 remap to TIM16 up 
#define DMA1_CH3_USART1_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART1_RX) //!< DMA1 channel 3 remap to USART1 Rx 
#define DMA1_CH3_USART2_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART2_RX) //!< DMA1 channel 3 remap to USART2 Rx 
#define DMA1_CH3_USART3_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART3_RX) //!< DMA1 channel 3 remap to USART3 Rx
#define DMA1_CH3_USART4_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART4_RX) //!< DMA1 channel 3 remap to USART4 Rx 
#define DMA1_CH3_USART5_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART5_RX) //!< DMA1 channel 3 remap to USART5 Rx
#define DMA1_CH3_USART6_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART6_RX) //!< DMA1 channel 3 remap to USART6 Rx 
#define DMA1_CH3_USART7_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART7_RX) //!< DMA1 channel 3 remap to USART7 Rx 
#define DMA1_CH3_USART8_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR1_CH3_USART8_RX) //!< DMA1 channel 3 remap to USART8 Rx 
/** 
  * @ brief DMA1 Channel 4 remap bit field definition
  */
#define DMA1_CH4_DEFAULT      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 4 default remap position 
#define DMA1_CH4_TIM7_UP      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_TIM7_UP)   //!< DMA1 channel 4 remap to TIM7 up
#define DMA1_CH4_DAC_CH2      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_DAC_CH2)   //!< DMA1 channel 4 remap to DAC Channel 2
#define DMA1_CH4_I2C2_TX      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_I2C2_TX)   //!< DMA1 channel 4 remap to I2C2 Tx 
#define DMA1_CH4_SPI2_RX      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_SPI2_RX)   //!< DMA1 channel 4 remap to SPI2 Rx 
#define DMA1_CH4_TIM2_CH4     (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_TIM2_CH4)  //!< DMA1 channel 4 remap to TIM2 channel 4 
#define DMA1_CH4_TIM3_CH1     (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_TIM3_CH1)  //!< DMA1 channel 4 remap to TIM3 channel 1
#define DMA1_CH4_TIM3_TRIG    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_TIM3_TRIG) //!< DMA1 channel 4 remap to TIM3 Trig 
#define DMA1_CH4_TIM16_CH1    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_TIM16_CH1) //!< DMA1 channel 4 remap to TIM16 channel 1
#define DMA1_CH4_TIM16_UP     (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_TIM16_UP)  //!< DMA1 channel 4 remap to TIM16 up 
#define DMA1_CH4_USART1_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART1_TX) //!< DMA1 channel 4 remap to USART1 Tx 
#define DMA1_CH4_USART2_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART2_TX) //!< DMA1 channel 4 remap to USART2 Tx 
#define DMA1_CH4_USART3_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART3_TX) //!< DMA1 channel 4 remap to USART3 Tx  
#define DMA1_CH4_USART4_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART4_TX) //!< DMA1 channel 4 remap to USART4 Tx 
#define DMA1_CH4_USART5_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART5_TX) //!< DMA1 channel 4 remap to USART5 Tx 
#define DMA1_CH4_USART6_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART6_TX) //!< DMA1 channel 4 remap to USART6 Tx  
#define DMA1_CH4_USART7_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART7_TX) //!< DMA1 channel 4 remap to USART7 Tx
#define DMA1_CH4_USART8_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR1_CH4_USART8_TX) //!< DMA1 channel 4 remap to USART8 Tx 
/** 
  * @ brief DMA1 Channel 5 remap bit field definition
  */
#define DMA1_CH5_DEFAULT      (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 5 default remap position 
#define DMA1_CH5_I2C2_RX      (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_I2C2_RX)   //!< DMA1 channel 5 remap to I2C2 Rx 
#define DMA1_CH5_SPI2_TX      (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_SPI2_TX)   //!< DMA1 channel 5 remap to SPI1 Tx 
#define DMA1_CH5_TIM1_CH3     (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_TIM1_CH3)  //!< DMA1 channel 5 remap to TIM1 channel 3 
#define DMA1_CH5_USART1_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART1_RX) //!< DMA1 channel 5 remap to USART1 Rx 
#define DMA1_CH5_USART2_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART2_RX) //!< DMA1 channel 5 remap to USART2 Rx 
#define DMA1_CH5_USART3_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART3_RX) //!< DMA1 channel 5 remap to USART3 Rx 
#define DMA1_CH5_USART4_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART4_RX) //!< DMA1 channel 5 remap to USART4 Rx 
#define DMA1_CH5_USART5_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART5_RX) //!< DMA1 channel 5 remap to USART5 Rx
#define DMA1_CH5_USART6_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART6_RX) //!< DMA1 channel 5 remap to USART6 Rx 
#define DMA1_CH5_USART7_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART7_RX) //!< DMA1 channel 5 remap to USART7 Rx
#define DMA1_CH5_USART8_RX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR1_CH5_USART8_RX) //!< DMA1 channel 5 remap to USART8 Rx
/** 
  * @ brief DMA1 Channel 6 remap bit field definition
  */
#define DMA1_CH6_DEFAULT      (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 6 default remap position 
#define DMA1_CH6_I2C1_TX      (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_I2C1_TX)   //!< DMA1 channel 6 remap to I2C1 Tx 
#define DMA1_CH6_SPI2_RX      (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_SPI2_RX)   //!< DMA1 channel 6 remap to SPI2 Rx 
#define DMA1_CH6_TIM1_CH1     (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM1_CH1)  //!< DMA1 channel 6 remap to TIM1 channel 1
#define DMA1_CH6_TIM1_CH2     (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM1_CH2)  //!< DMA1 channel 6 remap to TIM1 channel 2
#define DMA1_CH6_TIM1_CH3     (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM1_CH3)  //!< DMA1 channel 6 remap to TIM1 channel 3
#define DMA1_CH6_TIM3_CH1     (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM3_CH1)  //!< DMA1 channel 6 remap to TIM3 channel 1 
#define DMA1_CH6_TIM3_TRIG    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM3_TRIG) //!< DMA1 channel 6 remap to TIM3 Trig 
#define DMA1_CH6_TIM16_CH1    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM16_CH1) //!< DMA1 channel 6 remap to TIM16 channel 1 
#define DMA1_CH6_TIM16_UP     (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_TIM16_UP)  //!< DMA1 channel 6 remap to TIM16 up 
#define DMA1_CH6_USART1_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART1_RX) //!< DMA1 channel 6 remap to USART1 Rx 
#define DMA1_CH6_USART2_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART2_RX) //!< DMA1 channel 6 remap to USART2 Rx 
#define DMA1_CH6_USART3_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART3_RX) //!< DMA1 channel 6 remap to USART3 Rx
#define DMA1_CH6_USART4_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART4_RX) //!< DMA1 channel 6 remap to USART4 Rx 
#define DMA1_CH6_USART5_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART5_RX) //!< DMA1 channel 6 remap to USART5 Rx
#define DMA1_CH6_USART6_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART6_RX) //!< DMA1 channel 6 remap to USART6 Rx 
#define DMA1_CH6_USART7_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART7_RX) //!< DMA1 channel 6 remap to USART7 Rx 
#define DMA1_CH6_USART8_RX    (uint32_t) (DMAx_CHANNEL6_REMAP | DMA_RMPCR1_CH6_USART8_RX) //!< DMA1 channel 6 remap to USART8 Rx 
/** 
  * @ brief DMA1 Channel 7 remap bit field definition
  */
#define DMA1_CH7_DEFAULT      (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_DEFAULT)       //!< DMA1 channel 7 default remap position    
#define DMA1_CH7_I2C1_RX      (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_I2C1_RX)   //!< DMA1 channel 7 remap to I2C1 Rx 
#define DMA1_CH7_SPI2_TX      (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_SPI2_TX)   //!< DMA1 channel 7 remap to SPI2 Tx 
#define DMA1_CH7_TIM2_CH2     (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_TIM2_CH2)  //!< DMA1 channel 7 remap to TIM2 channel 2 
#define DMA1_CH7_TIM2_CH4     (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_TIM2_CH4)  //!< DMA1 channel 7 remap to TIM2 channel 4 
#define DMA1_CH7_TIM17_CH1    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_TIM17_CH1) //!< DMA1 channel 7 remap to TIM17 channel 1 
#define DMA1_CH7_TIM17_UP     (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_TIM17_UP)  //!< DMA1 channel 7 remap to TIM17 up 
#define DMA1_CH7_USART1_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART1_TX) //!< DMA1 channel 7 remap to USART1 Tx 
#define DMA1_CH7_USART2_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART2_TX) //!< DMA1 channel 7 remap to USART2 Tx 
#define DMA1_CH7_USART3_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART3_TX) //!< DMA1 channel 7 remap to USART3 Tx 
#define DMA1_CH7_USART4_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART4_TX) //!< DMA1 channel 7 remap to USART4 Tx 
#define DMA1_CH7_USART5_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART5_TX) //!< DMA1 channel 7 remap to USART5 Tx
#define DMA1_CH7_USART6_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART6_TX) //!< DMA1 channel 7 remap to USART6 Tx
#define DMA1_CH7_USART7_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART7_TX) //!< DMA1 channel 7 remap to USART7 Tx 
#define DMA1_CH7_USART8_TX    (uint32_t) (DMAx_CHANNEL7_REMAP | DMA_RMPCR1_CH7_USART8_TX) //!< DMA1 channel 7 remap to USART8 Tx 

#define DMA1_REMAP_CHECK(value)    ((value == DMA1_CH1_DEFAULT)   || (value == DMA1_CH1_ADC)         ||\
                                    (value == DMA1_CH1_TIM17_CH1) || (value == DMA1_CH1_TIM17_UP)    ||\
                                    (value == DMA1_CH1_USART1_RX) || (value == DMA1_CH1_USART2_RX)   ||\
                                    (value == DMA1_CH1_USART3_RX) || (value == DMA1_CH1_USART4_RX)   ||\
                                    (value == DMA1_CH1_USART5_RX) || (value == DMA1_CH1_USART6_RX)   ||\
                                    (value == DMA1_CH1_USART7_RX) || (value == DMA1_CH1_USART8_RX)   ||\
                                    (value == DMA1_CH2_DEFAULT)   ||  (value == DMA1_CH2_ADC)        ||\
                                    (value == DMA1_CH2_I2C1_TX)   ||  (value == DMA1_CH2_SPI1_RX)    ||\
                                    (value == DMA1_CH2_TIM1_CH1)  ||  (value == DMA1_CH2_I2C1_TX)    ||\
                                    (value == DMA1_CH2_TIM17_CH1) ||  (value == DMA1_CH2_TIM17_UP)   ||\
                                    (value == DMA1_CH2_USART1_TX) ||  (value == DMA1_CH2_USART2_TX)  ||\
                                    (value == DMA1_CH2_USART3_TX) || (value == DMA1_CH2_USART4_TX)   ||\
                                    (value == DMA1_CH2_USART5_TX) ||  (value == DMA1_CH2_USART6_TX)  ||\
                                    (value == DMA1_CH2_USART7_TX) ||  (value == DMA1_CH2_USART8_TX)  ||\
                                    (value == DMA1_CH3_DEFAULT)   || (value == DMA1_CH3_TIM6_UP)     ||\
                                    (value == DMA1_CH3_DAC_CH1)   || (value == DMA1_CH3_I2C1_RX)     ||\
                                    (value == DMA1_CH3_SPI1_TX)   || (value == DMA1_CH3_TIM1_CH2)    ||\
                                    (value == DMA1_CH3_TIM2_CH2)  || (value == DMA1_CH3_TIM16_CH1)   ||\
                                    (value == DMA1_CH3_TIM16_UP)  || (value == DMA1_CH3_USART1_RX)   ||\
                                    (value == DMA1_CH3_USART2_RX) || (value == DMA1_CH3_USART3_RX)   ||\
                                    (value == DMA1_CH3_USART4_RX) || (value == DMA1_CH3_USART5_RX)   ||\
                                    (value == DMA1_CH3_USART6_RX) || (value == DMA1_CH3_USART7_RX)   ||\
                                    (value == DMA1_CH3_USART8_RX) || (value == DMA1_CH4_DEFAULT)     ||\
                                    (value == DMA1_CH4_TIM7_UP)   || (value == DMA1_CH4_DAC_CH2)     ||\
                                    (value == DMA1_CH4_I2C2_TX)   || (value == DMA1_CH4_SPI2_RX)     ||\
                                    (value == DMA1_CH4_TIM2_CH4)  || (value == DMA1_CH4_TIM3_CH1)    ||\
                                    (value == DMA1_CH4_TIM3_TRIG) || (value == DMA1_CH4_TIM16_CH1)   ||\
                                    (value == DMA1_CH4_TIM16_UP)  || (value == DMA1_CH4_USART1_TX)   ||\
                                    (value == DMA1_CH4_USART2_TX) ||  (value == DMA1_CH4_USART3_TX)  ||\
                                    (value == DMA1_CH4_USART4_TX) || (value == DMA1_CH4_USART5_TX)   ||\
                                    (value == DMA1_CH4_USART6_TX) ||  (value == DMA1_CH4_USART7_TX)  ||\
                                    (value == DMA1_CH4_USART8_TX) || (value == DMA1_CH5_DEFAULT)     ||\
                                    (value == DMA1_CH5_I2C2_RX)   ||  (value == DMA1_CH5_SPI2_TX)    ||\
                                    (value == DMA1_CH5_TIM1_CH3)  ||  (value == DMA1_CH5_USART1_RX)  ||\
                                    (value == DMA1_CH5_USART2_RX) || (value == DMA1_CH5_USART3_RX)   ||\
                                    (value == DMA1_CH5_USART4_RX) || (value == DMA1_CH5_USART5_RX)   ||\
                                    (value == DMA1_CH5_USART6_RX) ||  (value == DMA1_CH5_USART7_RX)  ||\
                                    (value == DMA1_CH5_USART8_RX) || (value == DMA1_CH6_DEFAULT)     ||\
                                    (value == DMA1_CH6_I2C1_TX)   || (value == DMA1_CH6_SPI2_RX)     ||\
                                    (value == DMA1_CH6_TIM1_CH1)  || (value == DMA1_CH6_TIM1_CH2)    ||\
                                    (value == DMA1_CH6_TIM1_CH3)  || (value == DMA1_CH6_TIM3_CH1)    ||\
                                    (value == DMA1_CH6_TIM3_TRIG) || (value == DMA1_CH6_TIM16_CH1)   ||\
                                    (value == DMA1_CH6_TIM16_UP)  || (value == DMA1_CH6_USART1_RX)   ||\
                                    (value == DMA1_CH6_USART2_RX) || (value == DMA1_CH6_USART3_RX)   ||\
                                    (value == DMA1_CH6_USART4_RX) || (value == DMA1_CH6_USART5_RX)   ||\
                                    (value == DMA1_CH6_USART6_RX) || (value == DMA1_CH6_USART7_RX)   ||\
                                    (value == DMA1_CH6_USART8_RX) || (value == DMA1_CH7_DEFAULT)     ||\
                                    (value == DMA1_CH7_I2C1_RX)   ||  (value == DMA1_CH7_SPI2_TX)    ||\
                                    (value == DMA1_CH7_TIM2_CH2)  ||  (value == DMA1_CH7_TIM2_CH4)   ||\
                                    (value == DMA1_CH7_TIM17_CH1) || (value == DMA1_CH7_TIM17_UP)    ||\
                                    (value == DMA1_CH7_USART1_TX) || (value == DMA1_CH7_USART2_TX)   ||\
                                    (value == DMA1_CH7_USART3_TX) || (value == DMA1_CH7_USART4_TX)   ||\
                                    (value == DMA1_CH7_USART5_TX) || (value == DMA1_CH7_USART6_TX)   ||\
                                    (value == DMA1_CH7_USART7_TX) ||  (value == DMA1_CH7_USART8_TX))
                                                                                                     
/** 
  * @ brief DMA2 Channel 1 remap bit field definition
  */
#define DMA2_CH1_DEFAULT      (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_DEFAULT)       //!< DMA2 channel 1 default remap position   
#define DMA2_CH1_I2C2_TX      (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_I2C2_TX)   //!< DMA2 channel 1 remap to I2C2 TX 
#define DMA2_CH1_USART1_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART1_TX) //!< DMA2 channel 1 remap to USART1 Tx 
#define DMA2_CH1_USART2_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART2_TX) //!< DMA2 channel 1 remap to USART2 Tx 
#define DMA2_CH1_USART3_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART3_TX) //!< DMA2 channel 1 remap to USART3 Tx 
#define DMA2_CH1_USART4_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART4_TX) //!< DMA2 channel 1 remap to USART4 Tx 
#define DMA2_CH1_USART5_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART5_TX) //!< DMA2 channel 1 remap to USART5 Tx
#define DMA2_CH1_USART6_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART6_TX) //!< DMA2 channel 1 remap to USART6 Tx 
#define DMA2_CH1_USART7_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART7_TX) //!< DMA2 channel 1 remap to USART7 Tx 
#define DMA2_CH1_USART8_TX    (uint32_t) (DMAx_CHANNEL1_REMAP | DMA_RMPCR2_CH1_USART8_TX) //!< DMA2 channel 1 remap to USART8 Tx 

/** 
  * @ brief DMA2 Channel 2 remap bit field definition
  */
#define DMA2_CH2_DEFAULT      (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_DEFAULT)       //!< DMA2 channel 2 default remap position      
#define DMA2_CH2_I2C2_RX      (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_I2C2_RX)   //!< DMA2 channel 2 remap to I2C2 Rx 
#define DMA2_CH2_USART1_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART1_RX) //!< DMA2 channel 2 remap to USART1 Rx 
#define DMA2_CH2_USART2_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART2_RX) //!< DMA2 channel 2 remap to USART2 Rx 
#define DMA2_CH2_USART3_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART3_RX) //!< DMA2 channel 2 remap to USART3 Rx 
#define DMA2_CH2_USART4_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART4_RX) //!< DMA2 channel 2 remap to USART4 Rx 
#define DMA2_CH2_USART5_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART5_RX) //!< DMA2 channel 2 remap to USART5 Rx 
#define DMA2_CH2_USART6_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART6_RX) //!< DMA2 channel 2 remap to USART6 Rx 
#define DMA2_CH2_USART7_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART7_RX) //!< DMA2 channel 2 remap to USART7 Rx 
#define DMA2_CH2_USART8_RX    (uint32_t) (DMAx_CHANNEL2_REMAP | DMA_RMPCR2_CH2_USART8_RX) //!< DMA2 channel 2 remap to USART8 Rx 

/** 
  * @ brief DMA2 Channel 3 remap bit field definition
  */
#define DMA2_CH3_DEFAULT      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_DEFAULT)       //!< DMA2 channel 3 default remap position  
#define DMA2_CH3_TIM6_UP      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_TIM6_UP)   //!< DMA2 channel 3 remap to TIM6 up 
#define DMA2_CH3_DAC_CH1      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_DAC_CH1)   //!< DMA2 channel 3 remap to DAC channel 1 
#define DMA2_CH3_SPI1_RX      (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_SPI1_RX)   //!< DMA2 channel 3 remap to SPI1 Rx 
#define DMA2_CH3_USART1_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART1_RX) //!< DMA2 channel 3 remap to USART1 Rx 
#define DMA2_CH3_USART2_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART2_RX) //!< DMA2 channel 3 remap to USART2 Rx 
#define DMA2_CH3_USART3_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART3_RX) //!< DMA2 channel 3 remap to USART3 Rx
#define DMA2_CH3_USART4_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART4_RX) //!< DMA2 channel 3 remap to USART4 Rx 
#define DMA2_CH3_USART5_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART5_RX) //!< DMA2 channel 3 remap to USART5 Rx 
#define DMA2_CH3_USART6_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART6_RX) //!< DMA2 channel 3 remap to USART6 Rx 
#define DMA2_CH3_USART7_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART7_RX) //!< DMA2 channel 3 remap to USART7 Rx 
#define DMA2_CH3_USART8_RX    (uint32_t) (DMAx_CHANNEL3_REMAP | DMA_RMPCR2_CH3_USART8_RX) //!< DMA2 channel 3 remap to USART8 Rx 

/** 
  * @ brief DMA2 Channel 4 remap bit field definition
  */
#define DMA2_CH4_DEFAULT      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_DEFAULT)       //!< DMA2 channel 4 default remap position  
#define DMA2_CH4_TIM7_UP      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_TIM7_UP)   //!< DMA2 channel 4 remap to TIM7 up 
#define DMA2_CH4_DAC_CH2      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_DAC_CH2)   //!< DMA2 channel 4 remap to DAC channel 2
#define DMA2_CH4_SPI1_TX      (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_SPI1_TX)   //!< DMA2 channel 4 remap to SPI1 Tx 
#define DMA2_CH4_USART1_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART1_TX) //!< DMA2 channel 4 remap to USART1 Tx 
#define DMA2_CH4_USART2_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART2_TX) //!< DMA2 channel 4 remap to USART2 Tx
#define DMA2_CH4_USART3_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART3_TX) //!< DMA2 channel 4 remap to USART3 Tx 
#define DMA2_CH4_USART4_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART4_TX) //!< DMA2 channel 4 remap to USART4 Tx
#define DMA2_CH4_USART5_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART5_TX) //!< DMA2 channel 4 remap to USART5 Tx 
#define DMA2_CH4_USART6_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART6_TX) //!< DMA2 channel 4 remap to USART6 Tx
#define DMA2_CH4_USART7_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART7_TX) //!< DMA2 channel 4 remap to USART7 Tx
#define DMA2_CH4_USART8_TX    (uint32_t) (DMAx_CHANNEL4_REMAP | DMA_RMPCR2_CH4_USART8_TX) //!< DMA2 channel 4 remap to USART8 Tx 

/** 
  * @ brief DMA2 Channel 5 remap bit field definition
  */
#define DMA2_CH5_DEFAULT      (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_DEFAULT)       //!< DMA2 channel 5 default remap position  
#define DMA2_CH5_ADC          (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_ADC)       //!< DMA2 channel 5 remap to ADC  
#define DMA2_CH5_USART1_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART1_TX) //!< DMA2 channel 5 remap to USART1 Tx
#define DMA2_CH5_USART2_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART2_TX) //!< DMA2 channel 5 remap to USART2 Tx 
#define DMA2_CH5_USART3_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART3_TX) //!< DMA2 channel 5 remap to USART3 Tx 
#define DMA2_CH5_USART4_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART4_TX) //!< DMA2 channel 5 remap to USART4 Tx
#define DMA2_CH5_USART5_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART5_TX) //!< DMA2 channel 5 remap to USART5 Tx 
#define DMA2_CH5_USART6_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART6_TX) //!< DMA2 channel 5 remap to USART6 Tx 
#define DMA2_CH5_USART7_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART7_TX) //!< DMA2 channel 5 remap to USART7 Tx
#define DMA2_CH5_USART8_TX    (uint32_t) (DMAx_CHANNEL5_REMAP | DMA_RMPCR2_CH5_USART8_TX) //!< DMA2 channel 5 remap to USART8 Tx

#define DMA2_REMAP_CHECK(value)   ((value == DMA2_CH1_DEFAULT)  || (value == DMA2_CH1_I2C2_TX)   ||\
                                  (value == DMA2_CH1_USART1_TX) || (value == DMA2_CH1_USART2_TX) ||\
                                  (value == DMA2_CH1_USART3_TX) || (value == DMA2_CH1_USART4_TX) ||\
                                  (value == DMA2_CH1_USART5_TX) || (value == DMA2_CH1_USART6_TX) ||\
                                  (value == DMA2_CH1_USART7_TX) || (value == DMA2_CH1_USART8_TX) ||\
                                  (value == DMA2_CH2_DEFAULT)   || (value == DMA2_CH2_I2C2_RX)   ||\
                                  (value == DMA2_CH2_USART1_RX) || (value == DMA2_CH2_USART2_RX) ||\
                                  (value == DMA2_CH2_USART3_RX) || (value == DMA2_CH2_USART4_RX) ||\
                                  (value == DMA2_CH2_USART5_RX) || (value == DMA2_CH2_USART6_RX) ||\
                                  (value == DMA2_CH2_USART7_RX) || (value == DMA2_CH2_USART8_RX) ||\
                                  (value == DMA2_CH3_DEFAULT)   ||  (value == DMA2_CH3_TIM6_UP)  ||\
                                  (value == DMA2_CH3_DAC_CH1)   ||  (value == DMA2_CH3_SPI1_RX)  ||\
                                  (value == DMA2_CH3_USART1_RX) || (value == DMA2_CH3_USART2_RX) ||\
                                  (value == DMA2_CH3_USART3_RX) || (value == DMA2_CH3_USART4_RX) ||\
                                  (value == DMA2_CH3_USART5_RX) || (value == DMA2_CH3_USART6_RX) ||\
                                  (value == DMA2_CH3_USART7_RX) || (value == DMA2_CH3_USART8_RX) ||\
                                  (value == DMA2_CH4_DEFAULT)   ||  (value == DMA2_CH4_TIM7_UP)  ||\
                                  (value == DMA2_CH4_DAC_CH2)   ||  (value == DMA2_CH4_SPI1_TX)  ||\
                                  (value == DMA2_CH4_USART1_TX) || (value == DMA2_CH4_USART2_TX) ||\
                                  (value == DMA2_CH4_USART3_TX) || (value == DMA2_CH4_USART4_TX) ||\
                                  (value == DMA2_CH4_USART5_TX) || (value == DMA2_CH4_USART6_TX) ||\
                                  (value == DMA2_CH4_USART7_TX) || (value == DMA2_CH4_USART8_TX) ||\
                                  (value == DMA2_CH5_DEFAULT)   ||  (value == DMA2_CH5_ADC)      ||\
                                  (value == DMA2_CH5_USART1_TX) || (value == DMA2_CH5_USART2_TX) ||\
                                  (value == DMA2_CH5_USART3_TX) || (value == DMA2_CH5_USART4_TX) ||\
                                  (value == DMA2_CH5_USART5_TX) || (value == DMA2_CH5_USART6_TX) ||\
                                  (value == DMA2_CH5_USART7_TX) || (value == DMA2_CH5_USART8_TX ))                         
/**
  * @}
  */ 



/**
  * @fn void dma_def_init(dma_channel_reg_t* ptr_channel_struct)
  * @brief  Deinitializes the DMA Channelx registers to their default reset values.   
  * @param  ptr_channel_struct: pointer to a dma_channel_reg_t struct, it can be anyone of  
  *         channel 1 to channel 7 in DMA1.
  * @return None
  */
void dma_def_init(dma_channel_reg_t* ptr_channel_struct);

/**
  * @fn void dma_init(dma_channel_reg_t* ptr_channel_struct, dma_config_t* ptr_config_struct)
  * @brief  Initializes the DMA Channel according to the specified parameters 
  *         in the ptr_config_struct.
  * @param  ptr_channel_struct: pointer to a dma_channel_reg_t struct,it can be anyone of  
  *         channel1 to channel 7 in DMA1.
  * @param  ptr_config_struct: pointer to a dma_config_t structure containing the configuration
  *         for the specified DMA Channel.
  * @return None
  */
void dma_init(dma_channel_reg_t* ptr_channel_struct, dma_config_t* ptr_config_struct);

/**
  * @fn void dma_struct_config(dma_config_t* ptr_config_struct)
  * @brief  config each ptr_config_struct member with its default value.
  * @param  ptr_config_struct: pointer to a dma_config_t structure being initialized.        
  * @return None
  */
void dma_struct_config(dma_config_t* ptr_config_struct);

/**
  * @fn void dma_enable_ctrl(dma_channel_reg_t* ptr_channel_struct, enable_state_t enable_flag)
  * @brief  Enables or disables the specified DMA Channel.
  * @param  ptr_channel_struct: pointer to a dma_channel_reg_t struct, it can be anyone of  
  *         channel 1 to channel 7 in DMA1.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @return None
  */
void dma_enable_ctrl(dma_channel_reg_t* ptr_channel_struct, enable_state_t enable_flag);

/**
  * @fn void dma_remap_set(dma_reg_t* ptr_dma, uint32_t set_value)
  * @brief  Configure the DMAx channels remapping
  * @param  ptr_dma: pointer to the selected DMA peripheral, it can be DMA1 or DMA2.    
  * @param  set_value: it can be anyone of channel 1 to channel 7 in DMA1 or Channel 1 to channel 5
  *         in DMA2. 
  * @return None
  */
void dma_remap_set(dma_reg_t* ptr_dma, uint32_t set_value);

/**
  * @fn void dma_data_counter_set(dma_channel_reg_t* ptr_channel_struct, uint16_t counter)
  * @brief  Sets the number of data units using the current DMA Channel transfer.
  *         It can only be used when the ptr_channel_struct is disabled.
  * @param  ptr_channel_struct: pointer to a dma_channel_reg_t struct, it can be anyone of  
  *         channel 1 to channel 7 in DMA1.
  * @param  counter: The number of data units to transfer.         
  * @return None.
  */
void dma_data_counter_set(dma_channel_reg_t* ptr_channel_struct, uint16_t counter);

/**
  * @fn uint16_t dma_data_counter_get(dma_channel_reg_t* ptr_channel_struct)
  * @brief  Returns the number of remaining data units in the current DMA Channel transfer.
  * @param  ptr_channel_struct: pointer to a dma_channel_reg_t struct, it can be anyone of  
  *         channel 1 to channel 7 in DMA1. 
  * @return The number of remaining data units.
  */
uint16_t dma_data_counter_get(dma_channel_reg_t* ptr_channel_struct);

/**
  * @fn void dma_interrupt_set(dma_channel_reg_t* ptr_channel_struct, uint32_t set_value, enable_state_t enable_flag);
  * @brief  Enables or disables the specified DMA Channel interrupts.
  * @param  ptr_channel_struct: pointer to a dma_channel_reg_t struct,it can be anyone of  
  *         channel 1 to channel 7 in DMA1. 
  * @param  set_value: specifies the DMA interrupts sources to be enabled or disabled.      
  *          It can be any combination of the following values:
  *           @arg Transfer complete interrupt mask (DMA_INT_CONFIG_CMP) 
  *           @arg Half transfer interrupt mask (DMA_INT_CONFIG_HLF)
  *           @arg Transfer error interrupt mask (DMA_INT_CONFIG_ERR)
  * @param  enable_flag: the specified DMA interrupts ENABLE or DISABLE.
  * @return None
  */
void dma_interrupt_set(dma_channel_reg_t* ptr_channel_struct, uint32_t set_value, enable_state_t enable_flag);

/**
  * @fn bit_status_t dma_flag_status_get(uint32_t flag)
  * @brief  Checks whether the specified DMA Channel flag is set or not.
  * @param  flag: specifies the flag to check.   
  *          It can be one of the following value:
  *           @arg DMA1_FLAG_G1(Global interrupt flag of Channel 1)
  *           @arg DMA1_FLAG_CMP1(Transfer complete flag of Channel 1)
  *           @arg DMA1_FLAG_HLF1(Half transfer flag of Channel 1)
  *           @arg DMA1_FLAG_ERR1(Transfer error flag of Channel 1)    
  *           @arg DMA1_FLAG_G2(Global interrupt flag of Channel 2) 
  *           @arg DMA1_FLAG_CMP2(Transfer complete flag of Channel 2)
  *           @arg DMA1_FLAG_HLF2(Half transfer flag of Channel 2)
  *           @arg DMA1_FLAG_ERR2(Transfer error flag of Channel 2) 
  *           @arg DMA1_FLAG_G3(Global interrupt flag of Channel 3) 
  *           @arg DMA1_FLAG_CMP3(Transfer complete flag of Channel 3) 
  *           @arg DMA1_FLAG_HLF3(Half transfer flag of Channel 3)
  *           @arg DMA1_FLAG_ERR3(Transfer error flag of Channel 3) 
  *           @arg DMA1_FLAG_G4(Global interrupt flag of Channel 4) 
  *           @arg DMA1_FLAG_CMP4(Transfer complete flag of Channel 4) 
  *           @arg DMA1_FLAG_HLF4(Half transfer flag of Channel 4)
  *           @arg DMA1_FLAG_ERR4(Transfer error flag of Channel 4) 
  *           @arg DMA1_FLAG_G5(Global interrupt flag of Channel 5) 
  *           @arg DMA1_FLAG_CMP5(Transfer complete flag of Channel 5) 
  *           @arg DMA1_FLAG_HLF5(Half transfer flag of Channel 5)
  *           @arg DMA1_FLAG_ERR5(Transfer error flag of Channel 5) 
  * @return The new state (SET or RESET).
  */
bit_status_t dma_flag_status_get(uint32_t flag);

/**
  * @fn void dma_flag_clear(uint32_t flag)
  * @brief  Clears the DMA Channel flags.
  * @param  flag: specifies the flag to clear.
  *          It can be one of the following value:
  *           @arg DMA1_FLAG_G1(Global interrupt flag of Channel 1)
  *           @arg DMA1_FLAG_CMP1(Transfer complete flag of Channel 1) 
  *           @arg DMA1_FLAG_HLF1(Half transfer flag of Channel 1)
  *           @arg DMA1_FLAG_ERR1(Transfer error flag of Channel 1)    
  *           @arg DMA1_FLAG_G2(Global interrupt flag of Channel 2) 
  *           @arg DMA1_FLAG_CMP2(Transfer complete flag of Channel 2) 
  *           @arg DMA1_FLAG_HLF2(Half transfer flag of Channel 2)
  *           @arg DMA1_FLAG_ERR2(Transfer error flag of Channel 2) 
  *           @arg DMA1_FLAG_G3(Global interrupt flag of Channel 3) 
  *           @arg DMA1_FLAG_CMP3(Transfer complete flag of Channel 3)
  *           @arg DMA1_FLAG_HLF3(Half transfer flag of Channel 3)
  *           @arg DMA1_FLAG_ERR3(Transfer error flag of Channel 3) 
  *           @arg DMA1_FLAG_G4(Global interrupt flag of Channel 4) 
  *           @arg DMA1_FLAG_CMP4(Transfer complete flag of Channel 4) 
  *           @arg DMA1_FLAG_HLF4(Half transfer flag of Channel 4)
  *           @arg DMA1_FLAG_ERR4(Transfer error flag of Channel 4) 
  *           @arg DMA1_FLAG_G5(Global interrupt flag of Channel 5) 
  *           @arg DMA1_FLAG_CMP5(Transfer complete flag of Channel 5) 
  *           @arg DMA1_FLAG_HLF5(Half transfer flag of Channel 5)
  *           @arg DMA1_FLAG_ERR5(Transfer error flag of Channel 5) 
  * @return None
  */
void dma_flag_clear(uint32_t flag);

/**
  * @fn bit_status_t dma_interrupt_status_get(uint32_t flag)
  * @brief  Checks whether the specified DMA Channel interrupt has occurred or not.
  * @param  flag: specifies the DMA interrupt source to check.     
  *          It can be one of the following value:
  *           @arg DMA1_INT_G1(Global interrupt of Channel 1)
  *           @arg DMA1_INT_CMP1(Transfer complete interruptof Channel 1)
  *           @arg DMA1_INT_HLF1(Half transfer interrupt of Channel 1)
  *           @arg DMA1_INT_ERR1(Transfer error interrupt of Channel 1)   
  *           @arg DMA1_INT_G2(Global interrupt of Channel 2)
  *           @arg DMA1_INT_CMP2(Transfer complete interruptof Channel 2)
  *           @arg DMA1_INT_HLF2(Half transfer interrupt of Channel 2)
  *           @arg DMA1_INT_ERR2(Transfer error interrupt of Channel 2) 
  *           @arg DMA1_INT_G3(Global interrupt of Channel 3)
  *           @arg DMA1_INT_CMP3(Transfer complete interrupt of Channel 3)
  *           @arg DMA1_INT_HLF3(Half transfer interrupt of Channel 3)
  *           @arg DMA1_INT_ERR3(Transfer error interrupt of Channel 3) 
  *           @arg DMA1_INT_G4(Global interrupt of Channel 4)
  *           @arg DMA1_INT_CMP4(Transfer complete interrupt of Channel 4) 
  *           @arg DMA1_INT_HLF4(Half transfer interrupt of Channel 4)
  *           @arg DMA1_INT_ERR4(Transfer error interrupt of Channel 4) 
  *           @arg DMA1_INT_G5(Global interrupt of Channel 5)
  *           @arg DMA1_INT_CMP5(Transfer complete interrupt of Channel 5) 
  *           @arg DMA1_INT_HLF5(Half transfer interrupt of Channel 5)
  *           @arg DMA1_INT_ERR5(Transfer error interrupt of Channel 5) 
  * @return The new state (SET or RESET).
  */
bit_status_t dma_interrupt_status_get(uint32_t flag);

/**
  * @fn void dma_interrupt_flag_clear(uint32_t flag)
  * @brief  Clears the DMA Channel interrupt bits.
  * @param  flag: specifies the DMA interrupt pending bit to clear.   
  *          It can be one of the following value:
  *           @arg DMA1_INT_G1(Global interrupt of Channel 1)
  *           @arg DMA1_INT_CMP1(Transfer complete interruptof Channel 1)
  *           @arg DMA1_INT_HLF1(Half transfer interrupt of Channel 1)
  *           @arg DMA1_INT_ERR1(Transfer error interrupt of Channel 1)    
  *           @arg DMA1_INT_G2(Global interrupt of Channel 2)
  *           @arg DMA1_INT_CMP2(Transfer complete interruptof Channel 2)
  *           @arg DMA1_INT_HLF2(Half transfer interrupt of Channel 2)
  *           @arg DMA1_INT_ERR2(Transfer error interrupt of Channel 2) 
  *           @arg DMA1_INT_G3(Global interrupt of Channel 3)
  *           @arg DMA1_INT_CMP3(Transfer complete interrupt of Channel 3)
  *           @arg DMA1_INT_HLF3(Half transfer interrupt of Channel 3)
  *           @arg DMA1_INT_ERR3(Transfer error interrupt of Channel 3) 
  *           @arg DMA1_INT_G4(Global interrupt of Channel 4)
  *           @arg DMA1_INT_CMP4(Transfer complete interrupt of Channel 4)
  *           @arg DMA1_INT_HLF4(Half transfer interrupt of Channel 4)
  *           @arg DMA1_INT_ERR4(Transfer error interrupt of Channel 4) 
  *           @arg DMA1_INT_G5(Global interrupt of Channel 5)
  *           @arg DMA1_INT_CMP5(Transfer complete interrupt of Channel 5)
  *           @arg DMA1_INT_HLF5(Half transfer interrupt of Channel 5)
  *           @arg DMA1_INT_ERR5(Transfer error interrupt of Channel 5) 
  * @return None
  */
void dma_interrupt_flag_clear(uint32_t flag);


#ifdef __cplusplus
}
#endif

#endif

/**
  * @}
  */

/**
  * @}
  */

