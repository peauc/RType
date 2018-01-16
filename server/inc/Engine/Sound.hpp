//
// Created by romain on 11/01/18.
//

#ifndef RTYPE_SOUND_HPP
#define RTYPE_SOUND_HPP

namespace Engine {
	class Sound
	{
	public:
		Sound(unsigned int id, bool loop, bool music);
		~Sound() = default;

		unsigned int getId() const;
		void setId(unsigned int _id);
		bool isLoop() const;
		void setLoop(bool _loop);
		bool isMusic() const;
		void setMusic(bool _music);

	private:
		unsigned int _id;
		bool _loop;
		bool _music;
	};
}

#endif //RTYPE_SOUND_HPP
