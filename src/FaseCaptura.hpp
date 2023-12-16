#ifndef FASECAPTURA_HPP
#define FASECAPTURA_HPP

#include "ASCII_Engine/Fase.hpp"

class FaseCaptura : public Fase
{
public:
	FaseCaptura(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseCaptura(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseCaptura() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo *Capturado;
};

#endif // FASEFINAL_HPP