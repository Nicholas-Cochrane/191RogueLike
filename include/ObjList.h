#ifndef OBJLIST_H
#define OBJLIST_H
#include <TextureLoader.h>

//#include <sound.h>
using namespace std;

class GameObject;

class ObjList
{
    public:
        ObjList(int);
        virtual ~ObjList();

        //int createObj(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        //int createObj(double, double); // X,Y (return index) if no free space return -1

        int createProjectile(double, double, double, double, double, double, double, double);// X,Y,Z,scaleX,scaleY,Rotate,speedX,SpeedY (return index) if no free space return -1
        int createProjectile(double, double, double, double); // X,Y,VelocityX,VelocityY (return index) if no free space return -1
        int createProjectile(double,double,double,double,double); //x,y,Vx,Vy,rotation

        int createMine(double, double, double, double, double, double); // X,Y,Z,scaleX,scaleY,Rotate (return index)if no free space return -1
        int createMine(double, double); // X,Y (return index) if no free space return -1

        int createExplosion(double, double);

        bool deleteObject(int); // delete index (return false if NULL)
        GameObject* getObj(int);
        void draw();
        void runPerFrame();
        int Size();

        void initTextures();

        //called in an entities runperframe, and given the object type, returns true upon
        //collision between entity and certain object
        //for enemy and plaer (two entities), create the functn n glscene
        bool collisioncheck(double, double); // x y //call jn enemes rnperframe, passng enemes vale

        //functon that checks for collsion between enemy and mine called in
        //enemies runperframe, inputs are enemies xpos,ypos
        bool collisioncheckEM(double,double);

        //funtion that checks for collision between enemy and projectile
        //called in enemies runperdframe, npts are enemies xpos, ypos
        bool collisioncheckEF(double,double);

        //collision check for mine and boss
        bool collisioncheckBM(double,double);

        //collision check for gunfire and boss
        bool collisioncheckBF(double,double);

        //for collision sound, call it where this function is called
        //don't know if I'll use these
        //void setXpos(double); // called in the area object is spawned so it can give xPos a value
        //void setYpos(double); // called in the area object is spawned so it can give yPos a value
        //double getXpos(); //
        //double getYpos();
        //void soundT(sound*);
        bool mineRuntimeCheck();


    protected:

        TextureLoader* textures;

        GameObject **objectList;
        int size;

        const double zOffput = 0.00015;

    private:
        //double xPos;
        //double yPos;
};

#endif // OBJLIST_H
