#include "Help.h"
#include <iostream>

void Help::printInfo() const
{
	using std::cout;
	using std::endl;

	cout << endl << "First command must be \"load <images>\", where <images> are at least one image file name." << endl;
	cout << "Files must contain the binary implementation of .pbm, .pgm and .ppm files." << endl;
	cout << endl << "Commands:" << endl;
	cout << "1.load <images> - starting new session with <images>" << endl;
	cout << "2.The transformations: (apply to all images in session)" << endl;
	cout << "2.1.grayscale - turning color images into grey ones." << endl;
	cout << "2.2.monochrome - turning color and grey images into black and white ones." << endl;
	cout << "2.3.negative - turning images into their oposite colors." << endl;
	cout << "2.4.rotate <direction> - flipping images left or right." << endl;
	cout << "3.undo - removing last transformation in the session." << endl;
	cout << "4.add <image> - adding image in the session" << endl;
	cout << "5.session info" << endl;
	cout << "6.switch <session> - switching to other session by id." << endl;
	cout << "7.collage <direction> <image1> <image2> <outimage>- Making collage with 2 images vertically or horizontically." << endl;
	cout << "8.save - saving changes from transformations in the session and saving the result in files, undo doesn't help." << endl;
	cout << "9.saveas <name> - saving the first image in the session with a new name and Removes it from the session." << endl;
	cout << "10.closeimage - closes First image in session without saving it." << endl;
	cout << "11.close <session> - Closes session with id, without saving changes." << endl;
	cout << "12.help - Pops this information." << endl;
	cout << "13.exit - Ends program without saving." << endl;
}

void Help::execute()
{
	printInfo();
}
