//
// Created by buis_p on 1/17/18.
//

#ifndef RTYPE_DLLOADER_HPP
#	define RTYPE_DLLOADER_HPP

#	include <iostream>
#	include <string>
#	include <dlfcn.h>

template <class T>
class	DLLoader {
private:
	void	*handler;
public:
	DLLoader();
	explicit DLLoader(const std::string &libPath);
	DLLoader(const DLLoader<T> &other);
	DLLoader<T>	&operator=(const DLLoader<T> &other);
	~DLLoader() = default;

	void	diagnoseError();
	T		*getInstance(const std::string &);
};

#endif //RTYPE_DLLOADER_HPP

template<class T>
void	DLLoader<T>::diagnoseError() {
	std::string	errDL(dlerror());

	std::cerr << errDL << std::endl;
}

template<class T>
T		*DLLoader<T>::getInstance(const std::string &libPath) {

	T	*(*entr)();

	if ((this->handler = dlopen(libPath.c_str(), RTLD_LAZY)) == NULL) {
		this->diagnoseError();
		return (NULL);
	}
	if ((entr = (T *(*)()) dlsym(this->handler, "entryPoint")) == NULL) {
		this->diagnoseError();
		return (NULL);
	}
	return ((*entr)());
}

template<class T>
DLLoader<T>::DLLoader() {
	this->handler = NULL;
}

template<class T>
DLLoader<T>::DLLoader(const std::string &libPath) {
	this->handler = NULL;
}

template<class T>
DLLoader<T>::DLLoader(const DLLoader<T> &other) {
	this->handler = other.handler;
}

template<class T>
DLLoader<T> &DLLoader<T>::operator=(const DLLoader<T> &other) {
	this->handler = other.handler;
	return (*this);
}
