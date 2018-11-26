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


int main(int argc, char* argv[]) {

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
	//	   η αρνητική τιμή ενός πίξελ υπολογίζεται ως NegPixel(Pixel(x,y))=(1,1,1)-Pixel(x,y)
	// 1c) writePPM --> αποθηκεύει την εικόνα σε νέο αρχείο ppm, με επίθεμα	_neg (i.e, photo1_neg.ppm)
	// 1d) οι άνω 2 μέθοδοι να υλοποιηθούν στο ppm.cpp και να πακεταριστούν στο ppm.lib
	// 
	// 2) Υλοποίηση των μεθόδων της κλάσσης Image. H load να χρησιμοποιεί την readPPM, και η save την writePPM από την ppm.lib
	// 3) Υλοποίηση της main λειτουργικότητας στο 1, με χρήση της ppm.lib.
	
	string file;
	if (argc != 2) {
		cout << "Please enter the full name (with extension) of the ppm image: ";
		cin >> file;
	}
	else {
		file = argv[1];
	}

	Commons cm;
	Image im;
	//cout << "File: " << file << "\n";
	const char * filenameInChar = cm.stringToChar(file);
	const vector<string> filenameSplitted = cm.split(filenameInChar, '.');
	if (!im.load(filenameSplitted[0], filenameSplitted[1]))
		return 1;




	/*
	//Save negative
	bool saver = WritePPM(imageData, 500, 200, cm.stringToChar(filenameSplitted[0])+'_neg'+'.ppm');
	if (saver) {
		cout << "Please enter the full name (with extension) of the ppm image: ";
	}
	*/
	return 0;
}