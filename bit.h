#define set_bit(x,bit)      x=((x)|(1<<bit))
#define clear_bit(x,bit)    x=((x)&((1<<bit)^(0xFFFFFFFFFFFFFFFF)))
#define toggle_bit(x,bit)   x=((x)^(1<<bit))
#define check_bit(x,bit)   (x)&(1<<(bit))
#define number_set_ones(x)  x=~0
#define toggle_1st_byte(x)  x=((x)^(0x00000000000000FF))
#define toggle_2st_byte(x)  x=((x)^(0x000000000000FF00))
#define toggle_3rd_byte(x)  x=((x)^(0x0000000000FF0000))
#define toggle_4th_byte(x)  x=((x)^(0x00000000FF000000))
#define toggle_5th_byte(x)  x=((x)^(0x000000FF00000000))
#define toggle_6th_byte(x)  x=((x)^(0x0000FF0000000000))
#define toggle_7th_byte(x)  x=((x)^(0x00FF000000000000))
#define toggle_8th_byte(x)  x=((x)^(0xFF00000000000000))

