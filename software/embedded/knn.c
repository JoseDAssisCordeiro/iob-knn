#include "interconnect.h"
#include "iob_knn.h"
#include "KNNsw_reg.h"

//base address
static int base;

void knn_reset(){
  IO_SET(base, KNN_RESET, 1);
  IO_SET(base, KNN_RESET, 0);
}

void knn_start(){
  IO_SET(base, KNN_ENABLE, 1);
}

void knn_stop(){
  IO_SET(base, KNN_ENABLE, 0);
}

void knn_init(int base_address){
  base = base_address;
  knn_reset();
}

int get_y(int i, int i_1, int i_2, int i_3){

	IO_SET(base, KNN_I, i);
	IO_SET(base, KNN_I_1, i_1);
	IO_SET(base, KNN_I_2, i_2);
	IO_SET(base, KNN_I_3, i_3);
	return IO_GET(base, KNN_Y);

}
