#ifndef PLAYER_H
#define PLAYER_H
#include <gl/gl.h>
#include <textureLoader.h>
#include <Inputs.h>
#include <Timer.h>
#include <ObjList.h>



class Player
{
    public:
        Player();
        virtual ~Player();

        double x, y, z;
        double xMin, xMax, yMin, yMax;
        double xScale, yScale, zScale;
        double rotation; // current angle from default
        double speed;

        void drawPlayer();
        void lookAt(double,double);
        void playerInit(ObjList*);
        void playerInput(Inputs*);


    protected:
        ObjList* objectList;
        Timer spawnTimer;
        Timer mineSpawnTimer;
        Timer animationTimer;

    private:
        TextureLoader *idle;
};

#endif // PLAYER_H
