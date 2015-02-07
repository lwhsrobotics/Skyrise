#include "AutonomusCode.c"
void waitForPress(){
	while(!nLCDButtons){}
	wait1Msec(5);
}
void waitForRelease()
{
	while(!nLCDButtons){}
	wait1Msec(5);
}
int AutoSelc(){

	int count = 0;
	const short left = 1;
	const short midd = 2;
	const short right = 4;
	//nLCDButtons
	while(nLCDButtons != midd) {
		switch(count) {
		case 0:
			displayLCDCenteredString(0, "Cuber Magic");
			displayLCDCenteredString(1, "<-  Run?  ->");
			waitForPress(); //Runs Previous Method that checks for the button press
			if(nLCDButtons == left||nLCDButtons == right){
				waitForRelease();  //Runs Previous Method that checks for the button press
				count++;
			}
			break;
		case 1:
			displayLCDCenteredString(0, "Skyrise Magic");
			displayLCDCenteredString(1, "<-  Run?  ->");
			waitForPress(); //Runs Previous Method that checks for the button press
			if(nLCDButtons == left||nLCDButtons == right){
				waitForRelease();  //Runs Previous Method that checks for the button press
				count--;
			}
			break;
		}
	}


	switch(count) {//Selects which autonomus to run and runs it
		//runs None-Skyrise (Line Following?)
	case 0:
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDCenteredString(0, "Cuber Magic");
		displayLCDCenteredString(1, "************");
		return 0;
		break;
		//runs Skyrise Magic
	case 1:
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDCenteredString(0, "Skrise Magic");
		displayLCDCenteredString(1, "************");
		return 1;
		break;
		//If nothing is selected the it runs default
	default:
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDCenteredString(0, "FAILURE TO LOAD");
		displayLCDCenteredString(1, "************");
		return 2;
		break;
	}

}
