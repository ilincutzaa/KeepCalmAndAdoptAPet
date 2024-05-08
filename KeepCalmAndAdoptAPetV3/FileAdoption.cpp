#include "FileAdoption.h"

void CSVFileAdoption::saveToFile() {
	std::ofstream outfile{ this->filename };
	for (Dog d : this->getAdoptionList())
		outfile << d.getBreed() << "," << d.getName() << "," << d.getAge() << "," << d.getPhotograph() << std::endl;
	outfile.close();
}

void CSVFileAdoption::display() {
	ShellExecuteA(NULL, "open", "excel.exe", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void HTMLFileAdoption::saveToFile() {
	std::ofstream outfile{ this->filename };
	outfile << "<!DOCTYPE html>" << std::endl;
	outfile << "<html>" << std::endl;
	outfile << "<head>" << std::endl;
	outfile << "\t<title>ADOPTION LIST</title>" << std::endl;
	outfile << "</head>" << std::endl;
	outfile << "<body>" << std::endl;
	outfile << "<table border=\"1\">" << std::endl;
	outfile << "\t<tr>" << std::endl;
	outfile << "\t\t<td>Breed</td>" << std::endl;
	outfile << "\t\t<td>Name</td>" << std::endl;
	outfile << "\t\t<td>Age</td>" << std::endl;
	outfile << "\t\t<td>Photograph</td>" << std::endl;
	outfile << "\t</tr>" << std::endl;
	for(Dog d: this->getAdoptionList()){
		outfile << "\t<tr>" << std::endl;
		outfile << "\t\t<td>" << d.getBreed() << "</td>" << std::endl;
		outfile << "\t\t<td>" << d.getName() << "</td>" << std::endl;
		outfile << "\t\t<td>" << d.getAge() << "</td>" << std::endl;
		outfile << "\t\t<td><a href=" << d.getPhotograph() << ">Link</a></td>" << std::endl;
		outfile << "\t</tr>" << std::endl;
	}
	outfile << "</table>" << std::endl;
	outfile << "</body>" << std::endl;
	outfile << "</html>" << std::endl;
}

void HTMLFileAdoption::display() {
	ShellExecuteA(NULL, "open", "file:///C:/Users/TUF%20Gaming/source/repos/KeepCalmAndAdoptAPetV3/KeepCalmAndAdoptAPetV3/adoptedDogs.html", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void FileAdoption::addAdoptionList(Dog& d) {
	AdoptionList::addAdoptionList(d);
	this->saveToFile();
}
