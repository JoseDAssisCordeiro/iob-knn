//START_TABLE sw_reg
`SWREG_W(KNN_RESET,          1, 0) //Timer soft reset
`SWREG_W(KNN_ENABLE,         1, 0) //Timer enable
`SWREG_W(KNN_I,         	DATA_W, 0) // i
`SWREG_W(KNN_I_1,         	DATA_W, 0) // i - 1
`SWREG_W(KNN_I_2,         	DATA_W, 0) // i - 2
`SWREG_W(KNN_I_3,         	DATA_W, 0) // i - 3
`SWREG_R(KNN_Y,        DATA_W, 0) // Y
