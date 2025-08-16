/** 
 * Copyright (c) 2024,郑州潮阔电子科技有限公司
 * All rights reserved.
 * 
 * 文件名称：mcu_version.h
 * 摘    要：添加单片机MCU的版本号
 * 
 * 当前版本：1.0
 * 作    者：郭夫华
 * 完成日期：2024年9月23日
 *
 * 修订记录：
 */
#include "board/pgm.h"
#include "command.h" // DECL_COMMAND

/**
 * @brief MCU版本信息数据
 * 
 * 该数组存储了MCU的版本信息，包括主版本号、次版本号以及日期等信息。
 */
const uint8_t mcu_version_data[] PROGMEM = {
    'S', '1', 'P', 'r', 'o', '-', 'V', '1',
    '.', '0', '.', '0', '.', '0', '.', '1',
    '0', '0', '5', 0x00, 0x00, 0x00, 0x00, 0x00
};

/**
 * @brief MCU版本信息数据大小
 * 
 * 该变量存储了mcu_version_data数组的大小。使用ARRAY_SIZE宏计算数组元素数量，并将结果存储在
 * mcu_version_size中，以便后续函数使用。
 */
const uint32_t mcu_version_size PROGMEM
    = ARRAY_SIZE(mcu_version_data);
    
/**
 * @brief 获取MCU版本信息
 * 
 * 该函数通过调用sendf函数向主机发送MCU版本信息。版本信息从mcu_version_data中获取，
 *
 * @param args 保留参数，可能用于接收命令的额外参数
 */
void command_get_mcu_version(uint32_t *args)
{
    sendf("mcu version=%.*s", mcu_version_size, &mcu_version_data[0]);
}
DECL_COMMAND_FLAGS(command_get_mcu_version, HF_IN_SHUTDOWN, "get_mcu_version");
