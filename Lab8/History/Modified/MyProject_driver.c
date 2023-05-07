#include "MyProject_objects.h"
#include "MyProject_resources.h"
#include "built_in.h"


// TFT module connections
sbit TFT_BLED at GPIOE_ODR.B9;
sbit TFT_CS at GPIOE_ODR.B15;
unsigned int TFT_DataPort at GPIOE_ODR;
sbit TFT_RD at GPIOE_ODR.B10;
sbit TFT_RS at GPIOE_ODR.B12;
sbit TFT_RST at GPIOE_ODR.B8;
sbit TFT_WR at GPIOE_ODR.B11;
// End TFT module connections

// Touch Panel module connections
sbit DriveX_Left at GPIOB_ODR.B1;
sbit DriveX_Right at GPIOB_ODR.B8;
sbit DriveY_Up at GPIOB_ODR.B9;
sbit DriveY_Down at GPIOB_ODR.B0;
// End Touch Panel module connections

// Global variables
unsigned int Xcoord, Ycoord;
const ADC_THRESHOLD = 1500;
char PenDown;
void *PressedObject;
int PressedObjectType;
unsigned int caption_length, caption_height;
unsigned int display_width, display_height;

int _object_count;
unsigned short object_pressed;
TLabel *local_label;
TLabel *exec_label;
int label_order;
TImage *local_image;
TImage *exec_image;
int image_order;
TBox *local_box;
TBox *exec_box;
int box_order;
TBox_Round *local_round_box;
TBox_Round *exec_round_box;
int box_round_order;


void Init_ADC() {
  ADC_Set_Input_Channel(_ADC_CHANNEL_8 | _ADC_CHANNEL_9);
  ADC1_Init();
  Delay_ms(100);
}
static void InitializeTouchPanel() {
  Init_ADC();
  TFT_Init_ILI9341_8bit(320, 240);

  TP_TFT_Init(320, 240, 8, 9);                                  // Initialize touch panel
  TP_TFT_Set_ADC_Threshold(ADC_THRESHOLD);                              // Set touch panel ADC threshold

  PenDown = 0;
  PressedObject = 0;
  PressedObjectType = -1;
}

void Calibrate() {
  TFT_Set_Pen(CL_WHITE, 3);
  TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("Touch selected corners for calibration", 50, 80);
  TFT_Line(315, 239, 319, 239);
  TFT_Line(309, 229, 319, 239);
  TFT_Line(319, 234, 319, 239);
  TFT_Write_Text("first here", 210, 220);

  TP_TFT_Calibrate_Min();                      // Calibration of TP minimum
  Delay_ms(500);

  TFT_Set_Pen(CL_BLACK, 3);
  TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
  TFT_Line(315, 239, 319, 239);
  TFT_Line(309, 229, 319, 239);
  TFT_Line(319, 234, 319, 239);
  TFT_Write_Text("first here", 210, 220);

  TFT_Set_Pen(CL_WHITE, 3);
  TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("now here ", 20, 5);
  TFT_Line(0, 0, 5, 0);
  TFT_Line(0, 0, 0, 5);
  TFT_Line(0, 0, 10, 10);

  TP_TFT_Calibrate_Max();                       // Calibration of TP maximum
  Delay_ms(500);
}


/////////////////////////
  TScreen*  CurrentScreen;

  TScreen                Screen1;
  TBox_Round             BoxRound1;
  TLabel                 Label2;
char Label2_Caption[12] = "Zeyad Tarek";

  TBox_Round             BoxRound2;
  TLabel                 Label3;
char Label3_Caption[12] = "Ahmed Hosny";

  TBox_Round             BoxRound3;
  TLabel                 Label1;
char Label1_Caption[18] = "Abdelrahman Fathi";

  TLabel                 * const code Screen1_Labels[3]=
         {
         &Label2,              
         &Label3,              
         &Label1               
         };
  TBox_Round             * const code Screen1_Boxes_Round[3]=
         {
         &BoxRound1,           
         &BoxRound2,           
         &BoxRound3            
         };

  TScreen                Screen2;
  TBox                   Box2;
  TBox                   Box3;
  TImage               Image1;
  TImage                 * const code Screen2_Images[1]=
         {
         &Image1               
         };
  TBox                   * const code Screen2_Boxes[2]=
         {
         &Box2,                
         &Box3                 
         };



static void InitializeObjects() {
  Screen1.Color                     = 0x67E0;
  Screen1.Width                     = 320;
  Screen1.Height                    = 240;
  Screen1.LabelsCount               = 3;
  Screen1.Labels                    = Screen1_Labels;
  Screen1.ImagesCount               = 0;
  Screen1.BoxesCount                = 0;
  Screen1.Boxes_RoundCount          = 3;
  Screen1.Boxes_Round               = Screen1_Boxes_Round;
  Screen1.ObjectsCount              = 6;

  Screen2.Color                     = 0xFFFF;
  Screen2.Width                     = 320;
  Screen2.Height                    = 240;
  Screen2.LabelsCount               = 0;
  Screen2.ImagesCount               = 1;
  Screen2.Images                    = Screen2_Images;
  Screen2.BoxesCount                = 2;
  Screen2.Boxes                     = Screen2_Boxes;
  Screen2.Boxes_RoundCount          = 0;
  Screen2.ObjectsCount              = 3;


  BoxRound1.OwnerScreen     = &Screen1;
  BoxRound1.Order           = 0;
  BoxRound1.Left            = 8;
  BoxRound1.Top             = 6;
  BoxRound1.Width           = 308;
  BoxRound1.Height          = 61;
  BoxRound1.Pen_Width       = 1;
  BoxRound1.Pen_Color       = 0x0000;
  BoxRound1.Visible         = 1;
  BoxRound1.Active          = 1;
  BoxRound1.Transparent     = 1;
  BoxRound1.Gradient        = 1;
  BoxRound1.Gradient_Orientation = 0;
  BoxRound1.Gradient_Start_Color = 0xFFE0;
  BoxRound1.Gradient_End_Color = 0xFCC6;
  BoxRound1.Color           = 0xC618;
  BoxRound1.PressColEnabled = 0;
  BoxRound1.Press_Color     = 0xE71C;
  BoxRound1.Corner_Radius   = 20;
  BoxRound1.OnClickPtr      = BoxRound1OnClick;

  Label2.OwnerScreen     = &Screen1;
  Label2.Order           = 1;
  Label2.Left            = 74;
  Label2.Top             = 23;
  Label2.Width           = 161;
  Label2.Height          = 36;
  Label2.Visible         = 1;
  Label2.Active          = 1;
  Label2.Caption         = Label2_Caption;
  Label2.FontName        = Tahoma26x33_Regular;
  Label2.Font_Color      = 0x0000;
  Label2.VerticalText    = 0;

  BoxRound2.OwnerScreen     = &Screen1;
  BoxRound2.Order           = 2;
  BoxRound2.Left            = 12;
  BoxRound2.Top             = 81;
  BoxRound2.Width           = 300;
  BoxRound2.Height          = 61;
  BoxRound2.Pen_Width       = 1;
  BoxRound2.Pen_Color       = 0x0000;
  BoxRound2.Visible         = 1;
  BoxRound2.Active          = 1;
  BoxRound2.Transparent     = 1;
  BoxRound2.Gradient        = 1;
  BoxRound2.Gradient_Orientation = 0;
  BoxRound2.Gradient_Start_Color = 0x367F;
  BoxRound2.Gradient_End_Color = 0x319F;
  BoxRound2.Color           = 0xC618;
  BoxRound2.PressColEnabled = 0;
  BoxRound2.Press_Color     = 0xE71C;
  BoxRound2.Corner_Radius   = 20;
  BoxRound2.OnClickPtr      = BoxRound2OnClick;

  Label3.OwnerScreen     = &Screen1;
  Label3.Order           = 3;
  Label3.Left            = 61;
  Label3.Top             = 95;
  Label3.Width           = 179;
  Label3.Height          = 36;
  Label3.Visible         = 1;
  Label3.Active          = 1;
  Label3.Caption         = Label3_Caption;
  Label3.FontName        = Tahoma26x33_Regular;
  Label3.Font_Color      = 0x0000;
  Label3.VerticalText    = 0;

  BoxRound3.OwnerScreen     = &Screen1;
  BoxRound3.Order           = 4;
  BoxRound3.Left            = 8;
  BoxRound3.Top             = 165;
  BoxRound3.Width           = 308;
  BoxRound3.Height          = 61;
  BoxRound3.Pen_Width       = 1;
  BoxRound3.Pen_Color       = 0x0000;
  BoxRound3.Visible         = 1;
  BoxRound3.Active          = 1;
  BoxRound3.Transparent     = 1;
  BoxRound3.Gradient        = 1;
  BoxRound3.Gradient_Orientation = 0;
  BoxRound3.Gradient_Start_Color = 0xFCDF;
  BoxRound3.Gradient_End_Color = 0xF819;
  BoxRound3.Color           = 0xC618;
  BoxRound3.PressColEnabled = 0;
  BoxRound3.Press_Color     = 0xE71C;
  BoxRound3.Corner_Radius   = 20;
  BoxRound3.OnClickPtr      = BoxRound2OnClick;

  Label1.OwnerScreen     = &Screen1;
  Label1.Order           = 5;
  Label1.Left            = 40;
  Label1.Top             = 176;
  Label1.Width           = 240;
  Label1.Height          = 36;
  Label1.Visible         = 1;
  Label1.Active          = 1;
  Label1.Caption         = Label1_Caption;
  Label1.FontName        = Tahoma26x33_Regular;
  Label1.Font_Color      = 0x0000;
  Label1.VerticalText    = 0;

  Box2.OwnerScreen     = &Screen2;
  Box2.Order           = 0;
  Box2.Left            = 0;
  Box2.Top             = 1;
  Box2.Width           = 318;
  Box2.Height          = 84;
  Box2.Pen_Width       = 1;
  Box2.Pen_Color       = 0x0000;
  Box2.Visible         = 1;
  Box2.Active          = 1;
  Box2.Transparent     = 1;
  Box2.Gradient        = 1;
  Box2.Gradient_Orientation = 0;
  Box2.Gradient_Start_Color = 0xF800;
  Box2.Gradient_End_Color = 0xF800;
  Box2.Color           = 0xC618;
  Box2.PressColEnabled = 1;
  Box2.Press_Color     = 0xE71C;

  Box3.OwnerScreen     = &Screen2;
  Box3.Order           = 1;
  Box3.Left            = 1;
  Box3.Top             = 162;
  Box3.Width           = 318;
  Box3.Height          = 77;
  Box3.Pen_Width       = 1;
  Box3.Pen_Color       = 0x0000;
  Box3.Visible         = 1;
  Box3.Active          = 1;
  Box3.Transparent     = 1;
  Box3.Gradient        = 1;
  Box3.Gradient_Orientation = 0;
  Box3.Gradient_Start_Color = 0x0000;
  Box3.Gradient_End_Color = 0x0000;
  Box3.Color           = 0xC618;
  Box3.PressColEnabled = 1;
  Box3.Press_Color     = 0xE71C;

  Image1.OwnerScreen     = &Screen2;
  Image1.Order           = 2;
  Image1.Left            = 130;
  Image1.Top             = 91;
  Image1.Width           = 60;
  Image1.Height          = 60;
  Image1.Picture_Type    = 1;
  Image1.Picture_Ratio   = 1;
  Image1.Picture_Name    = eagle_jpg;
  Image1.Visible         = 1;
  Image1.Active          = 1;
}

static char IsInsideObject (unsigned int X, unsigned int Y, unsigned int Left, unsigned int Top, unsigned int Width, unsigned int Height) { // static
  if ( (Left<= X) && (Left+ Width - 1 >= X) &&
       (Top <= Y)  && (Top + Height - 1 >= Y) )
    return 1;
  else
    return 0;
}


#define GetLabel(index)               CurrentScreen->Labels[index]
#define GetImage(index)               CurrentScreen->Images[index]
#define GetBox(index)                 CurrentScreen->Boxes[index]
#define GetBox_Round(index)           CurrentScreen->Boxes_Round[index]


void DrawLabel(TLabel *ALabel) {
  if (ALabel->Visible != 0) {
    if (ALabel->VerticalText != 0)
      TFT_Set_Font(ALabel->FontName, ALabel->Font_Color, FO_VERTICAL_COLUMN);
    else
      TFT_Set_Font(ALabel->FontName, ALabel->Font_Color, FO_HORIZONTAL);
    TFT_Write_Text(ALabel->Caption, ALabel->Left, ALabel->Top);
  }
}

void DrawImage(TImage *AImage) {
  if (AImage->Visible != 0) {
    TFT_Image_Jpeg(AImage->Left, AImage->Top, AImage->Picture_Name);
  }
}

void DrawBox(TBox *ABox) {
  if (ABox->Visible != 0) {
    if (object_pressed == 1) {
      object_pressed = 0;
      TFT_Set_Brush(ABox->Transparent, ABox->Press_Color, ABox->Gradient, ABox->Gradient_Orientation, ABox->Gradient_End_Color, ABox->Gradient_Start_Color);
    }
    else {
      TFT_Set_Brush(ABox->Transparent, ABox->Color, ABox->Gradient, ABox->Gradient_Orientation, ABox->Gradient_Start_Color, ABox->Gradient_End_Color);
    }
    TFT_Set_Pen(ABox->Pen_Color, ABox->Pen_Width);
    TFT_Rectangle(ABox->Left, ABox->Top, ABox->Left + ABox->Width - 1, ABox->Top + ABox->Height - 1);
  }
}

void DrawRoundBox(TBox_Round *Around_box) {
  if (Around_box->Visible != 0) {
    if (object_pressed == 1) {
      object_pressed = 0;
      TFT_Set_Brush(Around_box->Transparent, Around_box->Press_Color, Around_box->Gradient, Around_box->Gradient_Orientation,
                    Around_box->Gradient_End_Color, Around_box->Gradient_Start_Color);
    }
    else {
      TFT_Set_Brush(Around_box->Transparent, Around_box->Color, Around_box->Gradient, Around_box->Gradient_Orientation,
                    Around_box->Gradient_Start_Color, Around_box->Gradient_End_Color);
    }
    TFT_Set_Pen(Around_box->Pen_Color, Around_box->Pen_Width);
    TFT_Rectangle_Round_Edges(Around_box->Left + 1, Around_box->Top + 1,
      Around_box->Left + Around_box->Width - 2,
      Around_box->Top + Around_box->Height - 2, Around_box->Corner_Radius);
  }
}

void DrawScreen(TScreen *aScreen) {
 unsigned int order;
  unsigned short label_idx;
  TLabel *local_label;
  unsigned short image_idx;
  TImage *local_image;
  unsigned short box_idx;
  TBox *local_box;
  unsigned short round_box_idx;
  TBox_Round *local_round_box;
  char save_bled;

  object_pressed = 0;
  order = 0;
  label_idx = 0;
  image_idx = 0;
  box_idx = 0;
  round_box_idx = 0;
  CurrentScreen = aScreen;

  if ((display_width != CurrentScreen->Width) || (display_height != CurrentScreen->Height)) {
    save_bled = TFT_BLED;
    TFT_BLED           = 0;
    TFT_Init_ILI9341_8bit(CurrentScreen->Width, CurrentScreen->Height);
    TP_TFT_Init(CurrentScreen->Width, CurrentScreen->Height, 8, 9);                                  // Initialize touch panel
    TP_TFT_Set_ADC_Threshold(ADC_THRESHOLD);                              // Set touch panel ADC threshold
    TFT_Fill_Screen(CurrentScreen->Color);
    display_width = CurrentScreen->Width;
    display_height = CurrentScreen->Height;
    TFT_BLED           = save_bled;
  }
  else
    TFT_Fill_Screen(CurrentScreen->Color);


  while (order < CurrentScreen->ObjectsCount) {
    if (label_idx < CurrentScreen->LabelsCount) {
      local_label = GetLabel(label_idx);
      if (order == local_label->Order) {
        label_idx++;
        order++;
        DrawLabel(local_label);
      }
    }

    if (box_idx < CurrentScreen->BoxesCount) {
      local_box = GetBox(box_idx);
      if (order == local_box->Order) {
        box_idx++;
        order++;
        DrawBox(local_box);
      }
    }

    if (round_box_idx < CurrentScreen->Boxes_RoundCount) {
      local_round_box = GetBox_Round(round_box_idx);
      if (order == local_round_box->Order) {
        round_box_idx++;
        order++;
        DrawRoundBox(local_round_box);
      }
    }

    if (image_idx < CurrentScreen->ImagesCount) {
      local_image = GetImage(image_idx);
      if (order == local_image->Order) {
        image_idx++;
        order++;
        DrawImage(local_image);
      }
    }

  }
}

void Get_Object(unsigned int X, unsigned int Y) {
  label_order         = -1;
  image_order         = -1;
  box_order           = -1;
  box_round_order     = -1;
  //  Labels
  for ( _object_count = 0 ; _object_count < CurrentScreen->LabelsCount ; _object_count++ ) {
    local_label = GetLabel(_object_count);
    if (local_label->Active != 0) {
      if (IsInsideObject(X, Y, local_label->Left, local_label->Top,
                         local_label->Width, local_label->Height) == 1) {
        label_order = local_label->Order;
        exec_label = local_label;
      }
    }
  }

  //  Images
  for ( _object_count = 0 ; _object_count < CurrentScreen->ImagesCount ; _object_count++ ) {
    local_image = GetImage(_object_count);
    if (local_image->Active != 0) {
      if (IsInsideObject(X, Y, local_image->Left, local_image->Top,
                         local_image->Width, local_image->Height) == 1) {
        image_order = local_image->Order;
        exec_image = local_image;
      }
    }
  }

  //  Boxes
  for ( _object_count = 0 ; _object_count < CurrentScreen->BoxesCount ; _object_count++ ) {
    local_box = GetBox(_object_count);
    if (local_box->Active != 0) {
      if (IsInsideObject(X, Y, local_box->Left, local_box->Top,
                         local_box->Width, local_box->Height) == 1) {
        box_order = local_box->Order;
        exec_box = local_box;
      }
    }
  }

  //  Boxes with Round Edges
  for ( _object_count = 0 ; _object_count < CurrentScreen->Boxes_RoundCount ; _object_count++ ) {
    local_round_box = GetBox_Round(_object_count);
    if (local_round_box->Active != 0) {
      if (IsInsideObject(X, Y, local_round_box->Left, local_round_box->Top,
                         local_round_box->Width, local_round_box->Height) == 1) {
        box_round_order = local_round_box->Order;
        exec_round_box = local_round_box;
      }
    }
  }

  _object_count = -1;
  if (label_order >  _object_count )
    _object_count = label_order;
  if (image_order >  _object_count )
    _object_count = image_order;
  if (box_order >  _object_count )
    _object_count = box_order;
  if (box_round_order >  _object_count )
    _object_count = box_round_order;
}


void Process_TP_Press(unsigned int X, unsigned int Y) {
  exec_label          = 0;
  exec_image          = 0;
  exec_box            = 0;
  exec_round_box      = 0;

  Get_Object(X, Y);

  if (_object_count != -1) {
    if (_object_count == label_order) {
      if (exec_label->Active != 0) {
        if (exec_label->OnPressPtr != 0) {
          exec_label->OnPressPtr();
          return;
        }
      }
    }

    if (_object_count == image_order) {
      if (exec_image->Active != 0) {
        if (exec_image->OnPressPtr != 0) {
          exec_image->OnPressPtr();
          return;
        }
      }
    }

    if (_object_count == box_order) {
      if (exec_box->Active != 0) {
        if (exec_box->OnPressPtr != 0) {
          exec_box->OnPressPtr();
          return;
        }
      }
    }

    if (_object_count == box_round_order) {
      if (exec_round_box->Active != 0) {
        if (exec_round_box->OnPressPtr != 0) {
          exec_round_box->OnPressPtr();
          return;
        }
      }
    }

  }
}

void Process_TP_Up(unsigned int X, unsigned int Y) {

  switch (PressedObjectType) {
    // Box
    case 6: {
      if (PressedObject != 0) {
        exec_box = (TBox*)PressedObject;
        if ((exec_box->PressColEnabled != 0) && (exec_box->OwnerScreen == CurrentScreen)) {
          DrawBox(exec_box);
        }
        break;
      }
      break;
    }
    // Round Box
    case 7: {
      if (PressedObject != 0) {
        exec_round_box = (TBox_Round*)PressedObject;
        if ((exec_round_box->PressColEnabled != 0) && (exec_round_box->OwnerScreen == CurrentScreen)) {
          DrawRoundBox(exec_round_box);
        }
        break;
      }
      break;
    }
  }

  exec_label          = 0;
  exec_image          = 0;

  Get_Object(X, Y);


  if (_object_count != -1) {
  // Labels
    if (_object_count == label_order) {
      if (exec_label->Active != 0) {
        if (exec_label->OnUpPtr != 0)
          exec_label->OnUpPtr();
        if (PressedObject == (void *)exec_label)
          if (exec_label->OnClickPtr != 0)
            exec_label->OnClickPtr();
        PressedObject = 0;
        PressedObjectType = -1;
        return;
      }
    }

  // Images
    if (_object_count == image_order) {
      if (exec_image->Active != 0) {
        if (exec_image->OnUpPtr != 0)
          exec_image->OnUpPtr();
        if (PressedObject == (void *)exec_image)
          if (exec_image->OnClickPtr != 0)
            exec_image->OnClickPtr();
        PressedObject = 0;
        PressedObjectType = -1;
        return;
      }
    }

  // Boxes
    if (_object_count == box_order) {
      if (exec_box->Active != 0) {
        if (exec_box->OnUpPtr != 0)
          exec_box->OnUpPtr();
        if (PressedObject == (void *)exec_box)
          if (exec_box->OnClickPtr != 0)
            exec_box->OnClickPtr();
        PressedObject = 0;
        PressedObjectType = -1;
        return;
      }
    }

  // Boxes with Round Edges
    if (_object_count == box_round_order) {
      if (exec_round_box->Active != 0) {
        if (exec_round_box->OnUpPtr != 0)
          exec_round_box->OnUpPtr();
        if (PressedObject == (void *)exec_round_box)
          if (exec_round_box->OnClickPtr != 0)
            exec_round_box->OnClickPtr();
        PressedObject = 0;
        PressedObjectType = -1;
        return;
      }
    }

  }
  PressedObject = 0;
  PressedObjectType = -1;
}

void Process_TP_Down(unsigned int X, unsigned int Y) {

  object_pressed      = 0;
  exec_label          = 0;
  exec_image          = 0;
  exec_box            = 0;
  exec_round_box      = 0;

  Get_Object(X, Y);

  if (_object_count != -1) {
    if (_object_count == label_order) {
      if (exec_label->Active != 0) {
        PressedObject = (void *)exec_label;
        PressedObjectType = 2;
        if (exec_label->OnDownPtr != 0) {
          exec_label->OnDownPtr();
          return;
        }
      }
    }

    if (_object_count == image_order) {
      if (exec_image->Active != 0) {
        PressedObject = (void *)exec_image;
        PressedObjectType = 3;
        if (exec_image->OnDownPtr != 0) {
          exec_image->OnDownPtr();
          return;
        }
      }
    }

    if (_object_count == box_order) {
      if (exec_box->Active != 0) {
        if (exec_box->PressColEnabled != 0) {
          object_pressed = 1;
          DrawBox(exec_box);
        }
        PressedObject = (void *)exec_box;
        PressedObjectType = 6;
        if (exec_box->OnDownPtr != 0) {
          exec_box->OnDownPtr();
          return;
        }
      }
    }

    if (_object_count == box_round_order) {
      if (exec_round_box->Active != 0) {
        if (exec_round_box->PressColEnabled != 0) {
          object_pressed = 1;
          DrawRoundBox(exec_round_box);
        }
        PressedObject = (void *)exec_round_box;
        PressedObjectType = 7;
        if (exec_round_box->OnDownPtr != 0) {
          exec_round_box->OnDownPtr();
          return;
        }
      }
    }

  }
}

void Check_TP() {
  if (TP_TFT_Press_Detect()) {
    if (TP_TFT_Get_Coordinates(&Xcoord, &Ycoord) == 0) {
    // After a PRESS is detected read X-Y and convert it to Display dimensions space
      Process_TP_Press(Xcoord, Ycoord);
      if (PenDown == 0) {
        PenDown = 1;
        Process_TP_Down(Xcoord, Ycoord);
      }
    }
  }
  else if (PenDown == 1) {
    PenDown = 0;
    Process_TP_Up(Xcoord, Ycoord);
  }
}

void Init_MCU() {
  GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_9);
  TFT_BLED = 1;
  TFT_Set_Default_Mode();
  TP_TFT_Set_Default_Mode();
}

void Start_TP() {
  Init_MCU();

  InitializeTouchPanel();

  Delay_ms(1000);
  TFT_Fill_Screen(0);
  Calibrate();
  TFT_Fill_Screen(0);

  InitializeObjects();
  display_width = Screen1.Width;
  display_height = Screen1.Height;
  DrawScreen(&Screen1);
}