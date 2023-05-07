typedef struct Screen TScreen;

typedef struct  Label {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  char          *Caption;
  const char    *FontName;
  unsigned int  Font_Color;
  char          VerticalText;
  char          Visible;
  char          Active;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TLabel;

typedef struct  Image {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  const char    *Picture_Name;
  char          Visible;
  char          Active;
  char          Picture_Type;
  char          Picture_Ratio;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TImage;

typedef struct  Box {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  char          Pen_Width;
  unsigned int  Pen_Color;
  char          Visible;
  char          Active;
  char          Transparent;
  char          Gradient;
  char          Gradient_Orientation;
  unsigned int  Gradient_Start_Color;
  unsigned int  Gradient_End_Color;
  unsigned int  Color;
  char          PressColEnabled;
  unsigned int  Press_Color;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TBox;

typedef struct  Box_Round {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  char          Pen_Width;
  unsigned int  Pen_Color;
  char          Visible;
  char          Active;
  char          Transparent;
  char          Gradient;
  char          Gradient_Orientation;
  unsigned int  Gradient_Start_Color;
  unsigned int  Gradient_End_Color;
  unsigned int  Color;
  char          Corner_Radius;
  char          PressColEnabled;
  unsigned int  Press_Color;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TBox_Round;

struct Screen {
  unsigned int           Color;
  unsigned int           Width;
  unsigned int           Height;
  unsigned int           ObjectsCount;
  unsigned int           LabelsCount;
  TLabel                 * const code *Labels;
  unsigned int           ImagesCount;
  TImage                 * const code *Images;
  unsigned int           BoxesCount;
  TBox                   * const code *Boxes;
  unsigned int           Boxes_RoundCount;
  TBox_Round             * const code *Boxes_Round;
};

extern   TScreen                Screen1;
extern   TBox_Round             BoxRound1;
extern   TLabel                 Label2;
extern   TBox_Round             BoxRound2;
extern   TLabel                 Label3;
extern   TBox_Round             BoxRound3;
extern   TLabel                 Label1;
extern   TLabel                 * const code Screen1_Labels[3];
extern   TBox_Round             * const code Screen1_Boxes_Round[3];

extern   TScreen                Screen2;
extern   TBox                   Box2;
extern   TBox                   Box3;
extern   TImage               Image1;
extern   TImage                 * const code Screen2_Images[1];
extern   TBox                   * const code Screen2_Boxes[2];


/////////////////////////
// Events Code Declarations
void BoxRound1OnClick();
void BoxRound2OnClick();
void BoxRound3OnClick();
/////////////////////////

/////////////////////////////////
// Caption variables Declarations
extern char BoxRound1_Caption[];
extern char Label2_Caption[];
extern char BoxRound2_Caption[];
extern char Label3_Caption[];
extern char BoxRound3_Caption[];
extern char Label1_Caption[];
extern char Box2_Caption[];
extern char Box3_Caption[];
extern char Image1_Caption[];
/////////////////////////////////

void DrawScreen(TScreen *aScreen);
void DrawLabel(TLabel *ALabel);
void DrawImage(TImage *AImage);
void DrawBox(TBox *ABox);
void DrawRoundBox(TBox_Round *Around_box);
void Check_TP();
void Start_TP();
void Process_TP_Press(unsigned int X, unsigned int Y);
void Process_TP_Up(unsigned int X, unsigned int Y);
void Process_TP_Down(unsigned int X, unsigned int Y);