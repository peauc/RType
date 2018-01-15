//
// Created by romain on 15/01/18.
//

#ifndef RTYPE_ICOMMAND_HPP
#define RTYPE_ICOMMAND_HPP

namespace Engine {
    namespace Commands {
        class ICommand {
        public:
            virtual void execute() = 0;
        };
    }
}

#endif //RTYPE_ICOMMAND_HPP
