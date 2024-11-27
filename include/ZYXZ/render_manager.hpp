#pragma once

/*
编辑者：初阳LOCW
最新编写时间：2024.11.27
*/

#include "common.hpp"
#include "os.hpp"

class Vector;

//TODO :待完善
class RenderManager{
    public:
    
    RenderManager();
    ~RenderManager();

    void drawTexture(Texture *texture, int x, int y, int w, int h);
    void drawTexture(Texture *texture, Rect *rect);
    void drawTexture(Texture *texture, Vector *position, Vector *size);
    void drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth);
    void drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect);
    void drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size);

    void drawTexture(Texture *texture, int x, int y, int w, int h, double angle);
    void drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle);
    void drawTexture(Texture *texture, Rect *rect, double angle);
    void drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle);
    void drawTexture(Texture *texture, Vector *position, Vector *size, double angle);
    void drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle);

    void drawTexture(Texture *texture, int x, int y, int w, int h, double angle, int centerx, int centery);
    void drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle, int centerx, int centery);
    void drawTexture(Texture *texture, Rect *rect, double angle,  int centerx, int centery);
    void drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle, int centerx, int centery);
    void drawTexture(Texture *texture, Vector *position, Vector *size, double angle,  int centerx, int centery);
    void drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle, int centerx, int centery);
    void drawTexture(Texture *texture, int x, int y, int w, int h, double angle,Point *center);
    void drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle,Point *center);
    void drawTexture(Texture *texture, Rect *rect, double angle, Point *center);
    void drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle,Point *center);
    void drawTexture(Texture *texture, Vector *position, Vector *size, double angle, Point *center);
    void drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle,Point *center);

    void drawTexture(Texture *texture, int x, int y, int w, int h, double angle, int centerx, int centery, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle, int centerx, int centery, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Rect *rect, double angle,  int centerx, int centery, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle, int centerx, int centery, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Vector *position, Vector *size, double angle,  int centerx, int centery, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle, int centerx, int centery, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, int x, int y, int w, int h, double angle,Point *center, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle,Point *center, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Rect *rect, double angle, Point *center, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle,Point *center, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Vector *position, Vector *size, double angle, Point *center, SDL_RendererFlip flip);
    void drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle,Point *center, SDL_RendererFlip flip);

    void present();
};