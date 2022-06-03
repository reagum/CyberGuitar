/*
 * Connection mpr to guitar neck
 * 
 * лад  |----------------------|
 *    1 |11 - 9 - 7 - 5 - 3 - 1| }
 *      |----------------------| }mpr I2Cone, 0x5A (cap[0])
 *    2 |10 - 8 - 6 - 4 - 2 - 0| }
 *      |----------------------|
 *    3 |11 - 9 - 7 - 5 - 3 - 1| }
 *      |----------------------| }mpr I2Cone, 0x5B (cap[1])
 *    4 |10 - 8 - 6 - 4 - 2 - 0| }
 *      |----------------------|
 *    5 |11 - 9 - 7 - 5 - 3 - 1| }
 *      |----------------------| }mpr I2Cone, 0x5C (cap[2])
 *    6 |10 - 8 - 6 - 4 - 2 - 0| }
 *      |----------------------|
 *    7 |11 - 9 - 7 - 5 - 3 - 1| }
 *      |----------------------| }mpr I2Ctwo, 0x5A (cap[3])
 *    8 |10 - 8 - 6 - 4 - 2 - 0| }
 *      |----------------------|
 *    9 |11 - 9 - 7 - 5 - 3 - 1| }
 *      |----------------------| }mpr I2Ctwo, 0x5B (cap[4])
 *   10 |10 - 8 - 6 - 4 - 2 - 0| }
 *      |----------------------|
 *   11 |11 - 9 - 7 - 5 - 3 - 1| }
 *      |----------------------| }mpr I2Ctwo, 0x5C (cap[5])
 *   12 |10 - 8 - 6 - 4 - 2 - 0| }
 *      |----------------------|
 * 
 */

bool grif[12][6] = { //guitar neck
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0},
};

int gstr[6] = {0,0,0,0,0,0}; //guitar strings (active)

void touches(){
  //mpr modules check
  for(int icap=0;icap<6;icap++){
        currtouched[icap]=cap[icap].touched();
        for (uint8_t i=0; i<12; i++) {
          // it if *is* touched and *wasnt* touched before, alert!
          if ((currtouched[icap] & _BV(i)) && !(lasttouched[icap] & _BV(i)) ) {
            Serial.print("mpr121 - ");Serial.print(icap);Serial.print(" - ");Serial.print(i); Serial.println(" touched");
            if(icap == 0){
              if(i==11) grif[0][0]=1;
              if(i==10) grif[1][0]=1;
              if(i==9)  grif[0][1]=1;
              if(i==8)  grif[1][1]=1;
              if(i==7)  grif[0][2]=1;
              if(i==6)  grif[1][2]=1;
              if(i==5)  grif[0][3]=1;
              if(i==4)  grif[1][3]=1;
              if(i==3)  grif[0][4]=1;
              if(i==2)  grif[1][4]=1;
              if(i==1)  grif[0][5]=1;
              if(i==0)  grif[1][5]=1;
            }
            if(icap == 1){
              if(i==11) grif[2][0]=1;
              if(i==10) grif[3][0]=1;
              if(i==9)  grif[2][1]=1;
              if(i==8)  grif[3][1]=1;
              if(i==7)  grif[2][2]=1;
              if(i==6)  grif[3][2]=1;
              if(i==5)  grif[2][3]=1;
              if(i==4)  grif[3][3]=1;
              if(i==3)  grif[2][4]=1;
              if(i==2)  grif[3][4]=1;
              if(i==1)  grif[2][5]=1;
              if(i==0)  grif[3][5]=1;
            }
            if(icap == 2){
              if(i==11) grif[4][0]=1;
              if(i==10) grif[5][0]=1;
              if(i==9)  grif[4][1]=1;
              if(i==8)  grif[5][1]=1;
              if(i==7)  grif[4][2]=1;
              if(i==6)  grif[5][2]=1;
              if(i==5)  grif[4][3]=1;
              if(i==4)  grif[5][3]=1;
              if(i==3)  grif[4][4]=1;
              if(i==2)  grif[5][4]=1;
              if(i==1)  grif[4][5]=1;
              if(i==0)  grif[5][5]=1;
            }
            if(icap == 3){
              if(i==11) grif[6][0]=1;
              if(i==10) grif[7][0]=1;
              if(i==9)  grif[6][1]=1;
              if(i==8)  grif[7][1]=1;
              if(i==7)  grif[6][2]=1;
              if(i==6)  grif[7][2]=1;
              if(i==5)  grif[6][3]=1;
              if(i==4)  grif[7][3]=1;
              if(i==3)  grif[6][4]=1;
              if(i==2)  grif[7][4]=1;
              if(i==1)  grif[6][5]=1;
              if(i==0)  grif[7][5]=1;
            }
            if(icap == 4){
              if(i==11) grif[8][0]=1;
              if(i==10) grif[9][0]=1;
              if(i==9)  grif[8][1]=1;
              if(i==8)  grif[9][1]=1;
              if(i==7)  grif[8][2]=1;
              if(i==6)  grif[9][2]=1;
              if(i==5)  grif[8][3]=1;
              if(i==4)  grif[9][3]=1;
              if(i==3)  grif[8][4]=1;
              if(i==2)  grif[9][4]=1;
              if(i==1)  grif[8][5]=1;
              if(i==0)  grif[9][5]=1;
            }
            if(icap == 5){
              if(i==11) grif[10][0]=1;
              if(i==10) grif[11][0]=1;
              if(i==9)  grif[10][1]=1;
              if(i==8)  grif[11][1]=1;
              if(i==7)  grif[10][2]=1;
              if(i==6)  grif[11][2]=1;
              if(i==5)  grif[10][3]=1;
              if(i==4)  grif[11][3]=1;
              if(i==3)  grif[10][4]=1;
              if(i==2)  grif[11][4]=1;
              if(i==1)  grif[10][5]=1;
              if(i==0)  grif[11][5]=1;
            }  
          }
          // if it *was* touched and now *isnt*, alert!
          if (!(currtouched[icap] & _BV(i)) && (lasttouched[icap] & _BV(i)) ) {
            Serial.print("mpr121 - ");Serial.print(icap);Serial.print(" - "); Serial.print(i); Serial.println(" released");
             if(icap == 0){
              if(i==11) grif[0][0]=0;
              if(i==10) grif[1][0]=0;
              if(i==9)  grif[0][1]=0;
              if(i==8)  grif[1][1]=0;
              if(i==7)  grif[0][2]=0;
              if(i==6)  grif[1][2]=0;
              if(i==5)  grif[0][3]=0;
              if(i==4)  grif[1][3]=0;
              if(i==3)  grif[0][4]=0;
              if(i==2)  grif[1][4]=0;
              if(i==1)  grif[0][5]=0;
              if(i==0)  grif[1][5]=0;
            }
            if(icap == 1){
              if(i==11) grif[2][0]=0;
              if(i==10) grif[3][0]=0;
              if(i==9)  grif[2][1]=0;
              if(i==8)  grif[3][1]=0;
              if(i==7)  grif[2][2]=0;
              if(i==6)  grif[3][2]=0;
              if(i==5)  grif[2][3]=0;
              if(i==4)  grif[3][3]=0;
              if(i==3)  grif[2][4]=0;
              if(i==2)  grif[3][4]=0;
              if(i==1)  grif[2][5]=0;
              if(i==0)  grif[3][5]=0;
            }
            if(icap == 2){
              if(i==11) grif[4][0]=0;
              if(i==10) grif[5][0]=0;
              if(i==9)  grif[4][1]=0;
              if(i==8)  grif[5][1]=0;
              if(i==7)  grif[4][2]=0;
              if(i==6)  grif[5][2]=0;
              if(i==5)  grif[4][3]=0;
              if(i==4)  grif[5][3]=0;
              if(i==3)  grif[4][4]=0;
              if(i==2)  grif[5][4]=0;
              if(i==1)  grif[4][5]=0;
              if(i==0)  grif[5][5]=0;
            }
            if(icap == 3){
              if(i==11) grif[6][0]=0;
              if(i==10) grif[7][0]=0;
              if(i==9)  grif[6][1]=0;
              if(i==8)  grif[7][1]=0;
              if(i==7)  grif[6][2]=0;
              if(i==6)  grif[7][2]=0;
              if(i==5)  grif[6][3]=0;
              if(i==4)  grif[7][3]=0;
              if(i==3)  grif[6][4]=0;
              if(i==2)  grif[7][4]=0;
              if(i==1)  grif[6][5]=0;
              if(i==0)  grif[7][5]=0;
            }
            if(icap == 4){
              if(i==11) grif[8][0]=0;
              if(i==10) grif[9][0]=0;
              if(i==9)  grif[8][1]=0;
              if(i==8)  grif[9][1]=0;
              if(i==7)  grif[8][2]=0;
              if(i==6)  grif[9][2]=0;
              if(i==5)  grif[8][3]=0;
              if(i==4)  grif[9][3]=0;
              if(i==3)  grif[8][4]=0;
              if(i==2)  grif[9][4]=0;
              if(i==1)  grif[8][5]=0;
              if(i==0)  grif[9][5]=0;
            }
            if(icap == 5){
              if(i==11) grif[10][0]=0;
              if(i==10) grif[11][0]=0;
              if(i==9)  grif[10][1]=0;
              if(i==8)  grif[11][1]=0;
              if(i==7)  grif[10][2]=0;
              if(i==6)  grif[11][2]=0;
              if(i==5)  grif[10][3]=0;
              if(i==4)  grif[11][3]=0;
              if(i==3)  grif[10][4]=0;
              if(i==2)  grif[11][4]=0;
              if(i==1)  grif[10][5]=0;
              if(i==0)  grif[11][5]=0;
            }
          }
        }
        lasttouched[icap] = currtouched[icap];
    }
    //esp32 touch pins check
    if(touchRead(TCH_0)<20) gstr[0]=20-touchRead(TCH_0); if(touchRead(TCH_0)>20) gstr[0]=0;
    if(touchRead(TCH_1)<20) gstr[1]=20-touchRead(TCH_1); if(touchRead(TCH_1)>20) gstr[1]=0;
    if(touchRead(TCH_2)<20) gstr[2]=20-touchRead(TCH_2); if(touchRead(TCH_2)>20) gstr[2]=0;
    if(touchRead(TCH_3)<20) gstr[3]=20-touchRead(TCH_3); if(touchRead(TCH_3)>20) gstr[3]=0;
    if(touchRead(TCH_4)<20) gstr[4]=20-touchRead(TCH_4); if(touchRead(TCH_4)>20) gstr[4]=0;
    if(touchRead(TCH_5)<20) gstr[5]=20-touchRead(TCH_5); if(touchRead(TCH_5)>20) gstr[5]=0;
}
