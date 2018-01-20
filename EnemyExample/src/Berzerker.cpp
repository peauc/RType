//
// Created by buis_p on 1/18/18.
//

#include "Berzerker.hpp"

Berzerker::Berzerker() {

}

Berzerker::Berzerker(const Berzerker &other) {
	(void)other;
}

Berzerker& Berzerker::operator=(const Berzerker &other) {
	(void)other;
	return (*this);
}

extern "C" {
	Engine::Entity	*entrypoint(void) {
		return (new Berzerker());
	}
}
