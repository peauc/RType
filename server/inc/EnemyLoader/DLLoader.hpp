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
public:
	DLLoader() = default;
	~DLLoader() = default;

	void	diagnoseError();
	T		*getInstance(const std::string &libPath);
};

#endif //RTYPE_DLLOADER_HPP

template<class T>
void	DLLoader<T>::diagnoseError() {
	std::string	errDL(dlerror());

	std::cerr << errDL << std::endl;
}

template<class T>
T		*DLLoader<T>::getInstance(const std::string &libPath) {
	void	*handler;
	T	*(*entr)();

	if ((handler = dlopen(libPath.c_str(), RTLD_LAZY)) == nullptr) {
		this->diagnoseError();
		return (NULL);
	}
	if ((entr = (T *(*)()) dlsym(handler, "entryPoint")) == NULL) {
		this->diagnoseError();
		return (NULL);
	}
	return ((*entr)());
}
