#include "MyProject_objects.h"
#include "MyProject_resources.h"

//--------------------- User code ---------------------//

//----------------- End of User code ------------------//

// Event Handlers
void BoxRound1OnClick() {
         GPIOD_ODR = 0xFFFF;

}
void BoxRound2OnClick() {
          GPIOD_ODR = 0x0000;
}
void BoxRound3OnClick() {

}