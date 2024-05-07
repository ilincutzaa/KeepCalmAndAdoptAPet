//#include <iostream>
//#include "FileRepository.h"
//#include "Controller.h"
//#include "UI.h"
//#include <fstream>
//#include "FileAdoption.h"
//
//void testReadDogs() {
//	std::ifstream f("testop.txt");
//	if (!f.is_open())
//		return;
//	if (f.peek() == std::ifstream::traits_type::eof())
//		return;
//	Dog d{ "Breed", "Age", 0, "https://keepcalmandadoptapet.com/photo.jpg" };
//	while (f >> d) {
//		std::cout << d;
//	}
//
//	f.close();
//}
//
//void testWriteDogs() {
//	std::ofstream f("testop.txt");
//	if (!f.is_open())
//		return;
//
//	std::vector<Dog> dogs;
//	Dog d1{ "Akita", "Melon", 2, "https://keepcalmandadoptapet.com/melon11.jpg" };
//	Dog d2{ "Shiba", "Baxter", 5, "https://keepcalmandadoptapet.com/baxter12.jpg" };
//	Dog d3{ "Bichon", "Minnie", 7,"https://keepcalmandadoptapet.com/minnie13.jpg" };
//	dogs.push_back(d1);
//	dogs.push_back(d2);
//	dogs.push_back(d3);
//
//	for (auto d : dogs) {
//		f << d;
//	}
//
//	f.close();
//}
//
//int main() {
//	{
//		testReadDogs();
//		testWriteDogs();
//		std::vector<Dog> v;
//		FileRepository repo{ v , "Dogs.txt"};
//		Controller control{ repo };
//		std::string inp;
//		while (true) {
//			std::cout << "Choose the type of file to save the adoption list in(CSV/HTML):\n(Or enter 0 to exit)\n>";
//			std::getline(std::cin, inp);
//			if (inp == "CSV") {
//				std::ofstream ofs;
//				ofs.open("adoptedDogs.csv", std::ofstream::out | std::ofstream::trunc);
//				ofs.close();
//				CSVFileAdoption* adoptionList = new CSVFileAdoption(repo, "adoptedDogs.csv");
//				UI ui{ control, adoptionList };
//				ui.start();
//				break;
//			}
//			else if (inp == "HTML") {
//				std::ofstream ofs;
//				ofs.open("adoptedDogs.html", std::ofstream::out | std::ofstream::trunc);
//				ofs.close();
//				HTMLFileAdoption* adoptionList = new HTMLFileAdoption(repo, "adoptedDogs.html");
//				UI ui{ control, adoptionList };
//				ui.start();
//				break;
//			}
//			else if (inp == "0")
//				break;
//			else
//				std::cout << "Invalid input\n";
//		}
//	}
//	return 0;
//}
