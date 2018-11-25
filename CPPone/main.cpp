#include <iostream>
#include "Image.h"
#include "Commons.h"
#include "ppm.h"
#include "Color.h"

#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include <cstring>

using namespace std;
using namespace imaging;
using namespace commons;


/*
Image* ReadPPM(const char* filename) {
	ifstream file(filename, ios_base::binary);
	if (!file) {
		return NULL;
	}

	string text;
	string line;
	unsigned short width, height;
	bool correcttype = false;
	vector<string> list;
	while (getline(file, line)) {
		text.append(line);
		text.append(" ");
		unsigned position = line.find("255");
		if (position != string::npos) {
			break;
		}
	}

	char* charText = stringToChar(text);
	list = split(charText, ' ');
	if (list[0] == "P3") {
		cerr << "P3 format is not supported." << endl;
		return NULL;
	}
	if (list[1] == "") {
		cerr << "The width of the image is not specified." << endl;
		return NULL;
	}
	width = mystoi(list[1]);
	if (list[2] == "") {
		cerr << "The height of the image is not specified." << endl;
		return NULL;
	}
	height = mystoi(list[2]);
	if (list[3] == "") {
		cerr << "The maximum value is not specified." << endl;
		return NULL;
	}
	if (mystoi(list[3]) > 255) {
		cerr << "Maximum value is over 255!" << endl;
		return NULL;
	}

	char* data = new char[width * height * 3];
	float* fdata = new float[width * height * 3];
	file.read(data, width * height * 3 * sizeof(char));

	for (int i = 0; i < width * height * 3; i++) {
		char t = data[i];
		unsigned char tt = (unsigned char)t;
		float pp = tt / 255.0f;
		fdata[i] = pp;
	}

	Image *image = new Image(width, height, (component_t*)fdata);
	delete[] data;
	return image;
}
*/

int main()
{
	
	// 0) DONE Το όνομα του εκτελέσιμου πρέπει να είναι neg.exe 
	//     το όνομα της εικόνας προς φόρτωση δίνεται ως όρισμα, αλλιώς ζητείται κατά την εκτέλεση
	// 1a) readPPM --> ανοίγει την εικόνα και και την αποθηκεύει σε ένα instance της κλάσης Image
	//     μετατρέπει τα εύρη [0,255] σε [0.0,1.0]
	//     να διαβάζει την κεφαλίδα της εικόνας, υποθέτωντας πως δεν υπάρχουν σχόλια ενδιάμεσα
	//     σφάλματα που μπορεί να προκύψουν, πρέπει να διαχειριστούν:
	//        - δεν υπάρχει το αρχείο που προσπαθούμε να ανοίξουμε ή δεν ανοίγει
	//        - δεν είναι τύπου P6
	//        - λείπει η οριζόντια ή/και η κάθετη διάσταση της εικόνας
	//        - απέτυχε να διαβαστεί η μέγιστη τιμή αποθήκευσης ή είναι μεγαλύτερη του 255
	// 1b) το πρόγραμμα επιστρέφει τις διαστάσεις της εικόνας και το αρνητικό της 
	//	   η αρνητική τιμή ενός πίξελ υπολογίζεται ως Negt(Pixel(x,y))=(1,1,1)-Pixel(x,y)
	// 1c) writePPM --> αποθηκεύει την εικόνα σε νέο αρχείο ppm, με επίθεμα	_neg (i.e, photo1_neg.ppm)
	// 1d) οι άνω 2 μέθοδοι να υλοποιηθούν στο ppm.cpp και να πακεταριστούν στο ppm.lib
	// 
	// 2) Υλοποίηση των μεθόδων της κλάσσης Image. H load να χρησιμοποιεί την readPPM, και η save την writePPM από την ppm.lib
	// 3) Υλοποίηση της main λειτουργικότητας στο 1, με χρήση της ppm.lib.
	
	string i;
	Commons cm;
	cout << "Please enter the full name (with extension) of the ppm image: ";
	cin >> i;
	cout << "File entered: " << i << "\n";
	///*
	int * w = NULL;
	int * h = NULL;
	//std::string s = std::to_string(i);
	ReadPPM(cm.stringToChar(i), w, h);
	//*/

	//cout << " and its double is " << i * 2 << "\n";
	return 0;
}