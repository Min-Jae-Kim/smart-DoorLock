#define CHECK

#define FALSE 0
#define TRUE 1

#define PIN_VIB 29
#define PIN_SPKR 25
#define MAX 256
#define PIC_PATH "/home/pi/"
#define PIC_CMD "raspistill --nopreview -w 640 -h 480 -t 1 -o " 

void MakeFileName();
void vibration();
void bell();
