#include "render_manager.hpp"
#include "object.hpp"
#include "object_manager.hpp"
#include "math.hpp"

RenderManager::RenderManager(){}

RenderManager::~RenderManager(){}

void RenderManager::drawTexture(Texture *texture, int x, int y, int w, int h){
    if(texture){
        SDL_Rect dstRect = {x, y, w, h};
        SDL_RenderCopy(OS::renderer, texture, NULL, &dstRect);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *rect){
    if (texture){
        SDL_RenderCopy(OS::renderer,texture,NULL,rect);
    }
}
void RenderManager::drawTexture(Texture *texture, Vector *position, Vector *size){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(), position->getIntY(), size->getIntX(), size->getIntY()};
        SDL_RenderCopy(OS::renderer,texture,NULL,&dstRect);
    }
}
void RenderManager::drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth){
    if (texture){
        SDL_Rect srcRect = {srcx, srcy, srcw, srch};
        SDL_Rect dstRect = {dstx, dsty, dstw, dsth};
        SDL_RenderCopy(OS::renderer,texture,&srcRect,&dstRect);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect){
    if (texture){
        SDL_RenderCopy(OS::renderer,texture,srcRect,dstRect);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(), position->getIntY(), size->getIntX(), size->getIntY()};
        SDL_RenderCopy(OS::renderer,texture,srcRect,&dstRect);
    }
}

//_______________________________________________________________________________________________________________
void RenderManager::drawTexture(Texture *texture, int x, int y, int w, int h, double angle){
    if (texture){
        SDL_Rect dstRect = {x, y, w, h};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,NULL,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle){
    if (texture){
        SDL_Rect srcRect = {srcx, srcy, srcw, srch};
        SDL_Rect dstRect = {dstx, dsty, dstw, dsth};
        SDL_RenderCopyEx(OS::renderer,texture,&srcRect,&dstRect,angle,NULL,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *rect, double angle){
    if (texture){
        SDL_RenderCopyEx(OS::renderer,texture,NULL,rect,angle,NULL,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle){
    if (texture){
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,dstRect,angle,NULL,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Vector *position, Vector *size, double angle){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(), position->getIntY(), size->getIntX(), size->getIntY()};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,NULL,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(), position->getIntY(), size->getIntX(), size->getIntY()};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,&dstRect,angle,NULL,SDL_FLIP_NONE);
    }
}

//_____________________________________________________________________________________________________________
void RenderManager::drawTexture(Texture *texture, int x, int y, int w, int h, double angle, int centerx, int centery){
    if (texture){
        SDL_Rect dstRect = {x, y, w, h};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,&center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle, int centerx, int centery){
    if (texture){
        SDL_Rect srcRect = {srcx, srcy, srcw, srch};
        SDL_Rect dstRect = {dstx, dsty, dstw, dsth};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,&srcRect,&dstRect,angle,&center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *rect, double angle,  int centerx, int centery){
    if (texture){
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,rect,angle,&center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle, int centerx, int centery){
    if (texture){
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,dstRect,angle,&center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Vector *position, Vector *size, double angle,  int centerx, int centery){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,&center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle, int centerx, int centery){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,&dstRect,angle,&center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, int x, int y, int w, int h, double angle,Point *center){
    if (texture){
        SDL_Rect dstRect = {x,y,w,h};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle,Point *center){
    if (texture){
        SDL_Rect srcRect = {srcx,srcy,srcw,srch};
        SDL_Rect dstRect = {dstx,dsty,dstw,dsth};
        SDL_RenderCopyEx(OS::renderer,texture,&srcRect,&dstRect,angle,center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *rect, double angle, Point *center){
    if (texture){
        SDL_RenderCopyEx(OS::renderer,texture,NULL,rect,angle,center,SDL_FLIP_NONE);
    }
}

void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle,Point *center){
    if (texture){
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,dstRect,angle,center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Vector *position, Vector *size, double angle, Point *center){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,center,SDL_FLIP_NONE);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle,Point *center){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,&dstRect,angle,center,SDL_FLIP_NONE);
    }
}

//_____________________________________________________________________________________________________________
void RenderManager::drawTexture(Texture *texture, int x, int y, int w, int h, double angle, int centerx, int centery, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect dstRect = {x, y, w, h};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,&center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle, int centerx, int centery, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect srcRect = {srcx, srcy, srcw, srch};
        SDL_Rect dstRect = {dstx, dsty, dstw, dsth};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,&srcRect,&dstRect,angle,&center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *rect, double angle,  int centerx, int centery, SDL_RendererFlip flip){
    if (texture){
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,rect,angle,&center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle, int centerx, int centery, SDL_RendererFlip flip){
    if (texture){
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,dstRect,angle,&center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Vector *position, Vector *size, double angle,  int centerx, int centery, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,&center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle, int centerx, int centery, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_Point center = {centerx,centery};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,&dstRect,angle,&center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, int x, int y, int w, int h, double angle,Point *center, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect dstRect = {x,y,w,h};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, int srcx, int srcy, int srcw, int srch, int dstx, int dsty, int dstw, int dsth, double angle,Point *center, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect srcRect = {srcx,srcy,srcw,srch};
        SDL_Rect dstRect = {dstx,dsty,dstw,dsth};
        SDL_RenderCopyEx(OS::renderer,texture,&srcRect,&dstRect,angle,center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *rect, double angle, Point *center, SDL_RendererFlip flip){
    if (texture){
        SDL_RenderCopyEx(OS::renderer,texture,NULL,rect,angle,center,flip);
    }
}

void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Rect *dstRect, double angle,Point *center, SDL_RendererFlip flip){
    if (texture){
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,dstRect,angle,center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Vector *position, Vector *size, double angle, Point *center, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_RenderCopyEx(OS::renderer,texture,NULL,&dstRect,angle,center,flip);
    }
}
void RenderManager::drawTexture(Texture *texture, Rect *srcRect, Vector *position, Vector *size, double angle,Point *center, SDL_RendererFlip flip){
    if (texture){
        SDL_Rect dstRect = {position->getIntX(),position->getIntY(),size->getIntX(),size->getIntY()};
        SDL_RenderCopyEx(OS::renderer,texture,srcRect,&dstRect,angle,center,flip);
    }
}

void RenderManager::present(){
    SDL_RenderPresent(OS::renderer);
}

void RenderManager::renderObjects(ObjectManager *objectManager){
    for (auto object = objectManager->objects.begin(); object != objectManager->objects.end(); ++object){
        if(object->second->isVisible) object->second->draw();
        std::cout << object->second->isVisible << std::endl;
    }
}