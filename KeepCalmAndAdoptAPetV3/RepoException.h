#pragma once
#include <string>
#include <exception>

class RepoException : public std::exception {
private:
	std::string message;
public:
	explicit RepoException(std::string msg) : message(msg) {};
	const char* what() const noexcept override {
		return message.c_str();
	}
};
