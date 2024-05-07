#pragma once
#include <string>
#include <exception>

class DogException : public std::exception {
private:
	std::string message;
public:
	explicit DogException(std::string msg) : message(msg) {};
	const char* what() const noexcept override {
		return message.c_str();
	}
};
