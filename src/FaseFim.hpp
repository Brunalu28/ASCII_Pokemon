#ifndef FASEFIM_HPP
#define FASEFIM_HPP

#include "ASCII_Engine/Fase.hpp"

class FaseFim : public Fase
{
public:
	FaseFim(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseFim(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseFim() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo *fim;
};

#endif // FASEFINAL_HPP