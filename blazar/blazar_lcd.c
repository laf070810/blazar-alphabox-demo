/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_lcd.h"
#include "blazar_lcd_font.h" 

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
unsigned int POINT_COLOR = 0x0000,BACK_COLOR = 0xFFFF;  
unsigned int DeviceCode;	

/*******************************************************************************
 * Code
 ******************************************************************************/
void delay_ms(int time)
{
  int i,j;
  for(i = 0;i < time/4.9;i ++)
  {
    for(j = 48000;j > 0;j --)
    {
//       asm("nop");    
    }
  }
}

void LCD_WriteReg(unsigned int LCD_Reg, unsigned int LCD_RegValue)
{	
	LCD_WR_REG(LCD_Reg);  
	LCD_WR_DATA(LCD_RegValue);	    		 
}	   

unsigned int LCD_ReadReg(unsigned int LCD_Reg)
{										   
    unsigned int t;
    LCD_WR_REG(LCD_Reg);
    GPIO_ConfigLCDDataPins(0);
    
    LCD_RS_SET;
    LCD_CS_CLR;

    LCD_RS_CLR;					   
    LCD_RS_SET;
    t = DATAIN;  
    LCD_CS_SET;

    GPIO_ConfigLCDDataPins(1);
    return t; 
}  

void LCD_WriteRAM_Prepare(void)
{
	LCD_WR_REG(0x2c);
}	 

void LCD_WriteRAM(unsigned int RGB_Code)
{							    
	LCD_WR_DATA(RGB_Code);
}

unsigned int LCD_BGR2RGB(unsigned int c)
{
	unsigned int  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
}		 
//璇诲彇涓煇鐐圭殑棰滆壊锟� 
//x:0~239
//y:0~319
//杩斿洖锟�姝ょ偣鐨勯锟�
/*unsigned int LCD_ReadPoint(unsigned int x,unsigned int y)
{
	unsigned int t;	
	if(x>=LCD_W||y>=LCD_H)return 0;//瓒呰繃浜嗚寖锟�鐩存帴杩斿洖		   
	LCD_SetCursor(x,y);
	LCD_WR_REG(R34);       //閫夋嫨GRAM鍦板潃 
	GPIOB->CRL=0X88888888; //PB0-7  涓婃媺杈撳叆
	GPIOB->CRH=0X88888888; //PB8-15 涓婃媺杈撳叆
	GPIOB->ODR=0XFFFF;     //鍏ㄩ儴杈撳嚭锟�
#if LCD_FAST_IO==1 //蹇�IO
	LCD_RS_SET;
	LCD_CS_CLR;
	//璇诲彇鏁版嵁(璇籊RAM锟�闇�璇�锟�
	LCD_RD_CLR;					   
	LCD_RD_SET;
	delay_us(2);//FOR 9320,寤舵椂2us					   
	//dummy READ
	LCD_RD_CLR;					   
	delay_us(2);//FOR 8989,寤舵椂2us					   
	LCD_RD_SET;
	t=DATAIN;  
	LCD_CS_SET;
#else
	LCD_RS_SET;
	LCD_CS_CLR;
	//璇诲彇鏁版嵁(璇籊RAM锟�闇�璇�锟�
	LCD_RS_CLR;					   
 	LCD_RS_SET;
 	//dummy READ
	LCD_RS_CLR;					   
 	LCD_RS_SET;
	t=DATAIN;  
	LCD_CS_SET;  
#endif 
	GPIOB->CRL=0X33333333; //PB0-7  涓婃媺杈撳嚭
	GPIOB->CRH=0X33333333; //PB8-15 涓婃媺杈撳嚭
	GPIOB->ODR=0XFFFF;    //鍏ㄩ儴杈撳嚭锟� 
	if(DeviceCode==0X4535||DeviceCode==0X4531||DeviceCode==0X8989||DeviceCode==0XB505)return t;//杩欏嚑绉岻C鐩存帴杩斿洖棰滆壊锟�
	else return LCD_BGR2RGB(t);
}
*/

void LCD_DisplayOn(void)
{					   
	LCD_WriteReg(R7, 0x0173);
}	 

void LCD_DisplayOff(void)
{	   
	LCD_WriteReg(R7, 0x0);
}   

void LCD_SetCursor(unsigned int row, unsigned int column)
{	
    LCD_WR_REG(0x2b);
    LCD_WR_DATA(row >> 8);
    LCD_WR_DATA(row & 0xff);
    LCD_WR_DATA(row >> 8);
    LCD_WR_DATA(row & 0xff);

    LCD_WR_REG(0x2a);
    LCD_WR_DATA(column >> 8);
    LCD_WR_DATA(column & 0xff);			 
    LCD_WR_DATA(column >> 8);
    LCD_WR_DATA(column & 0xff);
}  

void LCD_SetRegion(unsigned int row_start, unsigned int row_end, unsigned int column_start, unsigned int column_end)
{
#if USE_HORIZONTAL==1	//使用横屏
	LCD_WR_REG(0x2a);
    LCD_WR_DATA(row_start >> 8);
    LCD_WR_DATA(row_start & 0xff);
    LCD_WR_DATA(row_end >> 8);
    LCD_WR_DATA(row_end & 0xff);

    LCD_WR_REG(0x2b);
    LCD_WR_DATA(column_start >> 8);
    LCD_WR_DATA(column_start & 0xff);			 
    LCD_WR_DATA(column_end >> 8);
    LCD_WR_DATA(column_end & 0xff);
#else
	LCD_WR_REG(0x2b);
    LCD_WR_DATA(row_start >> 8);
    LCD_WR_DATA(row_start & 0xff);
    LCD_WR_DATA(row_end >> 8);
    LCD_WR_DATA(row_end & 0xff);

    LCD_WR_REG(0x2a);
    LCD_WR_DATA(column_start >> 8);
    LCD_WR_DATA(column_start & 0xff);			 
    LCD_WR_DATA(column_end >> 8);
    LCD_WR_DATA(column_end & 0xff);
#endif
}

void LCD_DrawPoint(unsigned int x,unsigned int y)
{
	LCD_SetCursor(x,y);
	LCD_WR_REG(0x2c);
    LCD_WR_DATA(POINT_COLOR>>8);  
    LCD_WR_DATA(POINT_COLOR&0xff); 
} 

void LCD_Init(void)
{ 
    GPIO_LCDPinsInit();
	
	LCD_RESET();//澶嶄綅
	  					 
	delay_ms(15); // delay 50 ms 
	LCD_WriteReg(0x00,0x01);
	delay_ms(15); // delay 50 ms  
    DeviceCode = LCD_ReadReg(0x04);   
//	printf(" LCD ID:%x\n",DeviceCode);   
 	
	//************* Start Initial Sequence **********//   ILI9341+IVO2.8
	LCD_WR_REG(0xCF);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0xD9); 
	LCD_WR_DATA(0X30); 
	 
	LCD_WR_REG(0xED);  
	LCD_WR_DATA(0x64); 
	LCD_WR_DATA(0x03); 
	LCD_WR_DATA(0X12); 
	LCD_WR_DATA(0X81); 
	 
	LCD_WR_REG(0xE8);  
	LCD_WR_DATA(0x85); 
	LCD_WR_DATA(0x10); 
	LCD_WR_DATA(0x78); 
	 
	LCD_WR_REG(0xCB);  
	LCD_WR_DATA(0x39); 
	LCD_WR_DATA(0x2C); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x34); 
	LCD_WR_DATA(0x02); 
	 
	LCD_WR_REG(0xF7);  
	LCD_WR_DATA(0x20); 
	 
	LCD_WR_REG(0xEA);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x00); 
	 
	LCD_WR_REG(0xC0);    //Power control 
	LCD_WR_DATA(0x21);   //VRH[5:0] 
	 
	LCD_WR_REG(0xC1);    //Power control 
	LCD_WR_DATA(0x12);   //SAP[2:0];BT[3:0] 
	 
	LCD_WR_REG(0xC5);    //VCM control 
	LCD_WR_DATA(0x32); 
	LCD_WR_DATA(0x3C); 
	 
	LCD_WR_REG(0xC7);    //VCM control2 
	LCD_WR_DATA(0XC1); 
	 
	LCD_WR_REG(0x36);    // Memory Access Control 
	LCD_WR_DATA(0x88);   // 0x08(浠庡乏鍒板彸,浠庝笂鍒颁笅) -> 0x88(浠庡乏鍒板彸,浠庝笅鍒颁笂)
	 
	LCD_WR_REG(0x3A);   
	LCD_WR_DATA(0x55); 
	
	LCD_WR_REG(0xB1);   
	LCD_WR_DATA(0x00);   
	LCD_WR_DATA(0x18); 
	 
	LCD_WR_REG(0xB6);    // Display Function Control 
	LCD_WR_DATA(0x0A); 
	LCD_WR_DATA(0xA2); 
	
	 
	 
	LCD_WR_REG(0xF2);    // 3Gamma Function Disable 
	LCD_WR_DATA(0x00); 
	 
	LCD_WR_REG(0x26);    //Gamma curve selected 
	LCD_WR_DATA(0x01); 
	 
	LCD_WR_REG(0xE0);    //Set Gamma 
	LCD_WR_DATA(0x0F); 
	LCD_WR_DATA(0x20); 
	LCD_WR_DATA(0x1E); 
	LCD_WR_DATA(0x09); 
	LCD_WR_DATA(0x12); 
	LCD_WR_DATA(0x0B); 
	LCD_WR_DATA(0x50); 
	LCD_WR_DATA(0XBA); 
	LCD_WR_DATA(0x44); 
	LCD_WR_DATA(0x09); 
	LCD_WR_DATA(0x14); 
	LCD_WR_DATA(0x05); 
	LCD_WR_DATA(0x23); 
	LCD_WR_DATA(0x21); 
	LCD_WR_DATA(0x00); 
	 
	LCD_WR_REG(0XE1);    //Set Gamma 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x19); 
	LCD_WR_DATA(0x19); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x12); 
	LCD_WR_DATA(0x07); 
	LCD_WR_DATA(0x2D); 
	LCD_WR_DATA(0x28); 
	LCD_WR_DATA(0x3F); 
	LCD_WR_DATA(0x02); 
	LCD_WR_DATA(0x0A); 
	LCD_WR_DATA(0x08); 
	LCD_WR_DATA(0x25); 
	LCD_WR_DATA(0x2D); 
	LCD_WR_DATA(0x0F); 
	 
	LCD_WR_REG(0x11);    //Exit Sleep 
	delay_ms(120); 
	LCD_WR_REG(0x29);    //Display on 

	LCD_LED_CLR;//鐐逛寒鑳屽厜	 
//	LCD_Clear(WHITE);
}  		  

void LCD_Clear(unsigned int Color)
{
	LCD_Fill(0, LCD_H - 1, 0, LCD_W - 1, WHITE);
} 

void LCD_Fill(unsigned int row_start, unsigned int row_end, unsigned int column_start, unsigned int column_end, unsigned int color)
{          
	unsigned long pixel_num = (row_end - row_start + 1) * (column_end - column_start + 1);
	
	LCD_SetRegion(row_start, row_end, column_start, column_end);
	LCD_WR_REG(0x2c);
	for(unsigned long i = 0; i < pixel_num; i++)
	{
		LCD_WR_DATA(color>>8);  
		LCD_WR_DATA(color&0xff);  
	}						  	    
}  

void LCD_DrawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
	unsigned int t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; //璁＄畻鍧愭爣澧為噺 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //璁剧疆鍗曟鏂瑰悜 
	else if(delta_x==0)incx=0;//鍨傜洿锟�
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//姘村钩锟�
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //閫夊彇鍩烘湰澧為噺鍧愭爣锟�
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//鐢荤嚎杈撳嚭 
	{  
		LCD_DrawPoint(uRow,uCol);//鐢荤偣 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}    

void LCD_DrawRectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}

void Draw_Circle(unsigned int x0,unsigned int y0,unsigned int r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //鍒ゆ柇涓嬩釜鐐逛綅缃殑鏍囧織
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a);             //3           
		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0-a,y0+b);             //1       
		LCD_DrawPoint(x0-b,y0-a);             //7           
		LCD_DrawPoint(x0-a,y0-b);             //2             
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0-b);             //5
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-b,y0+a);             
		a++;
		//浣跨敤Bresenham绠楁硶鐢诲渾     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		LCD_DrawPoint(x0+a,y0+b);
	}
} 
//鍦ㄦ寚瀹氫綅缃樉绀轰竴涓瓧锟�
//x:0~234
//y:0~308
//num:瑕佹樉绀虹殑瀛楃:" "--->"~"
//size:瀛椾綋澶у皬 12/16
//mode:鍙犲姞鏂瑰紡(1)杩樻槸闈炲彔鍔犳柟锟�0)
//鍦ㄦ寚瀹氫綅缃樉绀轰竴涓瓧锟�
//x:0~234
//y:0~308
//num:瑕佹樉绀虹殑瀛楃:" "--->"~"
//size:瀛椾綋澶у皬 12/16
//mode:鍙犲姞鏂瑰紡(1)杩樻槸闈炲彔鍔犳柟锟�0)
void LCD_ShowChar(unsigned int x,unsigned int y,unsigned int num,unsigned int size,unsigned int mode)
{  
#if USE_HORIZONTAL==1
#define MAX_CHAR_POSX 320
#define MAX_CHAR_POSY 240 
#else     
#define MAX_CHAR_POSX 240
#define MAX_CHAR_POSY 320
#endif 
  unsigned int temp;
  unsigned int pos,t;
  unsigned int x0=x;
  unsigned int colortemp=POINT_COLOR;      
  if(x>MAX_CHAR_POSX||y>MAX_CHAR_POSY)return;	    
    //璁剧疆绐楀彛		   
    num=num-' ';//寰楀埌鍋忕Щ鍚庣殑锟�
    if(!mode) //闈炲彔鍔犳柟锟�
    {
        for(pos=0;pos<size;pos++)
        {
          if(size==12)temp=asc2_1206[num][pos];//璋冪敤1206瀛椾綋
          else temp=asc2_1608[num][pos];		 //璋冪敤1608瀛椾綋
          for(t=0;t<size/2;t++)
          {                 
            if(temp&0x01)POINT_COLOR=colortemp;
            else POINT_COLOR=BACK_COLOR;
            LCD_DrawPoint(x,y);	
            temp>>=1; 
            x++;
          }
          x=x0;
          y++;
        }	
    }else//鍙犲姞鏂瑰紡
    {
        for(pos=0;pos<size;pos++)
        {
          if(size==12)temp=asc2_1206[num][pos];//璋冪敤1206瀛椾綋
          else temp=asc2_1608[num][pos];		 //璋冪敤1608瀛椾綋
          for(t=0;t<size/2;t++)
          {                 
            if(temp&0x01)LCD_DrawPoint(x+t,y+pos);//鐢讳竴涓偣     
            temp>>=1; 
          }
        }
    }
    POINT_COLOR=colortemp;	    	   	 	  
}   
//m^n鍑芥暟
unsigned long mypow(unsigned int m,unsigned int n)
{
	unsigned long result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//鏄剧ず2涓暟锟�
//x,y :璧风偣鍧愭爣	 
//len :鏁板瓧鐨勪綅锟�
//size:瀛椾綋澶у皬
//color:棰滆壊
//num:鏁帮拷?0~4294967295);	 
void LCD_ShowNum(unsigned int x,unsigned int y,unsigned long num,unsigned int len,unsigned int size)
{         	
	unsigned int t,temp;
	unsigned int enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0);
				continue;
			}else enshow=1; 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0); 
	}
} 
//鏄剧ず2涓暟锟�
//x,y:璧风偣鍧愭爣
//size:瀛椾綋澶у皬
//mode:妯″紡	0,濉厖妯″紡;1,鍙犲姞妯″紡
//num:鏁帮拷?0~99);	 
void LCD_Show2Num(unsigned int x,unsigned int y,unsigned int num,unsigned int len,unsigned int size,unsigned int mode)
{         	
	unsigned int t,temp;						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode); 
	}
} 
//鏄剧ず瀛楃锟�
//x,y:璧风偣鍧愭爣  
//*p:瀛楃涓茶捣濮嬪湴鍧�
//锟�6瀛椾綋


void LCD_ShowString(unsigned char lx,unsigned char ly,char *sch) {
	char *p2ch = sch;
	unsigned char L_x = lx;
	while (*p2ch) {
		LCD_ShowChar(L_x,ly,*p2ch++,12,0);
		L_x+=12;
	}
}


void LCD_ShowPicture(unsigned int x,unsigned int y,const unsigned char *pic){
	unsigned int i,j;
	for(j=y;j<pic_y+y;j++)
    {
	for(i=x;i<=pic_x+x;i++)
	{	  
	 	  LCD_SetCursor(i,j);      //璁剧疆鍏夋爣浣嶇疆 
	          LCD_WR_REG(0x2c);//寮�鍐欏叆GRAM
              LCD_WR_DATA(pic[2*((j-y)*pic_x+i-x)+1]);  
              LCD_WR_DATA(pic[2*((j-y)*pic_x+i-x)]);  
	}
    }
}


void GPIO_LCDPinsInit(void)
{
	gpio_pin_config_t gpio_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    
	for (int i = 0; i < 8; i++)
	{
		GPIO_PinInit(GPIOD, i, &gpio_config);
	}
	GPIO_PinInit(GPIOB, 8, &gpio_config);
	GPIO_PinInit(GPIOB, 9, &gpio_config);
	GPIO_PinInit(GPIOB, 10, &gpio_config);
	GPIO_PinInit(GPIOB, 11, &gpio_config);
	GPIO_PinInit(GPIOA, 19, &gpio_config);
	GPIO_PinInit(GPIOE, 31, &gpio_config);
}


unsigned int GPIO_ReadLCDDataPins(void)
{
	unsigned int Result = 0;
	
	for (int i = 0; i < 8; i++)
	{
		Result += GPIO_ReadPinInput(GPIOD, i) << i;
	}
	
	return Result;
}


void GPIO_ConfigLCDDataPins(int flag)
{
	gpio_pin_config_t gpio_config;
	gpio_config.outputLogic = 1U;
	
	//1 for output and 0 for input
	if (flag == 0)
	{
		gpio_config.pinDirection = kGPIO_DigitalInput;
	}
	else
	{
		gpio_config.pinDirection = kGPIO_DigitalOutput;
	}
	
	for (int i = 0; i < 8; i++)
	{
		GPIO_PinInit(GPIOD, i, &gpio_config);
	}
}
